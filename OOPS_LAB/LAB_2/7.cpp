#include<iostream>
using namespace std;

class product{
        int p_id,qua_av,sold;
        float price;
        char name[50];
    public:
        void inp(){
            cout<<"Enter product id, name of the product, available quantity and price per unit."<<endl;
            cin>>p_id;
            cin>>name;
            cin>>qua_av;
            cin>>price;
        }
        void display(){
            cout<<"Details of product."<<endl;
            cout<<"\nProduct ID: "<<p_id<<"\nName of the product: "<<name<<"\nQuantity available: "<<qua_av<<"\nprice per unit: "<<price<<endl;
        }
        void tot_inv_value(){
            cout<<"The total value of the inventory after sales is "<<price*qua_av<<endl;
        }
        void sell(){
            cout<<"No. of items sold ";
            cin>>sold;
            if (sold>qua_av){
                cout<<"Quantity sold cannot be greater than stock quantity.";
                return;
            }
            else{
                qua_av=qua_av-sold;
                tot_inv_value();
            }
        }
};

int main(){
    product p;
    p.inp();
    p.display();
    p.sell();
    return 0;
}