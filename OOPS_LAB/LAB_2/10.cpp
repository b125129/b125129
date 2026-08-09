#include <iostream>
using namespace std;

// Class definition to calculate electricity bills based on slab rates
class ElectricityBill {
private:
    // Private data members
    int con_num;
    char con_name[50];
    int units;
    int total;
public:
    // Function to collect consumer information and consumption details
    void details(){
        cout << "Enter Consumer Number: ";
        cin >> con_num;
        cout << "Enter Consumer Name: ";
        cin >> con_name;
        cout << "Enter Units Consumed: ";
        cin >> units;
    }
    // Function to compute the bill total using tiered slab rates
    void calc_bill(){
    if (units <= 100) {
        total = units * 5;
    } 
    else if (units <= 200) {
        total = (100 * 5) + ((units - 100) * 7);
    } 
    else {
        total = (100 * 5) + (100 * 7) + ((units - 200) * 10);
    }
    };
    // Function to print the complete electricity bill details
    void display(){
        cout << "\nConsumer Number: " << con_num;
        cout << "\nConsumer Name: " << con_name;
        cout << "\nUnits Consumed: " << units;
        cout << "\nTotal Amount: " << total << endl;
    }
};

int main() {
    // Create an instance (object) of ElectricityBill
    ElectricityBill bill;
    
    bill.details();
    bill.calc_bill();
    bill.display();
    return 0;
}
