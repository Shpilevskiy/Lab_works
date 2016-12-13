package XmlUtils.Parsers.Sax;

import Stationery.Stationery;
import org.xml.sax.helpers.DefaultHandler;

import java.util.ArrayList;
import java.util.List;


class StationerySaxHandler extends DefaultHandler {

    private List<Stationery> stationeryList = new ArrayList<>();
    private Stationery node = null;

    private boolean firm = false;
    private boolean country = false;
    private boolean type = false;
    private boolean purpose = false;
    private boolean material = false;
    private boolean price = false;

    public List<Stationery> getStationeryList() {
       return stationeryList;
    }

    @Override
    public void startDocument() {
        System.out.println("SAX parser is working");
    }

    @Override
    public void endDocument() {
        System.out.println("SAX parser finished it work");
    }

    @Override
    public void startElement(String uri, String localName, String qName, org.xml.sax.Attributes attributes) throws org.xml.sax.SAXException {


        if (qName.equalsIgnoreCase("item")) {
            node = new Stationery();
        }
        else if (qName.equalsIgnoreCase("firm")) {
            firm = true;
        }
        else if (qName.equalsIgnoreCase("country")) {
            country = true;
        }
        else if (qName.equalsIgnoreCase("type")) {
            type = true;
        }
        else if (qName.equalsIgnoreCase("purpose")) {
            purpose = true;
        }
        else if (qName.equalsIgnoreCase("material")) {
            material = true;
        }
        else if (qName.equalsIgnoreCase("price")) {
            price = true;
        }
    }

    @Override
    public void endElement(String uri, String localName, String qName) {
        if(qName.equalsIgnoreCase("item")) {
            stationeryList.add(node);
        }
    }

    @Override
    public void characters(char ch[], int start, int length) {

        if (price) {
            node.setPrice(Integer.parseInt(new String(ch, start, length)));
            price = false;
        }

        if (country) {
            node.setCountry(new String(ch, start, length));
            country = false;
        }

        if (type) {
            node.setType(new String(ch, start, length));
            type = false;
        }

        if (purpose) {
            node.setPurpose(new String(ch, start, length));
            purpose = false;
        }

        if (firm) {
            node.setFirm(new String(ch, start, length));
            firm = false;
        }

        if (material) {
            node.setMaterial(new String(ch, start, length));
            material = false;
        }
    }
}
