//  write a program to find a real root of the equation x^2-4x-10=0 , that lies between -2 and -1.5 using bisection method.


#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return x * x - 4 * x - 10;
}

double bisection(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        cout << "No root found in the given interval." << endl;
        return 0;
    }

    double c = a;
    while (abs(f(c)) > tol) {
        c = (a + b) / 2;
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

    double root = bisection(a, b, tol);

    if (root != 0) {
        cout << "The root is approximately: " << root << endl;
    }

    return 0;
}
