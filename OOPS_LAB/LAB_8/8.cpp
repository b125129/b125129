#include <iostream>
using namespace std;

class CloudResource {
public:
    virtual void calculateCost(double cpuHours) {
        cout << "Base cloud resource cost calculation." << endl;
    }
};

class StandardInstance : public CloudResource {
public:
    void calculateCost(double cpuHours) override {
        double rate = 5.0;
        double totalCost = cpuHours * rate;
        if (cpuHours > 100) {
            totalCost -= totalCost * 0.15; // 15% discount
        }
        cout << "Standard Instance Final Cost: Rs. " << totalCost << endl;
    }
};

class PremiumInstance : public CloudResource {
public:
    void calculateCost(double cpuHours) override {
        double rate = 12.0;
        double totalCost = cpuHours * rate;
        if (cpuHours > 100) {
            totalCost -= totalCost * 0.15; // 15% discount
        }
        cout << "Premium Instance Final Cost: Rs. " << totalCost << endl;
    }
};

int main() {
    StandardInstance stdInst;
    PremiumInstance premInst;
    
    stdInst.calculateCost(120.0); 
    premInst.calculateCost(80.0); 
    
    return 0;
}