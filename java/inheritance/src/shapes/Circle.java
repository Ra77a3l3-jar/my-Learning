package shapes;

import shapes.Drawable;

public class Circle extends Shape implements Drawable {

    private double radius;

    public Circle(String color, double radius) {
        super(color); // Call parent constructor
        this.radius = radius;
    }

    // Implement shape abstract methods
    @Override
    public double getArea() {
        return Math.PI * radius * radius;
    }

    @Override
    public double getPerimeter() {
        return 2 * Math.PI * radius;
    }

    // Implement drawable methods
    @Override
    public void draw() {
        System.out.println("Drawing a " + color + " circle with radius " + radius);
    }

    @Override
    public String getDescription() {
        return "A" + color + " circle with radius " + radius;
    }

    public double getRadius() {
        return radius;
    }
}
