package vehicles;

public class Motorcycle extends Veichle implements Rentable {

    private int engineCapacity;
    private boolean available;
    private static final double MAX_SPEED = 180.0;
    private static final double DAILY_RATE = 35.0;
    
    public Motorcycle(String brand, String model, int year, int engineCapacity) {
        super(brand, model, year);
        this.engineCapacity = engineCapacity;
        this.available = true;
    }
    
    // Implement abstract methods from Vehicle
    @Override
    public void accelerate() {
        if (currentSpeed < MAX_SPEED) {
            currentSpeed += 15; 
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
            currentSpeed -= 20; 
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
        if (engineCapacity > 500) {
            cost += days * 15;
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
            System.out.println("Motorcycle rented successfully: " + brand + " " + model);
        } else {
            System.out.println("Motorcycle is not available for rent.");
        }
    }
    
    @Override
    public void returnVehicle() {
        available = true;
        currentSpeed = 0;
        System.out.println("Motorcycle returned: " + brand + " " + model);
    }
    
    public int getEngineCapacity() {
        return engineCapacity;
    }
}
