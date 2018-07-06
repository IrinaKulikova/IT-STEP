package application;

import java.io.*;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;

public class DownLoadThread extends Thread {

    private boolean loaded;
    private List<Byte> data;
    private Object monitor;
    private String path;

    public List<Byte> getContent() {
        return data;
    }

    public boolean isLoaded() {
        return loaded;
    }

    public String getPath() {
        return path;
    }

    public DownLoadThread(String path, Object monitor) {
        this.path = path;
        this.monitor = monitor;
        data = new ArrayList<>();
    }

    @Override
    public void run() {
        try {
            downLoad();
        } catch (MalformedURLException e) {
            System.out.println(e.getMessage());
        }
    }

    synchronized void downLoad() throws MalformedURLException {
        URL url = new URL(path);
        try (InputStream in = url.openStream()) {
            int buff;
            while ((buff = in.read()) != -1) {
                synchronized (monitor) {
                    data.add((byte) buff);
                    monitor.notifyAll();
                }
            }
            synchronized (monitor) {
                monitor.notifyAll();
                loaded = true;
            }
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}