#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int empID;
    string empName;
    double salary;

public:
    void input() {
        cout << "Enter Employee ID: ";
        cin >> empID;
        cout << "Enter Employee Name: ";
        cin>>empName;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void display()  {
        cout << "ID: " << empID << "\t Name: " << empName << "\tSalary: " << salary << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee* emp = new Employee[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Employee " << i + 1 << ":" << endl;
        emp[i].input();
    }

    cout << "\n--- All Employee Details ---" << endl;
    for (int i = 0; i < n; i++) {
        emp[i].display();
    }

    delete[] emp;
    emp = nullptr;

    return 0;
}