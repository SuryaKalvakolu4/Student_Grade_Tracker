#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

struct Student {
    std::string name;
    std::vector<double> grades;
};

int main() {
    std::vector<Student> students;
    char choice;

    do {
        std::cout << "1. Add Student\n";
        std::cout << "2. Add Grade for Student\n";
        std::cout << "3. Calculate Average Grade\n";
        std::cout << "4. View Students and Grades\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case '1':
                {
                    Student newStudent;
                    std::cout << "Enter student name: ";
                    std::cin >> newStudent.name;
                    students.push_back(newStudent);
                }
                break;
            case '2':
                {
                    std::string studentName;
                    double grade;
                    std::cout << "Enter student name: ";
                    std::cin >> studentName;
                    bool found = false;
                    for (auto& student : students) {
                        if (student.name == studentName) {
                            std::cout << "Enter grade for " << studentName << ": ";
                            std::cin >> grade;
                            student.grades.push_back(grade);
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        std::cout << "Student not found!\n";
                    }
                }
                break;
            case '3':
                {
                    std::string studentName;
                    std::cout << "Enter student name: ";
                    std::cin >> studentName;
                    bool found = false;
                    for (const auto& student : students) {
                        if (student.name == studentName) {
                            double total = 0;
                            for (const auto& grade : student.grades) {
                                total += grade;
                            }
                            double average = total / student.grades.size();
                            std::cout << "Average grade for " << studentName << ": " << std::fixed << std::setprecision(2) << average << std::endl;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        std::cout << "Student not found!\n";
                    }
                }
                break;
            case '4':
                {
                    std::cout << "Students and Grades:\n";
                    for (const auto& student : students) {
                        std::cout << "Student: " << student.name << ", Grades: ";
                        for (const auto& grade : student.grades) {
                            std::cout << grade << " ";
                        }
                        std::cout << std::endl;
                    }
                }
                break;
            case '5':
                std::cout << "Exiting program...";
                break;
            default:
                std::cout << "Invalid choice!\n";
                break;
        }
    } while (choice != '5');

    return 0;
}

