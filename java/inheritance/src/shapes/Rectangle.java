package shapes;

import shapes.Drawable;

public class Rectangle extends Shape implements Drawable {

    private double width;
    private double height;

    public Rectangle(String color, double width, double height) {
        super(color);
        this.width = width;
        this.height = height;
    }

    // Implement shape abstract methods
    @Override
    public double getArea() {
        return width * height;
    }

    @Override
    public double getPerimeter() {
        return (width * 2) + (height * 2);
    }

    // Implement drawable methods
    @Override
    public void draw() {
        System.out.println("Drawing a " + color + " rectangle with width " + width + " and height " + height);
    }

    @Override
    public String getDescription() {
        return "A " + color + " rectangle with width " + width + " and height " + height;
    }

    public double getWidth() {
        return width;
    }

    public double getHeight() {
        return height;
    }    
}
