#include <iostream>
using namespace std;

class Search
{
public:
    // Search an integer in an integer array
    int find(int arr[], int size, int key)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == key)
                return i;
        }

        return -1;
    }

    // Search a character in a character array
    int find(char arr[], int size, char key)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == key)
                return i;
        }

        return -1;
    }

    // Search an integer within a specified range
    int find(int arr[], int start, int end, int key)
    {
        for (int i = start; i <= end; i++)
        {
            if (arr[i] == key)
                return i;
        }

        return -1;
    }
};

int main()
{
    Search obj;

    int choice;

    cout << "===== Element Search =====" << endl;
    cout << "1. Search integer in integer array" << endl;
    cout << "2. Search character in character array" << endl;
    cout << "3. Search integer within a specified range" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
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

            int key;

            cout << "Enter integer to search: ";
            cin >> key;

            int position = obj.find(arr, size, key);

            if (position != -1)
                cout << "Element found at index: "
                     << position << endl;
            else
                cout << "Element not found." << endl;

            break;
        }

        case 2:
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

            char key;

            cout << "Enter character to search: ";
            cin >> key;

            int position = obj.find(arr, size, key);

            if (position != -1)
                cout << "Character found at index: "
                     << position << endl;
            else
                cout << "Character not found." << endl;

            break;
        }

        case 3:
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

            int start, end, key;

            cout << "Enter starting index: ";
            cin >> start;

            cout << "Enter ending index: ";
            cin >> end;

            if (start < 0 || end >= size || start > end)
            {
                cout << "Invalid range!" << endl;
                break;
            }

            cout << "Enter integer to search: ";
            cin >> key;

            int position = obj.find(arr, start, end, key);

            if (position != -1)
                cout << "Element found at index: "
                     << position << endl;
            else
                cout << "Element not found in the specified range."
                     << endl;

            break;
        }

        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}