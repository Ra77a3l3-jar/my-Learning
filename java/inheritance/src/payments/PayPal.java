package payments;

import payments.PaymentMethod;

public class PayPal implements PaymentMethod {

    private String email;
    private double balance;

    public PayPal(String email, double balance) {
        this.email = email;
        this.balance = balance;
    }

    // Implement PaymentMethod interface methods
    @Override
    public boolean processPayment(double amount) {
        if(balance >= amount) {
            balance -= amount;
            System.out.println(" PayPal payment of $ " + amount + " processed from " + email);
            System.out.println(" Remaining balance of $ " + balance);
            return true;
        } else {
            System.out.println(" Insufficient PayPal balance. Payment failed.");
            return false;
        }
    }

    @Override
    public String getPaymentDetails() {
        return "PayPal account: " + email + " | Balance: $ " + balance;
    }

    @Override
    public boolean refund(double amount) {
        balance += amount;
        System.out.println(" Refund of $ " + amount + " credited to PayPal account: " + email);
        System.out.println(" New balance of $ " + balance);
        return true;
    }

    public String getEmail() {
        return email;
    }

    public double getBalance() {
        return balance;
    }
}
