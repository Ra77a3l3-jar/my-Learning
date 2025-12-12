package employees;

public class FullTImeEmployee extends Employee {

    private double bonus;

    public FullTImeEmployee(String name, int id, double baseSalary, double bonus) {
        super(name, id, baseSalary);
        this.bonus = bonus;
    }

    // Implement abstract methods from Employee
    @Override
    public double calculateSalary() {
        return baseSalary + bonus;
    }

    public double getBonus() {
        return bonus;
    }
}
