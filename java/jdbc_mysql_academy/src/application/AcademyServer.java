package application;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class AcademyServer {

    private String userName;
    private String password;
    private Statement stmt;
    private Connection conn;

    AcademyServer(String userName, String password) {

        String connectionString = "jdbc:mysql://localhost:3306/javaacademy" +
                "?characterEncoding=UTF-8" +
                "&useUnicode=true" +
                "&useJDBCCompliantTimezoneShift=true" +
                "&useLegacyDatetimeCode=false" +
                "&serverTimezone=UTC";
        try {
            conn = DriverManager.getConnection(connectionString, userName, password);
            stmt = conn.createStatement();
            System.out.println("Connected!");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public boolean insertStudent(String name, String surname, int age, int groupId) throws SQLException {
        String sql = "INSERT INTO student( first_name , last_name , age, group_id)" +
                " VALUE ( '" + name + "' , '" + surname + "' , " + age + " , " + groupId + " )";
        int countChange = stmt.executeUpdate(sql);
        return countChange > 0;
    }

    public List<Student> getStudents() throws SQLException {
        ResultSet result = stmt.executeQuery("SELECT * FROM student");
        List<Student> students = new ArrayList<>();
        while (result.next()) {
            students.add(new Student(result.getInt(1), result.getString("first_name"),
                    result.getString("last_name"), result.getInt("age"), result.getInt("group_id")));
        }
        return students;
    }

    public List<Group> getGroups() throws SQLException {
        ResultSet result = stmt.executeQuery("SELECT * FROM `group`");
        List<Group> groups = new ArrayList<>();
        while (result.next()) {
            groups.add(new Group(result.getInt(1), result.getString("name")));
        }
        return groups;
    }

    public void close() throws SQLException {
        stmt.close();
        conn.close();
    }

    public boolean isExistsGroup(int id_group) {
        try {
            ResultSet res = stmt.executeQuery("SELECT * FROM `group` where id like " + id_group);
            return res.next();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return  false;
    }
}
