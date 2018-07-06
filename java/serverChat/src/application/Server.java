package application;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

/**
 * Многопоточный чат с ограниченным колличеством потоков - 4 штуки!
 */

public class Server {
    private final Object monitor = new Object();
    private List<Connection> list = new LinkedList<>();

    synchronized private int getCount() {
        return list.size();
    }

    synchronized private void removeThread(Connection thread) {
        list.remove(thread);
        notifyAll();
    }

    class Connection implements Runnable {
        Socket socket;

        Connection(Socket socket) {
            this.socket = socket;
        }

        @Override
        public void run() {
            try {
                System.out.println("Client connected");
                PrintWriter writer = new PrintWriter(socket.getOutputStream());
                Scanner scanner = new Scanner(socket.getInputStream());
                while (scanner.hasNextLine()) {
                    String str = scanner.nextLine();
                    if (str.equals("exit")) {
                        writer.println("Bye-bye");
                        writer.flush();
                        removeThread(this);
                        break;
                    }
                    writer.println("You sent me this message: " + str);
                    writer.flush();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    private void startServer() throws InterruptedException {
        try (ServerSocket serverSocket = new ServerSocket(37017)) {
            while (true) {
                System.out.println("Start server!");
                Socket connectionSocket = serverSocket.accept();
                Connection connection = new Connection(connectionSocket);
                synchronized (this) {
                    int maxThreads = 4;
                    while (getCount() >= maxThreads) {
                        System.out.println(getCount());
                        System.out.println("Wait");
                        wait();
                    }
                    Thread thread = new Thread(connection);
                    list.add(connection);
                    thread.start();
                    System.out.println("Connect " + getCount());
                }
            }
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }

    public static void main(String[] args) {
        Server server = new Server();
        try {
            server.startServer();
        } catch (InterruptedException e) {
            System.out.println(e.getMessage());
        }
    }
}