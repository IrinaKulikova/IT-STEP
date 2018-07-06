package application;

public class Student {

    public int getId() {
        return id;
    }

    private int id;

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public int getAge() {
        return age;
    }

    public int getGroup() {
        return group;
    }

    private String firstName;
    private String lastName;
    private int age;
    private int group;

    public Student(int id, String firstName, String lastName, int age, int group) {
        this.id = id;
        this.firstName = firstName;
        this.lastName = lastName;
        this.age = age;
        this.group = group;
    }

    @Override
    public String toString() {
        return firstName + ", " + lastName + ", " + age + ", " + group;
    }
}
