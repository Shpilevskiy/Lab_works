package XmlUtils.Decorator;

import Stationery.Stationery;
import XmlUtils.Parsers.XmlParser;
import XmlUtils.StationeryGenerator;

import java.util.List;


public class XmlParserAndGeneratorDecorator extends ParserDecorator {
    private XmlParser xmlParser;
    private StationeryGenerator stationeryGenerator;

    public XmlParserAndGeneratorDecorator(XmlParser xmlParser, String subElements, String fileName, int elementsCount, String baseElement, String subElement) {
        super(xmlParser);
        this.xmlParser = xmlParser;
        this.stationeryGenerator = new StationeryGenerator(
                fileName,
                elementsCount,
                baseElement,
                subElement,
                subElements);
    }

    @Override
    public void parseDataFromXml() {
        generateNewXmlFileToParse();
        super.parseDataFromXml();
    }

    @Override
    public List<Stationery> getStationeryList() {
        return xmlParser.getStationeryList();
    }

    private void generateNewXmlFileToParse() {
        stationeryGenerator.generateNewXML();
    }
}
