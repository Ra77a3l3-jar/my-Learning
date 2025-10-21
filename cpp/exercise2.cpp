#include <iostream>
#include <ostream>
#include <string>
#include <vector>

class Tablet {
    private:
        std::string brand;
        float price;
        float inches;

    public:

        Tablet(std::string b, float p, float i) : brand(b), price(p), inches(i) {}

        std::string getBrand() {
            return brand;
        }

        float getPrice() {
            return price;
        }

        float getInches() {
            return inches;
        }

        void setBrand(std::string newBrand) {
            brand = newBrand;
        }

        void setPrice(float newPrice) {
            price = newPrice;
        }

        void setInches(float newInches) {
            inches = newInches;
        }

        bool verifyBrandSamsung() {
            if(brand == "Samsung" || brand == "samsung" || brand == "SAMSUNG") {
                return true;
            }
            return false;
        }
};

int main(void) {

    std::vector<Tablet> tablets;

    for(int i = 0; i < 3; i++) {
        std::cout << "=== Info Tablet #" << i + 1 << " ===" << std::endl;

        std::string brand;
        std::cout << "Enter the brand: " << std::endl;
        std::cin >> brand;

        float price;
        std::cout << "Enter the price: " << std::endl;
        std::cin >> price;

        float inches;
        std::cout << "Enter the display inches: " << std::endl;
        std::cin >> inches;

        tablets.emplace_back(brand, price, inches);
    }

    int samsungCount = 0;

    for(int i = 0; i < tablets.size(); i++) {
        if(tablets[i].getInches() >= 10) {
            std::cout << "The tablet #" << i + 1 << " has a " << tablets[i].getInches() << " screen!" << std::endl;
        }
        if(tablets[i].verifyBrandSamsung()) {
            samsungCount++;
        }
    }
    if(samsungCount >= 2) {
        std::cout << "Two or more tablets are branded Samsung!" << std::endl;
    } else {
        std::cout << "Less than two tablets are branded Samsung!" << std::endl;
    }
    return 0;
}
