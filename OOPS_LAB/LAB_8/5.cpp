#include <iostream>
using namespace std;

class IrrigationSystem {
public:
    virtual void calculateWater(double moisture) {
        cout << "Base irrigation calculation." << endl;
    }
};

class DripIrrigation : public IrrigationSystem {
public:
    void calculateWater(double moisture) override {
        double waterNeeded = 2 * (100 - moisture);
        cout << "Drip Irrigation requires: " << waterNeeded << " litres." << endl;
    }
};

class SprinklerIrrigation : public IrrigationSystem {
public:
    void calculateWater(double moisture) override {
        double waterNeeded = 3 * (100 - moisture);
        cout << "Sprinkler Irrigation requires: " << waterNeeded << " litres." << endl;
    }
};

int main() {
    DripIrrigation drip;
    SprinklerIrrigation sprinkler;
    
    double moistureLevel = 45.0; 
    drip.calculateWater(moistureLevel);
    sprinkler.calculateWater(moistureLevel);
    
    return 0;
}