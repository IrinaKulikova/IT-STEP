package org.itstep.filter;

import org.itstep.dao.UserDaoFactory;
import org.itstep.dao.UserDaoTestImpl;
import org.itstep.service.CheckUserService;
import org.itstep.util.AuthorizationUtils;

import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebFilter("*")
public class AuthorizationFilter implements Filter {

    CheckUserService checkUserService;

    @Override
    public void init(FilterConfig filterConfig) throws ServletException {
        checkUserService = new CheckUserService();
        checkUserService.setUserDao(UserDaoFactory.getUserDao());
    }

    @Override
    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
        HttpServletRequest req = (HttpServletRequest) request;
        HttpServletResponse resp = (HttpServletResponse) response;
        String requestUri = req.getRequestURI();

        String login = "";
        String password = "";
        Cookie authorizationCookie = AuthorizationUtils.getAuthorizationCookie(req);
        if(authorizationCookie != null) {
            String[] data = authorizationCookie.getValue().split(":");
            login = data[0];
            password = data[1];
        }

        if ((requestUri.equals("/login") || requestUri.equals("/registration")) ||
                checkUserService.checkUser(login, password)) {
            chain.doFilter(request, response);
        } else {
            resp.sendRedirect("/login");
        }
    }

    @Override
    public void destroy() {

    }
}
