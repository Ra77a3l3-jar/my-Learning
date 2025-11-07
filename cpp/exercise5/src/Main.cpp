#include <iostream>
#include <vector>
#include <string>


class LibraryItem {
    protected:
        std::string title;
        int id;
        bool isCheckedOut;
        int dueDate;
        int daysOverdue;
        double dailyOverdueCost;

    public:

        LibraryItem() {
            title = "Unknown";
            id = 0;
            isCheckedOut = false;
            dueDate = 0;
            daysOverdue = 0;
            dailyOverdueCost = 0.0;
        }

        LibraryItem(std::string title, int id, bool check, int days, double cost) :
            title(title), id(id), isCheckedOut(check), dueDate(days), dailyOverdueCost(cost) {}

        virtual ~LibraryItem();

        virtual void displayInfo() const {
            std::cout << "\n=== Book Info ===\n" << std::endl;
            std::cout << "  The title is " << title << std::endl;
            std::cout << "  The books id is " << id << std::endl;
            if(isCheckedOut) {
                std::cout << "  The book is not avaible" << std::endl;
            } else {
                std::cout << "  The book is avaible right now" << std::endl;
            }
        }

        virtual double calculateLateFee() const {
            return daysOverdue * dailyOverdueCost;
        }

        void checkout() {
            std::cout << "\n=== Renting " << title << " ===\n" << std::endl;
            isCheckedOut = true;
        }

        void returnItem() {
            std::cout << "\n=== Returning " << title << " ===\n" << std::endl;
            isCheckedOut = false;
        }

        bool isAvaible() const {
            return isCheckedOut;
        }

        int getID() const {
            return id;
        }

        
};



int main(void) {
    
}
