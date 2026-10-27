#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string regNumber;
    int rentalDays;

public:
    Vehicle(string reg, int days) : regNumber(reg), rentalDays(days) {}
};

class Car : public Vehicle {
protected:
    double dailyRate;

public:
    Car(string reg, int days, double rate) 
        : Vehicle(reg, days), dailyRate(rate) {}
};

class LuxuryCar : public Car {
private:
    double luxuryCharge;

public:
    LuxuryCar(string reg, int days, double rate, double charge) 
        : Car(reg, days, rate), luxuryCharge(charge) {}

    void displayTotalCost() {
        double totalCost = (dailyRate + luxuryCharge) * rentalDays;
        cout << "\n--- Luxury Car Rental Details ---" << endl;
        cout << "Registration Number: " << regNumber << endl;
        cout << "Rental Duration: " << rentalDays << " days" << endl;
        cout << "Daily Rate: " << dailyRate << endl;
        cout << "Luxury Charge/Day: " << luxuryCharge << endl;
        cout << "Total Rental Cost: " << totalCost << endl;
    }
};

int main() {
    LuxuryCar myCar("OD-02-AB-1234", 4, 100, 50);
    myCar.displayTotalCost();
    return 0;
}