public class BankAccount {
    private String owner;
    private double balance;
    private String accountNumber;

    public BankAccount() {
        this.owner = "Unknown";
        this.accountNumber = "0000AAAA";
        this.balance = 0.0;
    }

    public BankAccount(String owner, String accountNumber, double balance) {
        this.owner = owner;
        this.accountNumber = accountNumber;
        this.balance = balance;
    }

    public void deposit(double deposit) { this.balance += deposit; }

    public void withdraw(double withdraw) {
        if(withdraw <= balance) {
            this.balance -= withdraw;
        } else {
            System.out.println(" The ammount requested excedes the balance avaible.");
        }
    }
    
    public double getBalance() { return balance; }

    public void getAccountInfo() {
        System.out.println("\n------------------------------------");
        System.out.println("  Owner : " + owner);
        System.out.println("  Account Number : " + accountNumber);
        System.out.println("  Balance : " + balance);
        System.out.println("------------------------------------\n");
    }
}
