package org.itstep.dao;

import org.itstep.model.User;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class UserDaoMysqlImpl implements UserDao {
    @Override
    public void save(User user) {
        Connection connection = BaseConfig.getInstance().getConnection();
        try {
            PreparedStatement statement = connection.prepareStatement("INSERT INTO `user`(`login`,`password`) values (?,?)");
            statement.setString(1, user.getLogin());
            statement.setString(2, user.getPassword());
            System.out.println(statement.executeUpdate());
        } catch (SQLException e) {
            e.printStackTrace();
        }
        if (connection != null) {
            try {
                connection.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        // реализовать сохранение пользователя в б/д
    }

    @Override
    public User find(int id) {
        // реализовать поиск пользователя в б/д
        User user = null;
        Connection connection = BaseConfig.getInstance().getConnection();
        try {
            PreparedStatement statement = connection.prepareStatement("SELECT * FROM `user` WHERE id=?");
            statement.setInt(1, id);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                user = new User(resultSet.getInt(1), resultSet.getString(2), resultSet.getString(3));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        if (connection != null) {
            try {
                connection.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return user;
    }

    @Override
    public List<User> findAll() {
        // реализовать поиск всех пользователей в б/д
        List<User> users = new ArrayList<>();
        Connection connection = BaseConfig.getInstance().getConnection();
        try {
            PreparedStatement statement = connection.prepareStatement("SELECT * FROM `user`");
            ResultSet resultSet = statement.executeQuery();
            while (resultSet.next()) {
                users.add(new User(resultSet.getInt(1), resultSet.getString(3), resultSet.getString(2)));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        if (connection != null) {
            try {
                connection.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return users;
    }

    @Override
    public void delete(int id) {
        Connection connection = BaseConfig.getInstance().getConnection();
        try {
            PreparedStatement statement = connection.prepareStatement("DELETE FROM `user` WHERE  id =?");
            statement.setInt(1, id);
            System.out.println(statement.executeUpdate());
        } catch (SQLException e) {
            e.printStackTrace();
        }
        if (connection != null) {
            try {
                connection.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        // реализовать удаление пользователя по id в б/д
    }

    @Override
    public void update(User user) {
        Connection connection = BaseConfig.getInstance().getConnection();
        try {
            PreparedStatement statement = connection.prepareStatement("UPDATE FROM `user` set `login`=?, `password`=? WHERE  id =?");
            statement.setString(1, user.getLogin());
            statement.setString(2, user.getPassword());
            statement.setInt(3, user.getId());
            System.out.println(statement.executeUpdate());
        } catch (SQLException e) {
            e.printStackTrace();
        }
        if (connection != null) {
            try {
                connection.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        // реализовать обновление пользователя в б/д
    }
}
