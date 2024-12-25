#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//output for given data
// f(1) = 3
// f(2) = 5
// x y
// 1 3.100121 -> output
// 3 4.8
// 4 8.4
// 5 14.5
// 6 23.6
// 7 36.2
// 8 52.8
// 9 73.9
// 10 100.00121 -> output
int main() {
    double x[100], y[100], xp, yp, p;
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    printf("Enter the data points (x and y pairs):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }
    printf("Enter the value of x for which you want to find y: ");
    scanf("%lf", &xp);
    yp = 0;
    for (int i = 0; i < n; i++) {
        p = 1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                p = p * (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp = yp + p * y[i]; // Corrected line
    }
    printf("The value of y at x = %lf is %lf\n", xp, yp);
    return 0;
}
