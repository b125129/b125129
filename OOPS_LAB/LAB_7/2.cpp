#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    int rollNo;

public:
    Student(string n, int r) : name(n), rollNo(r) {}

    virtual void displayDetails() const = 0;
    virtual void calculateResult() = 0;

    virtual ~Student() = default;
};

class RegularStudent : public Student {
private:
    double marks1, marks2, marks3;

public:
    RegularStudent(string n, int r, double m1, double m2, double m3)
        : Student(n, r), marks1(m1), marks2(m2), marks3(m3) {}

    void displayDetails() const override {
        cout << "\n--- Regular Student Details ---" << endl;
        cout << "Name: " << name << " | Roll No: " << rollNo << endl;
        cout << "Marks: " << marks1 << ", " << marks2 << ", " << marks3 << endl;
    }

    void calculateResult() override {
        double total = marks1 + marks2 + marks3;
        cout << "\n--- Regular Student Result ---" << endl;
        cout << "Total Marks: " << total << endl;
    }
};

class ScholarshipStudent : public Student {
private:
    double marks1, marks2, marks3;

public:
    ScholarshipStudent(string n, int r, double m1, double m2, double m3)
        : Student(n, r), marks1(m1), marks2(m2), marks3(m3) {}

    void displayDetails() const override {
        cout << "\n--- Scholarship Student Details ---" << endl;
        cout << "Name: " << name << " | Roll No: " << rollNo << endl;
        cout << "Marks: " << marks1 << ", " << marks2 << ", " << marks3 << endl;
    }

    void calculateResult() override {
        double total = marks1 + marks2 + marks3 + 5;
        cout << "\n--- Scholarship Student Result ---" << endl;
        cout << "Total Marks (including 5 bonus marks): " << total << endl;
    }
};

int main() {
    RegularStudent s1("Bob", 101, 80, 75, 85);
    ScholarshipStudent s2("Charlie", 102, 80, 75, 85);

    // Show both students' details before calculating either result
    s1.displayDetails();
    s2.displayDetails();

    s1.calculateResult();
    s2.calculateResult();

    return 0;
}

