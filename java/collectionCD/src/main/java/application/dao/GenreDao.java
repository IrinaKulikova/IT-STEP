package application.dao;

import application.dao.Dao;
import application.DataBaseConfig;
import application.models.AuthorModel;
import application.models.ContryModel;
import application.models.GenreModel;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class GenreDao implements Dao<GenreModel> {
    @Override
    public List<GenreModel> getAll() {
        Connection con = DataBaseConfig.getInstance().getConnection();
        List<GenreModel> list = new ArrayList<>();
        String sql = "SELECT * FROM `genre`";
        Statement stmt = null;
        try {
            stmt = con.createStatement();
            ResultSet resultSet = stmt.executeQuery(sql);
            while (resultSet.next()) {
                list.add(new GenreModel(resultSet.getInt(1), resultSet.getString(2)));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        if (con != null) {
            try {
                con.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return list;
    }

    @Override
    public boolean add(GenreModel genre) {
        Connection con = DataBaseConfig.getInstance().getConnection();
        String sql = "INSERT INTO `genre` (`name`) VALUE(?)";
        PreparedStatement stmt = null;
        boolean done = doUpdateOrAdd(genre, con, sql);
        if (con != null) {
            try {
                con.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return done;
    }

    private boolean doUpdateOrAdd(GenreModel obj, Connection con, String sql) {
        PreparedStatement stmt;
        boolean done = false;
        try {
            stmt = con.prepareStatement(sql);
            stmt.setString(1, obj.getName());
            done = stmt.executeUpdate() > 0;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        if (con != null) {
            try {
                con.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return done;
    }

    @Override
    public boolean update(GenreModel genre) {
        Connection con = DataBaseConfig.getInstance().getConnection();
        String sql = "UPDATE `genre` set `name`=? where `id`=?";
        PreparedStatement stmt = null;
        boolean done = false;
        done = doUpdateOrAdd(genre, con, sql);
        if (con != null) {
            try {
                con.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return done;
    }

    @Override
    public boolean removeById(int id) {
        Connection con = DataBaseConfig.getInstance().getConnection();
        String sql = "DELETE  FROM `genre` where `id`=?";
        PreparedStatement stmt = null;
        boolean done = false;
        try {
            stmt = con.prepareStatement(sql);
            stmt.setInt(1, id);
            done = stmt.executeUpdate() > 0;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        if (con != null) {
            try {
                con.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return done;
    }

    @Override
    public GenreModel getById(int id) {
        Connection con = DataBaseConfig.getInstance().getConnection();
        GenreModel genre = null;
        String sql = "SELECT * FROM `genre` where id=?";
        PreparedStatement stmt = null;
        try {
            stmt = con.prepareStatement(sql);
            stmt.setInt(1, id);
            ResultSet resultSet = stmt.executeQuery();
            if (resultSet.next()) {
                genre = new GenreModel(resultSet.getInt(1), resultSet.getString(2));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        if (con != null) {
            try {
                con.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return genre;
    }
}
