package XmlUtils.Decorator;

import Stationery.Stationery;
import XmlUtils.Parsers.XmlParser;

import java.util.List;


abstract class ParserDecorator implements XmlParser {
    private XmlParser xmlParser;

    ParserDecorator(XmlParser xmlParser) {
        this.xmlParser = xmlParser;
    }

    @Override
    public void parseDataFromXml() {
        xmlParser.parseDataFromXml();
    }

    @Override
    public List<Stationery> getStationeryList(){
        return xmlParser.getStationeryList();
    }
}
