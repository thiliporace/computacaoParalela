#include <stdio.h>
#include <math.h>
#include <omp.h>

double f(double x) {
    return exp(x);
}

double local_trap(double a, double b, int n) {
    double h = (b - a) / n;
    double local_integral = (f(a) + f(b)) / 2.0;

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        local_integral += f(x);
    }

    local_integral *= h;
    return local_integral;
}

int main() {
    double a = 0.0; 
    double b = 1.0; 
    int n = 1000000; 
    int num_threads = omp_get_max_threads();
    double integral = 0.0;

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        double thread_a = a + thread_id * (b - a) / num_threads;
        double thread_b = a + (thread_id + 1) * (b - a) / num_threads;
        int thread_n = n / num_threads;

        double local_result = local_trap(thread_a, thread_b, thread_n);

        #pragma omp atomic
        integral += local_result;
    }

    printf("Resultado da integração: %lf\n", integral);

    return 0;
}
