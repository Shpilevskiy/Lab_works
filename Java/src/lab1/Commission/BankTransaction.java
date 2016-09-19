package lab1.Commission;

import lab1.CustomExceptions.TooSmallAmountException;
import lab1.CustomExceptions.WrongTransferSumException;

public class BankTransaction implements Commission {
    private int userAmount;
    private int amountToTransfer;
    private int transferCommission;

    private static final int COMMISSION = 7;


    public BankTransaction(int sum) throws WrongTransferSumException {
        if (sum <= 0) throw new WrongTransferSumException();
        this.userAmount = sum;
    }

    public static String getCommissionInfo(){
        return "Банк берет комиссию за перевод по принципу - с каждой сотни рублей изымается комиссия - " + COMMISSION + " рублей. За неполную сотню также изымается " + COMMISSION + " рублей";
    }

    @Override
    public void calculateCommission() throws TooSmallAmountException {
        int sum = userAmount;
        amountToTransfer = 0;
        transferCommission = 0;
        do {
            transferCommission += COMMISSION;
            sum -= 100;
        }while (sum >0);
        amountToTransfer = userAmount - transferCommission;
        if (amountToTransfer <= 0) throw new TooSmallAmountException(userAmount);
    }

    @Override
    public int getResultTransferAmount() {
        return amountToTransfer;
    }

    @Override
    public int getTransferCommission() {
        return transferCommission;
    }

    @Override
    public int getUserWantSum() {
        return userAmount;
    }
}
