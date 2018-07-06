package application;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.List;

class Closer {
    private List<Thread> threads = new ArrayList<>();

    void addThread(Thread thread) {
        threads.add(thread);
    }

    void close() throws IOException {

        for (Thread thread : threads) {
            if (thread != null) {
                if (thread.isAlive())
                    thread.interrupt();
            }
        }
    }
}