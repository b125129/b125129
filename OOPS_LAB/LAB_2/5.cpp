#include<iostream>
using namespace std;

// Class definition to represent an Employee and calculate salary breakdown
class employee{
        // Private data members
        int emp_id;
        char name[50];
        float b_salary,hra,da,gs;
    public:
        // Function to take employee details as input from the user
        void inp(){
            cout<<"Enter employee id, name of the employee and salary."<<endl;
            cin>>emp_id;
            cin>>name;
            cin>>b_salary;
        }
        // Function to compute salary components and gross total
        void sal(){
            hra=0.2*b_salary;
            da=0.1*b_salary;
            gs=b_salary+hra+da;
        }
        // Function to print salary breakup details
        void display(){
            cout<<"Details of salary."<<endl;
            cout<<"\nBasic Salary: "<<b_salary<<"\nHRA "<<hra<<"\nDA: "<<da<<"\nGross Salary: "<<gs<<endl;
        }
};

int main(){
    employee e;        // Instantiate an object 'e' of class 'employee'
    e.inp();
    e.sal();
    e.display();
    return 0;
}
