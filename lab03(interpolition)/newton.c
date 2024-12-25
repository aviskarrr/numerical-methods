#include<stdio.h>
#include<math.h>

int main() {
    double x[100], y[100], xp, yp = 0, p;
    int n;
    
    // Input section
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    printf("Enter the data points (x and y pairs):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }
    printf("Enter the value of x for which you want to find y: ");
    scanf("%lf", &xp);
    
    // Calculate divided differences table
    double dd[100][100];
    
    // First column is y values
    for (int i = 0; i < n; i++) {
        dd[i][0] = y[i];
    }
    
    // Calculate the divided difference table
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            dd[i][j] = (dd[i + 1][j - 1] - dd[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
    
    // Apply Newton's interpolation formula
    yp = dd[0][0];
    p = 1.0;
    
    for (int j = 1; j < n; j++) {
        p = p * (xp - x[j - 1]);
        yp = yp + p * dd[0][j];
    }
    
    // Print the result
    printf("\nDivided Difference Table:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf("%lf\t", dd[i][j]);
        }
        printf("\n");
    }
    
    printf("\nInterpolated value at x = %lf is y = %lf\n", xp, yp);
    
    return 0;
}
//##input data##
// 3 4.8
// 4 8.4
// 5 14.5
// 6 23.6
// 7 36.2
// 8 52.8
// 9 73.9

// Divided Difference Table:
// 4.800000        3.600000        1.250000        0.083333        -0.000000       -0.000000       0.000000
// 8.400000        6.100000        1.500000        0.083333        -0.000000       0.000000
// 14.500000       9.100000        1.750000        0.083333        0.000000
// 23.600000       12.600000       2.000000        0.083333
// 36.200000       16.600000       2.250000
// 52.800000       21.100000
// 73.900000

// Interpolated value at x = 1.000000 is y = 3.100000

// Divided Difference Table:
// 4.800000        3.600000        1.250000        0.083333        -0.000000       -0.000000       0.000000
// 8.400000        6.100000        1.500000        0.083333        -0.000000       0.000000
// 14.500000       9.100000        1.750000        0.083333        0.000000
// 23.600000       12.600000       2.000000        0.083333
// 36.200000       16.600000       2.250000
// 52.800000       21.100000
// 73.900000

// Interpolated value at x = 10.000000 is y = 100.000000