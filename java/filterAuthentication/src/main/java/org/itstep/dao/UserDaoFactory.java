package org.itstep.dao;

public class UserDaoFactory {

    private static UserDao userDao;

    public void setUserDao(UserDao userDao) {
        this.userDao = userDao;
    }

    public static UserDao getUserDao() {
        return userDao;
    }
}
