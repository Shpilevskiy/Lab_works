package lab1.CustomExceptions;

public class TooSmallAmountException extends Exception {
    private String error;

    public TooSmallAmountException(int sum){
        this.error = "Введенная сумма "+sum+" слишком мала. Сумма к переводу должна быть 8 и выше";
    }

    public String ToString() {
        return error;
    }
}