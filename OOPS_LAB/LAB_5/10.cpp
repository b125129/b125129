#include <iostream>
using namespace std;

class DataProcessor
{
public:
    // Add two integers
    int process(int a, int b)
    {
        return a + b;
    }

    // Add integer and floating-point value
    double process(int a, double b)
    {
        return a + b;
    }

    // Add two floating-point values
    double process(double a, double b)
    {
        return a + b;
    }

    // Find sum of integer array
    int process(int arr[], int size)
    {
        int sum = 0;

        for (int i = 0; i < size; i++)
        {
            sum += arr[i];
        }

        return sum;
    }

    // Add two integers using pointers
    int process(int *a, int *b)
    {
        return *a + *b;
    }
};

int main()
{
    DataProcessor obj;

    int choice;

    cout << "===== Overloaded Data Processor =====" << endl;
    cout << "1. Process two integers" << endl;
    cout << "2. Process an integer and floating-point value" << endl;
    cout << "3. Process two floating-point values" << endl;
    cout << "4. Process an integer array" << endl;
    cout << "5. Process two integer pointers" << endl;

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

            cout << "Result = "
                 << obj.process(a, b) << endl;

            break;
        }

        case 2:
        {
            int a;
            double b;

            cout << "Enter integer: ";
            cin >> a;

            cout << "Enter floating-point value: ";
            cin >> b;

            cout << "Result = "
                 << obj.process(a, b) << endl;

            break;
        }

        case 3:
        {
            double a, b;

            cout << "Enter first floating-point value: ";
            cin >> a;

            cout << "Enter second floating-point value: ";
            cin >> b;

            cout << "Result = "
                 << obj.process(a, b) << endl;

            break;
        }

        case 4:
        {
            int size;

            cout << "Enter array size: ";
            cin >> size;

            int arr[size];

            cout << "Enter " << size << " integers:" << endl;

            for (int i = 0; i < size; i++)
            {
                cin >> arr[i];
            }

            cout << "Array sum = "
                 << obj.process(arr, size) << endl;

            break;
        }

        case 5:
        {
            int a, b;

            cout << "Enter first integer: ";
            cin >> a;

            cout << "Enter second integer: ";
            cin >> b;

            cout << "Result using pointers = "
                 << obj.process(&a, &b) << endl;

            break;
        }

        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}