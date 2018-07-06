package application;

import java.io.*;

public class CopyFileThreads implements Runnable {
    private int sizeBuffer;
    private InputStream in;
    private OutputStream out;
    private final MonitorFile monitor;

    CopyFileThreads(int sizeBuffer, InputStream in, FileOutputStream out,
                    MonitorFile monitor) {
        this.sizeBuffer = sizeBuffer;
        this.in = in;
        this.out = out;
        this.monitor = monitor;
    }

    @Override
    public void run() {
        ReadAndWrite();
    }

    synchronized private void ReadAndWrite() {
        while (monitor.isWorked()) {
            synchronized (monitor) {
                try {
                    byte[] buffer = new byte[sizeBuffer];
                    in.skip(monitor.getMark());
                    int len = in.read(buffer, 0, sizeBuffer);
                    int mark = monitor.getMark();
                    monitor.setMark(mark);
                    out.write(buffer);
                    if (len <= 0) {
                        monitor.done();
                        monitor.notifyAll();
                    }
                } catch (IOException e) {
                    System.out.println(e.getMessage());
                }
                System.out.println(Thread.currentThread().getName());
            }
            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
    }
}