#include <iostream>
using namespace std;

class Temperature {
private:
    double celsius;
public:
    Temperature(double c = 0) : celsius(c) {}

    // Overload < operator
    bool operator<(const Temperature& t) const {
        return celsius < t.celsius;
    }

    // Overload > operator
    bool operator>(const Temperature& t) const {
        return celsius > t.celsius;
    }

    // Display function to show the temperature value
    void display() const {
        cout << celsius << " °C";
    }
};

int main() {
    Temperature t1(30.0);
    Temperature t2(30.0);

    cout << "Temperature 1: "; 
    t1.display(); 
    cout << endl;

    cout << "Temperature 2: "; 
    t2.display(); 
    cout << endl;

    // Using only < and > operators to determine lower, higher, or equal
    if (t1 < t2) {
        cout << "Result: Temperature 1 is lower than Temperature 2." << endl;
    } else if (t1 > t2) {
        cout << "Result: Temperature 1 is higher than Temperature 2." << endl;
    } else {
        cout << "Result: Both temperatures are equal." << endl;
    }

    return 0;
}