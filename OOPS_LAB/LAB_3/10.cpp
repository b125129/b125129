#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int empID;
    string empName;
    double basicSalary;
    int numMonths;
    double* monthlyEarnings; // Dynamic array

public:
    Employee() : empID(0), basicSalary(0.0), numMonths(0), monthlyEarnings(nullptr) {}

    void acceptData() {
        cout << "Enter Employee ID: ";
        cin >> empID;
        cin.ignore();
        cout << "Enter Employee Name: ";
        getline(cin, empName);
        cout << "Enter Basic Salary: ";
        cin >> basicSalary;
        cout << "Enter number of months for analysis: ";
        cin >> numMonths;

        // Dynamic memory allocation
        monthlyEarnings = new double[numMonths];

        cout << "Enter earnings for " << numMonths << " months:" << endl;
        for (int i = 0; i < numMonths; i++) {
            cout << "Month " << i + 1 << ": ";
            cin >> monthlyEarnings[i];
        }
    }

    void analyzeSalary() const {
        if (numMonths <= 0) return;

        double total = 0.0;
        int maxMonthIndex = 0;

        for (int i = 0; i < numMonths; i++) {
            total += monthlyEarnings[i];
            if (monthlyEarnings[i] > monthlyEarnings[maxMonthIndex]) {
                maxMonthIndex = i;
            }
        }

        double average = total / numMonths;

        cout << "\n--- Salary Analysis Report ---" << endl;
        cout << "Employee ID   : " << empID << endl;
        cout << "Employee Name : " << empName << endl;
        cout << "Basic Salary  : $" << basicSalary << endl;
        cout << "Total Earnings: $" << total << endl;
        cout << "Average Monthly Earning: $" << average << endl;
        cout << "Highest Earning Month  : Month " << (maxMonthIndex + 1) 
             << " ($" << monthlyEarnings[maxMonthIndex] << ")" << endl;
    }

    // Destructor to deallocate memory
    ~Employee() {
        delete[] monthlyEarnings;
    }
};

int main() {
    Employee emp;
    emp.acceptData();
    emp.analyzeSalary();

    return 0;
}