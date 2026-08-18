#include <iostream>
#include <string>
using namespace std;

class Mobile {
private:
    string brand;
    string model;
    int battery_percentage;

public:
    Mobile(string bd, string mod, int battery) {
        brand=bd;
        model=mod;
        battery_percentage=battery;
    }
        
    friend void checkBattery(Mobile &m);
};

void checkBattery(Mobile &m) {
    cout << "--- Mobile Details ---" << endl;
    cout << "Brand: " << m.brand << endl;
    cout << "Model: " << m.model << endl;
    cout << "Battery Percentage: " << m.battery_percentage << "%" << endl;

    if (m.battery_percentage < 20) {
        cout << "Status: Battery Low" << endl;
    } else {
        cout << "Status: Battery Normal" << endl;
    }
}

int main() {
    string brand;
    string model;
    int battery_percentage;

    cout<<"Enter brand, model and battery percentage."<<endl;
    cin>>brand>>model>>battery_percentage;

    Mobile phone1(brand,model,battery_percentage);
    checkBattery(phone1);
    return 0;
}