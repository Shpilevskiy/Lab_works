package XmlUtils;

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
import java.util.*;

public class StationeryGenerator {

    private String fileName;
    private int itemsCount;
    private ArrayList<String> elements;
    private String baseElement;
    private String rootElement;
    private static ArrayList<String> FIRMS = new ArrayList<String>(){{
       add("Jhonsons");
       add("Farikson");
       add("General&Smith");
       add("Конструктор");
       add("Birthday");
    }};
    private static ArrayList<String> COUNTRIES = new ArrayList<String>(){{
       add("Бельгия");
       add("Беларусь");
       add("Германия");
       add("Россия");
       add("Китай");
    }};
    private static ArrayList<String> TYPES = new ArrayList<String>(){{
       add("Карандаш");
       add("Циркуль");
       add("Линейка");
       add("Бумага");
       add("Стирка");
    }};
    private static ArrayList<String> PURPOSES = new ArrayList<String>(){{
       add("Аккуратно, без усилий");
       add("Хрупкий");
       add("Влагостойкий");
       add("Несгораемый");
       add("Работает в космосе");
    }};
    private static ArrayList<String> MATERIALS = new ArrayList<String>(){{
       add("Дерево");
       add("Метал");
       add("Сплав");
       add("Композит");
       add("Аллюминий");
    }};

    public StationeryGenerator(String fileName, int itemsCount, String rootElement, String baseElement, String elementsUnderBase) {
        this.fileName = fileName;
        this.itemsCount = itemsCount;
        this.baseElement = baseElement;
        this.rootElement = rootElement;
        this.elements = new ArrayList<>(Arrays.asList(elementsUnderBase.split(" ")));
    }

    private String getValueFromConstant(ArrayList<String> list) {
        Random random = new Random();
        int index = random.nextInt(list.size());
        return list.get(index);
    }

    public void generateNewXML() {
        DocumentBuilderFactory docFactory = DocumentBuilderFactory.newInstance();
        try {
            DocumentBuilder documentBuilder = docFactory.newDocumentBuilder();

            Document document = documentBuilder.newDocument();
            Element rootElement = document.createElement(this.rootElement);
            document.appendChild(rootElement);

            for (int i=0; i<itemsCount; ++i) {
                Element item = document.createElement(baseElement);
                rootElement.appendChild(item);
                for (String element : elements) {
                    Element childOfItem = document.createElement(element);
                    String elementValue = "Lorem ipsum doloras";
                    if (Objects.equals(element, "firm")){
                        elementValue = getValueFromConstant(FIRMS);
                    }if (Objects.equals(element, "country")){
                        elementValue = getValueFromConstant(COUNTRIES);
                    }if (Objects.equals(element, "type")){
                        elementValue = getValueFromConstant(TYPES);
                    }if (Objects.equals(element, "purpose")){
                        elementValue = getValueFromConstant(PURPOSES);
                    }if (Objects.equals(element, "material")){
                        elementValue = getValueFromConstant(MATERIALS);
                    }if (Objects.equals(element, "price")){
                        Random generator = new Random();
                        elementValue = Integer.toString(generator.nextInt(1000000) + 1);
                    }

                    childOfItem.appendChild(document.createTextNode(elementValue));
                    item.appendChild(childOfItem);
                }
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
