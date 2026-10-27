#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;

public:
    Person(string n) : name(n) {
        cout << "Person constructor executed." << endl;
    }
};

class Employee : public Person {
protected:
    int employeeID;

public:
    Employee(string n, int id) : Person(n), employeeID(id) {
        cout << "Employee constructor executed." << endl;
    }
};

class Manager : public Employee {
private:
    string department;

public:
    Manager(string n, int id, string dept) 
        : Employee(n, id), department(dept) {
        cout << "Manager constructor executed." << endl;
    }

    void displayData() {
        cout << "\n--- Manager Info ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Department: " << department << endl;
    }
};

int main() {
    cout << "Creating Manager object...\n" << endl;
    Manager mgr("Grace Hopper", 501, "Research & Development");
    mgr.displayData();
    return 0;
}