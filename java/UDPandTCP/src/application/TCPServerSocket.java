package application;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.security.DigestInputStream;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Arrays;

/**
 * Реализовать программу передачи фйала (alice.txt) по сети
 * используя два протокола TCP и UDP.
 * Размер передаваемых даннх не должен превышать 16 байт
 * <p>
 * Дополнительное задание:
 * Проверить результирующие файлы испоьзуя хеш (MD5 или SHA, можно оба)
 */

public class TCPServerSocket {
    private final int PORT = 8448;
    //считываем сюда фаил в бинарном виде
    private byte[] buffer;
    private String pathFile = "alice.txt";
    private boolean fileLoaded = false;
    private final Object monitor = new Object();
    private byte[] md5;

    private synchronized byte[] getBytes(int start, int end) {
        byte[] part;
        synchronized (monitor) {
            part = Arrays.copyOfRange(buffer, start, end);
        }
        return part;
    }

    private void start() throws IOException {
        System.out.println("The file downloaded in binary form!");
        try (ServerSocket serverSocket = new ServerSocket(PORT)) {
            while (true) {
                Socket socket = serverSocket.accept();
                System.out.println("Socket created!");
                new Thread() {
                    @Override
                    public void run() {
                        try {
                            sendFile(socket);
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                    }
                }.start();
            }
        }
    }


    //метод загрузки файла в строку
    private synchronized void LoadFile() throws IOException, NoSuchAlgorithmException {
        MessageDigest md = MessageDigest.getInstance("MD5");
        try (InputStream in = new FileInputStream(pathFile);
             DigestInputStream dis = new DigestInputStream(in, md)) {
            buffer = new byte[in.available()];
            in.read(buffer, 0, in.available());
            fileLoaded = true;
            notify();
        }
        md5 = md.digest();
    }

    private void sendFile(Socket socket) throws IOException {
        OutputStream out = socket.getOutputStream();
        InputStream in = socket.getInputStream();

        int sizeBuffer = 16;
        byte[] answer = new byte[sizeBuffer];
        int offset = 0;
        int length = 0;
        byte[] bytes;

        //отправляем имя файла, пока клиент не ответит ок
        int lengthAnswer;
        do {
            out.write(("TCP" + pathFile).getBytes());
            lengthAnswer = in.read(answer);
        } while (!new String(answer, 0, lengthAnswer).equalsIgnoreCase("OK"));

        System.out.println("Client has got name of file");

        do {
            do {
                length += sizeBuffer;
                if (length > buffer.length) {
                    length = buffer.length;
                }
                bytes = getBytes(offset, length);
                out.write(bytes);
                offset = length;

            } while (offset < buffer.length);

            out.write("END OF FILE".getBytes());
            lengthAnswer = in.read(answer);
        } while (!new String(answer, 0, lengthAnswer).equalsIgnoreCase("OK"));

        System.out.println("Client has got a file " + pathFile);

        do {
            out.write(md5);
            lengthAnswer = in.read(answer);
        } while (!new String(answer, 0, lengthAnswer).equalsIgnoreCase("OK"));

        System.out.println("The socket has destroyed");
    }

    public static void main(String[] args) throws IOException, InterruptedException, NoSuchAlgorithmException {
        TCPServerSocket socket = new TCPServerSocket();
        socket.LoadFile();
        synchronized (socket) {
            while (!socket.fileLoaded) {
                socket.wait();
            }
        }
        socket.start();
    }
}