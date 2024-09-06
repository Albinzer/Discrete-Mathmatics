// Write a program to find the f(7.5) from the following table  using newton _ gregory backward interpolation formula

#include <iostream>
#include <cmath>
using namespace std;

double n_g(double x[], double y[], int n, double xip) {
    double h = x[1] - x[0];  // Correct calculation of step size
    double u = (xip - x[n-1]) / h;  // Correct calculation for u for backward interpolation
    double yip = y[n-1];  // Start from the last term in backward interpolation

    for (int i = 1; i < n; i++) {
        double pro = 1;  // Reinitialize pro for each term
        for (int j = 0; j < i; j++) {
            pro *= (u + j);  // Compute the product term
        }
        yip += (pro / std::tgamma(i + 1)) * (y[n-1] - y[n-1-i]);  // Apply the backward difference formula
    }
    
    return yip;  // Return the interpolated value
}

int main() {
    int n;
    
    cout << "Enter the value of n: ";
    cin >> n;

    double x[n], y[n];  // Initialize arrays after n is defined
    cout << "Enter the values of x: ";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Enter the values of y: ";
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    double xip;
    cout << "Enter the value of ip: ";
    cin >> xip;

    double evf = n_g(x, y, n, xip);
    cout << "Estimated value at " << xip << " is: " << evf << endl;

    return 0;
}
