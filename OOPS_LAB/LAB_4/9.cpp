#include <iostream>
#include <string>
using namespace std;

class Exam {
private:
    string studentName;
    string subject;
    double marks;
    double maxMarks;

public:
    Exam(string name, string sub, double m, double maxM) {
        studentName=name;
        subject=sub;
        marks=m;
        maxMarks=maxM;
    }

    friend class Result;
};

class Result {
public:
    double calculatePercentage(Exam& e) {
        return (e.marks / e.maxMarks) * 100.0;
    }

    void displayResult(Exam& e) {
        double percentage = calculatePercentage(e);
        cout << "--- Exam Result ---" << endl;
        cout << "Student Name: " << e.studentName << endl;
        cout << "Subject: " << e.subject << endl;
        cout << "Marks Obtained: " << e.marks << " / " << e.maxMarks << endl;
        cout << "Percentage: " << percentage << "%" << endl;

        if (percentage >= 40.0) {
            cout << "Final Status: Pass" << endl;
        } else {
            cout << "Final Status: Fail" << endl;
        }
    }
};

int main() {
    string studentName;
    string subject;
    double marks;
    double maxMarks;

    cout<<"Enter student name, subject name, marks and Maxmarks."<<endl;
    cin>>studentName>>subject>>marks>>maxMarks;

    Exam exam1(studentName,subject,marks,maxMarks);
    Result res;

    res.displayResult(exam1);
    return 0;
}
