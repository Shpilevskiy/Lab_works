package lab1.Commission;


import lab1.CustomExceptions.TooSmallAmountException;

interface Commission {
    void calculateCommission() throws TooSmallAmountException;
    int getResultTransferAmount();
    int getTransferCommission();
    int getUserWantSum();
}

