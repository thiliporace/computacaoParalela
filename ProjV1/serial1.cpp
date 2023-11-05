#include <iostream>
#include <omp.h>

double e = 0;
double previous_fat;

double fat(int num) {
	double result;
	if (num == 0) {
		result = 1;
		previous_fat = result;
		return result;
	}

	result = previous_fat * num;
	previous_fat = result;
	return result;
}

double calc_fraction(int limit,int count) {
	if (count == limit) {
		return e;
	}
	e = e + 1 / fat(count);
	count++;
	return calc_fraction(limit, count);
}

int main() {
	double start = omp_get_wtime();
	int count = 0;
	int limit = 171;
	e = calc_fraction(limit, count);
	double end = omp_get_wtime();
	std::cout << "Valor de e:" << e << "\n";
	std::cout << "Tempo para obter o valor resultante:" << end - start << "\n";
} 
