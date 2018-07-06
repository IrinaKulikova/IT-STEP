package application;

public class Group {
    private int id;

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    private String name;

    public Group(int id, String name) {
        this.id = id;
        this.name = name;
    }

    @Override
    public String toString() {
        return id + ", " + name;
    }
}
