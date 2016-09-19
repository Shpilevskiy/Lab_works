package lab1.Utils;


public class Menu {
    private String outputInfo;
    private int minValue;
    private int maxValue;

    public Menu(String outputInfo,int minValue,int maxValue) {
        this.outputInfo = outputInfo;
        this.maxValue = maxValue;
        this.minValue = minValue;
    }

    public int getUserChoice() {
        System.out.println(outputInfo);
        while (true) {
            int userInput = GetIntValue.getIntValue("Ваш выбор: ");
            if (userInput <= maxValue && userInput >= minValue) {
                return userInput;
            }
            else {
                System.out.println("Пожалуйста, введите нужный пункт меню");
            }
        }
    }
}
