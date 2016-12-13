package XmlUtils;

import Stationery.Stationery;
import org.w3c.dom.Document;
import org.w3c.dom.Element;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import java.io.File;
import java.util.ArrayList;
import java.util.Objects;
import java.util.Random;

public class StationerySaver {
    private String fileName;
    private String rootElement;
    private String baseElement;

    public StationerySaver(String fileName, String rootElement, String baseElement) {
        this.fileName = fileName;
        this.baseElement = baseElement;
        this.rootElement = rootElement;
    }

    public void updateStatemant(ArrayList<Stationery> stationeryArrayList) {
        DocumentBuilderFactory docFactory = DocumentBuilderFactory.newInstance();
        try {
            DocumentBuilder documentBuilder = docFactory.newDocumentBuilder();

            Document document = documentBuilder.newDocument();
            Element rootElement = document.createElement(this.rootElement);
            document.appendChild(rootElement);

            for (Stationery stationery : stationeryArrayList) {
                Element item = document.createElement(baseElement);
                rootElement.appendChild(item);

                Element childOfItem = document.createElement("firm");
                childOfItem.appendChild(document.createTextNode(stationery.firm));
                item.appendChild(childOfItem);

                childOfItem = document.createElement("country");
                childOfItem.appendChild(document.createTextNode(stationery.country));
                item.appendChild(childOfItem);

                childOfItem = document.createElement("type");
                childOfItem.appendChild(document.createTextNode(stationery.type));
                item.appendChild(childOfItem);

                childOfItem = document.createElement("purpose");
                childOfItem.appendChild(document.createTextNode(stationery.purpose));
                item.appendChild(childOfItem);

                childOfItem = document.createElement("material");
                childOfItem.appendChild(document.createTextNode(stationery.material));
                item.appendChild(childOfItem);

                childOfItem = document.createElement("price");
                childOfItem.appendChild(document.createTextNode(String.valueOf(stationery.price)));
                item.appendChild(childOfItem);
            }

            TransformerFactory transformerFactory = TransformerFactory.newInstance();
            Transformer transformer = transformerFactory.newTransformer();
            DOMSource source = new DOMSource(document);
            StreamResult result = new StreamResult(new File(fileName));

            transformer.transform(source, result);
            System.out.println("Saved");
        } catch (ParserConfigurationException | TransformerException e) {
            e.printStackTrace();
        }
    }
}
