#include<iostream>
using namespace std;

class Distance{
    float inches ;
    float feet ;

    public:
      void get_data(){
        cout <<"Enter  Inches: " ;
        cin >> inches ;

        cout <<"Enter feet:";
        cin >> feet ;
      }
     
      void Total_dis(){     
       cout << "Total distance in feet = "<<  inches/12+ feet  ;

      }
       
     
};

int main(){
    Distance d;
    d.get_data();
    d.Total_dis();

    return 0 ;
}