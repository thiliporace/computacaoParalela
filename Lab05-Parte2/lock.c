#include <stdio.h>
#include <omp.h>

#define N 1000
#define NUM_THREADS 2

int A[N][N], B[N][N], C[N][N];
omp_lock_t lock; // Declaração do lock

void multiply_matrices(int start_row, int end_row) {
    for (int i = start_row; i < end_row; i++) {
        for (int j = 0; j < N; j++) {
            int sum = 0;
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }

            // Bloqueia a atualização da matriz C
            omp_set_lock(&lock);

            C[i][j] = sum;

            // Libera o lock
            omp_unset_lock(&lock);
        }
    }
}

int main() {
    double start = omp_get_wtime();
    omp_init_lock(&lock); // Inicializa o lock

#pragma omp parallel num_threads(NUM_THREADS)
    {
        int thread_id = omp_get_thread_num();
        int chunk_size = N / NUM_THREADS;
        int start_row = thread_id * chunk_size;
        int end_row = (thread_id == NUM_THREADS - 1) ? N : start_row + chunk_size;

        multiply_matrices(start_row, end_row);
    }

    // Liberar o lock
    omp_destroy_lock(&lock);
    double end = omp_get_wtime();
    printf("time spent in this process: %f", end - start);
    return 0;
}
