package application;

public enum Items {
    NEW_LOAD(1, "New Load"), PROGRESS_LOADS(2, "Progress loads"), SETTINGS(3, "Settings"), EXIT(4, "Exit");
    private final int number;
    private final String name;

    private Items(int number, String name) {
        this.number = number;
        this.name = name;
    }

    public static Items getItemByIndex(int index) {
        Items[] items = values();
        for (Items item : items) {
            if (item.getNumber() == index) {
                return item;
            }
        }
        throw new IndexOutOfBoundsException("Index out of range");
    }

    public int getNumber() {
        return number;
    }

    public String geNameItem() {
        return name;
    }
}