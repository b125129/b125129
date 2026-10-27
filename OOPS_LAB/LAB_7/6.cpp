#include <iostream>
using namespace std;

class InternalExam {
public:
    void display() {
        cout << "Internal Exam " <<endl;
    }
};

class ExternalExam {
public:
    void display() {
        cout << "External Exam" << endl;
    }
};

class FinalResult : public InternalExam, public ExternalExam {
public:
    void showDetails() {
        // Resolving ambiguity using scope resolution operator
        InternalExam::display();
        ExternalExam::display();
    }
};

int main() {
    FinalResult result;
    result.showDetails();
    return 0;
}