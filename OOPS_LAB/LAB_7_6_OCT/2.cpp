#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    int rollNo;

public:
    Student(string n, int r) : name(n), rollNo(r) {}
    virtual void calculateResult() = 0; // Pure virtual function
};

class RegularStudent : public Student {
private:
    double marks1, marks2, marks3;

public:
    RegularStudent(string n, int r, double m1, double m2, double m3) 
        : Student(n, r), marks1(m1), marks2(m2), marks3(m3) {}

    void calculateResult() override {
        double total = marks1 + marks2 + marks3;
        cout << "\n--- Regular Student ---" << endl;
        cout << "Name: " << name << " | Roll No: " << rollNo << endl;
        cout << "Total Marks: " << total << endl;
    }
};

class ScholarshipStudent : public Student {
private:
    double marks1, marks2, marks3;

public:
    ScholarshipStudent(string n, int r, double m1, double m2, double m3) 
        : Student(n, r), marks1(m1), marks2(m2), marks3(m3) {}

    void calculateResult() override {
        double total = (marks1 + marks2 + marks3) + 5; // Adds 5 bonus marks
        cout << "\n--- Scholarship Student ---" << endl;
        cout << "Name: " << name << " | Roll No: " << rollNo << endl;
        cout << "Total Marks (incl. 5 bonus marks): " << total << endl;
    }
};

int main() {
    RegularStudent s1("Bob", 101, 80, 75, 85);
    ScholarshipStudent s2("Charlie", 102, 80, 75, 85);

    s1.calculateResult();
    s2.calculateResult();

    return 0;
}
