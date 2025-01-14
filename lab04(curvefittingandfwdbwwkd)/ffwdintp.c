#include <stdio.h>

int main()
{
    float x[20], y[20][20];
    int i, j, n;

    /* Input Section */
    printf("Enter the number of data points (max 20): ");
    scanf("%d", &n);

    if (n > 20 || n <= 0) {
        printf("Invalid number of data points. Please enter a value between 1 and 20.\n");
        return 1;
    }

    printf("Enter data points:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i][0]);
    }

    // Forward Difference Calculation
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }

    printf("\nFORWARD DIFFERENCE TABLE:\n\n");
    printf("x\t\t");
    for (i = 0; i < n; i++) {
        printf("∆^%d y\t\t", i);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("%0.2f\t\t", x[i]);
        for (j = 0; j < n - i; j++) {
            printf("%0.2f\t\t", y[i][j]);
        }
        printf("\n");
    }

    // Backward Difference Table (simply reverse the order of printing)
    printf("\n\nBACKWARD DIFFERENCE TABLE:\n\n");
    printf("x\t\t");
    for (i = 0; i < n; i++) {
        printf("∆^%d y\t\t", i);
    }
    printf("\n");

    // Print the values in reverse order for the backward difference table
    for (i = n - 1; i >= 0; i--) {
        printf("%0.2f\t\t", x[i]);
        for (j = 0; j < n - i; j++) {
            printf("%0.2f\t\t", y[i][j]);
        }
        printf("\n");
    }

    return 0;
}
