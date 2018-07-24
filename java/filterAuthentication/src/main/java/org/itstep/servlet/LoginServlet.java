package org.itstep.servlet;

import org.itstep.dao.UserDao;
import org.itstep.dao.UserDaoFactory;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/login")
public class LoginServlet extends HttpServlet {
    UserDao userDao;
    @Override
    public void init() throws ServletException {
        userDao = UserDaoFactory.getUserDao();
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.getRequestDispatcher("/WEB-INF/view/login.jsp")
                .forward(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // получить логин и пароль преданные в запросе
        String login = req.getParameter("login");
        String password = req.getParameter("password");

        // установить cookie setAuthenticationCookie()
        setAuthenticationCookie(resp, login, password);

        // перенаправление на /
        resp.sendRedirect("/");
    }

    private void setAuthenticationCookie(HttpServletResponse resp, String login, String password) {
        resp.addCookie(new Cookie("user", login + ":" + password));
    }
}
