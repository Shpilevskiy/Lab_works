package XmlUtils.Factory;

import XmlUtils.Decorator.XmlParserAndGeneratorDecorator;
import XmlUtils.Parsers.Dom.StationeryDomParser;
import XmlUtils.Parsers.XmlParser;


public class DomFactory implements ParserAbstractFactory {

    @Override
    public XmlParser createXmlParser(String subElement, String fileName) {
        return new StationeryDomParser(fileName, subElement);
    }

    @Override
    public XmlParser createDecoratedParser(String fileName, String baseElement, String subElement, int elementsCount, String subElements) {
        return new XmlParserAndGeneratorDecorator(new StationeryDomParser(fileName, subElement), subElements, fileName, elementsCount, baseElement, subElement);
    }
}
