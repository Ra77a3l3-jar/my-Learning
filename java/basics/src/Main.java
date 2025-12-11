import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        
        BankAccount[] bankAccounts = new BankAccount[3];

        for(int i = 0; i < bankAccounts.length; i++) {
            System.out.println("\n---------------------------------");
            System.out.print(" Enter the owners name : ");
            String name = cin.nextLine();
            System.out.print(" Enter the accounts number : ");
            String accountNumber = cin.nextLine();
            System.out.print(" Enter the accounts balance : ");
            double balance = cin.nextDouble();
            cin.nextLine();
            System.out.println("---------------------------------\n");
            bankAccounts[i] = new BankAccount(name, accountNumber, balance);
        }

        System.out.println("\n---Testing withdraw---");

        bankAccounts[0].withdraw(21.40);
        bankAccounts[1].withdraw(36.70);
        bankAccounts[2].withdraw(4853.21);

        for(int i = 0; i < bankAccounts.length; i++) {
            bankAccounts[i].getAccountInfo();
        }

        System.out.println("\n---Testing deposit---");

        bankAccounts[0].deposit(57.90);
        bankAccounts[1].deposit(71.48);
        bankAccounts[2].deposit(218.34);

        for(int i = 0; i < bankAccounts.length; i++) {
            bankAccounts[i].getAccountInfo();
        }

        Student[] students = new Student[5];

        for(int i = 0; i < students.length; i++) {
            System.out.println("\n------------------------------");
            System.out.print(" Enter the students name : ");
            String name = cin.nextLine();
            System.out.print(" Enter the students id : ");
            int id = cin.nextInt();
            cin.nextLine();

            students[i] = new Student(id, name);

            System.out.print(" Enter the number of grades : ");
            int numGrades = cin.nextInt();
            cin.nextLine();
            for(int j = 0; j < numGrades; j++) {
                System.out.print(" - Enter the grade " + j + " : ");
                double grade = cin.nextDouble();
                cin.nextLine();
                students[i].addGrade(grade);
            }
        }

        double bestAvrGrades = students[0].averageGrade();
        int studentIndex = 0;

        for(int i = 1; i < students.length; i++) {
            if(students[i].averageGrade() > bestAvrGrades) {
                bestAvrGrades = students[i].averageGrade();
                studentIndex = i;
            }
        }

        for(int i = 0; i < students.length; i++) {
            students[i].getStudentInfo();
        }

        System.out.println("\n-------------------------------------");
        System.out.println(" The student with the best average grades is " + students[studentIndex].getName() + ".");
        System.out.println(" Avr. Grade of " + bestAvrGrades + ".");
        System.out.println("-------------------------------------\n");

        Rectangle[] rectangles = new Rectangle[2];

        System.out.println("\n-----------------------------");
        System.out.print(" Enter the width of the first rectangle : ");
        double width1 = cin.nextDouble();
        System.out.print(" Enter the height of the first rectangle : ");
        double height1 = cin.nextDouble();
        System.out.println("-----------------------------\n");
        rectangles[0] = new Rectangle(width1, height1);

        System.out.println("\n-------------------------");
        System.out.print(" Enter the side of the rectangle : ");
        double length = cin.nextDouble();
        System.out.println("-------------------------\n");
        rectangles[1] = new Rectangle(length);

        for(int i = 0; i < rectangles.length; i++) {
            rectangles[i].getRectangleInfo();
        }
        cin.close();
    }
}
