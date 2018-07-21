package application.servlets;

import application.dao.AuthorDao;
import application.dao.ConrtyDao;
import application.dao.GenreDao;
import application.models.AuthorModel;
import org.json.JSONObject;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;

@WebServlet("/editauthor.jsp")
public class EditAuthorServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        int id = -1;
        AuthorModel author = null;
        try {
            String data = req.getParameter("id");
            if (data != null) {
                id = Integer.parseInt(data);
                if (id > 0) {
                    author = new AuthorDao().getById(id);
                }
            } else {
                author = new AuthorModel(0, "", "", new GenreDao().getById(1), new ConrtyDao().getById(1));
            }
        } catch (Exception ex) {
            resp.sendRedirect("/");
            return;
        }
        req.setAttribute("author", author);
        req.setAttribute("genres", new GenreDao().getAll());
        req.setAttribute("contries", new ConrtyDao().getAll());
        req.getRequestDispatcher("/WEB-INF/views/editauthor.jsp").forward(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setContentType("application/json; charset=utf-8;");
        String body = "";
        BufferedReader reader = req.getReader();
        String line = "";
        while ((line = reader.readLine()) != null) {
            body += line;
        }
        System.out.println(body);
        JSONObject author = new JSONObject(body);
        if (author.getInt("id") > 0) {
            new AuthorDao().update(new AuthorModel(author.getInt("id"), author.getString("name"),
                    author.getString("lastname"), new GenreDao().getById(author.getInt("genre_id")),
                    new ConrtyDao().getById(author.getInt("contry_id"))));
        } else {
            new AuthorDao().add(new AuthorModel(-1, author.getString("name"), author.getString("lastname"),
                    new GenreDao().getById(author.getInt("genre_id")),
                    new ConrtyDao().getById(author.getInt("contry_id"))));
            resp.sendRedirect("/");
        }
    }
}