#include <stdio.h>
#include <math.h>

// Given equation is y' = 1 + 3x^2
// y(1) = 2
// y(2.5) = ?

double fd(double x) {
    return 1 + 3 * x * x;
}

int main() {
    double x0 = 1, y0 = 2, xn = 2.5, h = 0.0001;
    int n = (int)((xn - x0) / h);
    double x = x0, y = y0;

    for (int i = 0; i < n; i++) {
        y = y + h * fd(x);
        x = x + h;
    }

    printf("Euler's method: y(%lf) = %lf\n", x, y);

    return 0;
}

// at h = 0.25, y(2.5) = 16.203125
// at h = 0.5, y(2.5) = 14.375
