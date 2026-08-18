#include <iostream>
#include <string>
using namespace std;

class TrainSeat {
private:
    int seatNumber;
    string passengerName;
    bool isBooked;

public:
    TrainSeat(int seat, string name, bool booked) {
        seatNumber=seat;
        passengerName=name;
        isBooked=booked;
    }

    friend class TicketChecker;
};

class TicketChecker {
public:
    void displayDetails(TrainSeat &ts) {
        cout << "--- Seat Details ---" << endl;
        cout << "Seat Number: " << ts.seatNumber << endl;
        cout << "Booking Status: " << (ts.isBooked ? "Booked" : "Available") << endl;
        if (ts.isBooked) {
            cout << "Passenger Name: " << ts.passengerName << endl;
        }
    }

    void checkStatus(const TrainSeat &ts) {
        if (ts.isBooked) {
            cout << "Seat " << ts.seatNumber << " is currently Booked." << endl;
        } else {
            cout << "Seat " << ts.seatNumber << " is Available." << endl;
        }
    }

    void displayPassengerName(const TrainSeat &ts) {
        if (ts.isBooked) {
            cout << "Passenger: " << ts.passengerName << endl;
        } else {
            cout << "No passenger assigned to this seat." << endl;
        }
    }
};

int main() {
    int seatNumber;
    string passengerName;
    bool isBooked;
    char choice;

    cout<<"Enter seat no."<<endl;
    cin>>seatNumber;
    cout<<"Is the door locked?(y/n)?"<<endl;
    cin>>choice;

    if (choice=='y' || choice=='Y')
    {
        isBooked=true;
        cout<<"Enter the passenger name: ";
        cin>>passengerName;
    }


    TrainSeat seat1(seatNumber,passengerName,isBooked);
    TicketChecker checker;

    checker.displayDetails(seat1);
    return 0;
}
