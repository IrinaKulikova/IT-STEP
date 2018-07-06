package application;

public enum ItemsMenu {
    SHOWALLSTUDENTS("Show all students", 0),
    SHOWALLGROUPS("Show all groups", 1),
    ADDSTUDENT("Add student", 2),
    EXIT("Exit", 3);

    String name;
    int numberItem;

    ItemsMenu(String name, int number) {
        this.name = name;
        this.numberItem = number;
    }

    public static boolean isExistes(int number) {
        ItemsMenu[] items = values();
        for (ItemsMenu item : items) {
            if (item.getNumber() == number) {
                return true;
            }
        }
        return false;
    }

    public int getNumber() {
        return numberItem;
    }
}
