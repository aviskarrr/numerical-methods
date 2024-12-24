#include<stdio.h>
#include<math.h>

double fals_fun(double x){
    return (x*x - 4*x - 10);
}

double fals_fun2(double x){
    return (x * tan(x) - 1);
}

int main(){
    double x0, x1, x2, f0, f1, f2, e;
    int step = 1;

    printf("Enter two initial guesses:\n");
    while (1) {
        scanf("%lf%lf", &x1, &x2);
        f1 = fals_fun2(x1);
        f2 = fals_fun2(x2);

        // Check if guesses bracket the root
        if (f1 * f2 > 0) {
            printf("Incorrect initial guesses. They must bracket the root.\n");
            printf("f(x1) = %.6f, f(x2) = %.6f\n", f1, f2);
            printf("Enter two new initial guesses:\n");
        } else {
            break;
        }
    }

    printf("Enter the tolerable error:\n");
    scanf("%lf", &e);

    printf("\nStep\t\tx1\t\tx2\t\tx0\t\tf(x0)\n");

    do {
        // False Position formula
        x0 = ((x1 * f2) - (x2 * f1)) / (f2 - f1);
        f0 = fals_fun2(x0);

        printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\n", step, x1, x2, x0, f0);

        // Update interval based on the sign of f(x0)
        if (f1 * f0 < 0) {
            x2 = x0;
            f2 = f0;
        } else {
            x1 = x0;
            f1 = f0;
        }

        step++;
    } while (fabs(f0) > e);

    printf("\nRoot is: %.6f\n", x0);
    return 0;
}
