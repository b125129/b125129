#include <iostream>
using namespace std;

class Modifier
{
public:
    // Modify an integer
    int modify(int value, int amount)
    {
        return value + amount;
    }

    // Modify a floating-point number
    double modify(double value, double amount)
    {
        return value + amount;
    }

    // Modify an integer using pointer
    void modify(int *value, int amount)
    {
        *value = *value + amount;
    }
};

int main()
{
    Modifier obj;

    int choice;

    cout << "===== Modify a Value =====" << endl;
    cout << "1. Add value to an integer" << endl;
    cout << "2. Add value to a floating-point number" << endl;
    cout << "3. Modify an integer using pointer" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
        {
            int value, amount;

            cout << "Enter integer value: ";
            cin >> value;

            cout << "Enter value to add: ";
            cin >> amount;

            cout << "Before modification: "
                 << value << endl;

            value = obj.modify(value, amount);

            cout << "After modification: "
                 << value << endl;

            break;
        }

        case 2:
        {
            double value, amount;

            cout << "Enter floating-point value: ";
            cin >> value;

            cout << "Enter value to add: ";
            cin >> amount;

            cout << "Before modification: "
                 << value << endl;

            value = obj.modify(value, amount);

            cout << "After modification: "
                 << value << endl;

            break;
        }

        case 3:
        {
            int value, amount;

            cout << "Enter integer value: ";
            cin >> value;

            cout << "Enter value to add: ";
            cin >> amount;

            cout << "Before modification: "
                 << value << endl;

            obj.modify(&value, amount);

            cout << "After modification: "
                 << value << endl;

            break;
        }

        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}