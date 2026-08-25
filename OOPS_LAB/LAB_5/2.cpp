#include <iostream>
using namespace std;

class Comparison
{
public:
    // Find larger of two integers
    int larger(int a, int b){return (a > b) ? a : b;}

    // Find larger of two floating-point numbers
    double larger(double a, double b){return (a > b) ? a : b;}

    // Find larger of three integers
    int larger(int a, int b, int c)
    {
        int maxValue = a;

        if (b > maxValue)
            maxValue = b;

        if (c > maxValue)
            maxValue = c;

        return maxValue;
    }
};

int main()
{
    Comparison obj;

    int choice;

    cout << "===== Value Comparison =====" << endl;
    cout << "1. Compare two integers" << endl;
    cout << "2. Compare two floating-point numbers" << endl;
    cout << "3. Compare three integers" << endl;

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

            cout << "Larger value = "<< obj.larger(a, b) << endl;

            break;
        }

        case 2:
        {
            double a, b;

            cout << "Enter first floating-point number: ";
            cin >> a;

            cout << "Enter second floating-point number: ";
            cin >> b;

            cout << "Larger value = "<< obj.larger(a, b) << endl;

            break;
        }

        case 3:
        {
            int a, b, c;

            cout << "Enter first integer: ";
            cin >> a;

            cout << "Enter second integer: ";
            cin >> b;

            cout << "Enter third integer: ";
            cin >> c;

            cout << "Largest value = "<< obj.larger(a, b, c) << endl;

            break;
        }

        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}