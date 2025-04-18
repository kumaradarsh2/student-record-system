#include <iostream>
#include <string>
#include <vector>

// Class name should be PascalCase, variables camelCase
class Student {
public:
    int id;
    std::string name;
    int age;
    std::string branch;
    int marks[3];
};

// Need to Research this later
std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << "Id : " << s.id << "\n";
    os << "Name: " << s.name << "\n";
    os << "Age: " << s.age << "\n";
    os << "Branch: " << s.branch << "\n";
    os << "Marks: ";
    for (int i = 0; i < 3; ++i) {
        os << s.marks[i] << " ";
    }
    os << "\n";
    return os;
}

void displayStudent() {
    std::cout << "1.Add a student" << std::endl;
    std::cout << "2.View all Students" << std::endl;
    std::cout << "3.Search Student" << std::endl;
    std::cout << "4.Modify Student" << std::endl;
    std::cout << "5.Delete Student" << std::endl;
    std::cout << "6.Exit" << std::endl;
}

std::vector<Student> studentList;

void addStudent() {
    // adds student
    // creating an student object
    Student obj;

    std::cout << "Enter your id: ";
    std::cin >> obj.id;

    std::cin.ignore(); // flush leftover newline
    std::cout << "Enter your name: ";
    // std::cin >> obj.name;
    // use std::getline instead
    std::getline(std::cin, obj.name);

    std::cout << "Enter your age: ";
    std::cin >> obj.age;

    std::cout << "Enter your branch: ";
    std::cin >> obj.branch;

    std::cout << "Enter your marks" << std::endl;;
    for (int i = 0; i < 3; ++i) {
        std::cout << "Enter subject " << i + 1 << ": ";
        std::cin >> obj.marks[i];
    }

    studentList.push_back(obj);
}

void viewStudent() {
    // displays all the students
    for (Student elem : studentList) {
        std::cout << elem << std::endl;
    }
}

void searchStudent() {
    // searches all the students
    int searchId;
    std::cout << "Enter the id: ";
    std::cin >> searchId;

    // loop through the list and print if found
    for (auto elem : studentList) {
        if (elem.id == searchId) {
            std::cout << elem << std::endl;
            // breaks out of loop after search is done
            break;
        }
    }
}

void modifyStudent() {
    // modifies all the students
    int searchId;
    std::cout << "Enter the id: ";
    std::cin >> searchId;

    // loop through the list and print if found
    for (auto elem : studentList) {
        if (elem.id == searchId) {
            // ask to modify
            std::cout << "What do you want to modify? \n";
            break;
        }
    }
}

void deleteStudent() {
    // deletes a student
    int searchId;
    std::cout << "Enter the id: ";
    std::cin >> searchId;

    // Using traditional for loop to delete the element
    for (size_t i = 0; i < studentList.size(); ++i) {
        if (studentList[i].id == searchId) {
            studentList.erase(studentList.begin() + i);
            std::cout << "Student deleted.\n";
            return; // exits function after student is deleted
        } 
    }
}

int exitProgram() {
    // exits the program
    return 0;
}

int main() {
    int choice;

    // do-while loop to run the program until user chooses to exit
    do {
        displayStudent();
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1: addStudent(); break;
            case 2: viewStudent(); break;
            case 3: searchStudent(); break;
            case 4: modifyStudent(); break;
            case 5: deleteStudent(); break;
            case 6: exitProgram(); break;
            default: std::cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}