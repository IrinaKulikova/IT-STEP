package application;

import java.io.*;

public class SaveThread extends Thread {

    private DownLoadThread loader;
    private String path;
    private boolean saved;
    private Object monitor;
    private int savedBytes;

    public String getPath() {
        return path;
    }

    public boolean isSaved() {
        return saved;
    }

    public int getSavedBytes() {
        return savedBytes;
    }

    public void setSavedBytes(int savedBytes) {
        this.savedBytes = savedBytes;
    }

    private synchronized void waitAndSave() throws InterruptedException, IOException {
        synchronized (monitor) {
            while (!loader.isLoaded()) {
                monitor.wait();
            }

            try (OutputStream out = new FileOutputStream(path)) {
                for (int i = 0; i < loader.getContent().size(); i++) {
                    byte[] bytes = new byte[1];
                    bytes[0] = loader.getContent().get(i);
                    out.write(bytes, 0, 1);
                    setSavedBytes(getSavedBytes() + 1);
                    monitor.notifyAll();
                }
                saved = true;
                monitor.notifyAll();
            }
        }
    }


    @Override
    public void run() {
        try {
            waitAndSave();
        } catch (InterruptedException | IOException e) {
            System.out.println(e.getMessage());
        }
    }

    public SaveThread(Object monitor, DownLoadThread loader, String path) {
        this.loader = loader;
        this.path = path;
        this.monitor = monitor;
    }
}
