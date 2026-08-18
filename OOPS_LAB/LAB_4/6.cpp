
#include <iostream>
using namespace std;

class Door {
private:
    int doorNumber;
    bool isLocked;

public:
    Door(int number, bool locked) {
        doorNumber=number;
        isLocked=locked;
    }
    // Declaring SecuritySystem as a Friend Class
    friend class SecuritySystem;
};

class SecuritySystem {
public:
    void checkLockStatus(Door &d) {
        cout << "Door Number: " << d.doorNumber << endl;
        if (d.isLocked) {
            cout << "Lock Status: Locked" << endl;
        } else {
            cout << "Lock Status: Unlocked" << endl;
        }
    }
};

int main() {
    int doorNumber;
    char choice;
    bool isLocked=false;

    cout<<"Enter door no."<<endl;
    cin>>doorNumber;
    cout<<"Is the door locked?(y/n)?"<<endl;
    cin>>choice;

    if (choice=='y' || choice=='Y')
    {
        isLocked=true;
    }

    Door mainDoor(doorNumber,isLocked);
    SecuritySystem system;

    system.checkLockStatus(mainDoor);
    return 0;
}