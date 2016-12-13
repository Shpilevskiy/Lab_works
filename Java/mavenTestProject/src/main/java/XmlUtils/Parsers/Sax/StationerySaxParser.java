package XmlUtils.Parsers.Sax;

import Stationery.Stationery;
import XmlUtils.Parsers.XmlParser;
import org.xml.sax.SAXException;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;


public class StationerySaxParser implements XmlParser {

    private StationerySaxHandler saxHandler;
    private SAXParser saxParser;
    private String fileName;
    private List<Stationery> stationeryList = new ArrayList<>();

    public StationerySaxParser(String fileName) {
        this.fileName = fileName;
        this.saxHandler = new StationerySaxHandler();

        SAXParserFactory saxParserFactory = SAXParserFactory.newInstance();
        try {
            this.saxParser = saxParserFactory.newSAXParser();
        } catch (ParserConfigurationException | SAXException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void parseDataFromXml() {
        try {
            saxParser.parse(new File(fileName), saxHandler);
        } catch (SAXException | IOException e) {
            e.printStackTrace();
        }
        stationeryList = saxHandler.getStationeryList();
    }

    @Override
    public List<Stationery> getStationeryList() {
        return stationeryList;
    }
}
