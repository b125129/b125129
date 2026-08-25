#include <iostream>
using namespace std;

class Calculator
{
public:
    // Add two integers
    int calculate(int a, int b) {return a + b;}

    // Add three integers
    int calculate(int a, int b, int c)  {return a + b + c;}

    // Add two float values
    double calculate(double a, double b){return a + b;}
};

int main()
{
    Calculator obj;  
    int choice;

    cout << "===== Number Calculator =====" << endl;
    cout << "1. Add two integers" << endl;
    cout << "2. Add three integers" << endl;
    cout << "3. Add two floating-point values" << endl;
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

            cout << "Result = " << obj.calculate(a, b) << endl;

            break;
        }

        case 2:
        {
            int a, b, c;

            cout << "Enter first integer: ";
            cin >> a;

            cout << "Enter second integer: ";
            cin >> b;

            cout << "Enter third integer: ";
            cin >> c;

            cout << "Result = " << obj.calculate(a, b, c) << endl;

            break;
        }

        case 3:
        {
            double a, b;

            cout << "Enter first floating-point value: ";
            cin >> a;

            cout << "Enter second floating-point value: ";
            cin >> b;

            cout << "Result = " << obj.calculate(a, b) << endl;

            break;
        }

        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}