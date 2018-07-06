package application;

import java.sql.SQLException;
import java.util.List;
import java.util.Scanner;

public class UserInterface {
    private AcademyServer server;
    Scanner scanner = new Scanner(System.in);
    Commands[] commands;

    public UserInterface(AcademyServer server) {
        this.server = server;
        commands = new Commands[ItemsMenu.values().length];
        commands[ItemsMenu.SHOWALLSTUDENTS.numberItem] = new Commands() {
            @Override
            public void callBackFunction() {
                try {
                    showAllStudents();
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
        };

        commands[ItemsMenu.SHOWALLGROUPS.numberItem] = new Commands() {
            @Override
            public void callBackFunction() {
                try {
                    showAllGroup();
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
        };

        commands[ItemsMenu.ADDSTUDENT.numberItem] = new Commands() {
            @Override
            public void callBackFunction() {
                try {
                    addStudents();
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
        };

        commands[ItemsMenu.EXIT.numberItem] = new Commands() {
            @Override
            public void callBackFunction() {
                try {
                    exit();
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
        };
    }

    public void showAllGroup() throws SQLException {
        List<Group> groups = server.getGroups();
        for (Group group : groups) {
            System.out.println(group);
        }
    }

    public void showAllStudents() throws SQLException {
        List<Student> students = server.getStudents();
        for (Student student : students) {
            System.out.println(student);
        }
    }

    public String getString(String msg) {
        System.out.print(msg);
        return scanner.nextLine();
    }

    public int getNumber(String msg) {
        System.out.print(msg);
        while (!scanner.hasNextInt()) {
            System.out.print(msg);
            scanner.nextLine();
        }
        int number = scanner.nextInt();
        scanner.nextLine();
        return number;
    }

    public void addStudents() throws SQLException {
        String name = getString("Please, enter name: ");
        String lastName = getString("Please, enter last name: ");
        int age;
        int minAge = 6;
        do {
            age = getNumber("Please, enter age:");
        } while (age < minAge);
        showAllGroup();
        int group;
        do {
            group = getNumber("Please, enter id of group: ");
        } while (!server.isExistsGroup(group));
        server.insertStudent(name, lastName, age, group);
    }

    public void start() {
        int answer;
        do {
            for (ItemsMenu item : ItemsMenu.values()) {
                System.out.println(item.numberItem + " " + item.name);
            }

            do {
                answer = getNumber("Please, choose menu: ");
            } while (!ItemsMenu.isExistes(answer));
            commands[answer].callBackFunction();
            System.out.println("****************************************");
        } while (answer < ItemsMenu.EXIT.numberItem);
    }

    public void exit() throws SQLException {
        server.close();
    }
}
