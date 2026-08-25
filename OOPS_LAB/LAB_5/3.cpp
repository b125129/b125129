#include <iostream>
using namespace std;

class ArrayTotal
{
public:
    
    // Find total of an integer array
    int total(int arr[], int size)
    {
        int sum = 0;

        for (int i = 0; i < size; i++)
        {
            sum += arr[i];
        }

        return sum;
    }

    // Find total of a floating-point array
    double total(double arr[], int size)
    {
        double sum = 0.0;

        for (int i = 0; i < size; i++)
        {
            sum += arr[i];
        }

        return sum;
    }

    // Find total of a portion of an integer array
    int total(int arr[], int start, int end)
    {
        int sum = 0;

        for (int i = start; i <= end; i++)
        {
            sum += arr[i];
        }

        return sum;
    }
};

int main()
{
    ArrayTotal obj;

    int choice;

    cout << "===== Array Total Calculator =====" << endl;
    cout << "1. Total of integer array" << endl;
    cout << "2. Total of floating-point array" << endl;
    cout << "3. Total of a portion of integer array" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
        {
            int size;

            cout << "Enter the size of integer array: ";
            cin >> size;

            int arr[size];

            cout << "Enter " << size << " integer elements:" << endl;

            for (int i = 0; i < size; i++)
            {
                cin >> arr[i];
            }

            cout << "Total = "<< obj.total(arr, size) << endl;

            break;
        }

        case 2:
        {
            int size;

            cout << "Enter the size of floating-point array: ";
            cin >> size;

            double arr[size];

            cout << "Enter " << size<< " floating-point elements:" << endl;

            for (int i = 0; i < size; i++)
            {
                cin >> arr[i];
            }

            cout << "Total = "<< obj.total(arr, size) << endl;

            break;
        }

        case 3:
        {
            int size;

            cout << "Enter the size of integer array: ";
            cin >> size;

            int arr[size];

            cout << "Enter " << size << " integer elements:" << endl;

            for (int i = 0; i < size; i++)
            {
                cin >> arr[i];
            }

            int start, end;

            cout << "Enter starting index: ";
            cin >> start;

            cout << "Enter ending index: ";
            cin >> end;

            if (start < 0 || end >= size || start > end)
            {
                cout << "Invalid range!" << endl;
                break;
            }
            else
            {
                cout << "Total of specified portion = "<< obj.total(arr, start, end)<< endl;
            }

            break;
        }

        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}