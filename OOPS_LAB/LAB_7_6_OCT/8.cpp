#include <iostream>
#include <string>
using namespace std;

class Patient {
protected:
    string patientName;
    string patientID;
    int age;

public:
    Patient(string name, string id, int a) 
        : patientName(name), patientID(id), age(a) {}
};

class InPatient : public Patient {
private:
    double roomChargesPerDay;
    int numberOfDays;

public:
    InPatient(string name, string id, int a, double rate, int days)
        : Patient(name, id, a), roomChargesPerDay(rate), numberOfDays(days) {}

    void calculateAndDisplayBill() {
        double totalBill = roomChargesPerDay * numberOfDays;

        // Directly accessing protected members inherited from Patient
        cout << "\n--- In-Patient Billing Info ---" << endl;
        cout << "Patient ID: " << patientID << endl;
        cout << "Patient Name: " << patientName << endl;
        cout << "Age: " << age << endl;
        cout << "Stay Duration: " << numberOfDays << " days" << endl;
        cout << "Daily Room Charge: $" << roomChargesPerDay << endl;
        cout << "Total Hospital Bill: $" << totalBill << endl;
    }
};

int main() {
    InPatient patient("Frank", "P1042", 45, 250.0, 5);
    patient.calculateAndDisplayBill();
    return 0;
}