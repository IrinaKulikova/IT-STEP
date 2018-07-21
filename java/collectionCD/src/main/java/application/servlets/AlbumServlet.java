package application.servlets;

import application.dao.AlbumDao;
import application.dao.AuthorDao;
import application.dao.GenreDao;
import application.models.AlbumModel;
import application.models.AuthorModel;
import application.models.GenreModel;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/album.jsp")
public class AlbumServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setAttribute("album", new AlbumDao().getById(Integer.parseInt(req.getParameter("id"))));
        req.getRequestDispatcher("/WEB-INF/views/album.jsp").forward(req, resp);
    }
}
