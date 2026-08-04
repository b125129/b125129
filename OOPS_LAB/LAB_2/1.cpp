#include<iostream>
using namespace std;

class student{
        int roll_no,marks;
        char name[50];
    public:
        void inp(){
            cout<<"Enter name, roll_no. and marks of the student."<<endl;
            cin>>name;
            cin>>roll_no;
            cin>>marks;
        }
        void display(){
            cout<<"Details of the student are as follows"<<endl;
            cout<<"\nName: "<<name<<"\nRoll no. "<<roll_no<<"\nMarks: "<<marks<<endl;
        }
};
int main(){
    student s;
    s.inp();
    s.display();
    return 0;
}