#include <iostream>
using namespace std;

int main() {
    int parcels = 15;
    int *ptr = &parcels;
    cout << "Initial number of parcels: " << *ptr << endl;
    int add_parcel;
    cout << "Enter number of additional parcels delivered: ";
    cin >> add_parcel;
    *ptr += add_parcel;
    cout << "Updated number of parcels: " << *ptr << endl;
    return 0;
}