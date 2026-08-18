#include <iostream>
#include <string>
using namespace std;

class Parking_Slot {
private:
    int slot_Number;
    string vehicle_Number;
    bool occ;

public:
    Parking_Slot(int slot, string veh_no, bool o){
        slot_Number=slot;
        vehicle_Number=veh_no;
        occ=o;
    }
        
    // Friend function declaration
    friend void checkSlot(Parking_Slot &slot);
};

void checkSlot(Parking_Slot &slot) {
    cout << "Slot Number: " << slot.slot_Number << endl;
    if (slot.occ) {
        cout << "Status: Occupied" << endl;
        cout << "Vehicle Number: " << slot.vehicle_Number << endl;
    } else {
        cout << "Status: Available" << endl;
    }
}

int main() {
    int slot_Number;
    string vehicle_Number = "NA";
    bool occ=false;
    char choice;

    cout<<"Enter slot no."<<endl;
    cin>>slot_Number;
    cout<<"Is the slot occupied?(y/n)?"<<endl;
    cin>>choice;

    if (choice=='y' || choice=='Y')
    {
        occ=true;
        cout<<"Enter the vehicle no.";
        cin>>vehicle_Number;
    }
     
    Parking_Slot slot(slot_Number,vehicle_Number,occ);
    checkSlot(slot);
    
    return 0;
}