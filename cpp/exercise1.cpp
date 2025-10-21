#include <iostream>

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double calculateArea() const {
        return width * height;
    }

    double calculatePerimeter() const {
        return 2 * (width + height);
    }

    void display(int id) const {
        std::cout << "Rectangle " << id << ": Width=" << width
                  << ", Height=" << height
                  << ", Area=" << calculateArea()
                  << ", Perimeter=" << calculatePerimeter()
                  << std::endl;
    }
};

int main() {
    Rectangle rectangle1(6, 9);
    Rectangle rectangle2(2, 31);

    rectangle1.display(1);
    rectangle2.display(2);

    return 0;
}
