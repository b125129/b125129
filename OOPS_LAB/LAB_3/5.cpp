#include<iostream>
#include<string>
using namespace std;

class Student{
    int roll;
    string name;
    float marks;
    public:
        void input(void){
            cout<<"Enter roll, name and marks: "<<endl;
            cin>>roll>>name>>marks;
        }
        void display(void){
            cout<<"Roll no: "<<roll<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Marks: "<<marks<<endl;
        }
};

int main(){
    Student* studptr=new Student();
    studptr->input();
    studptr->display();

    delete studptr;
    studptr=nullptr;
    return 0;
}