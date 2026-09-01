#include <iostream>
using namespace std;

int main() {
    int BID[6] = {1001, 1002, 1003, 1004, 1005, 1006};
    int *arr = BID;
    cout << "Library Shelf Book ID's:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << "Book ID: " << *arr << "\t Address: " << arr << endl;
        arr++; 
    }
    return 0;
}