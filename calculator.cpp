#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    int choice;

    cout << "=================================\n";
    cout << "   Welcome to Calculator \n";
    cout << "=================================\n";

    do {
        cout << "\nChoose an operation:\n";
        cout << "1. Addition (+)\n";
        cout << "2. Subtraction (-)\n";
        cout << "3. Multiplication (*)\n";
        cout << "4. Division (/)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 5) {
            cout << "\nThanks for using the calculator.\n";
            break;
        }

        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        switch (choice) {
            case 1:
                cout << "Result: " << num1 + num2 << endl;
                break;
            case 2:
                cout << "Result: " << num1 - num2 << endl;
                break;
            case 3:
                cout << "Result: " << num1 * num2 << endl;
                break;
            case 4:
                if (num2 != 0)
                    cout << "Result: " << num1 / num2 << endl;
                else
                    cout << "Error! Division by zero." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (true);

    return 0;
}
