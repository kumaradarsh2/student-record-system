#include <iostream>
#include <cstdlib> // For std::system()
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

// Adding an Input validation function
// This function re-prompts the user to enter the valid integer until the user keeps entering invalid input (like "String")
int getValidatedInt(const std::string& prompt) {
    int num;
    while (true) {
        std::cout << prompt;
        std::cin >> num;

        if (std::cin.fail()) {
            std::cin.clear(); // clear failbit
            std::cin.ignore(1000, '\n'); // discard input buffer
            std::system("clear");
            std::cout << "Invalid Input. Please enter a number.\n\n";
        }
        else {
            std::cin.ignore(1000, '\n'); // flush remaining buffer
            return num;
        }
    }
}


// This is the array containing elements of user-defined data type (eg. Student in this case)
std::vector<Student> studentList;

// Function to add students to studentList
void addStudent() {
    // creating a student object
    Student obj;

    // std::cout << "Enter your id: ";
    // std::cin >> obj.id;
    obj.id = getValidatedInt("Enter your id: ");

    // std::cin.ignore(); // flush leftover newline
    std::cout << "Enter your name: ";
    // std::cin >> obj.name;
    // use std::getline instead
    std::getline(std::cin, obj.name);

    obj.age = getValidatedInt("Enter your age: ");
    
    // std::cin.ignore();  // this is unnecessary here cause getValidatedInt function already consumes the newline
    std::cout << "Enter your branch: ";
    std::getline(std::cin, obj.branch);

    std::cout << "Enter your marks" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::string prompt = "Enter subject " + std::to_string(i + 1) + ": ";
        obj.marks[i] = getValidatedInt(prompt);
    }

    studentList.push_back(obj);

    std::system("clear"); // clearing before going to next window

    std::cout << obj.name << " has been added." << std::endl;   
}

void viewStudent() {
    // displays all the students
    std::cout << "\nDisplaying Students Ids\n" << std::endl;
    for (Student elem : studentList) {
        std::cout << elem << std::endl;
    }
}

void searchStudent() {
    // searches all the students
    int searchId = getValidatedInt("Enter the id: ");

    bool found = false;
    // loop through the list and print if found
    for (auto elem : studentList) {
        if (elem.id == searchId) {
            found = true;
            std::cout << elem << std::endl;
            // breaks out of loop after search is done
            break;
        }
    }

    if (!found) std::cout << "Student not found" << std::endl;
}

void modifyStudent() {
    // modifies all the students
    int searchId = getValidatedInt("Enter the id: ");

    bool found = false;

    // loop through the list and print if found

    // Note: ranged for loop provides a way to iterate through a container but it gives "copy" of each element
    // If we wanna modify original elements of container, we use "Reference" (auto&) or a "Pointer" (auto*) in Loop Declaration
    for (auto& elem : studentList) {
        if (elem.id == searchId) {
            found = true;
            // ask to modify
            std::cout << "What do you want to modify? \n";
            std::cout << "1. Name" << std::endl;
            std::cout << "2. Age" << std::endl;
            std::cout << "3. Branch" << std::endl;
            std::cout << "4. Marks" << std::endl;
            // std::cout << "5. Modify all files" << std::endl;

            int modify;
            std::cin >> modify;
            
            switch (modify) {
                case 1: 
                    std::cin.ignore(); // flush leftover newline
                    std::cout << "Enter your name: ";
                    std::getline(std::cin, elem.name);
                    std::cout << "Name has been modified" << std::endl;
                    break;
                case 2:
                    elem.age = getValidatedInt("Enter your age: ");
                    std::cout << "Age has been modified" << std::endl;
                    break;
                case 3: 
                    std::cin.ignore(); 
                    std::cout << "Enter your branch: ";
                    std::getline(std::cin, elem.branch);
                    std::cout << "Branch has been modified" << std::endl;
                    break;
                case 4: 
                    std::cout << "Enter your marks" << std::endl;
                    for (int i = 0; i < 3; ++i) {
                        std::string prompt = "Enter subject " + std::to_string(i + 1) + ": ";
                        elem.marks[i] = getValidatedInt(prompt);
                    }
                    std::cout << "Marks have been modified" << std::endl;
                    break;

                default: std::cout << "Invalid input" << std::endl;
            }

            break;
        }   
    }

    if (!found) std::cout << "Student not found" << std::endl;
}

void deleteStudent() {
    // deletes a student
    int searchId = getValidatedInt("Enter the id: ");

    bool validId = false;
    
    // Using traditional for loop to delete the element
    for (size_t i = 0; i < studentList.size(); ++i) {
        if (studentList[i].id == searchId) {
            validId = true;
            studentList.erase(studentList.begin() + i);
            std::cout << "Student deleted.\n";
            return; // exits function after student is deleted
        } 
    }

    if (!validId) std::cout << "Invalid ID" << std::endl;
}

void userChoice(int choice) {
    switch(choice) {
        case 1: addStudent(); break;
        case 2: viewStudent(); break;
        case 3: searchStudent(); break;
        case 4: modifyStudent(); break;
        case 5: deleteStudent(); break;
        case 6: exit(0); break;
        default: std::cout << "Invalid choice.\n";
    }
}   

int main() {
    int choice;

    do {
        // do-while loop to run the program until user chooses to exit
        std::system("clear");

        std::cout << "Student Record System\n" << std::endl;

        displayStudent();
        std::cout << "Enter choice: ";
        std::cin >> choice;

        // Clear the screen after taking choice from the user
        std::system("clear");

        if (choice >=1 && choice <= 5) {
            userChoice(choice);
        }
        else if (choice == 6) {
            std::cout << "Exiting the program...\n";
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }

        if (choice != 6) {
            std::cout << "\nPress enter to go back to menu...";
            std::cin.ignore();
            std::cin.get(); // wait for enter key
        }

    } while (choice != 6);

    return 0;
}