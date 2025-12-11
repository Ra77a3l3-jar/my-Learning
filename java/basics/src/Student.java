import java.util.ArrayList;

public class Student {
    
    private int id;
    private String name;
    private ArrayList<Double> grades;

    public Student() {
        this.id = 0;
        this.name = "Unknown";
        this.grades = new ArrayList<Double>();
    }

    public Student(int id, String name) {
        this.id = id;
        this.name = name;
        this.grades = new ArrayList<Double>();
    }

    public String getName() { return name; }

    public void addGrade(double grade) {
        this.grades.add(grade);
    }

    public double averageGrade() {
        double sum = 0.0;

        for(double grade : grades) {
            sum += grade;
        }
        return grades.isEmpty() ? 0 : sum / grades.size();
    }

    public void getStudentInfo() {
        System.out.println("\n---------------------------------");
        System.out.println(" Name : " + name + ".");
        System.out.println(" Id : " + id + ".");
        System.out.println(" Grades : " + grades.toString() + " .");
        System.out.println("-----------------------------------\n");
    }
}
