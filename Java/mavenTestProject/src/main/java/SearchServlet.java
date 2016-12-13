import Stationery.Stationery;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.ArrayList;
import java.util.stream.Collectors;

/**
 * Created by nick on 13.12.16.
 */

@WebServlet("/search")
public class SearchServlet extends BaseServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {

        resp.setContentType("text/html; charset=UTF-8");
        req.setAttribute("stationeryList", getActualStationeryList());
        req.getRequestDispatcher(SEARCH_PAGE).forward(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {

        String country = getCountry(req);
        String firm = getFirm(req);
        String type = getType(req);
        String purpose = getPurpose(req);
        String material = getMaterial(req);
        String price = getPrice(req);

        ArrayList<Stationery> searchResultList = new ArrayList<Stationery>();
        System.out.println("HERE");
        searchResultList.addAll(getActualStationeryList().stream().filter(s -> (isEmpty(country) || s.getСountry().contains(country))
                && (isEmpty(firm) || s.getFirm().contains(firm))
                && (isEmpty(type) || s.getType().contains(type))
                && (isEmpty(purpose) || s.getPurpose().contains(purpose))
                && (isEmpty(material) || s.getMaterial().contains(material))
                && (isEmpty(price) || String.valueOf(s.getPrice()).contains(price))).collect(Collectors.toList()));

        resp.setContentType("text/html; charset=UTF-8");
        req.setAttribute("stationeryList", searchResultList);
        req.getRequestDispatcher(SEARCH_PAGE).forward(req, resp);
    }
}
