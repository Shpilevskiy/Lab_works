package lab1.CustomExceptions;


public class WrongTransferSumException extends Exception {
    private String error;

    public WrongTransferSumException(){
        this.error = "Неверная сумма, невозможно выполнить транзакцию";
    }

    public String ToString() {
        return error;
    }
}

