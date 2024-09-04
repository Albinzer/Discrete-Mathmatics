// Write a program to find the f(7.5) from the following table  using newton _ gregory backward interpolation formula

#include <iostream>
#include <cmath>

using namespace std;

double newton_gregory_backward_interpolation(double x[], double y[], int n, double x_interp) {
    double h = x[1] - x[0];
    double u = (x_interp - x[n - 1]) / h;

    double y_interp = y[n - 1];

    for (int i = 1; i < n; i++) {
        double product = 1;
        for (int j = 0; j < i; j++) {
            product *= (u + j);
        }
        y_interp += (product / std::tgamma(i + 1)) * (y[n - i] - y[n - i - 1]);
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

    double x_interp;
    cout << "Enter the value for interpolation: ";
    cin >> x_interp;

    double f_7_5 = newton_gregory_backward_interpolation(x, y, n, x_interp);
    cout << "f(7.5) = " << f_7_5 << endl;

    return 0;
}
