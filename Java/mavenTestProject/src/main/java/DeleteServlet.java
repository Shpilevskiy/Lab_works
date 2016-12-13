import Stationery.Stationery;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.ArrayList;


@WebServlet("/delete")
public class DeleteServlet extends BaseServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {

        resp.setContentType("text/html; charset=UTF-8");
        req.setAttribute("stationeryList", getActualStationeryList());
        req.getRequestDispatcher(DELETE_PAGE).forward(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {
        int id = getId(req);

        ArrayList<Stationery> actualStationeryList = getActualStationeryList();
        actualStationeryList.remove(id);
        updateStationeryStatement(actualStationeryList);

        resp.setContentType("text/html; charset=UTF-8");
        req.setAttribute("stationeryList", getActualStationeryList());
        req.getRequestDispatcher(DELETE_PAGE).forward(req, resp);
    }
}
