#include <iostream>
#include <string>
using namespace std;

class SmartDevice {
private:
    string deviceName;
    string deviceType;
    bool powerStatus; 
public:
    SmartDevice(string name, string type, bool status) 
    {
        deviceName=name;
        deviceType=type;
        powerStatus=status;
    }

    // Declaring HomeController as a Friend Class
    friend class HomeController;
};

class HomeController {
public:
    void displayInfo(SmartDevice&dev) {
        cout << "Device Name: " << dev.deviceName << endl;
        cout << "Device Type: " << dev.deviceType << endl;
        cout << "Power Status: " << (dev.powerStatus ? "ON" : "OFF") << endl;
    }

    void turnOn(SmartDevice &dev) {
        dev.powerStatus = true;
        cout << dev.deviceName << " has been turned ON." << endl;
    }

    void turnOff(SmartDevice &dev) {
        dev.powerStatus = false;
        cout << dev.deviceName << " has been turned OFF." << endl;
    }

    void displayStatus(SmartDevice& dev) {
        cout << dev.deviceName << " is currently " << (dev.powerStatus ? "ON" : "OFF") << "." << endl;
    }
};

int main() {
    string deviceName;
    string deviceType;
    bool powerStatus=false;
    char choice;

    cout<<"Enter device Name."<<endl;
    cin>>deviceName;
    cout<<"Enter device type."<<endl;
    cin>>deviceType;

    cout<<"Is the device on?(y/n)?"<<endl;
    cin>>choice;

    if (choice=='y' || choice=='Y')
    {
        powerStatus=true;
    }

    SmartDevice tv(deviceName,deviceType,powerStatus);
    HomeController hc;

    cout << "--- Initial State ---" << endl;
    hc.displayInfo(tv);

    cout << "\n--- Actions ---" << endl;
    hc.turnOn(tv);
    hc.displayStatus(tv);

    hc.turnOff(tv);
    hc.displayStatus(tv);

    return 0;
}
