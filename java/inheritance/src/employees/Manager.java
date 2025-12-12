package employees;

import java.awt.print.Book;

public class Manager extends FullTImeEmployee {

    private int teamSize;

    public Manager(String name, int id, double baseSalary, double bonus, int teamSize) {
        super(name, id, baseSalary, bonus);
        this.teamSize = teamSize;
    }

    // Override the abstract method implemented in the Full time employee
    @Override
    public double calculateSalary() {
        double teamBonusPercentage = teamSize * 0.02; // 2% per team member
        double teamBonus = teamBonusPercentage + baseSalary;
        return baseSalary + bonus + teamBonus;
    }

    public int getTeamSize() {
        return teamSize;
    }
}
