package vehicles;

public class Car extends Veichle implements Rentable {

    private int numDoors;
    private String transmission;
    private boolean available;
    private static final double MAX_SPEED = 200.0;
    private static final double DAILY_RATE = 50.0;
    
    public Car(String brand, String model, int year, int numDoors, String transmission) {
        super(brand, model, year);
        this.numDoors = numDoors;
        this.transmission = transmission;
        this.available = true;
    }
    
    // Implement abstract methods from Vehicle
    @Override
    public void accelerate() {
        if (currentSpeed < MAX_SPEED) {
            currentSpeed += 10;
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
            currentSpeed -= 15;
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
        if (transmission.equalsIgnoreCase("automatic")) {
            cost += days * 10;
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
            System.out.println("Car rented successfully: " + brand + " " + model);
        } else {
            System.out.println("Car is not available for rent.");
        }
    }
    
    @Override
    public void returnVehicle() {
        available = true;
        currentSpeed = 0;
        System.out.println("Car returned: " + brand + " " + model);
    }
    
    public int getNumDoors() {
        return numDoors;
    }
    
    public String getTransmission() {
        return transmission;
    }
}
