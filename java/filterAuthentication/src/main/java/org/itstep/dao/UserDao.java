package org.itstep.dao;

import org.itstep.model.User;

import java.util.List;

public interface UserDao {

    void save(User user);
    User find(int id);
    List<User> findAll();
    void delete(int id);
    void update(User user);

}
