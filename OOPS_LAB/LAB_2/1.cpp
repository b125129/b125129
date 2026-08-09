#include<iostream>
using namespace std;

// Define a class to represent a Student entity
class student{
        // Private data members
        int roll_no,marks;
        char name[50];
    public:
        // Member function to take input from the user
        void inp(){
            cout<<"Enter name, roll_no. and marks of the student."<<endl;
            cin>>name;
            cin>>roll_no;
            cin>>marks;
        }

        // Member function to display student details
        void display(){
            cout<<"Details of the student are as follows"<<endl;
            cout<<"\nName: "<<name<<"\nRoll no. "<<roll_no<<"\nMarks: "<<marks<<endl;
        }
};
int main(){
    student s;        // Instantiate an object 's' of class 'student'
    s.inp();
    s.display();
    return 0;
}
