#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNum, double bal)
        : accountNumber(accNum), balance(bal) {}

    void displayDetails() const {
        cout << "Account: " << accountNumber << endl;
        cout << "Starting Balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(string accNum, double bal)
        : BankAccount(accNum, bal) {}

    void addInterest(double ratePercent) {
        double interest = balance * (ratePercent / 100);
        balance += interest;

        cout << "\n--- Savings Account Result ---" << endl;
        cout << "Interest Added: " << interest << endl;
        cout << "Final Balance: " << balance << endl;
    }
};

class CurrentAccount : public BankAccount {
public:
    CurrentAccount(string accNum, double bal)
        : BankAccount(accNum, bal) {}

    void applyMaintenanceCharge(double minBalance, double charge) {
        cout << "\n--- Current Account Result ---" << endl;

        if (balance < minBalance) {
            balance -= charge;
            cout << "Balance below " << minBalance
                 << ". Maintenance charge of " << charge << " applied." << endl;
        } else {
            cout << "Minimum balance requirement met. No charge applied." << endl;
        }

        cout << "Final Balance: " << balance << endl;
    }
};

int main() {
    SavingsAccount sa("SA1001", 5000);
    CurrentAccount ca("CA2002", 1500);

    cout << "--- Account Details Before Transactions ---" << endl;
    sa.displayDetails();
    cout << endl;
    ca.displayDetails();

    sa.addInterest(5);
    ca.applyMaintenanceCharge(2000, 100);

    return 0;
}

