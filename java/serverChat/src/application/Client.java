package application;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.util.Scanner;

public class Client {

    private void startClient() {
        try (Socket socket = new Socket()) {
            socket.connect(new InetSocketAddress("127.0.0.1", 37017));
            Scanner scanner = new Scanner(socket.getInputStream());
            PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);
            Scanner iScanner = new Scanner(System.in);

            while (true) {
                System.out.print("enter the message: ");
                String msg = iScanner.nextLine();
                writer.println(msg);
                String response = scanner.nextLine();
                System.out.println(response);
                if (msg.equals("exit")) break;
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        Client client = new Client();
        client.startClient();
    }
}