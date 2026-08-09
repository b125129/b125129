#include<iostream>
using namespace std;

// Class definition to manage and convert distance measurements
class Distance{
    // Private attributes
    float inches ;
    float feet ;

    public:
      // Member function to take user input for distance components
      void get_data(){
        cout <<"Enter  Inches: " ;
        cin >> inches ;

        cout <<"Enter feet:";
        cin >> feet ;
      }
      // Member function to convert total distance to feet and display the result
      void Total_dis(){     
        // Converts inches to feet (inches / 12) and adds
       cout << "Total distance in feet = "<<  inches/12+ feet  ;

      }
       
     
};

int main(){
    // Instantiate an object 'd' of class 'Distance'
    Distance d;
    d.get_data();
    d.Total_dis();

    return 0 ;
}
