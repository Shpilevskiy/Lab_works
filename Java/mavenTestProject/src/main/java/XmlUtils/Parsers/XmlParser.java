package XmlUtils.Parsers;

import Stationery.Stationery;

import java.util.List;


public interface XmlParser {
    void parseDataFromXml();
    List<Stationery>  getStationeryList();
}
