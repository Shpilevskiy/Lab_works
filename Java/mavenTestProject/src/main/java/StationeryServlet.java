import Stationery.Stationery;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.ArrayList;


@WebServlet("/stationery")
public class StationeryServlet extends BaseServlet{
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {
        resp.setContentType("text/html; charset=UTF-8");

        String country = getCountry(req);
        String firm = getFirm(req);
        String type = getType(req);
        String purpose = getPurpose(req);
        String material = getMaterial(req);
        String price = getPrice(req);

        if (!isEmpty(type) && !isEmpty(country) && !isEmpty(firm) && !isEmpty(purpose) && !isEmpty(material) && !isEmpty(price)) {
            try {
                int intPrice;
                intPrice = Integer.parseInt(price);

                ArrayList<Stationery> stationeryArrayList = getActualStationeryList();
                stationeryArrayList.add(new Stationery(country, firm, type, purpose, material, intPrice));
                updateStationeryStatement(stationeryArrayList);
                resp.sendRedirect(resp.encodeRedirectURL("/"));

            } catch (NumberFormatException e) {
                req.setAttribute("errorText", "Ой, я даже подскажу, нужно передавать целые числа!");

                req.getRequestDispatcher("ErrorPage.jsp").forward(req, resp);
                System.out.println("Wrong number");
                return;
            }
        }
        else {
            req.setAttribute("errorText", "Хм, ошибочка при вводе, наверняка не заполнены все поля, а это плохо, они грустят, заполните их, пожалуйста");
            req.getRequestDispatcher("ErrorPage.jsp").forward(req, resp);
        }

        System.out.println(type + "  " + country + "  " + firm + "  " + purpose + "  " + price + "  " + material);
    }
}
