#include <iostream>
using namespace std;

int main() {
    
    int*ptr = new int; //assinging pointer to int.

    //input and storing a value
    cout << "Enter an integer value: ";
    cin >> *ptr;

    //display values
    cout << "Stored Value: " << *ptr << endl;
    cout << "Memory Address: " << ptr << endl;

    delete[] ptr;   // deletes the value stored at that address
    ptr = nullptr;  // pointer stills points to that adress so we release it as that memory doesn't hold anything

    // just to show
    cout << "checking Memory Address: " << ptr << endl; // just to verify

    return 0;
}