#include <iostream>
using namespace std;

class Display
{
public:
    // Display integer
    void show(int value)
    {
        cout << "Integer: " << value << endl;
    }

    // Display floating-point number
    void show(double value)
    {
        cout << "Floating-point value: "
             << value << endl;
    }

    // Display character
    void show(char value)
    {
        cout << "Character: "
             << value << endl;
    }

    // Display integer array
    void show(int arr[], int size)
    {
        cout << "Integer array: ";

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    // Display character array
    void show(char arr[], int size)
    {
        cout << "Character array: ";

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    Display obj;

    int choice;

    cout << "===== Display Data =====" << endl;
    cout << "1. Display an integer" << endl;
    cout << "2. Display a floating-point number" << endl;
    cout << "3. Display a character" << endl;
    cout << "4. Display an integer array" << endl;
    cout << "5. Display a character array" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
        {
            int value;

            cout << "Enter integer: ";
            cin >> value;

            obj.show(value);

            break;
        }

        case 2:
        {
            double value;

            cout << "Enter floating-point value: ";
            cin >> value;

            obj.show(value);

            break;
        }

        case 3:
        {
            char value;

            cout << "Enter character: ";
            cin >> value;

            obj.show(value);

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

            obj.show(arr, size);

            break;
        }

        case 5:
        {
            int size;

            cout << "Enter array size: ";
            cin >> size;

            char arr[size];

            cout << "Enter " << size << " characters:" << endl;

            for (int i = 0; i < size; i++)
            {
                cin >> arr[i];
            }

            obj.show(arr, size);

            break;
        }

        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}