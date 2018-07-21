package application.dao;

import java.sql.SQLException;
import java.util.List;

public interface Dao<T> {
    List<T> getAll() throws SQLException;

    boolean add(T obj) throws SQLException;

    boolean update(T obj) throws SQLException;

    boolean removeById(int id) throws SQLException;

    T getById(int id);
}
