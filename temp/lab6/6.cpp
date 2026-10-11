#include <iostream>
using namespace std;

class Counter {
private:
    int value;
public:
    Counter(int v = 0) : value(v) {}

    // Prefix increment: ++c
    Counter& operator++() {
        ++value;
        return *this;
    }

    // Postfix increment: c++
    Counter operator++(int) {
        Counter temp = *this;
        value++;
        return temp;
    }

    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Counter c(5);
    cout << "Initial "; c.display();
    
    cout << "After prefix (++c): ";
    (++c).display();
    
    cout << "After postfix (c++): ";
    (c++).display();
    cout << "Value after postfix completes: "; c.display();
    return 0;
}