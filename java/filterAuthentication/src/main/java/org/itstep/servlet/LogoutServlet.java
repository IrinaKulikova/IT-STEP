package org.itstep.servlet;

import org.itstep.util.AuthorizationUtils;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/logout")
public class LogoutServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        Cookie authorizationCookie = AuthorizationUtils.getAuthorizationCookie(req);
        authorizationCookie.setMaxAge(0);
        resp.addCookie(authorizationCookie);
        resp.sendRedirect("/login");
    }
}
