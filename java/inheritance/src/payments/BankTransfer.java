package payments;

import payments.PaymentMethod;

public class BankTransfer implements PaymentMethod {

    private String accountNumber;
    private String rountingNUmber;
    private double balance;

    public BankTransfer(String accountNumber, String routingNumber, double balance) {
        this.accountNumber = accountNumber;
        this.rountingNUmber = routingNumber;
        this.balance = balance;
    }

    // Implementetion of PaymentMethod interface methods
    @Override
    public boolean processPayment(double amount) {
        if(balance >= amount) {
            balance -= amount;
            System.out.println(" Bank transfer of $ " + amount + " processed.");
            System.out.println(" Account: **** " + accountNumber.substring(accountNumber.length() - 4));
            System.out.println(" Remaining balance of $ " + balance);
            return true;
        } else {
            System.out.println(" Insufficient funds in the bank account. Transfer failed.");
            return false;
        }
    }

    @Override
    public String getPaymentDetails() {
        String maskedAccount = "****" + accountNumber.substring(accountNumber.length() - 4);
        return "Bank Transfer | Account: " + maskedAccount +
               " | Routing: " + rountingNUmber + " | Balance: $ " + balance;
    }

    @Override
    public boolean refund(double amount) {
        balance += amount;
        System.out.println(" Refund of $ " + amount + " transferred to bank account.");
        System.out.println(" New balance of $ " + balance);
        return true;
    }

    public String getAccountNumber() {
        return accountNumber;
    }

    public double getBalance() {
        return balance;
    }
}
