#include <iostream>
#include <vector>
#include <string>


class LibraryItem {
    protected:
        std::string title;
        int id;
        bool isCheckedOut;
        int daysOverdue;

    public:

        LibraryItem() {
            title = "Unknown";
            id = 0;
            isCheckedOut = false;
            daysOverdue = 0;
        }

        LibraryItem(std::string title, int id) :
            title(title), id(id) {}

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
            return daysOverdue * 0.30;
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

        std::string getTitle() const {
            return title;
        }
};

class Book : public LibraryItem {
    private:
        std::string author;
        int pages;

        public:
            Book(std::string title, int id, std::string author, int pages) :
                LibraryItem(title, id),
                author(author), pages(pages) {}

            void displayInfo() const override {
                std::cout << "\n=== Book Info ===\n" << std::endl;
                std::cout << "  The title is " << title << " and the author is " << author << std::endl;
                std::cout << "  The books id is " << id << std::endl;
                std::cout << "  The books is " << pages << " long" << std::endl;
                if(isCheckedOut) {
                    std::cout << "  The book is not avaible" << std::endl;
                } else {
                    std::cout << "  The book is avaible right now" << std::endl;
                }    
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

        Magazine(std::string title, int id, int iss_num, std::string month) :
            LibraryItem(title, id),
            issue_number(iss_num), month(month) {}
        
        double calculateLateFee() const override {
            return daysOverdue * 0.25;
        }
};

class DVD : public LibraryItem {
    private:
        int durationMinutes;
        std::string director;

    public:

        DVD(std::string title, int id, int duration, std::string director) :
            LibraryItem(title, id),
            durationMinutes(duration), director(director) {}

        double calculateLateFee() const override {
            return daysOverdue * 1.00;
        }
};

class Library {
    private:
        std::vector<LibraryItem*> items;

    public:

        void addItem(LibraryItem* item) {
            /* TODO implement a window to choose wich item do we want to create (Librarie Item, Magazine, Book or a DVD) */ 
        }

        void displayAllItems() const {
            for(int i = 0; i < items.size(); i++) {
                items[i]->displayInfo();
            }
        }

        void checkoutItemID(int id) {
            for(int i = 0; i < items.size(); i++) {
                if(items[i]->getID() == id) {
                    items[i]->checkout();    
                }
            }
        }

        void checkoutItemTitle(std::string title) {
            for(int i = 0; i < items.size(); i++) {
                if(items[i]->getTitle() == title) {
                    items[i]->checkout();
                }
            }
        }
};

int main(void) {
    
}
