#include <iostream>
#include <vector>
#include <string>
#include <limits>

class LibraryItem {
    protected:
        std::string title;
        int id;
        bool isCheckedOut;
        int daysOverdue;

    public:

        LibraryItem()
            : title("Unknown"), id(0), isCheckedOut(false), daysOverdue(0) {}

        LibraryItem(std::string title, int id)
            : title(std::move(title)), id(id), isCheckedOut(false), daysOverdue(0) {}

        virtual ~LibraryItem() {}

        virtual void displayInfo() const {
            std::cout << "\n=== Item Info ===\n";
            std::cout << "  Title: " << title << "\n";
            std::cout << "  ID: " << id << "\n";
            std::cout << "  Available: " << (isAvailable() ? "yes" : "no") << "\n";
        }

        virtual double calculateLateFee() const {
            return daysOverdue * 0.30;
        }

        void checkout() {
            if (!isCheckedOut) {
                std::cout << "\n=== Checking out: " << title << " ===\n";
                isCheckedOut = true;
            } else {
                std::cout << "Item '" << title << "' is already checked out.\n";
            }
        }

        void returnItem() {
            if (isCheckedOut) {
                std::cout << "\n=== Returning: " << title << " ===\n";
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
        Book(std::string title, int id, std::string author, int pages)
            : LibraryItem(std::move(title), id), author(std::move(author)), pages(pages) {}

        void displayInfo() const override {
            std::cout << "\n=== Book ===\n";
            std::cout << "  Title: " << title << "\n";
            std::cout << "  Author: " << author << "\n";
            std::cout << "  ID: " << id << "\n";
            std::cout << "  Pages: " << pages << "\n";
            std::cout << "  Available: " << (isAvailable() ? "yes" : "no") << "\n";
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
        Magazine(std::string title, int id, int iss_num, std::string month)
            : LibraryItem(std::move(title), id), issue_number(iss_num), month(std::move(month)) {}

        void displayInfo() const override {
            std::cout << "\n=== Magazine ===\n";
            std::cout << "  Title: " << title << "\n";
            std::cout << "  Issue: " << issue_number << " (" << month << ")\n";
            std::cout << "  ID: " << id << "\n";
            std::cout << "  Available: " << (isAvailable() ? "yes" : "no") << "\n";
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
        DVD(std::string title, int id, int duration, std::string director)
            : LibraryItem(std::move(title), id), durationMinutes(duration), director(std::move(director)) {}

        void displayInfo() const override {
            std::cout << "\n=== DVD ===\n";
            std::cout << "  Title: " << title << "\n";
            std::cout << "  Director: " << director << "\n";
            std::cout << "  Duration: " << durationMinutes << " min\n";
            std::cout << "  ID: " << id << "\n";
            std::cout << "  Available: " << (isAvailable() ? "yes" : "no") << "\n";
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
            std::cout << "\n=== Add Item ===\n";
            std::cout << "  1. Book\n  2. Magazine\n  3. DVD\n";
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
                std::cout << "Title: "; std::getline(std::cin, title);
                std::cout << "ID: "; std::cin >> id; std::cin.ignore();
                std::cout << "Author: "; std::getline(std::cin, author);
                std::cout << "Pages: "; std::cin >> pages; std::cin.ignore();
                addItem(new Book(title, id, author, pages));
            } else if (choice == 2) {
                std::string title, month;
                int id, issue;
                std::cout << "Title: "; std::getline(std::cin, title);
                std::cout << "ID: "; std::cin >> id; std::cin.ignore();
                std::cout << "Month: "; std::getline(std::cin, month);
                std::cout << "Issue number: "; std::cin >> issue; std::cin.ignore();
                addItem(new Magazine(title, id, issue, month));
            } else if (choice == 3) {
                std::string title, director;
                int id, duration;
                std::cout << "Title: "; std::getline(std::cin, title);
                std::cout << "ID: "; std::cin >> id; std::cin.ignore();
                std::cout << "Director: "; std::getline(std::cin, director);
                std::cout << "Duration in minutes: "; std::cin >> duration; std::cin.ignore();
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
            for (auto* it : items) it->displayInfo();
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
                    std::cout << "Late fee: " << fee << "\n";
                    return;
                }
            }
            std::cout << "Item with ID " << id << " not found.\n";
        }

        double getTotalLateFees() const {
            double total = 0.0;
            for (auto* it : items) {
                // assume daysOverdue is set only for returned items in this simple model
                total += it->calculateLateFee();
            }
            return total;
        }

        ~Library() {
            for (auto* it : items) delete it;
        }
};
