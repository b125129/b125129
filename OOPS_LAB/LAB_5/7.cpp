#include <iostream>
using namespace std;

class DataComparison
{
public:
    // Compare two integers
    int compare(int a, int b)
    {
        return (a > b) ? a : b;
    }

    // Compare two floating-point numbers
    double compare(double a, double b)
    {
        return (a > b) ? a : b;
    }

    // Compare two integer arrays
    bool compare(int arr1[], int arr2[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr1[i] != arr2[i])
                return false;
        }

        return true;
    }
};

int main()
{
    DataComparison obj;

    int choice;

    cout << "===== Compare Data Sets =====" << endl;
    cout << "1. Compare two integers" << endl;
    cout << "2. Compare two floating-point numbers" << endl;
    cout << "3. Compare two integer arrays" << endl;

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

            cout << "Larger value = "
                 << obj.compare(a, b) << endl;

            break;
        }

        case 2:
        {
            double a, b;

            cout << "Enter first floating-point value: ";
            cin >> a;

            cout << "Enter second floating-point value: ";
            cin >> b;

            cout << "Larger value = "
                 << obj.compare(a, b) << endl;

            break;
        }

        case 3:
        {
            int size;

            cout << "Enter size of both arrays: ";
            cin >> size;

            int arr1[size];
            int arr2[size];

            cout << "Enter elements of first array:" << endl;

            for (int i = 0; i < size; i++)
            {
                cin >> arr1[i];
            }

            cout << "Enter elements of second array:" << endl;

            for (int i = 0; i < size; i++)
            {
                cin >> arr2[i];
            }

            if (obj.compare(arr1, arr2, size))
                cout << "Both arrays are identical." << endl;
            else
                cout << "Arrays are not identical." << endl;

            break;
        }

        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}