package application;

/**
 * класс монитор, хранит сдвиг считывания данных с файлe
 */
class MonitorFile {

    private boolean worked = true;
    private int mark;

    synchronized boolean isWorked() {
        return worked;
    }

    synchronized void done() {
        this.worked = false;
    }

    synchronized int getMark() {
        return mark;
    }

    synchronized void setMark(int mark) {
        this.mark = mark;
    }
}