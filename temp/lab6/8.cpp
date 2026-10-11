#include <iostream>
#include <string>
using namespace std;

class Item {
private:
    string name;
    double price;
    int quantity;
public:
    Item(string n, double p, int q) : name(n), price(p), quantity(q) {}

    Item operator+(const Item& i) const {
        if (name == i.name && price == i.price) {
            return Item(name, price, quantity + i.quantity);
        } else {
            cout << "Items are different or have different prices!" << endl;
            return *this;
        }
    }

    void display() const {
        cout << "Item: " << name << ", Price: " << price << ", Quantity: " << quantity << endl;
    }
};
int main() {
    Item item1("Pen", 10.0, 5);
    Item item2("Pen", 10.0, 3);

    cout << "Items before combining:" << endl;
    item1.display();
    item2.display();

    Item combinedItem = item1 + item2;

    cout << "\nCombined item:" << endl;
    combinedItem.display();

    return 0;
}
/*
int main() {
    Item item1("Pen", 10.0, 5);
    Item item2("Pen", 10.0, 3);
    
    Item combinedItem = item1 + item2;
    combinedItem.display();
    return 0;
}
*/
