#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter total number of students: ";
    cin >> n;

    int *stu_id = new int[n];

    cout << "Enter " << n << " student ID's:" << endl;
    int *ptr = stu_id;
    for (int i = 0; i < n; i++) {
        cin >> *ptr;
        ptr++;
    }

    int to_find;
    cout << "Enter Student ID to search: ";
    cin >> to_find;

    ptr = stu_id;
    bool found = false;
    int position = -1;

    for (int i = 0; i < n; i++) {
        if (*ptr == to_find) {
            found = true;
            position = i;
            break;
        }
        ptr++;
    }

    if (found) {
        cout << "ID " << to_find << " found at index " << position << " (Position " << position + 1 << ")." << endl;
    } else {
        cout << "ID " << to_find << " was not found." << endl;
    }

    delete[] stu_id;

    return 0;
}