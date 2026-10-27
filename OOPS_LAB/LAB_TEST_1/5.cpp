#include <iostream>
using namespace std;

void updateVisitors(int *count){
    int new_visitor;
    cout << "Enter the number of new visitors." << endl;
    cin>>new_visitor;
    *count += new_visitor;
    return;
}

int main() {
    int no_of_visitors = 15;
    int *ptr = &no_of_visitors;
    cout << "Initial number of visitors: " << *ptr << endl;

    updateVisitors(ptr);
    
    cout << "Updated number of visitors: " << *ptr << endl;
    return 0;
}