#include<iostream>
using namespace std;

class rectangle{
        float length,breadth;
    public:
        void inp(){
            cout<<"Enter length and breadth of the rectangle"<<endl;
            cin>>length;
            cin>>breadth;
        }
        float area(){
            float area=length*breadth;
            return area;
        }
        float perim(){
            float p=2*(length+breadth);
            return p;
        }
        void display(float area,float perimeter){
            cout<<"\nArea: "<<area<<"\nPerimeter: "<<perimeter<<endl;
        }
};
int main(){
    rectangle r;
    float ar,per;
    r.inp();
    ar=r.area();
    per=r.perim();

    r.display(ar,per);
    return 0;
}