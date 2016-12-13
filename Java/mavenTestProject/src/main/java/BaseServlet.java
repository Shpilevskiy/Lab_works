import Stationery.Stationery;
import XmlUtils.StationerySaver;
import XmlUtils.XmlParsersFacade;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;


public abstract class BaseServlet extends HttpServlet {
    String SUB_ELEMENTS = "firm country type purpose material price";
    String FILE_NAME = "/home/nick/example.xml";
    int ELEMENTS_COUNT = 10;
    String BASE_ELEMENT = "Stationery";
    String SUB_ELEMENT = "item";
    String INDEX_PAGE = "1.jsp";
    String SEARCH_PAGE = "SearchPage.jsp";
    String DELETE_PAGE = "DeletePage.jsp";
    String EDIT_PAGE = "EditPage.jsp";


    static boolean isEmpty(final String s) {
        // Null-safe, short-circuit evaluation.
        return s == null || s.trim().isEmpty();
    }

    ArrayList<Stationery> getActualStationeryList() {
        XmlParsersFacade xmlParsersFacade = new XmlParsersFacade(FILE_NAME, SUB_ELEMENT);
        return (ArrayList<Stationery>) xmlParsersFacade.runDomParser();
    }

    void updateStationeryStatement(ArrayList<Stationery> stationeryArrayList) {
        StationerySaver saver = new StationerySaver(FILE_NAME, BASE_ELEMENT, SUB_ELEMENT);
        saver.updateStatemant(stationeryArrayList);
    }

    String getFirm(HttpServletRequest request) {
        String firm = request.getParameter("firm");
        try {
            firm = new String (firm.getBytes ("iso-8859-1"), "UTF-8");
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        return firm;
    }

    String getCountry(HttpServletRequest request) {
        String tmp = request.getParameter("country");
        try {
            tmp = new String (tmp.getBytes ("iso-8859-1"), "UTF-8");
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        return tmp;
    }

    String getType(HttpServletRequest request) {
        String tmp = request.getParameter("type");
        try {
            tmp = new String (tmp.getBytes ("iso-8859-1"), "UTF-8");
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        return tmp;
    }

    String getPurpose(HttpServletRequest request) {
        String tmp = request.getParameter("purpose");
        try {
            tmp = new String (tmp.getBytes ("iso-8859-1"), "UTF-8");
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        return tmp;
    }

    String getMaterial(HttpServletRequest request) {
        String tmp = request.getParameter("material");
        try {
            tmp = new String (tmp.getBytes ("iso-8859-1"), "UTF-8");
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        return tmp;
    }

    String getPrice(HttpServletRequest request) {
        String tmp = request.getParameter("price");
        try {
            tmp = new String (tmp.getBytes ("iso-8859-1"), "UTF-8");
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        return tmp;
    }

    int getId(HttpServletRequest request) {
        String tmp = request.getParameter("id");
        try {
            tmp = new String (tmp.getBytes ("iso-8859-1"), "UTF-8");
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        return Integer.valueOf(tmp);
    }
}
