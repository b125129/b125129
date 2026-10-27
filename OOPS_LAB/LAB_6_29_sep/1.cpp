#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    int inches;
public:
    Distance(int f = 0, int i = 0) : feet(f), inches(i) {
        feet += inches / 12;
        inches %= 12;
    }

    Distance operator+(const Distance& d) const {
        int totalFeet = feet + d.feet;
        int totalInches = inches + d.inches;
        return Distance(totalFeet, totalInches);
    }

    void display() const {
        cout << feet << " feet " << inches << " inches" << endl;
    }
};

int main() {
    Distance d1(5, 8);
    Distance d2(3, 7);
    Distance result = d1 + d2;
    
    cout << "Distance 1: "; d1.display();
    cout << "Distance 2: "; d2.display();
    cout << "Result: "; result.display();
    return 0;
}