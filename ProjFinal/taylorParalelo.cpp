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


void factorial(mpf_t result, int limit){
	mpf_set_ui (result,1);
	for (int i = 2; i <= limit;i++){
		mpf_mul_ui(result,result,i);
	}
}

void calcTaylor(int limit, mpf_t e) {
	omp_set_num_threads(2);
	#pragma omp parallel
	{
		int id = omp_get_thread_num();
		int num_thrds = omp_get_num_threads();
		int local_n = limit / num_thrds;
        int start = id * local_n;
        int end = (id + 1) * local_n - 1;
        if (id == num_thrds - 1) {
            end = limit;
        }

		mpf_t frac, elocal;
		mpf_init2(elocal, 67108864);
		mpf_init2(frac, 67108864); // Disponibiliza 67 milhoes de bits para a variavel frac
		mpf_set_ui(frac, 1);
		mpf_set_ui(elocal, 0);

		factorial(frac,start);
		mpf_ui_div(frac,1,frac);

		for (int i = start; i < end; ++i) { 
			mpf_add(elocal,elocal,frac);
			mpf_div_ui(frac,frac,i+1);
		}
		
		#pragma omp critical
		mpf_add(e,e,elocal);

		mpf_clear(frac);
		mpf_clear(elocal);
	}
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
	int limit = 500;
	mpf_t e;
	mpf_init2(e, 67108864);
	mpf_set_ui(e, 0);
	double start = omp_get_wtime();
	calcTaylor(limit, e);
	save_to_file(e, "ValorParalelo.txt");
	double end = omp_get_wtime();
	printf("Tempo gasto para calcular o valor de e: %f", end - start);
	mpf_clear(e);
}
