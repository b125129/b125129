#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name;
    double price;
    int quantity;
public:
    Product(string n = "", double p = 0, int q = 0) : name(n), price(p), quantity(q) {}

    // Overload + operator to combine quantities if name and price match
    Product operator+(const Product& p) const {
        if (name == p.name && price == p.price) {
            return Product(name, price, quantity + p.quantity);
        } else {
            cout << "Products do not match in name and price." << endl;
            return *this;
        }
    }

    // Overload > operator to compare based on total value (price * quantity)
    bool operator>(const Product& p) const {
        return (price * quantity) > (p.price * p.quantity);
    }

    void display() const {
        cout << "Product: " << name << ", Price: " << price << ", Quantity: " << quantity << ", Total Value: " << (price * quantity) << endl;
    }
};

int main() {
    Product p1("Notebook", 50.0, 2);
    Product p2("Notebook", 50.0, 3);
    Product p3("Pen", 10.0, 10);

    // Display all items
    cout << "--- Initial Products in Inventory ---" << endl;
    cout << "p1 -> "; p1.display();
    cout << "p2 -> "; p2.display();
    cout << "p3 -> "; p3.display();

    cout << "\n--- Performing Operations ---" << endl;

    cout << "Combining p1 and p2:" << endl;
    Product combined = p1 + p2;
    combined.display();

    cout << "\nComparing total values (p1 > p3):" << endl;
    if (p1 > p3) {
        cout << "Product 1 has a higher total value than Product 3." << endl;
    } else {
        cout << "Product 1 does not have a higher total value than Product 3." << endl;
    }

    return 0;
}