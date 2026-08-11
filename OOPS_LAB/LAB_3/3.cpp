#include <iostream>
using namespace std;

int main() {
    // to accept the size of the array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Dynamically allocate array of n integers
    int* arr = new int[n];

    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int min=0;

    for (int i = 0; i < n; i++)
    {
        if (arr[min]>arr[i])        
        {
            min=i;
        }
        
    }

    cout<<"The largest element is: "<<arr[min]<<endl;

    // Release allocated memory using delete[]
    delete[] arr;
    arr = nullptr;

    return 0;
}