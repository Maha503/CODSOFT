#include <iostream>
using namespace std;

int main() {
    double num1, num2; // Declare two variables to hold the numbers
    char operation;     // Variable to store the operation choice

    // Display the menu
    cout << "Basic Calculator Program\n";
    cout << "=========================\n";
    cout << "Enter two numbers and choose an operation (+, -, *, /):\n";
    
    // Take input from the user
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    // Perform the chosen operation using a switch statement
    switch (operation) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Result: " << num1 / num2 << endl;
            } else {
                cout << "Error: Division by zero is not allowed!" << endl;
            }
            break;
        default:
            cout << "Invalid operation! Please choose one of +, -, *, or /." << endl;
    }

    return 0;
}
