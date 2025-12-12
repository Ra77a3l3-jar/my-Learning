package shapes;

import shapes.Drawable;

public class Triangle extends Shape implements Drawable {

    private double base;
    private double height;
    private double side1;
    private double side2;
    private double side3;

    public Triangle(String color, double base, double height, double side1, double side2, double side3) {
        super(color);
        this.base = base;
        this.height = height;
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    // Implement shape abstract method
    @Override
    public double getArea() {
        return (base  * height) / 2;
    }

    public double getPerimeter() {
        return side1 + side2 + side3;
    }

    // Implement Drawable methods
    @Override
    public void draw() {
        System.out.println("Drawing a " + color + " triangle with a base " + base + " a height " + height);
    }

    @Override
    public String getDescription() {
        return "A " + color + " triangle with a base " + base + " a height " + height; 
    }

    public double getBase() {
        return base;
    }

    public double getHeight() {
        return height;
    }
}
