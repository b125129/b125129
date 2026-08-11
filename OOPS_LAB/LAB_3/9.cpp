#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int productID;
    string productName;
    double price;
    int quantity;

public:
    void acceptDetails() {
        cout << "Enter Product ID: ";
        cin >> productID;
        cin.ignore();
        cout << "Enter Product Name: ";
        getline(cin, productName);
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    void displayDetails() const {
        cout << "ID: " << productID 
             << " | Name: " << productName 
             << " | Price: $" << price 
             << " | Qty: " << quantity 
             << " | Total: $" << (price * quantity) << endl;
    }

    double getTotalCost() const {
        return price * quantity;
    }
};

int main() {
    int n;
    cout << "Enter number of products in cart: ";
    cin >> n;

    // Dynamically allocated array of products
    Product* cart = new Product[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Product " << i + 1 << ":" << endl;
        cart[i].acceptDetails();
    }

    cout << "\n--- Shopping Cart Summary ---" << endl;
    double grandTotal = 0.0;
    for (int i = 0; i < n; i++) {
        cart[i].displayDetails();
        grandTotal += cart[i].getTotalCost();
    }

    cout << "\nGrand Total Amount: $" << grandTotal << endl;

    delete[] cart;
    cart = nullptr;

    return 0;
}