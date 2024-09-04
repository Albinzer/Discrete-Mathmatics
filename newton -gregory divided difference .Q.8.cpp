//  Write a program to find the value of f(15) fromt he following table using newton -gregory divided difference formula for unequal intervals .

#include <iostream>
#include <cmath>

using namespace std;

double newton_gregory_divided_difference(double x[], double y[], int n, double x_interp) {
    double divided_diff[n][n];

    // Calculate divided differences
    for (int i = 0; i < n; i++) {
        divided_diff[i][0] = y[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            divided_diff[j][i] = (divided_diff[j + 1][i - 1] - divided_diff[j][i - 1]) / (x[j + i] - x[j]);
        }
    }

    // Calculate interpolated value
    double y_interp = y[0];
    double product = 1;

    for (int i = 1; i < n; i++) {
        product *= (x_interp - x[i - 1]);
        y_interp += product * divided_diff[0][i];
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

    double f_15 = newton_gregory_divided_difference(x, y, n, x_interp);
    cout << "f(15) = " << f_15 << endl;

    return 0;
}
