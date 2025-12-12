package payments;

public interface PaymentMethod {

    public boolean processPayment(double amount);

    public String getPaymentDetails();

    public boolean refund(double amount);

}
