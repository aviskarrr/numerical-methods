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

void gauss_jordan(double A[N][N+1], double x[N]) {
    int i, j, k;
    
    // Forward elimination and making diagonal 1
    for (i = 0; i < N; i++) {
        double pivot = A[i][i];
        for (j = 0; j <= N; j++) {
            A[i][j] /= pivot;
        }
        
        for (k = 0; k < N; k++) {
            if (k != i) {
                double factor = A[k][i];
                for (j = 0; j <= N; j++) {
                    A[k][j] -= factor * A[i][j];
                }
            }
        }
    }
    
    // Extracting solutions
    for (i = 0; i < N; i++) {
        x[i] = A[i][N];
    }
}

int main() {
    double A[N][N+1] = {
        {2, -1, 1, 1},
        {3, 2, -4, -2},
        {-1, 0.5, -1, 0}
    };
    double x[N];
    
    printf("Solution using Gaussian Elimination:\n");
    gaussian_elimination(A, x);
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %.6lf\n", i, x[i]);
    }
    
    double B[N][N+1] = {
        {2, -1, 1, 1},
        {3, 2, -4, -2},
        {-1, 0.5, -1, 0}
    };
    
    printf("\nSolution using Gauss-Jordan Method:\n");
    gauss_jordan(B, x);
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %.6lf\n", i, x[i]);
    }
    
    return 0;
}
