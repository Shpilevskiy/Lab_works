package lab1;

import lab1.CustomExceptions.WrongTransferSumException;
import lab1.CustomExceptions.TooSmallAmountException;
import lab1.Utils.GetIntValue;
import lab1.Utils.Menu;
import lab1.Commission.BankTransaction;

//18.Банк берет комиссию за перевод по принципу - с каждой сотни рублей изымается комиссия - 7 рублей. За неполную сотню также изымается 7 рублей. К примеру, за перевод одного рубля придется выложить 1 + 7 = 8 рублей.
//За перевод 101 рубля придется выложить уже 100 + 7 + 1 + 7 = 115 рублей
//        Пользователь вводит сумму, которую хочет перевести, а программа должна определить:
//        1. Максимально возможную сумму перевода (с учетом, что комиссия за перевод будет браться из переводимой суммы).
//        2. Комиссию за данный перевод.


public class Main {
    public static void main(String[] args) {
        BankTransaction transaction = null;
        Menu menu = new Menu("1)Инициализировать транзакцию\n2)Рассчитать комиссию\n3)Информация по коммиссии\n0)Выход",0, 3);
        while (true) {
            switch (menu.getUserChoice()) {
                case 0: {
                    System.out.println("Завершение сессии");
                    return;
                }
                case 1: {
                    int sum = GetIntValue.getIntValue("Сумма желаемого перевода: ");
                    try {
                        transaction = new BankTransaction(sum);
                    } catch (WrongTransferSumException e) {
                        System.out.println(e.ToString());
                        transaction = null;
                    }
                    break;
                }
                case 2:{
                    if (transaction == null) System.out.println("Транзакция не была инициализирована!");
                    else {
                        try {
                            transaction.calculateCommission();
                            System.out.println("Операция по расчету успешно выполнена:" +
                                    " \n Исходная сумма: "+transaction.getUserWantSum() +
                                    "\n Комиссия: "+transaction.getTransferCommission() +
                                    "\nБудет переведено: "+transaction.getResultTransferAmount());

                        } catch (TooSmallAmountException e) {
                            System.out.println(e.ToString());
                            transaction = null;
                        }
                    }
                    break;
                }
                case 3:{
                    System.out.println(BankTransaction.getCommissionInfo());
                    break;
                }
                default:{
                    System.out.println("Ошибка ввода");
                    break;
                }
            }
        }
    }
}
