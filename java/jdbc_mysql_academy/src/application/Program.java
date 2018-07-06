package application;

import java.sql.*;

public class Program {
    public static void main(String[] args) {
        new UserInterface(new AcademyServer("root", "")).start();
    }
}
