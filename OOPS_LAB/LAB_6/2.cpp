#include <iostream>
using namespace std;

int main() {
    double balance = 100;
    double *ptr = &balance;
    cout << "Current Balance: " << *ptr << endl;

    double deposit;
    cout << "Amount deposited: ";
    cin >> deposit;
    *ptr += deposit;

    double withdrawal;
    cout << "Enter amount to withdraw: ";
    cin >> withdrawal;
    *ptr -= withdrawal;

    cout << "Final Balance: " << *ptr << endl;

    return 0;
}