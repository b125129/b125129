#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    double basicSalary;

public:
    Employee(string n, double bs) : name(n), basicSalary(bs) {}
};

class Developer : public Employee {
protected:
    int experience;

public:
    Developer(string n, double bs, int exp) 
        : Employee(n, bs), experience(exp) {}
};

class SeniorDeveloper : public Developer {
private:
    double projectBonus;

public:
    SeniorDeveloper(string n, double bs, int exp, double pb) 
        : Developer(n, bs, exp), projectBonus(pb) {}

    void displaySalary() {
        double experienceBonus = 0.05 * basicSalary * experience;
        double finalSalary = basicSalary + experienceBonus + projectBonus;

        cout << "\n--- Senior Developer Details ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Experience: " << experience << " years" << endl;
        cout << "Experience Bonus: " << experienceBonus << endl;
        cout << "Project Bonus: " << projectBonus << endl;
        cout << "Final Salary: " << finalSalary << endl;
    }
};

int main() {
    SeniorDeveloper dev("Alice Smith", 50000, 5, 3000);
    dev.displaySalary();
    return 0;
}