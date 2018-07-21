package application;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

//синглетон
public class DataBaseConfig {

    private static DataBaseConfig dataBaseConfig;

    private DataBaseConfig() {
        userName = "root";
        password = "";
    }

    public static DataBaseConfig getInstance() {
        if (dataBaseConfig == null) {
            dataBaseConfig = new DataBaseConfig();
        }
        return dataBaseConfig;
    }

    private String userName;
    private String password;
    private Connection connection;

    public Connection getConnection() {
        String connectionString = "jdbc:mysql://localhost:3306/collectioncd" +
                "?characterEncoding=UTF-8" +
                "&useUnicode=true" +
                "&useJDBCCompliantTimezoneShift=true" +
                "&useLegacyDatetimeCode=false" +
                "&serverTimezone=UTC";
        try {
            connection = DriverManager.getConnection(connectionString, userName, password);
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return connection;
    }

    public void close() throws SQLException {
        if (connection != null) {
            connection.close();
        }
    }
}