#include <iostream>
using namespace std;

class ParkingSlot {
public:
    virtual void calculateFee(int hours) {
        cout << "Base parking fee calculation." << endl;
    }
};

class TwoWheelerSlot : public ParkingSlot {
public:
    void calculateFee(int hours) override {
        double rate = 10.0;
        double totalFee = hours * rate;
        if (hours > 5) {
            totalFee -= totalFee * 0.10; 
        }
        cout << "Two-Wheeler Final Parking Fee: Rs. " << totalFee << endl;
    }
};

class FourWheelerSlot : public ParkingSlot {
public:
    void calculateFee(int hours) override {
        double rate = 30.0;
        double totalFee = hours * rate;
        if (hours > 5) {
            totalFee -= totalFee * 0.10; // 10% discount
        }
        cout << "Four-Wheeler Final Parking Fee: Rs. " << totalFee << endl;
    }
};

int main() {
    TwoWheelerSlot bikeSlot;
    FourWheelerSlot carSlot;
    
    bikeSlot.calculateFee(6); 
    carSlot.calculateFee(4);  
    
    return 0;
}