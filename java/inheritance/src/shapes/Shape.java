package shapes;

public abstract class Shape implements Comparable<Shape> {

    protected String color;

    public Shape(String color) {
        this.color = color;
    }

    // Abstract methods - subclasses implement them
    public abstract double getArea();
    public abstract double getPerimeter();

    // Concrete method
    public void printInfo() {
        System.out.println("\n----Shape Info----");
        System.out.println(" Color : " + color);
        System.out.println(" Area : " + getArea());
        System.out.println(" Perimeter : " + getPerimeter());
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    // Implement comparable interface
    @Override
    public int compareTo(Shape shape) {
        if(this.getArea() < shape.getArea()) {
            return -1;
        } else if(this.getArea() > shape.getArea()) {
            return 1;
        } else {
            return 0;
        }
    }
}
