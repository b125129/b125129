#include<iostream>
using namespace std;

class calc{
        float n1,n2;
    public:
        void inp(){
            cout<<"Enter 1st and 2nd number."<<endl;
            cin>>n1;
            cin>>n2;
        }
        void add(){
            cout<<"Addition: "<<n1+n2<<endl;
        }
        void sub(){
            cout<<"Subtraction: "<<n1-n2<<endl;
        }
        void mul(){
            cout<<"Multiplication: "<<n1*n2<<endl;
        }
        void div(){
            if(n2==0){
                cout<<"Division by not 0."<<endl;
                return;
            }
            cout<<"Division: "<<n1/n2<<endl;
        }
};

int main(){
    calc c;
    float ar,per;
    c.inp();
    c.add();
    c.sub();
    c.mul();
    c.div();
    return 0;
}
