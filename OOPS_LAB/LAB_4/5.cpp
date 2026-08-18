#include <iostream>
#include <string>
using namespace std;

class FoodOrder {
private:
    int orderID;
    string foodItem;
    int quantity;
    double price;

public:
    FoodOrder(int id, string item, int qty, double p) {
        orderID=id;
        foodItem=item;
        quantity=qty;
        price=p;
    }
        
    // Friend function declaration
    friend void calculateBill(FoodOrder &order);
};

void calculateBill(FoodOrder &order) {
    double totalBill = order.quantity * order.price;
    cout << "--- Order Details ---" << endl;
    cout << "Order ID: " << order.orderID << endl;
    cout << "Food Item: " << order.foodItem << endl;
    cout << "Quantity: " << order.quantity << endl;
    cout << "Price per Item: $" << order.price << endl;
    cout << "Total Bill: $" << totalBill << endl;
}

int main() {
    int orderID;
    string foodItem;
    int quantity;
    double price;
    cout<<"Enter order ID, food item, quantity and price."<<endl;
    cin>>orderID>>foodItem>>quantity>>price;

    FoodOrder order(orderID,foodItem,quantity,price);
    calculateBill(order);
    return 0;
}