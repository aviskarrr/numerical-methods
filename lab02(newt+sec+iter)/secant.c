#include <stdio.h>
#include <math.h>

// Function definition
double secant_fun(double x) {
    return (x * x - 4 * x - 10);
}

int main() {
    double x0, x1, x2, f0, f1, f2, e;
    int step = 1;

    // Input initial guesses and tolerable error
    printf("Enter two initial guesses:\n");
    scanf("%lf%lf", &x0, &x1);

    printf("Enter the tolerable error:\n");
    scanf("%lf", &e);

    // Calculate initial function values
    f0 = secant_fun(x0);
    f1 = secant_fun(x1);

    printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");

    do {
        // Secant method formula
        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        f2 = secant_fun(x2);

        // Print the current step
        printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\n", step, x0, x1, x2, f2);

        // Update values for the next iteration
        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;

        step++;
    } while (fabs(f2) > e);

    // Print the root
    printf("\nRoot is: %.6f\n", x2);
    return 0;
}
