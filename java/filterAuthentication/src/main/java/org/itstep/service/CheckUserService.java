package org.itstep.service;

import org.itstep.dao.UserDao;
import org.itstep.model.User;

import java.util.List;

public class CheckUserService {
    private UserDao userDao;

    public UserDao getUserDao() {
        return userDao;
    }

    public void setUserDao(UserDao userDao) {
        this.userDao = userDao;
    }

    public boolean checkUser(String login, String password) {
        List<User> users = userDao.findAll();
        boolean exists = false;
        for (User user : users) {
            if (login.equals(user.getLogin()) && password.equals(user.getPassword())) {
                exists = true;
                break;
            }
        }
        return exists;
        //return users.stream().anyMatch(u -> login.equals(u.getLogin()) && password.equals(u.getPassword()));
    }
}
