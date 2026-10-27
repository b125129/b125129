#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(8, 5);
    Complex c2(3, 2);
    Complex result = c1 - c2;
    
    cout << "C1 = 8 + 5i, C2 = 3 + 2i\nResult: ";
    result.display();
    return 0;
}