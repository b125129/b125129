#include<iostream>
using namespace std;

// Class definition for a basic calculator
class calc{
        // Private data members to hold two numbers
        float n1,n2;
    public:
        // Function to take input for two numbers from the user
        void inp(){
            cout<<"Enter 1st and 2nd number."<<endl;
            cin>>n1;
            cin>>n2;
        }
        // Function to calculate and output the sum
        void add(){
            cout<<"Addition: "<<n1+n2<<endl;
        }
        // Function to calculate and output the difference
        void sub(){
            cout<<"Subtraction: "<<n1-n2<<endl;
        }
        // Function to calculate and output the product
        void mul(){
            cout<<"Multiplication: "<<n1*n2<<endl;
        }
        // Function to perform division with a zero-check safety guard
        void div(){
            // Check to prevent division by zero (undefined mathematical operation)
            if(n2==0){
                cout<<"Division by not 0."<<endl;
                return;
            }
            cout<<"Division: "<<n1/n2<<endl;
        }
};

int main(){
    calc c;        // Create an instance (object) of the 'calc' class

    // Sequentially invoke class methods
    c.inp();
    c.add();
    c.sub();
    c.mul();
    c.div();
    return 0;
}
