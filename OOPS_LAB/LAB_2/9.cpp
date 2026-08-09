#include<iostream>
using namespace std;

// Class definition to calculate student marks, percentage, and final grade
class Student{
    // Private attributes
    int roll_no;
    char name[50];
    int sub1,sub2,sub3,sub4,sub5;

    public:
    // Member function to take inputs for student details and 5 subject marks
    void get_detail(){
        cout<<"Enter roll number : ";
        cin>>roll_no;
        cout<<"Enter name : ";
        cin>>name;
        cout<<"Enter marks of 5 subjects : ";
        cin>>sub1>>sub2>>sub3>>sub4>>sub5;
    }
    // Member function to calculate and display total marks and percentage
    void student_marks(){
        cout <<"Total marks of student = "<< sub1+sub2+sub3+sub4+sub5 ;
        cout <<"\nPercentage marks of student = "<< ((sub1+sub2+sub3+sub4+sub5)/500.0)*100 ;
    }
    // Member function to evaluate and print the letter grade based on percentage
    void grade(){
        float percentage = ((sub1+sub2+sub3+sub4+sub5)/500.0)*100;
        if(percentage>=90){
            cout <<"\nGrade = A" ;
        }
        else if(percentage>=80){
            cout <<"\nGrade = B" ;
        }
        else if(percentage>=70){
            cout <<"\nGrade = C" ;
        }
        else if(percentage>=60){
            cout <<"\nGrade = D" ;
        }
        else{
            cout <<"\nGrade = F" ;
        }
    }
};

int main(){
    Student s;    // Instantiate an object 's' of class 'Student'
    
    s.get_detail();
    s.student_marks();
    s.grade();
    return 0;
}
