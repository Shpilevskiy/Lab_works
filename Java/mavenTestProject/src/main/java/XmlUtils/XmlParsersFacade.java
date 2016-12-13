package XmlUtils;

import Stationery.Stationery;
import Stationery.StationeryCompositeAnalysis;
import XmlUtils.Factory.DomFactory;
import XmlUtils.Factory.SaxFactory;
import XmlUtils.Parsers.XmlParser;

import java.util.List;


public class XmlParsersFacade {
    private XmlParser domParser;
    private XmlParser saxParser;

    private List<Stationery> domStationeryList;
    private List<Stationery> saxStationeryList;

    public XmlParsersFacade(String subElement, String fileName) {
        SaxFactory saxFactory = new SaxFactory();
        this.saxParser = saxFactory.createXmlParser(fileName, null);

        DomFactory domFactory = new DomFactory();
        this.domParser = domFactory.createXmlParser(fileName, subElement);
    }

    public XmlParsersFacade(String fileName, String baseElement, String subElement, int elementsCount, String subElements) {
        SaxFactory saxFactory = new SaxFactory();
        this.saxParser = saxFactory.createDecoratedParser(fileName, baseElement, subElement, elementsCount, subElements);

        DomFactory domFactory = new DomFactory();
        this.domParser = domFactory.createDecoratedParser(fileName, baseElement, subElement, elementsCount, subElements);
    }

    private List<Stationery> runSaxParser() {
        saxParser.parseDataFromXml();
        List<Stationery> stationeryList = saxParser.getStationeryList();

        System.out.println("ОТРАБОТАЛ SAX ПАРСЕР");
        saxStationeryList = stationeryList;
        return stationeryList;
    }


    public List<Stationery> runDomParser() {
        domParser.parseDataFromXml();
        List<Stationery> stationeryList = domParser.getStationeryList();

        System.out.println("ОТРАБОТАЛ DOM ПАРСЕР");
        domStationeryList = stationeryList;
        return stationeryList;
    }

    public void parseWithAllParsers() {
        runSaxParser();
        runDomParser();
    }

    public void printXmlDataFromFileWithDom() {
        StationeryCompositeAnalysis analysis = new StationeryCompositeAnalysis(domStationeryList);
        System.out.print(analysis);
    }

    public void printXmlDataFromFileWithSAX() {
        runSaxParser();
        StationeryCompositeAnalysis analysis = new StationeryCompositeAnalysis(saxStationeryList);
        System.out.print(analysis);
    }

    public void printDomTopFiveItems() {
        StationeryCompositeAnalysis analysis = new StationeryCompositeAnalysis(domStationeryList);
        System.out.println("ТОП 5 товаров по цене: \n" + analysis.getTopFiveItemsWithMaximumPrice());
    }

    public void printDomStationerySize() {
        StationeryCompositeAnalysis analysis = new StationeryCompositeAnalysis(domStationeryList);
        System.out.println("Количество товаров: " + analysis.getStationerySize());
    }

    public void printDomSumPrice() {
        StationeryCompositeAnalysis analysis = new StationeryCompositeAnalysis(domStationeryList);
        System.out.println("Общая сумма: " + analysis.getSumPrice());
    }
}
