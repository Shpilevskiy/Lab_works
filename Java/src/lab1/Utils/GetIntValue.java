package lab1.Utils;

import java.util.Scanner;

public class GetIntValue {
    static public int getIntValue(String outputMessage) {
        Scanner sc = new Scanner(System.in);
        System.out.println(outputMessage);
        while (true) {
            if(sc.hasNextInt()) {
                return sc.nextInt();
            } else {
                System.out.print("Пожалуйста, введите целое число");
                sc = new Scanner(System.in);
            }
        }

    }
}
