package application.dao;

import application.DataBaseConfig;
import application.models.AlbumModel;
import application.models.AuthorModel;
import application.models.ContryModel;
import application.models.GenreModel;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class AlbumDao implements Dao<AlbumModel> {
    @Override
    public List<AlbumModel> getAll() {
        Connection con = DataBaseConfig.getInstance().getConnection();
        List<AlbumModel> list = new ArrayList<>();
        String sql = "SELECT * FROM `album`";
        PreparedStatement stmt = null;
        try {
            stmt = con.prepareStatement(sql);
            ResultSet resultSet = stmt.executeQuery();
            while (resultSet.next()) {
                sql = "SELECT a.id, a.name, a.lastname, g.id,g.name,c.id,c.name FROM `author` as a join `genre` as g join `contry` as c on a.contry_id=c.id and a.genre_id=g.id  where a.id=?";
                stmt = con.prepareStatement(sql);
                stmt.setInt(1, resultSet.getInt(1));
                ResultSet result = stmt.executeQuery();
                if (result.next()) {
                    list.add(new AlbumModel(resultSet.getInt(1),
                            new AuthorModel(result.getInt(1), result.getString(2), result.getString(3),
                                    new GenreModel(result.getInt(4), result.getString(5)),
                                    new ContryModel(result.getInt(6), result.getString(7))),
                            resultSet.getString(3),
                            resultSet.getInt(4)));
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
    public boolean add(AlbumModel album) {
        Connection con = DataBaseConfig.getInstance().getConnection();
        String sql = "INSERT INTO `album` (`author_id`, `name`, `tracks`) VALUE(?,?,?)";
        PreparedStatement stmt = null;
        boolean done = false;
        try {
            stmt = con.prepareStatement(sql);
            stmt.setInt(1, album.getAuthor().getId());
            stmt.setString(2, album.getName());
            stmt.setInt(3, album.getTracks());
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
    public boolean update(AlbumModel album) {
        Connection con = DataBaseConfig.getInstance().getConnection();
        String sql = "UPDATE `album` set `author_id`=?, `name`=?, `tracks`=? where `id`=?";
        PreparedStatement stmt = null;
        boolean done = false;
        try {
            stmt = con.prepareStatement(sql);
            stmt.setInt(1, album.getAuthor().getId());
            stmt.setString(2, album.getName());
            stmt.setInt(3, album.getTracks());
            stmt.setInt(4,album.getId());
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
        String sql = "DELETE  FROM `album` where `id`=?";
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
    public AlbumModel getById(int id) {
        Connection con = DataBaseConfig.getInstance().getConnection();
        AlbumModel album = null;
        String sql = "SELECT a.id,a.name,a.tracks,au.id,au.name,au.lastname,g.id,g.name,c.id,c.name" +
                " FROM `album` as a " +
                "join `author` as au  " +
                "join genre as g " +
                "join contry as c " +
                "on a.author_id=au.id " +
                "and au.genre_id=g.id " +
                "and au.contry_id=c.id " +
                "where a.id=?";
        PreparedStatement stmt = null;
        try {
            stmt = con.prepareStatement(sql);
            stmt.setInt(1, id);
            ResultSet resultSet = stmt.executeQuery();
            if (resultSet.next()) {
                album = new AlbumModel(resultSet.getInt(1),
                        new AuthorModel(resultSet.getInt(4), resultSet.getString(5), resultSet.getString(6),
                                new GenreModel(resultSet.getInt(7), resultSet.getString(8)),
                                new ContryModel(resultSet.getInt(9), resultSet.getString(10))),
                        resultSet.getString(2),
                        resultSet.getInt(3));
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
        return album;
    }

    public List<AlbumModel> getByAythorId(int author_id) {
        Connection con = DataBaseConfig.getInstance().getConnection();
        List<AlbumModel> list = new ArrayList<>();
        String sql = "SELECT a.id, a.name, a.tracks, au.id, au.name, au.lastname , g.id, g.name, c.id, c.name" +
                " FROM `album` as a" +
                " join genre as g " +
                " join author as au " +
                " join contry as c " +
                " on au.genre_id=g.id and " +
                " c.id=au.contry_id and " +
                " a.author_id=au.id " +
                " where a.author_id=?";
        PreparedStatement stmt = null;
        try {
            stmt = con.prepareStatement(sql);
            stmt.setInt(1, author_id);
            ResultSet resultSet = stmt.executeQuery();
            while (resultSet.next()) {
                list.add(new AlbumModel(resultSet.getInt(1),
                        new AuthorModel(resultSet.getInt(4), resultSet.getString(5), resultSet.getString(6),
                                new GenreModel(resultSet.getInt(7), resultSet.getString(8)),
                                new ContryModel(resultSet.getInt(9), resultSet.getString(10))),
                        resultSet.getString(2),
                        resultSet.getInt(3)));
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
}
