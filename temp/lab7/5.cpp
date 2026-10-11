#include <iostream>
#include <string>
using namespace std;

class Academic {
protected:
    double m1, m2, m3;

public:
    Academic(double a, double b, double c) : m1(a), m2(b), m3(c) {}
};

class Sports {
protected:
    double sportsMarks;

public:
    Sports(double s) : sportsMarks(s) {}
};

class StudentResult : public Academic, public Sports {

public:
    StudentResult(double a, double b, double c, double s) 
        : Academic(a, b, c), Sports(s){}

    void displayResult() {
        double total = m1 + m2 + m3 + sportsMarks;
        double average = total / 4;

        cout << "\n--- Performance Result ---" << endl;
        cout << "Academic Subject 1: " << m1 << endl;
        cout << "Academic Subject 2: " << m2 << endl;
        cout << "Academic Subject 3: " << m3 << endl;
        cout << "Sports Marks: " << sportsMarks << endl;
        cout << "Total Marks: " << total << endl;
        cout << "Average Marks: " << average << endl;
    }
};

int main() {
    StudentResult student(85, 90, 88, 95);
    student.displayResult();
    return 0;
}