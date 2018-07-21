package application.dao;


import application.DataBaseConfig;
import application.models.AuthorModel;
import application.models.ContryModel;
import application.models.GenreModel;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class AuthorDao implements Dao<AuthorModel> {
    @Override
    public List<AuthorModel> getAll() {
        Connection con = DataBaseConfig.getInstance().getConnection();
        List<AuthorModel> list = new ArrayList<>();
        String sql = "SELECT id FROM `author`";
        PreparedStatement stmt = null;
        try {
            stmt = con.prepareStatement(sql);
            ResultSet resultSet = stmt.executeQuery();
            while (resultSet.next()) {
                sql = "select a.id,a.name,a.lastname,g.id,g.name,c.id,c.name from author as a join genre as g join contry as c on a.genre_id=g.id and a.contry_id=c.id where a.id =?";
                stmt = con.prepareStatement(sql);
                stmt.setInt(1, resultSet.getInt(1));
                ResultSet result = stmt.executeQuery();
                if (result.next()) {
                    list.add(new AuthorModel(
                            result.getInt(1),
                            result.getString(2),
                            result.getString(3),
                            new GenreModel(result.getInt(4), result.getString(5)),
                            new ContryModel(result.getInt(6), result.getString(7))));
                }
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
    public boolean add(AuthorModel author) {
        Connection con = DataBaseConfig.getInstance().getConnection();
        String sql = "INSERT INTO `author` (`name`,`lastname`, `genre_id`, `contry_id`) VALUE(?,?,?,?)";
        PreparedStatement stmt = null;
        boolean done=false;
        try {
            stmt = con.prepareStatement(sql);
            stmt.setString(1, author.getName());
            stmt.setString(2, author.getLastname());
            stmt.setInt(3, author.getGenre().getId());
            stmt.setInt(4, author.getContry().getId());
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
    public boolean update(AuthorModel author) {
        Connection con = DataBaseConfig.getInstance().getConnection();
        String sql = "UPDATE `author` set `name`=?, `lastname`=?, `genre_id`=?, `contry_id`=? where `id`=?";
        PreparedStatement stmt = null;
        boolean done = false;
        try {
            stmt = con.prepareStatement(sql);
            stmt.setString(1, author.getName());
            stmt.setString(2, author.getLastname());
            stmt.setInt(3, author.getGenre().getId());
            stmt.setInt(4, author.getContry().getId());
            stmt.setInt(5,author.getId());
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
    public boolean removeById(int id) {
        Connection con = DataBaseConfig.getInstance().getConnection();
        String sql = "DELETE  FROM `author` where `id`=?";
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
    public AuthorModel getById(int id) {
        Connection con = DataBaseConfig.getInstance().getConnection();
        AuthorModel author = null;
        String sql = "select a.id,a.name,a.lastname,g.id,g.name,c.id,c.name from author as a join genre as g join contry as c on a.genre_id=g.id and a.contry_id=c.id where a.id =?";

        PreparedStatement stmt = null;
        try {
            stmt = con.prepareStatement(sql);
            stmt.setInt(1, id);
            ResultSet result = stmt.executeQuery();
            if (result.next()) {
                author = new AuthorModel(
                        result.getInt(1),
                        result.getString(2),
                        result.getString(3),
                        new GenreModel(result.getInt(4), result.getString(5)),
                        new ContryModel(result.getInt(6), result.getString(7)));
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
        return author;
    }
}
