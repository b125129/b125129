#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    int numSubjects;
    float* marks; // Pointer to dynamic array

public:
    Student() : rollNumber(0), numSubjects(0), marks(nullptr) {}

    void acceptDetails() {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Name: ";
        cin>>name;
        cout << "Enter Number of Subjects: ";
        cin >> numSubjects;

        // Dynamic memory allocation inside class
        marks = new float[numSubjects];

        cout << "Enter marks for " << numSubjects << " subjects:" << endl;
        for (int i = 0; i < numSubjects; i++) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    void displayResult() const {
        float total = 0;
        for (int i = 0; i < numSubjects; i++) {
            total += marks[i];
        }
        float average = (numSubjects > 0) ? (total / numSubjects) : 0;

        cout << "\n--- Student Report ---" << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name       : " << name << endl;
        cout << "Marks      : ";
        for (int i = 0; i < numSubjects; i++) {
            cout << marks[i] << " ";
        }
        cout << "\nTotal Marks: " << total << endl;
        cout << "Average    : " << average << endl;
    }

    // Destructor to release dynamically allocated memory
    ~Student() {
        delete[] marks;
    }
};

int main() {
    Student student;
    student.acceptDetails();
    student.displayResult();

    return 0;
}