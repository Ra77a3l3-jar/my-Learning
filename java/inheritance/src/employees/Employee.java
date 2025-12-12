package employees;

public abstract class Employee {

    protected String name;
    protected int id;
    protected double baseSalary;

    public Employee(String name, int id, double baseSalary) {
        this.name = name;
        this.id = id;
        this.baseSalary = baseSalary;
    }

    // Abstract methods - subclasses implement them
    public abstract double calculateSalary();

    // Concrete methods
    public String getEmployeeInfo() {
        System.out.println("\n----Employee Info----");
        System.out.println(" Name : " + name);
        System.out.println(" Id : " + id);
        System.out.println(" Base salary : " + baseSalary);
    }

    public int getId() {
        return id;
    }

    public double getBaseSalary() {
        return baseSalary;
    }
}
