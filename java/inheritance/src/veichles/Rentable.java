package vehicles;

public interface Rentable {
    double calculateRentalCost(int days);
    boolean isAvailable();
    void rent();
    void returnVehicle();
}
