#include <iostream>
#include <cmath>
using namespace std;

class MatchFormat {
public:
    virtual void calculateTarget(int firstInningsScore) {
        cout << "Base match format target calculation." << endl;
    }
};

class T20Match : public MatchFormat {
public:
    void calculateTarget(int firstInningsScore) override {
        // 1% margin, rounded up
        int margin = ceil(0.01 * firstInningsScore);
        int target = firstInningsScore + margin;
        cout << "T20 Match Target: " << target << " (Margin: " << margin << ")" << endl;
    }
};

class ODIMatch : public MatchFormat {
public:
    void calculateTarget(int firstInningsScore) override {
        // 2% margin, rounded up
        int margin = ceil(0.02 * firstInningsScore);
        int target = firstInningsScore + margin;
        cout << "ODI Match Target: " << target << " (Margin: " << margin << ")" << endl;
    }
};

int main() {
    T20Match t20;
    ODIMatch odi;
    
    t20.calculateTarget(185);
    odi.calculateTarget(300);
    
    return 0;
}