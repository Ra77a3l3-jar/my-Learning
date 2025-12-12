package payments;

import payments.PaymentMethod;

public class CreditCard implements PaymentMethod {

    private String cardNumber;
    private String expirationDate;
    private String cvv;
    private double balance;

    public CreditCard(String cardNumber, String expirationDate, String cvv, double balance) {
        this.cardNumber = cardNumber;
        this.expirationDate = expirationDate;
        this.cvv = cvv;
        this.balance = balance;
    }

    // Implement PaymentMethod methods
    @Override
    public boolean processPayment(double amount) {
        if(balance >= amount) {
            balance -= amount;
            System.out.println(" Credit card payment of $ " + amount + " processed successfully.");
            System.out.println(" Remaining balance of $ " + balance);
            return true;
        } else {
            System.out.println(" Insufficient funds. Payment declined.");
            return false;
        }
    }

    @Override
    public String getPaymentDetails() {
        String maskedCard = "**** **** ****" + cardNumber.substring(cardNumber.length() - 4);
        return "Credit card: " + maskedCard + " | Exp: " + expirationDate + " | Balance: $ " + balance;
    }

    @Override
    public boolean refund(double amount) {
        balance += amount;
        System.out.println(" Refund of $ " + amount + " processed to credit card.");
        System.out.println(" New balance of $ " + balance);
        return true;
    }

    public double getBalance() {
        return balance;
    }   
}
