#include<iostream>
using namespace std;

class employee{
        int emp_id;
        char name[50];
        float b_salary,hra,da,gs;
    public:
        void inp(){
            cout<<"Enter employee id, name of the employee and salary."<<endl;
            cin>>emp_id;
            cin>>name;
            cin>>b_salary;
        }
        void sal(){
            hra=0.2*b_salary;
            da=0.1*b_salary;
            gs=b_salary+hra+da;
        }
        void display(){
            cout<<"Details of salary."<<endl;
            cout<<"\nBasic Salary: "<<b_salary<<"\nHRA "<<hra<<"\nDA: "<<da<<"\nGross Salary: "<<gs<<endl;
        }
};

int main(){
    employee e;
    e.inp();
    e.sal();
    e.display();
    return 0;
}
