#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
public:
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {
        hours += minutes / 60;
        minutes %= 60;
    }

    Time operator+(const Time& t) const {
        int totalHours = hours + t.hours;
        int totalMinutes = minutes + t.minutes;
        return Time(totalHours, totalMinutes);
    }

    void display() const {
        cout << hours << " hours " << minutes << " minutes" << endl;
    }
};

int main() {
    Time t1(4, 45);
    Time t2(2, 30);
    Time result = t1 + t2;
    
    cout << "Time 1: "; t1.display();
    cout << "Time 2: "; t2.display();
    cout << "Result: "; result.display();
    return 0;
}