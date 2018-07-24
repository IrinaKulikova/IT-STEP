package org.itstep.dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class BaseConfig {

    private static BaseConfig dataBaseConfig;

    private BaseConfig() {
        userName = "root";
        password = "";
    }

    public static BaseConfig getInstance() {
        if (dataBaseConfig == null) {
            dataBaseConfig = new BaseConfig();
        }
        return dataBaseConfig;
    }

    private String userName;
    private String password;
    private Connection connection;

    public Connection getConnection() {
        String connectionString = "jdbc:mysql://localhost:3306/sitespringuser" +
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

}
