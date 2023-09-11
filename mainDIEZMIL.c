#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to allocate memory for a matrix
int** allocateMatrix(int n) {
    int** matrix = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*) malloc(n * sizeof(int));
    }
    return matrix;
}


// 6 matrix multiplication functions with different loop orders
void multiplyMatrices_ijk(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiplyMatrices_ikj(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiplyMatrices_jik(int** A, int** B, int** C, int n) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiplyMatrices_jki(int** A, int** B, int** C, int n) {
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiplyMatrices_kij(int** A, int** B, int** C, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiplyMatrices_kji(int** A, int** B, int** C, int n) {
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}


// Function to multiply matrices A and B, and store the result in matrix C
void multiplyMatrices(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}



int main() {
    int n = 10000;  // Example size
    int** A = allocateMatrix(n);
    int** B = allocateMatrix(n);
    int** C = allocateMatrix(n);

    // Fill matrices A and B with some values (for demonstration purposes, using random values)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;  // Random values between 0 and 9
            B[i][j] = rand() % 10;
        }
    }

    clock_t start, end;
    double cpu_time_used;

    // Multiply matrices using ijk order
    start = clock();
    multiplyMatrices_ijk(A, B, C, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time for ijk: %f seconds\n", cpu_time_used);

    // Multiply matrices using ikj order
    start = clock();
    multiplyMatrices_ikj(A, B, C, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time for ikj: %f seconds\n", cpu_time_used);

    // Multiply matrices using jik order
    start = clock();
    multiplyMatrices_jik(A, B, C, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time for jik: %f seconds\n", cpu_time_used);

    // Multiply matrices using jki order
    start = clock();
    multiplyMatrices_jki(A, B, C, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time for jki: %f seconds\n", cpu_time_used);

    // Multiply matrices using kij order
    start = clock();
    multiplyMatrices_kij(A, B, C, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time for kij: %f seconds\n", cpu_time_used);

    // Multiply matrices using kji order
    start = clock();
    multiplyMatrices_kji(A, B, C, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time for kji: %f seconds\n", cpu_time_used);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}

