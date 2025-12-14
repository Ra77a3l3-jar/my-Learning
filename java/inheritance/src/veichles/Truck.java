package vehicles;

public class Truck extends Veichle implements Rentable {

    private double loadCapacity;
    private boolean available;
    private static final double MAX_SPEED = 120.0;
    private static final double DAILY_RATE = 80.0;
    
    public Truck(String brand, String model, int year, double loadCapacity) {
        super(brand, model, year);
        this.loadCapacity = loadCapacity;
        this.available = true;
    }
    
    // Implement abstract methods from Vehicle
    @Override
    public void accelerate() {
        if (currentSpeed < MAX_SPEED) {
            currentSpeed += 5; 
            if (currentSpeed > MAX_SPEED) {
                currentSpeed = MAX_SPEED;
            }
            System.out.println(brand + " " + model + " accelerating to " + currentSpeed + " km/h");
        } else {
            System.out.println("Already at maximum speed!");
        }
    }
    
    @Override
    public void brake() {
        if (currentSpeed > 0) {
            currentSpeed -= 10; 
            if (currentSpeed < 0) {
                currentSpeed = 0;
            }
            System.out.println(brand + " " + model + " braking to " + currentSpeed + " km/h");
        } else {
            System.out.println("Already stopped!");
        }
    }
    
    @Override
    public double getMaxSpeed() {
        return MAX_SPEED;
    }
    
    // Implement Rentable methods
    @Override
    public double calculateRentalCost(int days) {
        double cost = days * DAILY_RATE;
        if (loadCapacity > 5000) {
            cost += days * 20;
        }
        return cost;
    }
    
    @Override
    public boolean isAvailable() {
        return available;
    }
    
    @Override
    public void rent() {
        if (available) {
            available = false;
            System.out.println("Truck rented successfully: " + brand + " " + model);
        } else {
            System.out.println("Truck is not available for rent.");
        }
    }
    
    @Override
    public void returnVehicle() {
        available = true;
        currentSpeed = 0;
        System.out.println("Truck returned: " + brand + " " + model);
    }
    
    public double getLoadCapacity() {
        return loadCapacity;
    }
}
