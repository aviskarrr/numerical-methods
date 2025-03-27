#include <stdio.h>
#include <math.h>

// Define the function f(x, y, z) = y'' (example: y'' = -y)
double f(double x, double y, double z) {
    return -y; // Example: Simple harmonic motion y'' + y = 0
}

// Runge-Kutta 4th Order Method for 2nd Order ODE
void RK4(double x0, double y0, double z0, double h, int n) {
    double x = x0, y = y0, z = z0;

    printf("x\t\ty\t\tz (y')\n");
    printf("%.5lf\t%.5lf\t%.5lf\n", x, y, z);

    for (int i = 0; i < n; i++) {
        // Compute Runge-Kutta coefficients
        double K1 = h * z;
        double L1 = h * f(x, y, z);

        double K2 = h * (z + L1 / 2);
        double L2 = h * f(x + h / 2, y + K1 / 2, z + L1 / 2);

        double K3 = h * (z + L2 / 2);
        double L3 = h * f(x + h / 2, y + K2 / 2, z + L2 / 2);

        double K4 = h * (z + L3);
        double L4 = h * f(x + h, y + K3, z + L3);

        // Update y and z
        y += (K1 + 2 * K2 + 2 * K3 + K4) / 6;
        z += (L1 + 2 * L2 + 2 * L3 + L4) / 6;
        x += h;

        printf("%.5lf\t%.5lf\t%.5lf\n", x, y, z);
    }
}

int main() {
    double x0 = 0.0, y0 = 1.0, z0 = 0.0; // Initial conditions: y(0) = 1, y'(0) = 0
    double h = 0.1; // Step size
    int n = 20; // Number of steps

    RK4(x0, y0, z0, h, n);

    return 0;
}
