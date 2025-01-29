#include <stdio.h>

#define N 3  // Number of equations

void gaussian_elimination(double A[N][N+1], double x[N]) {
    int i, j, k;
    
    // Forward elimination
    for (i = 0; i < N; i++) {
        // Partial pivoting (if needed)
        for (k = i + 1; k < N; k++) {
            double factor = A[k][i] / A[i][i];
            for (j = i; j <= N; j++) {
                A[k][j] -= factor * A[i][j];
            }
        }
    }
    
    // Back substitution
    for (i = N - 1; i >= 0; i--) {
        x[i] = A[i][N];
        for (j = i + 1; j < N; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
}

int main() {
    double A[N][N+1] = {
        {1, 2, 3, 6},
        {2, 3, 5, 10},
        {2, -1, 3, 4}
    };
    double x[N];
    
    gaussian_elimination(A, x);
    
    printf("Solution: \n");
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %.6lf\n", i, x[i]);
    }
    
    return 0;
}

//answer:
// x = 1.000000
// y = 1.000000
// z = 1.000000

