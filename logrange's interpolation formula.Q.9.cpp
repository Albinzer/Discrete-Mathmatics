// Write a program to find the value of y when x=10 using logrange's interpolation formula for unequal intervals.


#include <iostream>
#include <cmath>

using namespace std;

double lagrange_interpolation(double x[], double y[], int n, double x_interp) {
    double y_interp = 0;

    for (int i = 0; i < n; i++) {
        double product = 1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                product *= (x_interp - x[j]) / (x[i] - x[j]);
            }
        }
        y_interp += y[i] * product;
    }

    return y_interp;
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    double x[n], y[n];

    cout << "Enter the x values:\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Enter the y values:\n";
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    double x_interp = 10; // Set the desired x value for interpolation

    double y_10 = lagrange_interpolation(x, y, n, x_interp);
    cout << "y(10) = " << y_10 << endl;

    return 0;
}
