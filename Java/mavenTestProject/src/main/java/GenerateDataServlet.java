import Stationery.Stationery;
import XmlUtils.XmlParsersFacade;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

@WebServlet("/generate")
public class GenerateDataServlet extends BaseServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {

        XmlParsersFacade xmlParsersFacade = new XmlParsersFacade(FILE_NAME, BASE_ELEMENT, SUB_ELEMENT, ELEMENTS_COUNT, SUB_ELEMENTS);
        xmlParsersFacade.runDomParser();
        resp.sendRedirect("/");
    }

}
