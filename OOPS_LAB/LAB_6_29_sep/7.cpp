#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;
    
public:
    static int count;
    Date(int d, int m, int y) : day(d), month(m), year(y) {count+=1;}

    void display(){
        cout<<"Date"<<count<< ": "<< "Day: " << day<<"\tMonth: " << month<<"\tYear: "<<year<<endl;
    }
    bool operator==(const Date& d) const {
        return (day == d.day && month == d.month && year == d.year);
    }
};
int Date::count = 0;

int main() {
    Date d1(15, 8, 2026);
     d1.display();
    Date d2(15, 8, 2026);
    d2.display();
    if (d1 == d2) {
        cout << "Both dates are equal." << endl;
    } else {
        cout << "Dates are not equal." << endl;
    }
    return 0;
}
