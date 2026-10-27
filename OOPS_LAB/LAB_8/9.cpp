#include <iostream>
using namespace std;

class Robot {
public:
    virtual void move(double distance) {
        cout << "Robot is moving." << endl;
    }
};

class WheeledRobot : public Robot {
public:
    void move(double distance) override {
        double speed = 2.0; 
        double time = distance / speed;
        cout << "Wheeled Robot took " << time << " seconds for " << distance << " meters." << endl;
    }
};

class TrackedRobot : public Robot {
public:
    void move(double distance) override {
        double speed = 1.2; 
        double time = distance / speed;
        cout << "Tracked Robot took " << time << " seconds for " << distance << " meters." << endl;
    }
};

int main() {
    Robot* r1 = new WheeledRobot();
    Robot* r2 = new TrackedRobot();
    
    double distance = 24.0;
    
    r1->move(distance);
    r2->move(distance);
    
    delete r1;
    delete r2;
    return 0;
}