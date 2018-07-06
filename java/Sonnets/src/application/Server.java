package application;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

/**
 * Реализовать клиент-серверное приложение для загрузки сонетов Шекспира.
 * Клиент при обращении к серверу получает случайно выбранный сонет Шекспира из файла.
 * Сонеты Шекспира можно скачать по адресу: http://lib.ru/SHAKESPEARE/sonets.txt
 * <p>
 * Дополнительное задание:
 * Реализовать многопоточный сервер
 */

public class Server {
    private Map<Integer, String> sonnets = new HashMap<>();
    private List<Socket> sockets = new LinkedList<>();
    private String file = "sonnets.txt";
    private boolean loaded = false;

    private Server() {
        try (InputStream in = new FileInputStream(file)) {
            List<String> lines = Files.readAllLines(Paths.get(file), StandardCharsets.UTF_8);
            StringBuilder sonnet = new StringBuilder();
            int counter = 0;
            for (int i = 0; i < lines.size(); i++) {
                if (lines.get(i).matches("\\d+") || lines.get(i).matches("x x x")) {
                    if (!sonnet.toString().equals("")) {
                        sonnets.put(counter++, sonnet.toString().trim());
                        sonnet = new StringBuilder();
                        //пропускаем пустые строки после номера соннета
                        for (int j = i; lines.get(j).length() == 0; j++) {
                            i++;
                        }
                    }
                } else {
                    sonnet.append(lines.get(i));
                    sonnet.append("\n");
                }
            }
            sonnets.remove(0);
            synchronized (this) {
                notify();
                loaded = true;
            }
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }

    synchronized private void startServer() throws InterruptedException, IOException {
        try (ServerSocket serverSocket = new ServerSocket(7017)) {
            System.out.println("Start server!");
            synchronized (this) {
                while (!loaded) {
                    wait();
                }
            }
            while (true) {
                Socket connectionSocket = serverSocket.accept();
                new Thread() {
                    @Override
                    public void run() {
                        System.out.println("Client connected");
                        try (PrintWriter writer = new PrintWriter(connectionSocket.getOutputStream(), true)) {
                            int index = new Random().nextInt(sonnets.size() - 1);
                            writer.println(sonnets.get(index + 1));
                            writer.flush();
                        } catch (IOException e) {
                            System.out.println(e.getMessage());
                        }
                    }
                }.start();
            }
        }
    }

    public static void main(String[] args) {
        Server server = new Server();
        try {
            server.startServer();
        } catch (IOException | InterruptedException e) {
            System.out.println(e.getMessage());
        }
    }
}