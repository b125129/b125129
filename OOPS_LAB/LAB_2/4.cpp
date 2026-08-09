#include<iostream>
using namespace std;

// Class definition to model a Bank Account entity
class Account{
    // Private data members
    int acc_num ;
    char name[50];
    float balance ;

    public:
      // Function to gather account information from the user
      void get_detail(){
        cout <<"Enter Account Number: " ;
        cin >> acc_num;
        cout <<"Enter Account Holder Name:" ;
        cin >> name ;
        cout <<"Enter balance:";
        cin >> balance ;
      }
      // Function to process a deposit transaction
      void Deposit(){
        int dep_amm ;
        cout <<"\nAmount deposited:";
        cin >> dep_amm ;
        balance= balance + dep_amm ;

        cout <<"\nDeposit success"<<endl;

        cout <<"\nAmount After deposition = "<<balance;
      }
      // Function to process a withdrawal transaction
      void Withdraw(){
        int dr_amm ;
        cout <<"\nEnter amount to withdraw:";
        cin >> dr_amm ;
         balance= balance - dr_amm ;

         cout <<"\nWithdrawal successful"<<endl;

         cout <<"\nTotal amount After Withdraw = "<< balance ;
      }
      // Function to print updated account details
      void updated(){
        cout<<"\n-------Account details-------" ;
        cout <<"\nAccount Number = "<<acc_num;
        cout <<"\nHolder name ="<<name;
        cout <<"\nBalance = "<<balance ;
      }
};


int main(){
    Account a1;    // Instantiate an 'Account' object named 'a1'

    // Sequentially invoke class methods
    a1.get_detail();
    a1.Deposit();
    a1.Withdraw();
    a1.updated();
 
    return 0;
};
