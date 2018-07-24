package org.itstep.servlet;

import org.itstep.dao.UserDao;
import org.itstep.dao.UserDaoFactory;
import org.itstep.model.User;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/registration")
public class RegistrationServlet extends HttpServlet {
    UserDao userDao;
    @Override
    public void init() throws ServletException {
        userDao = UserDaoFactory.getUserDao();
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.getRequestDispatcher("/WEB-INF/view/registration.jsp")
                .forward(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // получить логин и пароль, добавить пользователя в dao
        String login = req.getParameter("login");
        String password = req.getParameter("password");
        userDao.save(new User(login, password));

        // перенаправить на /login
        resp.sendRedirect("/login");
    }
}
