package application;

public class Info {
    private DownLoadThread loader;
    private SaveThread saver;

    Info(DownLoadThread loader, SaveThread saver) {
        this.loader = loader;
        this.saver = saver;
    }

    void currentStatus() {
        System.out.println("Address: " + loader.getPath());
        System.out.println("File: " + saver.getPath());
        System.out.println("Loaded bytes: " + loader.getContent().size());
        System.out.println("Saved bytes : " + saver.getSavedBytes());
        System.out.println("Complete:  " + saver.isSaved());
        System.out.println("------------------------\n");
    }
}
