package application;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.security.DigestInputStream;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Arrays;
import java.util.Scanner;

public class TCPSocket {

    private final int port = 8448;
    private final String host = "localhost";
    private final InetSocketAddress address;
    private final int sizeBuffer = 16;
    private String fileName = "new.txt";
    public final int count = 0;
    private byte[] md5_local;

    public TCPSocket() throws UnknownHostException {
        address = new InetSocketAddress(host, port);
    }

    private void start() throws IOException, NoSuchAlgorithmException {

        Socket socket = new Socket();
        socket.connect(address);

        System.out.println("I have got the connection!");

        InputStream in = socket.getInputStream();
        OutputStream out = socket.getOutputStream();

        byte[] buffer = new byte[sizeBuffer * 4];
        int lenName = in.read(buffer);
        fileName = new String(buffer, 0, lenName);
        out.write("OK".getBytes());

        System.out.println("I have got the name of file");

        do {
            try (FileOutputStream fout = new FileOutputStream(fileName)) {
                int length = 0;
                while (true) {
                    buffer = new byte[sizeBuffer];
                    length = in.read(buffer);
                    if (new String(buffer, 0, length).equalsIgnoreCase("END OF FILE")) {
                        out.write("OK".getBytes());
                        System.out.println("I have got the file " + fileName);
                        break;
                    }
                    fout.write(buffer);
                }
            }

            byte[] md5 = new byte[16];
            in.read(md5);
            GetMD5();
            if (Arrays.equals(md5, md5_local)) {
                out.write("OK".getBytes());
                System.out.println("md5 equals!!!!");
                System.out.println("The socket has destroyed");
                break;
            } else {
                out.write("ERROR".getBytes());
            }
        } while (true);
    }

    private void GetMD5() throws NoSuchAlgorithmException, IOException {
        MessageDigest md = MessageDigest.getInstance("MD5");
        try (InputStream is = Files.newInputStream(Paths.get(fileName));
             DigestInputStream dis = new DigestInputStream(is, md)) {
        }
        md5_local = md.digest();
    }

    public static void main(String[] args) {
        try {
            new TCPSocket().start();
        } catch (IOException | NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}
