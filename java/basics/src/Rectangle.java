public class Rectangle {

    private double width;
    private double height;

    public Rectangle() {
        this.width = 1;
        this.height = 1;
    }

    public Rectangle(double length) {
        this.width = length;
        this.height = length;
    }

    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    public boolean isSquare() {
        return width == height;
    }

    public double getPerimeter() {
        return (width * 2) + (height * 2);
    }

    public double getArea() {
        return width * height;
    }

    public void setWidth(double width) {
        if(width > 0) { this.width = width; }
    }
    public double getWidth() { return width; }

    public void setHeight(double height) {
        if(height > 0) { this.height = height; }
    }
    public double getHeight() { return height; }

    public void getRectangleInfo() {
        System.out.println("\n--------------------------------");
        System.out.println(" Width is " + width + ".");
        System.out.println(" Height is " + height + ".");
        System.out.println(" Area is " + getArea() + ".");
        System.out.println(" Perimeter is " + getPerimeter() + ".");
        System.out.println(" Rectangle is squared ? " + isSquare() + ".");
        System.out.println("---------------------------------\n");
    }
}
