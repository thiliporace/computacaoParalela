#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define N 1000 

int main() {
    int **A, **B, **C;

    A = (int **)malloc(N * sizeof(int *));
    B = (int **)malloc(N * sizeof(int *));
    C = (int **)malloc(N * sizeof(int *));
    
    for (int i = 0; i < N; i++) {
        A[i] = (int *)malloc(N * sizeof(int));
        B[i] = (int *)malloc(N * sizeof(int));
        C[i] = (int *)malloc(N * sizeof(int));
    }

    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int local_sum = 0;
                for (int k = 0; k < N; k++) {
                    local_sum += A[i][k] * B[k][j];
                }
                #pragma omp critical
                C[i][j] = local_sum;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}

