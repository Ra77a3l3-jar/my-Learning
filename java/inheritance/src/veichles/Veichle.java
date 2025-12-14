package vehicles;

public abstract class Veichle {

    protected String brand;
    protected String model;
    protected int year;
    protected double currentSpeed;
    
    public Veichle(String brand, String model, int year) {
        this.brand = brand;
        this.model = model;
        this.year = year;
        this.currentSpeed = 0.0;
    }
    
    // Abstract methods - subclasses implement
    public abstract void accelerate();
    public abstract void brake();
    public abstract double getMaxSpeed();
    
    // Concrete methods
    public String getInfo() {
        return year + " " + brand + " " + model + 
               " (Current Speed: " + currentSpeed + " km/h, Max Speed: " + getMaxSpeed() + " km/h)";
    }
    
    public boolean isMoving() {
        return currentSpeed > 0;
    }
    
    public String getBrand() {
        return brand;
    }
    
    public String getModel() {
        return model;
    }
    
    public int getYear() {
        return year;
    }
    
    public double getCurrentSpeed() {
        return currentSpeed;
    }
    
    public void setCurrentSpeed(double speed) {
        if (speed <= getMaxSpeed() && speed >= 0) {
            this.currentSpeed = speed;
        }
    }
}
