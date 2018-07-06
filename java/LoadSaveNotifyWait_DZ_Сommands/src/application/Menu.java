package application;

import java.io.File;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Menu {

    private Items[] items;
    private Scanner scanner;
    private Closer closer;
    private MenuMethods[] callBacks;
    private Path root = Paths.get("./loaded/one");
    private List<Info> currentStatus;

    Menu() {
        int countItems = 4;
        items = new Items[countItems];
        for (int i = 0; i < countItems; i++) {
            items[i] = Items.getItemByIndex(i + 1);
        }
        scanner = new Scanner(System.in);
        closer = new Closer();
        callBacks = new MenuMethods[items.length];
        addCallBackFunctionsToItemsMenu();
        currentStatus = new ArrayList<>();

        //сразу запускаю тестовый поток
        String url = "http://ol3.mp3party.net/online/3791/3791001.mp3";
        String demonThreadLoadLongFile = "basta.mp3";
        StartLoad(url, demonThreadLoadLongFile);
    }

    private void StartLoad(String url, String filename) {
        Path f = Paths.get(root.toString(), filename);
        final Object monitor = new Object();
        DownLoadThread loader = new DownLoadThread(url, monitor);
        SaveThread saver = new SaveThread(monitor, loader, f.normalize().toString());
        Info info = new Info(loader, saver);
        loader.start();
        saver.start();
        currentStatus.add(info);
        closer.addThread(loader);
        closer.addThread(saver);
    }

    private void addCallBackFunctionsToItemsMenu() {
        callBacks[0] = new MenuMethods() {
            @Override
            public void callBackFunction() {
                System.out.print("Enter URL: ");
                String url = scanner.nextLine();
                System.out.print("Enter file name: ");
                String fileName = scanner.nextLine();
                StartLoad(url, fileName);
            }
        };

        callBacks[1] = new MenuMethods() {
            @Override
            public void callBackFunction() {

                System.out.println("\nProgress loads: ");
                for (int i = 0; i < currentStatus.size(); i++) {
                    currentStatus.get(i).currentStatus();
                }
            }
        };

        callBacks[2] = new MenuMethods() {
            @Override
            public void callBackFunction() {
                File rootDir = new File(".//loaded");
                File[] innerFiles = rootDir.listFiles();
                if (innerFiles == null) {
                    System.out.println("\nNo inner directories!\n");
                    return;
                }
                int answer;
                System.out.println("\nChoose directory for saving files: \n");
                do {
                    for (int i = 0; i < innerFiles.length; i++) {
                        if (!innerFiles[i].isFile()) {
                            System.out.println("\t" + i + " " + innerFiles[i].getName());
                        }
                    }
                    System.out.print(" Enter index of directory: ");
                    while (!scanner.hasNextInt()) {
                        System.out.print(" Enter index of directory: ");
                        scanner.next();
                    }
                    answer = scanner.nextInt();
                    scanner.nextLine();
                } while (answer < 0 || answer > innerFiles.length - 1);
                root = Paths.get(rootDir.getName(), innerFiles[answer].getName());
                System.out.println("Current directory: " + root + "\n");
            }
        };

        callBacks[3] = new MenuMethods() {
            @Override
            public void callBackFunction() {
                try {
                    closer.close();
                    System.exit(0);
                } catch (IOException e) {
                    System.out.println(e.getMessage());
                }
            }
        };
    }

    void start() {

        int answer;
        do {
            System.out.println("Menu: ");
            for (Items anItem : items) {
                System.out.println(anItem.getNumber() + " " + anItem.geNameItem());
            }
            System.out.print("Your choose: ");
            while (!scanner.hasNextInt()) {
                System.out.print("Your choose: ");
                scanner.next();
            }
            answer = scanner.nextInt();
            scanner.nextLine();
        } while (answer < items[0].getNumber() || answer > items[items.length - 1].getNumber());
        callBacks[answer - 1].callBackFunction();
        start();
    }
}