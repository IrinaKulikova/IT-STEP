package application.dao;

import application.DataBaseConfig;
import application.models.ContryModel;
import application.models.GenreModel;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class ConrtyDao implements Dao<ContryModel> {
    @Override
    public List<ContryModel> getAll() {
        Connection con = DataBaseConfig.getInstance().getConnection();
        List<ContryModel> list = new ArrayList<>();
        String sql = "SELECT * FROM `contry`";
        Statement stmt = null;
        try {
            stmt = con.createStatement();
            ResultSet resultSet = stmt.executeQuery(sql);
            while (resultSet.next()) {
                list.add(new ContryModel(resultSet.getInt(1), resultSet.getString(2)));
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
    public boolean add(ContryModel contry) {
        Connection con = DataBaseConfig.getInstance().getConnection();
        String sql = "INSERT INTO `contry` (`name`) VALUE(?)";
        PreparedStatement stmt = null;
        boolean done = doUpdateOrAdd(contry, con, sql);
        if (con != null) {
            try {
                con.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return done;
    }

    private boolean doUpdateOrAdd(ContryModel obj, Connection con, String sql) {
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
    public boolean update(ContryModel contry) {
        Connection con = DataBaseConfig.getInstance().getConnection();
        String sql = "UPDATE `contry` set `name`=? where `id`=?";
        PreparedStatement stmt = null;
        boolean done = false;
        done = doUpdateOrAdd(contry, con, sql);
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
        String sql = "DELETE  FROM `contry` where `id`=?";
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
    public ContryModel getById(int id) {
        Connection con = DataBaseConfig.getInstance().getConnection();
        ContryModel contry = null;
        String sql = "SELECT * FROM `contry` where id=?";
        PreparedStatement stmt = null;
        try {
            stmt = con.prepareStatement(sql);
            stmt.setInt(1, id);
            ResultSet resultSet = stmt.executeQuery();
            if (resultSet.next()) {
                contry = new ContryModel(resultSet.getInt(1), resultSet.getString(2));
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
        return contry;
    }
}
