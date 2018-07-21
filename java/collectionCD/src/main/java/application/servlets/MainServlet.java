package application.servlets;

import application.dao.AuthorDao;
import application.models.AuthorModel;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.List;

@WebServlet("/")
public class MainServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        List<AuthorModel> authors = new AuthorDao().getAll();
        req.setAttribute("authors", authors);
        req.getRequestDispatcher("/WEB-INF/views/index.jsp").forward(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String body = "";
        BufferedReader reader = req.getReader();
        String line = "";
        while ((line = reader.readLine()) != null) {
            body += line;
        }

        int id = -1;
        if (body != "") {
            try {
                id = Integer.parseInt(body);
            } catch (ClassCastException e) {
                e.printStackTrace();
            }
            new AuthorDao().removeById(id);
        }
    }
}
