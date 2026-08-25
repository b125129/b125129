#include <iostream>
using namespace std;

class Counter
{
public:
    // Count digits in an integer
    int count(int number)
    {
        if (number == 0)
            return 1;

        if (number < 0)
            number = -number;

        int digits = 0;

        while (number > 0)
        {
            number = number / 10;
            digits++;
        }

        return digits;
    }

    // Count elements in integer array
    int count(int arr[], int size)
    {
        return size;
    }

    // Count occurrences of a character
    int count(char arr[], int size, char key)
    {
        int occurrences = 0;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] == key)
                occurrences++;
        }

        return occurrences;
    }
};

int main()
{
    Counter obj;

    int choice;

    cout << "===== Counting Operation =====" << endl;
    cout << "1. Count digits in an integer" << endl;
    cout << "2. Count elements in an integer array" << endl;
    cout << "3. Count occurrences of a character" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
        {
            int number;

            cout << "Enter an integer: ";
            cin >> number;

            cout << "Number of digits = "
                 << obj.count(number) << endl;

            break;
        }

        case 2:
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

            cout << "Number of elements = "
                 << obj.count(arr, size) << endl;

            break;
        }

        case 3:
        {
            int size;

            cout << "Enter character array size: ";
            cin >> size;

            char arr[size];

            cout << "Enter " << size << " characters:" << endl;

            for (int i = 0; i < size; i++)
            {
                cin >> arr[i];
            }

            char key;

            cout << "Enter character to count: ";
            cin >> key;

            cout << "Number of occurrences = "
                 << obj.count(arr, size, key) << endl;

            break;
        }

        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}