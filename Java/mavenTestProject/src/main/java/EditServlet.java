import Stationery.Stationery;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.ArrayList;

@WebServlet("/edit")
public class EditServlet extends BaseServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {

        resp.setContentType("text/html; charset=UTF-8");
        req.setAttribute("stationeryList", getActualStationeryList());
        req.getRequestDispatcher(EDIT_PAGE).forward(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {
        int id = getId(req);
        String country = getCountry(req);
        String firm = getFirm(req);
        String type = getType(req);
        String purpose = getPurpose(req);
        String material = getMaterial(req);
        String price = getPrice(req);

        ArrayList<Stationery> actualStationeryList = getActualStationeryList();
        Stationery stationery = actualStationeryList.get(id);
        actualStationeryList.remove(id);

        if(!isEmpty(country)) stationery.setCountry(country);
        if(!isEmpty(firm)) stationery.setFirm(firm);
        if(!isEmpty(type)) stationery.setType(type);
        if(!isEmpty(purpose)) stationery.setPurpose(purpose);
        if(!isEmpty(material)) stationery.setMaterial(material);
        if(!isEmpty(price)) stationery.setPrice(Integer.valueOf(price));

        actualStationeryList.add(id, stationery);
        updateStationeryStatement(actualStationeryList);

        resp.setContentType("text/html; charset=UTF-8");
        req.setAttribute("stationeryList", getActualStationeryList());
        req.getRequestDispatcher(EDIT_PAGE).forward(req, resp);
    }
}
