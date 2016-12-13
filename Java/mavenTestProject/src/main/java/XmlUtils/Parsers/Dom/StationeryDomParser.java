package XmlUtils.Parsers.Dom;


import Stationery.Stationery;
import XmlUtils.Parsers.XmlParser;
import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class StationeryDomParser implements XmlParser {

    private String fileName;
    private String baseElement;
    private List<Stationery> stationeryList = new ArrayList<Stationery>();


    public StationeryDomParser(String fileName, String baseElement) {
        this.fileName = fileName;
        this.baseElement = baseElement;
    }

    public void parseDataFromXml()
    {
        File dataFile = new File(fileName);
        DocumentBuilderFactory builderFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder documentBuilder = null;
        try {
            documentBuilder = builderFactory.newDocumentBuilder();
        } catch (ParserConfigurationException e) {
            e.printStackTrace();
        }
        try {
            assert documentBuilder != null;
            Document document = documentBuilder.parse(dataFile);
            document.getDocumentElement().normalize();

//            String parsedRootElement = document.getDocumentElement().getNodeName();

            NodeList nodeList = document.getElementsByTagName(baseElement);

            for (int i = 0; i < nodeList.getLength(); ++i) {
                Node node = nodeList.item(i);
                Stationery stationeryElement = new Stationery();
                if(node.getNodeType() == Node.ELEMENT_NODE){
                    NodeList childNodes = node.getChildNodes();
                    for (int j=0; j < childNodes.getLength(); j++) {
                        Node childNode = childNodes.item(j);
                        String nodeName = childNode.getNodeName();
                        String nodeTextContext = childNode.getTextContent();
                        if (Objects.equals(nodeName, "firm")){
                            stationeryElement.setFirm(nodeTextContext);
                        } else if (Objects.equals(nodeName, "country")){
                            stationeryElement.setCountry(nodeTextContext);
                        }else if (Objects.equals(nodeName, "type")){
                            stationeryElement.setType(nodeTextContext);
                        }else if (Objects.equals(nodeName, "purpose")){
                            stationeryElement.setPurpose(nodeTextContext);
                        }else if (Objects.equals(nodeName, "material")){
                            stationeryElement.setMaterial(nodeTextContext);
                        }else if (Objects.equals(nodeName, "price")){
                            stationeryElement.setPrice(Integer.parseInt(nodeTextContext));
                        }
                    }
                    stationeryList.add(stationeryElement);
                }
            }
        } catch (SAXException | IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    public List<Stationery> getStationeryList() {
        return stationeryList;
    }
}
