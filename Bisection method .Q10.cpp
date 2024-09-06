//  write a program to find a real root of the equation x^2-4x-10=0 , that lies between -2 and -1.5 using bisection method.


#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x * x - 4 * x - 10;  // Define the function for which to find the root
}

double bisection(double a, double b, double tol) {
    // Check if the root is bracketed in the interval [a, b]
    if (f(a) * f(b) >= 0) {
        cout << "No root found in the given interval." << endl;
        return 0;
    }

    double c = a;
    while (abs(f(c)) > tol) {
        c = (a + b) / 2;  // Calculate midpoint
        if (f(c) == 0.0)  // Check if c is a root
            break;
        else if (f(c) * f(a) < 0) {
            b = c;  // The root lies in the left half
        } else {
            a = c;  // The root lies in the right half
        }
    }

    return c;  // Return the computed root
}

int main() {
    double a, b, tol;
    cout << "Enter the values of a and b: ";
    cin >> a >> b;

    cout << "Enter the tolerance value: ";
    cin >> tol;

    double root = bisection(a, b, tol);
    if (root != 0) {
        cout << "The root is: " << root << endl;
    }

    return 0;
}
