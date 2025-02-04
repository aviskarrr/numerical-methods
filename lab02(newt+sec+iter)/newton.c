#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define f(x) (x*x - 4*x - 10)


#define g(x) (2*x -4)

int main() {
    float x0, x1, f0, f1, g0, e;
    int step = 1, N; 

    /* Inputs */

    printf("\nEnter initial guess:\n");
    scanf("%f", &x0);
    printf("Enter tolerable error:\n");

    scanf("%f", &e);
    printf("Enter maximum iterations:\n");
    scanf("%d", &N);

    /* Implementing Newton-Raphson Method */
    printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");

    do {
        g0 = g(x0);
        f0 = f(x0);

        if (g0 == 0.0) {
            printf("Mathematical Error: Derivative is zero at x = %.6f.\n", x0);
            exit(1);
        }

        // Calculate next approximation
        x1 = x0 - f0 / g0;

        // Calculate f(x1) for convergence check
        f1 = f(x1);

        // Print current step
        printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\n", step, x0, f0, x1, f1);

        x0 = x1; // Update x0 for next iteration
        step++;

        // Check if the number of iterations exceeds the maximum limit
        if (step > N) {
            printf("Not Convergent: Maximum iterations reached.\n");
            exit(1);
        }

    } while (fabs(f1) > e);

    printf("\nRoot is: %.6f\n", x1);
    return 0;
}
