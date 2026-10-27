#include <iostream>
using namespace std;

class Delivery {
public:
    virtual void estimateTime(double distance) {
        cout << "Base delivery estimation." << endl;
    }
};

class BikeDelivery : public Delivery {
public:
    void estimateTime(double distance) override {
        double timeInMinutes = (distance / 20.0) * 60.0 + 5.0;
        cout << "Bike Delivery Time: " << timeInMinutes << " minutes." << endl;
    }
};

class DroneDelivery : public Delivery {
public:
    void estimateTime(double distance) override {
        double timeInMinutes = (distance / 40.0) * 60.0 + 2.0;
        cout << "Drone Delivery Time: " << timeInMinutes << " minutes." << endl;
    }
};

int main() {
    BikeDelivery bike;
    DroneDelivery drone;
    
    double distance = 10.0; 
    bike.estimateTime(distance);
    drone.estimateTime(distance);
    
    return 0;
}