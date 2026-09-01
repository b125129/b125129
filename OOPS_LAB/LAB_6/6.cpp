#include <iostream>
using namespace std;

int highest_price(const int *ptr, int size) {
    int highest = *ptr;
    
    for (int i = 0; i < size; i++) {
        if (*ptr > highest) {
            highest = *ptr;
        }
        ptr++;
    }

    return highest;
}

int main() {
    int prices[7] = {10,20,30,60,40,23,43};
    int maxPrice = highest_price(prices, 7);

    cout << "Highest price of product is " << maxPrice << endl;

    return 0;
}