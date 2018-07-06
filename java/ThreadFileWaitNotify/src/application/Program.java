package application;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;

/**
 * Напишите класс, реализующий интерфейс Runnable, метод run() которого считывает из файла на жестком диске и выводит в
 * указанный поток какие-либо данные (например, файла alice.txt).
 * Считываются данные "порциями" по 32 байт (размер можно задать в конструкторе класса).
 * Для вывода каждой "порции" данных должно использоваться несколько операций вывода.
 * Операции вывода должны быть разделены вызовами sleep(100).
 * Запустите 10 экземпляров этого класса в разных потоках так, чтобы они выводили данные в один и тот же поток вывода.
 * Вывод информации должен быть синхронизирован так, чтобы в результирующем выходном потоке порции данных не "перемешивались".
 * Осуществите запись данных из общего потока в отдельный файл на жестком диске.
 */

public class Program {
    public static void main(String[] args) {
        int len = 32;
        int countThreads = 10;
        Thread[] arr = new Thread[countThreads];

        final MonitorFile monitor = new MonitorFile();

        String fileName = "alice.txt";
        String newFileName = "new.txt";
        if (Files.exists(Paths.get(newFileName))) {
            new File(newFileName).delete();
        }

        try (InputStream in = new FileInputStream(fileName);
             FileOutputStream out = new FileOutputStream(newFileName, true)) {
            for (int i = 0; i < countThreads; i++) {
                arr[i] = new Thread(new CopyFileThreads(len, in, out, monitor));
                arr[i].start();
            }
            synchronized (monitor) {
                if (monitor.isWorked()) {
                    try {
                        monitor.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}