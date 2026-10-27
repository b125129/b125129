#include <iostream>
using namespace std;

class Number {
private:
    int value;
public:
    Number(int v = 0) : value(v) {}

    Number operator-() const {
        return Number(-value);
    }

    void display() const {
        cout << value << endl;
    }
};

int main() {
    Number n1(25);
    Number n2 = -n1;
    
    cout << "n1: "; n1.display();
    cout << "n2: "; n2.display();
    return 0;
}