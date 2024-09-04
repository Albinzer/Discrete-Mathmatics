// write a program to find a  real root of the function x^2-x-2=0 in the range 1<x<3 using false position method .

#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return x * x - x - 2;
}

double falsePosition(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        cout << "No root found in the given interval." << endl;
        return 0;
    }

    double c;
    while (abs(f(c)) > tol) {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    return c;
}

int main() {
    double a, b, tol;

    cout << "Enter the initial interval endpoints (a and b): ";
    cin >> a >> b;

    cout << "Enter the desired tolerance: ";
    cin >> tol;

    double root = falsePosition(a, b, tol);

    if (root != 0) {
        cout << "The root is approximately: " << root << endl;
    }

    return 0;
}
