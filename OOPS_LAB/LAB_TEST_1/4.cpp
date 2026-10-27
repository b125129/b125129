#include <iostream>
using namespace std;

int main() {
    int seat_no[8] = {1001,1002,1003,1004,1005,1006,1007,1008};
    int *arr = seat_no;

    cout<<"Seat no. before alteration."<<endl;
    for (int i = 0; i < 8; i++) {
        cout << "index" << i << "\t Seat no: " << *arr << endl;
        arr++; 
    }
    int posn,seat;
    cout << "Enter the position and updated seat no." << endl;
    cin>>posn;
    cin>>seat;
    arr = seat_no;
    *(arr+posn)=seat;
    arr=seat_no;
    for (int i = 0; i < 8; i++) {
        cout << "index" << i << "\t Seat no: " << *arr << endl;
        arr++; 
    }
    return 0;
}