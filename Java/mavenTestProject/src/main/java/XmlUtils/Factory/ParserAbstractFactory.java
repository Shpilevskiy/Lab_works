package XmlUtils.Factory;

import XmlUtils.Parsers.XmlParser;

interface ParserAbstractFactory {
    XmlParser createXmlParser(String fileName, String domBaseElement);
    XmlParser createDecoratedParser(String fileName, String baseElement, String subElement, int elementsCount, String subElements);
}
