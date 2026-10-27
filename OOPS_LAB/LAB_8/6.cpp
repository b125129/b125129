#include <iostream>
using namespace std;

class SecurityScanner {
public:
    virtual void scan(int threats) {
        cout << "Base security scan." << endl;
    }
};

class BasicScanner : public SecurityScanner {
public:
    void scan(int threats) override {
        cout << "[Basic Scanner] Threats detected: " << threats << endl;
    }
};

class AdvancedScanner : public SecurityScanner {
public:
    void scan(int threats) override {
        int remaining = threats - (0.90 * threats);
        cout << "[Advanced Scanner] Threats detected: " << threats 
             << ", Remaining after removing 90%: " << remaining << endl;
    }
};

int main() {
    BasicScanner basic;
    AdvancedScanner advanced;
    
    basic.scan(50);
    advanced.scan(50);
    
    return 0;
}