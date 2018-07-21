package application.servlets;

import application.dao.AlbumDao;
import application.dao.AuthorDao;
import application.dao.ConrtyDao;
import application.dao.GenreDao;
import application.models.AlbumModel;
import application.models.AuthorModel;
import org.json.JSONObject;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;

@WebServlet("/editalbum.jsp")
public class EditAlbumServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        int id = -1;
        AlbumModel album = null;
        AuthorModel author = null;
        try {
            author = new AuthorDao().getById(Integer.parseInt(req.getParameter("author_id")));
            req.setAttribute("author", author);
        } catch (Exception ex) {
            resp.sendRedirect("/");
            return;
        }

        try {
            String data = req.getParameter("album_id");
            if (data != null) {
                id = Integer.parseInt(data);
                if (id > 0) {
                    album = new AlbumDao().getById(id);
                }
            } else {
                album = new AlbumModel(0, new AuthorDao().getById(author.getId()), "", 0);
            }
            req.setAttribute("album", album);
        } catch (Exception ex) {
            resp.sendRedirect("/");
            return;
        }
        req.setAttribute("authors", new AuthorDao().getAll());
        req.getRequestDispatcher("/WEB-INF/views/editalbum.jsp").forward(req, resp);
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
        JSONObject album = new JSONObject(body);
        if (album.getInt("id") > 0) {
            new AlbumDao().update(new AlbumModel(album.getInt("id"), new AuthorDao().getById(album.getInt("author_id")),
                    album.getString("name"), album.getInt("tracks")));
        } else {
            new AlbumDao().add(new AlbumModel(-1, new AuthorDao().getById(album.getInt("author_id")),
                    album.getString("name"), album.getInt("tracks")));
            resp.sendRedirect("/");
        }
    }
}