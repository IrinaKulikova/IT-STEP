package application.servlets;

import application.dao.AlbumDao;
import application.dao.ConrtyDao;
import application.dao.AuthorDao;
import application.dao.GenreDao;
import application.models.AuthorModel;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;

@WebServlet("/author.jsp")
public class AuthorServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        AuthorModel author = new AuthorDao().getById(Integer.parseInt(req.getParameter("id")));
        req.setAttribute("author", author);
        req.setAttribute("albums", new AlbumDao().getByAythorId(author.getId()));
        req.getRequestDispatcher("/WEB-INF/views/author.jsp").forward(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String body = "";
        BufferedReader reader = req.getReader();
        String line = "";
        while ((line = reader.readLine()) != null) {
            body += line;
        }
        System.out.println(body);
        int id = -1;
        try {
            id = Integer.parseInt(body);
        } catch (ClassCastException e) {
            e.printStackTrace();
        }
        new AlbumDao().removeById(id);
    }
}