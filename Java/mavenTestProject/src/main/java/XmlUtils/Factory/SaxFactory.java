package XmlUtils.Factory;

import XmlUtils.Decorator.XmlParserAndGeneratorDecorator;
import XmlUtils.Parsers.Sax.StationerySaxParser;
import XmlUtils.Parsers.XmlParser;


public class SaxFactory implements ParserAbstractFactory {

    @Override
    public XmlParser createXmlParser(String fileName, String baseElement) {
        return new StationerySaxParser(fileName);
    }

    @Override
    public XmlParser createDecoratedParser(String fileName, String baseElement, String subElement, int elementsCount, String subElements) {
        return new XmlParserAndGeneratorDecorator(new StationerySaxParser(fileName), subElements, fileName, elementsCount, baseElement, subElement);
    }
}
