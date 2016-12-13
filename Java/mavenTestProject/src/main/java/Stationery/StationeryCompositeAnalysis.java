package Stationery;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;


public class StationeryCompositeAnalysis {
    private List<Stationery> stationeryList;

    StationeryCompositeAnalysis() {
        List<Stationery> stationeryList = new ArrayList<>();
    }

    public StationeryCompositeAnalysis(List<Stationery> stationeryList)
    {
        this.stationeryList = stationeryList;
    }

    public StationeryCompositeAnalysis getTopFiveItemsWithMaximumPrice() {

        stationeryList.sort(Comparator.comparing(Stationery::getPrice));

        List<Stationery> topFive = stationeryList.subList(Math.max(stationeryList.size() - 5, 0), stationeryList.size());
        return new StationeryCompositeAnalysis(topFive);
    }

    public int getStationerySize() {
        return stationeryList.size();
    }

    public int getSumPrice() {
        int result = 0;
        for (Stationery aStationeryList : stationeryList) {
            result += aStationeryList.getPrice();
        }
        return result;
    }

    public void addNewStationery(Stationery stationery) {
        stationeryList.add(stationery);
    }

    @Override
    public String toString() {
        String resultString = "";
        for (Stationery aStationeryList : stationeryList) {
            resultString += aStationeryList;
        }
        return resultString;
    }
}
