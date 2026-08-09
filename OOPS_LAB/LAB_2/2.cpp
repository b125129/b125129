#include<iostream>
using namespace std;

// Class definition representing a Rectangle object
class rectangle{
        // Private attributes (data encapsulation)
        float length,breadth;
    public:
        // Function to take user input for length and breadth
        void inp(){
            cout<<"Enter length and breadth of the rectangle"<<endl;
            cin>>length;
            cin>>breadth;
        }
        // Member function to calculate and return the area
        float area(){
            float area=length*breadth;
            return area;
        }
        // Member function to calculate and return the perimeter
        float perim(){
            float p=2*(length+breadth);
            return p;
        }
        // Function to print the calculated area and perimeter
        void display(float area,float perimeter){
            cout<<"\nArea: "<<area<<"\nPerimeter: "<<perimeter<<endl;
        }
};
int main(){
    rectangle r;        // Instantiates an object 'r' of class 'rectangle'
    float ar,per;
    r.inp();
    ar=r.area();
    per=r.perim();

    r.display(ar,per);
    return 0;
}
