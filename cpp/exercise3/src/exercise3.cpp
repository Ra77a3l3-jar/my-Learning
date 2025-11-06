#include <iostream>
#include <vector>
#include <string>

class Student {
    private:
        std::string name;
        int ID;
        std::vector<double> grades;

    public:

        Student(const std::string& n, int i, const std::vector<double>& g) : name(n), ID(i), grades(g) {}

        void addGrade(double grade) {
            if (grade >= 0 && grade <= 100) {
                grades.push_back(grade);
            } else {
                std::cout << "Invalid grade: " << grade << std::endl;
            }
        }

        double calculateAverage() const {
            if (grades.empty()) return 0.0;
            double total = 0.0;
            for (double g : grades) {
                total += g;
            }
            return total / static_cast<double>(grades.size());
        }

        char getLetterGrade() const {
            double avg = calculateAverage();
            if (avg >= 90) return 'A';
            else if (avg >= 80) return 'B';
            else if (avg >= 70) return 'C';
            else if (avg >= 60) return 'D';
            else return 'F';
        }

        void displayReport() const {
            std::cout << "=== Student Report ===" << std::endl << std::endl;

            std::cout << "The students name is: " << name << std::endl;
            std::cout << "The students ID is: " << ID << std::endl;
            std::cout << "The students grades are: " << std::endl;
            for (size_t i = 0; i < grades.size(); ++i) {
                std::cout << grades[i];
                if (i + 1 < grades.size()) std::cout << ", ";
            }
            std::cout << std::endl;
            std::cout << "The students average grade is: " << calculateAverage() << std::endl;
            std::cout << "The letter grade is: " << getLetterGrade() << std::endl;
        }
          
};

int main(void) {

    std::vector<Student> students;

    for (int i = 0; i < 3; ++i) {
        std::cout << "=== Student Check-In ===" << std::endl;
        // Name input
        std::string name;
        std::cout << "Enter the students name:" << std::endl;
        std::getline(std::cin >> std::ws, name);
        // Id input
        int ID;
        std::cout << "Enter the students ID: " << std::endl;
        std::cin >> ID;
        // Input grades
        std::vector<double> grades;
        int numGrades = 0;
        std::cout << "How many grades would you like to add: " << std::endl;
        std::cin >> numGrades;
        for (int j = 0; j < numGrades; ++j) {
            double grade = 0;
            std::cout << "Enter the grade #" << j + 1 << " (0 - 100): " << std::endl;
            std::cin >> grade;
            grades.push_back(grade);
        }
        students.emplace_back(name, ID, grades);
    }

    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << "=== Student Check-out ===" << std::endl;
        int numGrade = 0;
        std::cout << "Enter how many new grades would you like to add: " << std::endl;
        std::cin >> numGrade;
        for (int j = 0; j < numGrade; ++j) {
            double grade = 0;
            std::cout << "Enter a new grade (0 - 100): " << std::endl;
            std::cin >> grade;
            students[i].addGrade(grade);
        }
        std::cout << std::endl;
        students[i].displayReport();
    }
    
    return 0;
}
