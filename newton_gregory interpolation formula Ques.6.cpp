// Write a program to find the population in the  any year using newton-Gregory  forward interpolation formula .

#include <iostream>
#include <cmath>

using namespace std;

double newton_gregory_forward_interpolation(double x[], double y[], int n, double x_interp) {
    double h = x[1] - x[0];
    double u = (x_interp - x[0]) / h;

    double y_interp = y[0];

    for (int i = 1; i < n; i++) {
        double product = 1;
        for (int j = 0; j < i; j++) {
            product *= (u - j);
        }
        y_interp += (product / std::tgamma(i + 1)) * (y[i] - y[i-1]);
    }

    return y_interp;
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    double x[n], y[n];

    cout << "Enter the x values (years):\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Enter the y values (population):\n";
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    double x_interp;
    cout << "Enter the year for interpolation: ";
    cin >> x_interp;

    double estimated_population = newton_gregory_forward_interpolation(x, y, n, x_interp);
    cout << "Estimated population in " << x_interp << ": " << estimated_population << endl;

    return 0;
}
