package org.itstep.dao;

import org.itstep.model.User;

import java.util.ArrayList;
import java.util.List;

public class UserDaoTestImpl implements UserDao {
    private static List<User> users = new ArrayList<>();

    @Override
    public void save(User user) {
        users.add(user);
    }

    @Override
    public User find(int id) {
        User user = null;
        for(User u: users) {
            if(u.getId() == id) {
                user = u;
                break;
            }
        }
        return user;
//        return users.stream()
//                    .filter(u -> u.getId() == id)
//                    .findFirst().orElse(null);
    }

    @Override
    public List<User> findAll() {
        return users;
    }

    @Override
    public void delete(int id) {
        User user = find(id);
        if(user != null) {
            users.remove(user);
        }
    }

    @Override
    public void update(User user) {
        User oldUser = find(user.getId());
        if(oldUser != null) {
            oldUser.setLogin(user.getLogin());
            oldUser.setPassword(user.getPassword());
        }
    }
}
