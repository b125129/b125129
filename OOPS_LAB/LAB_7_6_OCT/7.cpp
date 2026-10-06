#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n = "Vedantu", int a = 90) : name(n), age(a) {}
};

// Virtual inheritance avoids multiple copies of Person
class Student : virtual public Person {
protected:
    int rollNo;
    double cgpa;

public:
    Student(string n, int a, int r, double c) 
        : Person(n, a), rollNo(r), cgpa(c) {}
};

class Employee : virtual public Person {
protected:
    string employeeID;
    double salary;

public:
    Employee(string n, int a, string empId, double sal) 
        : Person(n, a), employeeID(empId), salary(sal) {}
};

class TeachingAssistant : public Student, public Employee {
public:
    TeachingAssistant(string n, int a, int r, double c, string empId, double sal) 
        : Person(n, a), Student(n, a, r, c), Employee(n, a, empId, sal) {}

    void displayInfo() {
        cout << "\n--- Teaching Assistant Details ---" << endl;
        cout << "Name: " << name << endl;           // Direct single access
        cout << "Age: " << age << endl;             // Direct single access
        cout << "Roll No: " << rollNo << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    TeachingAssistant ta("Emma Watson", 24, 201, 3.92, "TA998", 25000);
    ta.displayInfo();
    return 0;
}