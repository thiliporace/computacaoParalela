#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

//Include feito para aumentar a precisao dos decimais
#include <gmp.h>

/*As funcoes relacionadas a essa biblioteca sao responsaveis pelo calculo com numeros muito maiores
que os normais, por exemplo, um numero de tipo "double" consegue armazenar um tamanho de 10^308,
sendo assim ficaria impossivel ter uma precisao maior que essa na hora de calcular o valor de e().
Entao para isso, criamos variaveis do tipo mpf_t, que consegue armazenar valores com precisao extremamente
maiores que normalmente conseguiriamos sem estes tipos.*/



void calcTaylor(int limit, mpf_t* e) {
	mpf_t fat;
	mpf_init2(fat, 16777216); // Disponibiliza 16 milhoes de bits para a variavel fat
	mpf_set_ui(fat, 1);
	omp_set_num_threads(2);
#pragma omp parallel
	{
		mpf_t frac;
		mpf_init2(frac, 16777216); // Disponibiliza 16 milhoes de bits para a variavel frac
		mpf_set_ui(frac, 1);
		int id = omp_get_thread_num();
		int num_thrds = omp_get_num_threads();
		for (int i = id; i < limit; i = i + num_thrds) { // Loop que calcula o valor de e() ate o limite escolhido na main()
			if (i != 0) mpf_mul_ui(fat, fat, i);
			else mpf_set_ui(fat, 1);
			mpf_ui_div(frac, 1, fat);
			mpf_add(*e, *e, frac);
		}
		mpf_clear(frac);
	}
	mpf_clear(fat);
}

void save_to_file(mpf_t e, const char* filename) {
	FILE* file = fopen(filename, "w");
	if (file == NULL) {
		perror("Erro ao abrir o arquivo");
		return;
	}
	gmp_fprintf(file, "%.3000000Ff\n", e); // Salva em arquivo printando 3 milhoes de digitos
	fclose(file);
}

int main() {
	double start = omp_get_wtime();
	int limit = 500;
	mpf_t e;
	mpf_init2(e, 16777216);
	mpf_set_ui(e, 0);
	calcTaylor(limit, &e);
	save_to_file(e, "ValorParalelo.txt");
	double end = omp_get_wtime();
	printf("Tempo gasto para calcular o valor de e: %f", end - start);
	mpf_clear(e);
}
