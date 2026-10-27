#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    double totalMarks;
public:
    Student(string n, double m) : name(n), totalMarks(m) {}

    bool operator>(const Student& s) const {
        return totalMarks > s.totalMarks;
    }
    void display(){
        cout<< "Name: " << name<<"Marks: "<< totalMarks<<endl;
    }
    string getName() const { return name; }
};

int main() {
    Student s1("Alice", 450);
    Student s2("Bob", 480);
    s1.display();
    s2.display();
    if (s1 > s2) {
        cout << s1.getName() << " has higher marks." << endl;
    } else {
        cout << s2.getName() << " has higher marks." << endl;
    }
    return 0;
}
