#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define NUM_RUNS 1000

void multiply_matrices(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int sum = 0;
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

int main() {
    int A[N][N], B[N][N], C[N][N];
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    for (int run = 0; run < NUM_RUNS; run++) {
        multiply_matrices(A, B, C);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Tempo total para realizar a multiplicação %d vezes: %lf segundos\n", NUM_RUNS, cpu_time_used);

    return 0;
}
