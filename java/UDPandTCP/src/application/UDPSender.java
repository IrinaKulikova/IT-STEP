package application;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.security.DigestInputStream;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Arrays;

public class UDPSender {

    private static final int PORT_RECEIVER = 12_122;
    private static final int PORT_SENDER = 12_121;

    private String pathFile = "alice.txt";
    private DatagramSocket datagramSocketSender;
    private DatagramSocket datagramSocketReceiver;
    private byte[] buffer;
    private int sizeSend = 16;
    private boolean fileLoaded = false;
    private byte[] md5;
    DatagramPacket packetSend;
    DatagramPacket packetReseive;
    private int sizeReseive = 255;
    private final Object monitor = new Object();

    //синхронизированный метод для доступа к данным в массиве байт файла, который нужно передать по сети
    private synchronized byte[] getBytes(int start, int end) {
        byte[] part;
        synchronized (monitor) {
            part = Arrays.copyOfRange(buffer, start, end);
        }
        return part;
    }

    //конструктор
    public UDPSender() throws SocketException {
        datagramSocketReceiver = new DatagramSocket(PORT_RECEIVER);
        datagramSocketSender = new DatagramSocket();
        packetReseive = new DatagramPacket(new byte[sizeReseive], sizeReseive);
    }

    //запуск сеанса передачи файла по сети
    public void start() throws IOException {

        //ответ с другого конца соединения
        String request = "";
        byte[] data;
        do {
            datagramSocketReceiver.receive(packetReseive);
            request = new String(packetReseive.getData(), packetReseive.getOffset(), packetReseive.getLength());
            System.out.println(request);
        } while (!request.equalsIgnoreCase("REQUEST"));

        System.out.println("Got a request to transfer the file " + pathFile + " by the network!");

        do {
            data = ("UDP" + pathFile).getBytes();
            packetSend = new DatagramPacket(data, 0, data.length, InetAddress.getLocalHost(), PORT_SENDER);
            datagramSocketSender.send(packetSend);
            datagramSocketReceiver.receive(packetReseive);
            request = new String(packetReseive.getData(), packetReseive.getOffset(), packetReseive.getLength());
        } while (!request.equalsIgnoreCase("GOTNAME"));

        System.out.println("Sent name of the file is successful!");

        int offset = 0;
        int length = 0;
        byte[] sendPart;

        do {
            do {
                length += sizeSend;
                if (length > buffer.length) {
                    length = buffer.length;
                }
                sendPart = getBytes(offset, length);
                packetSend = new DatagramPacket(sendPart, 0, sendPart.length, InetAddress.getLocalHost(), PORT_SENDER);
                datagramSocketSender.send(packetSend);
                offset = length;
            } while (offset < buffer.length);

            data = "END OF FILE".getBytes();
            packetSend = new DatagramPacket(data, 0, data.length, InetAddress.getLocalHost(), PORT_SENDER);
            datagramSocketSender.send(packetSend);
            datagramSocketReceiver.receive(packetReseive);
            request = new String(packetReseive.getData(), packetReseive.getOffset(), packetReseive.getLength());

        } while (!request.equalsIgnoreCase("GOTFILE"));

        System.out.println("Sent the file is successful!");

        do {
            packetSend = new DatagramPacket(md5, 0, md5.length, InetAddress.getLocalHost(), PORT_SENDER);
            datagramSocketSender.send(packetSend);
            datagramSocketReceiver.receive(packetReseive);
            request = new String(packetReseive.getData(), packetReseive.getOffset(), packetReseive.getLength());
        } while (!request.equalsIgnoreCase("OK"));

        System.out.println("Sent the md5 is successful!");

        do {
            datagramSocketReceiver.receive(packetReseive);
            request = new String(packetReseive.getData(), packetReseive.getOffset(), packetReseive.getLength());
        } while (!request.equalsIgnoreCase("OK"));

        System.out.println("Sent is successful! Good buy!");
    }

    //метод загрузки файла в строку
    private synchronized void LoadFile() throws NoSuchAlgorithmException, IOException {
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

    public static void main(String[] args) {
        try {
            UDPSender client = new UDPSender();
            client.LoadFile();
            while (!client.fileLoaded) {
                client.wait();
            }
            client.start();
        } catch (NoSuchAlgorithmException | IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}