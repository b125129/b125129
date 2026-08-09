#include<iostream>
using namespace std;

// Class definition to manage library book issuance and fine calculations
class Book{
    // Private data members
    int book_id ;
    char book_title[50];
    char student_name[50];
    int no_of_days ;

    public:
    // Function to take borrowing details as input from the user
    void get_data(){
        cout <<"Enter Book Id: " ;
        cin >> book_id;
        cout <<"Enter Book Title:" ;
        cin >> book_title ;
        cout <<"Enter Student Name:";
        cin >> student_name ;
        cout <<"Enter No of Days:";
        cin >> no_of_days ;
    }
    // Function to display student borrowing details
    void student_details(){
        cout<<"\n-------Student details-------" ;
        cout <<"\nBook Id = "<<book_id;
        cout <<"\nBook Title ="<<book_title;
        cout <<"\nStudent Name = "<<student_name ;
        cout <<"\nNo of Days = "<<no_of_days ;
    }
    // Function to calculate and display fine based on total days kept
    void fine(){
        int fine_amount ;
        if(no_of_days>15){
            fine_amount = (no_of_days-15)*2 ;
            cout <<"\nFine Amount = "<<fine_amount ;
        }else{
            cout <<"\nNo Fine Amount" ;
        }
    }
    // Helper function to trigger both transaction details and fine display
    void Display_trascation(){
        student_details();
        fine();
    }
     
};

int main(){
    Book b1;    // Instantiate an object 'b1' of class 'Book'
    
    b1.get_data();
    b1.Display_trascation();
    return 0;
}
