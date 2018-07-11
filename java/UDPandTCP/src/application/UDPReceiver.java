package application;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.security.DigestInputStream;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Arrays;

public class UDPReceiver {

    private static final int PORT_RECEIVER = 12_121;
    private static final int PORT_SENDER = 12_122;

    private String pathFile;
    private DatagramSocket datagramSocketSender;
    private DatagramSocket datagramSocketReceiver;
    private byte[] buffer;
    private int sizeSend = 16;
    private byte[] md5 = new byte[0];
    private DatagramPacket packetSend;
    private DatagramPacket packetReceive;
    private int sizeReceive = 255;
    private final Object monitor = new Object();
    private byte[] md5_local = new byte[0];

    public UDPReceiver() throws SocketException {
        datagramSocketReceiver = new DatagramSocket(PORT_RECEIVER);
        datagramSocketSender = new DatagramSocket();
    }

    //стартуем загрузку файла
    public void start() throws IOException, NoSuchAlgorithmException, InterruptedException {
        byte[] data;
        //отправляем сикретное слова, мы готовы к загрузке
        data = "REQUEST".getBytes();
        packetSend = new DatagramPacket(data, 0, data.length, InetAddress.getLocalHost(), PORT_SENDER);
        datagramSocketSender.send(packetSend);

        //получакм имя файла
        do {
            packetReceive = new DatagramPacket(new byte[sizeReceive], sizeReceive);
            datagramSocketReceiver.receive(packetReceive);
            pathFile = new String(packetReceive.getData(), packetReceive.getOffset(), packetReceive.getLength());
            data = "GOTNAME".getBytes();
            packetSend = new DatagramPacket(data, 0, data.length, InetAddress.getLocalHost(), PORT_SENDER);
            datagramSocketSender.send(packetSend);
        } while (pathFile.equalsIgnoreCase(""));

        System.out.println("Sent name of the file is successful!");

        //получаем тело файла
        System.out.println(pathFile);
        try (OutputStream out = new FileOutputStream(pathFile)) {
            while (true) {
                int sizePartFile = 16;
                packetReceive = new DatagramPacket(new byte[sizePartFile], sizePartFile);
                datagramSocketReceiver.receive(packetReceive);
                //ждём конца файла
                if (new String(packetReceive.getData(), packetReceive.getOffset(), packetReceive.getLength()).equalsIgnoreCase("END OF FILE")) {
                    //отправляем ок
                    data = "GOTFILE".getBytes();
                    packetSend = new DatagramPacket(data, 0, data.length, InetAddress.getLocalHost(), PORT_SENDER);
                    datagramSocketSender.send(packetSend);
                    System.out.println("I have got the file " + pathFile);
                    break;
                }
                //пишим в фаил бинарные данные
                out.write(packetReceive.getData(), packetReceive.getOffset(), packetReceive.getLength());
            }
        }

        GetMD5();
        while (!Arrays.equals(md5, md5_local)) {
            datagramSocketReceiver.receive(packetReceive);
            md5 = packetReceive.getData();
            if (!Arrays.equals(md5, md5_local)) {
                data = "ERROR".getBytes();
                packetReceive = new DatagramPacket(data, 0, data.length, InetAddress.getLocalHost(), PORT_SENDER);
                datagramSocketSender.send(packetSend);
            }
        }

        data = "END".getBytes();
        packetReceive = new DatagramPacket(data, 0, data.length, InetAddress.getLocalHost(), PORT_SENDER);
        datagramSocketSender.send(packetSend);
        System.out.println("md5 equals!!!!!!");
        System.out.println("Sent the file is successful!");
    }

    private void GetMD5() throws NoSuchAlgorithmException, IOException {
        MessageDigest md = MessageDigest.getInstance("MD5");
        try (InputStream is = Files.newInputStream(Paths.get(pathFile));
             DigestInputStream dis = new DigestInputStream(is, md)) {
        }
        md5_local = md.digest();
    }

    public static void main(String[] args) {

        try {
            UDPReceiver server = new UDPReceiver();
            server.start();
        } catch (IOException | NoSuchAlgorithmException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}