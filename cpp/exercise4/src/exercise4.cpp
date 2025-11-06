#include <iostream>
#include <vector>
#include <string>

class BankAccount {
    protected:
        std::string accountNumber;
        double balance;
        std::string accountHolderName;

    public:

        BankAccount(const std::string accNum, double balan, const std::string accHolName)
                 : accountNumber(accNum), balance(balan), accountHolderName(accHolName) {}

        double getBalance() {
            return balance;
        }

        virtual void withdraw(double amount) {
            std::cout << "=== Withdrawing ===" << std::endl;
            std::cout << std::endl;
            std::cout << " Withdrawing " << amount << " $ from accout" << std::endl;
            balance -= amount;
            std::cout << " New balance is " << balance << "$" << std::endl;
        }

        void deposit(double amount) {
            std::cout << "=== Depositing ===" << std::endl;
            std::cout << std::endl;
            std::cout << " Depositing " << amount << " $  to account" << std::endl;
            balance += amount;
            std::cout << " New balance is " << balance << "$" << std::endl;
        }

        void displayInfo() {
            std::cout << "=== Account Information ===" << std::endl;
            std::cout << "Account Number: " << accountNumber << std::endl;
            std::cout << "Account Holder: " << accountHolderName << std::endl;
            std::cout << "Balance: $" << balance << std::endl;
            std::cout << "===========================" << std::endl;
        }
};

class SavingsAccount : public BankAccount {
    private:
        double interestRate;

    public:

        SavingsAccount(const std::string& accNum, double initBalance, const std::string accHName, const double intRate)
                : BankAccount(accNum, initBalance, accHName),
                interestRate(intRate) {}

        void addInterest() {
            std::cout << "=== Applying Interest ===" << std::endl;
            std::cout << std::endl;
            double interest = balance * interestRate;
            balance += interest;
            std::cout << " Interest applied: " << interest << " $" << std::endl;
            std::cout << " New balance: " << balance << " $" << std::endl;
        }

        void displayInfo() {
            BankAccount::displayInfo();
            std::cout << "Interest Rate: " << (interestRate * 100) << "%" << std::endl;
            std::cout << "===========================" << std::endl;
        }

        double getInterestRate() const {
            return interestRate;
        }
};

class CheckingAccount : public BankAccount {
    private:
        double overdraftLimit; // Maximum nagative balance allowed 

    public:

        CheckingAccount(const std::string accNum, double initBalance, const std::string accHName, double overDraftLim)
                : BankAccount(accNum, initBalance, accHName),
                overdraftLimit(overDraftLim) {
                    if(overdraftLimit < 0) {
                        std::cout << "The overdraft limit cannot be negative" << std::endl;
                        overdraftLimit = 0;
                    }
                }

        void withdraw(double amount) override {
            std::cout << "=== Withdrawing from checking accout ===" << std::endl;
            std::cout << std::endl;

            if(balance - amount < -overdraftLimit) { // Balance(400) - ammount(700) = -300 and overdraft(200) so excedes by 100
                std::cout << "❌ Withdrawal DENIED!" << std::endl;
                std::cout << "   Requested: " << amount << "$" << std::endl;
                std::cout << "   Current balance: " << balance << "$" << std::endl;
                std::cout << "   Overdraft limit: " << overdraftLimit << "$" << std::endl;
                std::cout << "   Maximum withdrawal allowed: " << (balance + overdraftLimit) << "$" << std::endl;
                std::cout << std::endl;
                return;
            }

            std::cout << "Withdrawing $" << amount << " from account" << std::endl;
            balance -= amount;
            std::cout << "New balance: $" << balance << std::endl;
        
            if(balance < 0) {
                std::cout << "⚠️  Account in OVERDRAFT: $" << (-balance) << std::endl;
                std::cout << "   Remaining overdraft: $" << (overdraftLimit + balance) << std::endl;
            }
            std::cout << std::endl;
        }

        void displayInfo() {
            std::cout << "=== Checking Account Information ===" << std::endl;
            std::cout << "Account Number: " << accountNumber << std::endl;
            std::cout << "Account Holder: " << accountHolderName << std::endl;
            std::cout << "Balance: $" << balance << std::endl;
            std::cout << "Overdraft Limit: $" << overdraftLimit << std::endl;
        
            if(balance < 0) {
                std::cout << "⚠️  IN OVERDRAFT: $" << (-balance) << std::endl;
                std::cout << "Available credit: $" << (overdraftLimit + balance) << std::endl;
            } else {
                std::cout << "Available funds (with overdraft): $" << (balance + overdraftLimit) << std::endl;
            }
            std::cout << "====================================" << std::endl;
        }

        double getOverdraftLimit() const {
            return overdraftLimit;
        }

        void setOverdraftLimit(double newLimit) {
            if(newLimit >= 0) {
                overdraftLimit = newLimit;
                std::cout << "Overdraft limit updated to: $" << overdraftLimit << std::endl;
            } else {
                std::cout << "Invalid overdraft limit. Must be non-negative." << std::endl;
            }
        }
};

int main(void) {

    std::cout << "--- BANK ACCOUNT MANAGEMENT SYSTEM ---\n" << std::endl;

    BankAccount basic("BA001", 1000.0, "John Doe");
    SavingsAccount savings("SA001", 5000.0, "Alice Johnson", 0.05);
    CheckingAccount checking("CK001", 800.0, "Emma Davis", 300.0);

    std::cout << "\n--- Basic Account ---" << std::endl;
    basic.displayInfo();
    basic.deposit(500.0);
    basic.withdraw(300.0);
    std::cout << std::endl;

    std::cout << "--- Savings Account ---" << std::endl;
    savings.displayInfo();
    savings.deposit(1000.0);
    savings.addInterest();
    std::cout << std::endl;

    std::cout << "--- Checking Account ---" << std::endl;
    checking.displayInfo();
    checking.withdraw(900.0);  // Uses overdraft
    checking.withdraw(300.0);  // Should be denied
    checking.deposit(500.0);   // Recover from overdraft
    std::cout << std::endl;

    std::cout << "--- Polymorphism Demo ---" << std::endl;
    std::vector<BankAccount*> accounts;
    accounts.push_back(&basic);
    accounts.push_back(&savings);
    accounts.push_back(&checking);

    std::cout << "Withdrawing $50 from all accounts:\n" << std::endl;
    for(int i = 0; i < accounts.size(); i++) {
        accounts[i]->withdraw(50.0);
        std::cout << std::endl;
    }

    std::cout << "========================================\n" << std::endl;

    return 0;
}
