#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

class LibraryItem {
    protected:
        std::string title;
        int id;
        bool isCheckedOut;
        int daysOverdue;

    public:

        LibraryItem()
            : title("Unknown"), id(0), isCheckedOut(false), daysOverdue(0) {}

        LibraryItem(const std::string& title, int id)
            : title(title), id(id), isCheckedOut(false), daysOverdue(0) {}

        virtual ~LibraryItem() = default;

        virtual void displayInfo() const {
            std::cout << "\nItem Info\n";
            std::cout << "  Title:     " << title << "\n";
            std::cout << "  ID:        " << id << "\n";
            std::cout << "  Available: " << (isAvailable() ? "Yes" : "No") << "\n";
        }

        virtual double calculateLateFee() const {
            return daysOverdue * 0.30;
        }

        void checkout() {
            if (!isCheckedOut) {
                std::cout << "\nChecking out: " << title << "\n";
                isCheckedOut = true;
            } else {
                std::cout << "Item '" << title << "' is already checked out.\n";
            }
        }

        void returnItem() {
            if (isCheckedOut) {
                std::cout << "\nReturning: " << title << "\n";
                isCheckedOut = false;
            } else {
                std::cout << "Item '" << title << "' was not checked out.\n";
            }
        }

        bool isAvailable() const {
            return !isCheckedOut;
        }

        int getID() const {
            return id;
        }

        void setDaysOverdue(int days) {
            daysOverdue = days;
        }
};

class Book : public LibraryItem {
    private:
        std::string author;
        int pages;

    public:
        Book(const std::string& title, int id, const std::string& author, int pages)
            : LibraryItem(title, id), author(author), pages(pages) {}

        void displayInfo() const override {
            std::cout << "\nBook\n";
            std::cout << "  Title:     " << title << "\n";
            std::cout << "  Author:    " << author << "\n";
            std::cout << "  ID:        " << id << "\n";
            std::cout << "  Pages:     " << pages << "\n";
            std::cout << "  Available: " << (isAvailable() ? "Yes" : "No") << "\n";
        }

        double calculateLateFee() const override {
            return daysOverdue * 0.50;
        }
};

class Magazine : public LibraryItem {
    private:
        int issue_number;
        std::string month;

    public:
        Magazine(const std::string& title, int id, int iss_num, const std::string& month)
            : LibraryItem(title, id), issue_number(iss_num), month(month) {}

        void displayInfo() const override {
            std::cout << "\nMagazine\n";
            std::cout << "  Title:     " << title << "\n";
            std::cout << "  Issue:     " << issue_number << " (" << month << ")\n";
            std::cout << "  ID:        " << id << "\n";
            std::cout << "  Available: " << (isAvailable() ? "Yes" : "No") << "\n";
        }

        double calculateLateFee() const override {
            return daysOverdue * 0.25;
        }
};

class DVD : public LibraryItem {
    private:
        int durationMinutes;
        std::string director;

    public:
        DVD(const std::string& title, int id, int duration, const std::string& director)
            : LibraryItem(title, id), durationMinutes(duration), director(director) {}

        void displayInfo() const override {
            std::cout << "\nDVD\n";
            std::cout << "  Title:     " << title << "\n";
            std::cout << "  Director:  " << director << "\n";
            std::cout << "  Duration:  " << durationMinutes << " min\n";
            std::cout << "  ID:        " << id << "\n";
            std::cout << "  Available: " << (isAvailable() ? "Yes" : "No") << "\n";
        }

        double calculateLateFee() const override {
            return daysOverdue * 1.00;
        }
};

class Library {
    private:
        std::vector<LibraryItem*> items;

    public:
        // Add an already-created item
        void addItem(LibraryItem* item) {
            items.push_back(item);
        }

        // Interactive way to create and add items
        void addItemInteractive() {
            std::cout << "\nAdd Item\n";
            std::cout << "  1. Book\n";
            std::cout << "  2. Magazine\n";
            std::cout << "  3. DVD\n";
            std::cout << "Choose type (1-3): ";

            int choice = 0;
            if (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input.\n";
                return;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (choice == 1) {
                std::string title, author;
                int id, pages;
                std::cout << "  Title:  "; std::getline(std::cin, title);
                std::cout << "  ID:     "; std::cin >> id; std::cin.ignore();
                std::cout << "  Author: "; std::getline(std::cin, author);
                std::cout << "  Pages:  "; std::cin >> pages; std::cin.ignore();
                addItem(new Book(title, id, author, pages));
            } else if (choice == 2) {
                std::string title, month;
                int id, issue;
                std::cout << "  Title:        "; std::getline(std::cin, title);
                std::cout << "  ID:           "; std::cin >> id; std::cin.ignore();
                std::cout << "  Month:        "; std::getline(std::cin, month);
                std::cout << "  Issue number: "; std::cin >> issue; std::cin.ignore();
                addItem(new Magazine(title, id, issue, month));
            } else if (choice == 3) {
                std::string title, director;
                int id, duration;
                std::cout << "  Title:               "; std::getline(std::cin, title);
                std::cout << "  ID:                  "; std::cin >> id; std::cin.ignore();
                std::cout << "  Director:            "; std::getline(std::cin, director);
                std::cout << "  Duration in minutes: "; std::cin >> duration; std::cin.ignore();
                addItem(new DVD(title, id, duration, director));
            } else {
                std::cout << "Invalid choice.\n";
            }
        }

        void displayAllItems() const {
            if (items.empty()) {
                std::cout << "No items in the library.\n";
                return;
            }
            for (const auto* it : items) it->displayInfo();
        }

        void checkoutItemID(int id) {
            for (auto* it : items) {
                if (it->getID() == id) {
                    it->checkout();
                    return;
                }
            }
            std::cout << "Item with ID " << id << " not found.\n";
        }

        void returnItemID(int id, int daysLate) {
            for (auto* it : items) {
                if (it->getID() == id) {
                    it->returnItem();
                    it->setDaysOverdue(daysLate);
                    double fee = it->calculateLateFee();
                    std::cout << "Late fee: $" << fee << "\n";
                    return;
                }
            }
            std::cout << "Item with ID " << id << " not found.\n";
        }

        double getTotalLateFees() const {
            double total = 0.0;
            for (const auto* it : items) {
                total += it->calculateLateFee();
            }
            return total;
        }

        ~Library() {
            for (auto* it : items) delete it;
        }
};


class User {
    protected:
        std::vector<int> ids;
        std::string name;
        double fees;

    public:

        User()
            : name("Unknown"), fees(0.0) {}

        User(const std::string& name, double fees)
            : name(name), fees(fees) {}

        ~User() = default;

        void checkoutItem(int id) {
            ids.push_back(id);
        }

        void returnItem(int id) {
            ids.erase(std::remove(ids.begin(), ids.end(), id), ids.end());
        }

        void setFees(double new_fees) {
            fees = new_fees;
        }
};

int main() {
    
    Library lib;
    User client;

    Book* Montecristo = new Book("Conte di Monte Cristo", 4521, "Andre` Dumas", 1436);
    Book* TheHoundOfTheBaskervilles = new Book("The Hound of the Baskervilles", 5732, "Sir Arthur Conan Doyle", 256);
    Magazine* LaManoRossa = new Magazine("Tex Willer, La mano rossa", 8234, 1, "November");
    Magazine* LaCittaCorotta = new Magazine("Tex Willer, La citta corotta", 9234, 322, "September");
    DVD* IronMan = new DVD("Iron Man", 8342, 126, "Jon Favreau");

    // Default items
    lib.addItem(Montecristo);
    lib.addItem(TheHoundOfTheBaskervilles);
    lib.addItem(LaManoRossa);
    lib.addItem(LaCittaCorotta);
    lib.addItem(IronMan);

    int choice = 0;

    while(true) {
        std::cout << "\nLibrary Menu\n";
        std::cout << "  1. Add new item\n";
        std::cout << "  2. Display all items\n";
        std::cout << "  3. Checkout an item\n";
        std::cout << "  4. Return an item\n";
        std::cout << "  5. Get all late fees\n";
        std::cout << "  6. Exit\n";
        std::cout << "Choose option: ";
        std::cin >> choice; std::cin.ignore();

        switch(choice) {
            case 1: {
                    lib.addItemInteractive();
                    break;
                }
            case 2: {
                    lib.displayAllItems();
                    break;
                }
            case 3: {
                    int id;
                    std::cout << "Enter ID to check out: ";
                    std::cin >> id; std::cin.ignore();
                    lib.checkoutItemID(id);
                    client.checkoutItem(id);
                    break;
                }
            case 4: {
                    int id, daysLate;
                    std::cout << "Enter ID to return: ";
                    std::cin >> id; std::cin.ignore();
                    std::cout << "Days late: ";
                    std::cin >> daysLate; std::cin.ignore();
                    lib.returnItemID(id, daysLate);
                    client.returnItem(id);
                    break;
                }
            case 5: {
                    double fees = lib.getTotalLateFees();
                    std::cout << "Total late fees: $" << fees << "\n";
                    client.setFees(fees);
                    break;
                }
            case 6: {
                    std::cout << "Exiting...\n";
                    exit(0);
                }
        }
    }
    
}
