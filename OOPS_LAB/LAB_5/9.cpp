#include <iostream>
using namespace std;

class Maximum
{
public:
    // Find maximum of two integers
    int findMax(int a, int b)
    {
        return (a > b) ? a : b;
    }

    // Find maximum using two integer pointers
    int findMax(int *a, int *b)
    {
        return (*a > *b) ? *a : *b;
    }

    // Find maximum in an integer array using pointer
    int findMax(int *arr, int size)
    {
        int maxValue = *arr;

        for (int i = 1; i < size; i++)
        {
            if (*(arr + i) > maxValue)
            {
                maxValue = *(arr + i);
            }
        }

        return maxValue;
    }
};

int main()
{
    Maximum obj;

    int choice;

    cout << "===== Maximum Value Finder =====" << endl;
    cout << "1. Maximum between two integers" << endl;
    cout << "2. Maximum using two integer pointers" << endl;
    cout << "3. Maximum in an integer array" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
        {
            int a, b;

            cout << "Enter first integer: ";
            cin >> a;

            cout << "Enter second integer: ";
            cin >> b;

            cout << "Maximum = "
                 << obj.findMax(a, b) << endl;

            break;
        }

        case 2:
        {
            int a, b;

            cout << "Enter first integer: ";
            cin >> a;

            cout << "Enter second integer: ";
            cin >> b;

            cout << "Maximum using pointers = "
                 << obj.findMax(&a, &b) << endl;

            break;
        }

        case 3:
        {
            int size;

            cout << "Enter array size: ";
            cin >> size;

            if (size <= 0)
            {
                cout << "Invalid array size!" << endl;
                break;
            }

            int arr[size];

            cout << "Enter " << size << " integers:" << endl;

            for (int i = 0; i < size; i++)
            {
                cin >> arr[i];
            }

            cout << "Maximum in array = "
                 << obj.findMax(arr, size) << endl;

            break;
        }

        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}