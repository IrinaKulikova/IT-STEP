package org.itstep.util;

import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;

public class AuthorizationUtils {
    public static Cookie getAuthorizationCookie(HttpServletRequest req) {
        Cookie authorizationCookie = null;
        Cookie[] cookies = req.getCookies();
        if(cookies != null) {
            for (Cookie c : cookies) {
                if (c.getName().equals("user")) {
                    authorizationCookie = c;
                    break;
                }
            }
        }
        return authorizationCookie;
    }
}
