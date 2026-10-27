#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter total number of parking slots: ";
    cin >> n;

    int *slots = new int[n];

    cout << "Enter status for each slot (0=available,1=occupied):" << endl;
    int *ptr = slots;
    for (int i = 0; i < n; i++) {
        cin >> *ptr;
        ptr++;
    }

    int avail_count = 0, occ_count = 0;
    ptr = slots;
    for (int i = 0; i < n; i++) {
        if (*ptr == 0) {
            avail_count++;
        } else if (*ptr == 1) {
            occ_count++;
        }
        ptr++;
    }

    cout << "Total Available Slots: " << avail_count << endl;
    cout << "Total Occupied Slots:  " << occ_count << endl;

    delete[] slots;

    return 0;
}