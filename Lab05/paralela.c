#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

double Local_trap(double a, double b, int n);

double f(double x) {
    return exp(x);
}

int main(int argc, char* argv[]) {
    double a = 0, b = 1;
    int n = 1000, thread_count;

    if (argc != 2) {
        fprintf(stderr, "Uso correto: %s <número_de_threads>\n", argv[0]);
        return 1;
    }

    thread_count = strtol(argv[1], NULL, 10);
    //printf("Enter a, b, and n\n");
    //scanf("%lf %lf %d", &a, &b, &n);

    double global_result = 0.0;
    #pragma omp parallel num_threads(thread_count)
    {
        double my_result = 0.0;
        my_result += Local_trap(a, b, n);
        #pragma omp critical
        global_result += my_result;
    }

    printf("With n = %d trapezoids, our estimate\n", n);
    printf("of the integral from %f to %f = %.14e\n", a, b, global_result);

    return 0;
}

double Local_trap(double a, double b, int n) {
    double h, x, my_result;
    int i;

    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();

    h = (b - a) / n;
    int local_n = n / thread_count;
    int local_start = my_rank * local_n;
    int local_end = local_start + local_n;

    my_result = (f(a + local_start * h) + f(a + local_end * h)) / 2.0;

    for (i = local_start + 1; i < local_end; i++) {
        x = a + i * h;
        my_result += f(x);
    }

    my_result *= h;
    return my_result;
}
