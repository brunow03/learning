#include <iostream>
#include <stdexcept>

using namespace std;


double divide(double numerator, double denominator) {
    if (denominator == 0) {
        throw runtime_error("Division by zero error");
    }
    return numerator / denominator;
}

int main() {
    double num, denom, result;

    cout << "Enter the numerator: ";
    cin >> num;

    while (true) {
        cout << "Enter the denominator: ";
        cin >> denom;

        try {
            result = divide(num, denom);
            cout << "Result: " << result << endl;
            break; // Exit the loop if the division is successful
        } catch (const runtime_error& e) {
            cerr << "Error: " << e.what() << ". Please try again." << endl;
        }
    }

    return 0;
}