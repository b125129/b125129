#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNum, double bal) : accountNumber(accNum), balance(bal) {}
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(string accNum, double bal) : BankAccount(accNum, bal) {}

    void addInterest(double ratePercent) {
        double interest = balance * (ratePercent / 100);
        balance += interest;
        cout << "\n--- Savings Account ---" << endl;
        cout << "Account: " << accountNumber << endl;
        cout << "Interest Added: " << interest << endl;
        cout << "Updated Balance: " << balance << endl;
    }
};

class CurrentAccount : public BankAccount {
public:
    CurrentAccount(string accNum, double bal) : BankAccount(accNum, bal) {}

    void applyMaintenanceCharge(double minBalance, double charge) {
        cout << "\n--- Current Account ---" << endl;
        cout << "Account: " << accountNumber << endl;
        if (balance < minBalance) {
            balance -= charge;
            cout << "Balance below " << minBalance << ". Maintenance charge of $" << charge << " applied." << endl;
        } else {
            cout << "Minimum balance requirement met. No charges applied." << endl;
        }
        cout << "Updated Balance: " << balance << endl;
    }
};

int main() {
    SavingsAccount sa("SA1001", 5000);
    CurrentAccount ca("CA2002", 1500);

    sa.addInterest(5);                           // 5% interest
    ca.applyMaintenanceCharge(2000, 100);        // Min balance 2000, fee 100

    return 0;
}