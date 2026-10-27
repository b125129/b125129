#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string employeeID;
    string name;

public:
    Employee(string id = "", string n = "") : employeeID(id), name(n) {}
};

class Developer : virtual public Employee {
protected:
    string programmingLanguage;

public:
    Developer(string id, string n, string lang) 
        : Employee(id, n), programmingLanguage(lang) {}
};

class Tester : virtual public Employee {
protected:
    string testingTool;

public:
    Tester(string id, string n, string tool) 
        : Employee(id, n), testingTool(tool) {}
};

class TechLead : public Developer, public Tester {
public:
    TechLead(string id, string n, string lang, string tool)
        : Employee(id, n), Developer(id, n, lang), Tester(id, n, tool) {}

    void displayDetails() {
        cout << "\n--- Tech Lead Details ---" << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Name: " << name << endl;
        cout << "Programming Language: " << programmingLanguage << endl;
        cout << "Testing Tool: " << testingTool << endl;
    }
};

int main() {
    TechLead lead("TL701", "Henry Ford", "C++", "Selenium");
    lead.displayDetails();
    return 0;
}