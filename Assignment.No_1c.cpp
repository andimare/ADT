#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Define the Student structure
struct Student {
    string lastName;
    string firstName;
    double averageMarks;
};

// Define the Employee structure
struct Employee {
    string lastName;
    string firstName;
    double salary;
};

// Function to give a 10% raise to employees who have a corresponding student record with average marks > 60
void giveRaise(Employee employees[], int numEmployees, const Student students[], int numStudents) {
    for (int i = 0; i < numEmployees; ++i) {
        for (int j = 0; j < numStudents; ++j) {
            if (employees[i].lastName == students[j].lastName &&
                employees[i].firstName == students[j].firstName &&
                students[j].averageMarks > 60) {
                employees[i].salary *= 1.10; 
                break; 
	        }
	    }
	}
}

// Function to print employee records
void printEmployees(const Employee employees[], int numEmployees){
    for (int i = 0; i < numEmployees; ++i) {
        cout << setw(10) << employees[i].lastName << " "
                  << setw(10) << employees[i].firstName << " "
                  << setw(10) << fixed << setprecision(2) << employees[i].salary << endl;
    }
}

int main() {
    // Sample student records
    Student students[] = {
        {"Joseph", "Arimathea", 75.5},
        {"Smith", "Will", 82.3},
        {"Marley", "Bob", 59.0}
    };

    // Sample employee records
    Employee employees[] = {
        {"Judas", "Iscariot", 50000.0},
        {"Smith", "Will", 60000.0},
        {"Marley", "Alice", 55000.0}
    };

    int numStudents = sizeof(students) / sizeof(students[0]);
    int numEmployees = sizeof(employees) / sizeof(employees[0]);

    // Print employees before raise
    cout << "Employees before raise:" << endl;
    printEmployees(employees, numEmployees);

    // Apply raises
    giveRaise(employees, numEmployees, students, numStudents);

    // Print employees after raise
    cout << "\nEmployees after raise:" << endl;
    printEmployees(employees, numEmployees);

    return 0;
}

