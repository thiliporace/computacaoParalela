#include <stdio.h>
#include <stdlib.h>

int **criaMatriz(int **M, int linhas, int colunas) {
    M = new int*[linhas];
  for (int i = 0; i < linhas; i++) {
      M[i] = new int[colunas];
  }
  return M;
}

int **preencheMatriz(int **M, int linhas, int colunas) {
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      M[i][j] = (rand() % 199) - 99;
    }
  }
  return M;
}

int **moduloMatriz(int **M, int linhas, int colunas) {
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      if (M[i][j] < 0)
        M[i][j] = abs(M[i][j]);
    }
  }
  return M;
}

void printMatriz(int **M, int linhas, int colunas) {
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      printf("%3d ", M[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int linhas = 10;
  int colunas = 10;

  int **M = criaMatriz(M, linhas, colunas);
  M = preencheMatriz(M, linhas, colunas);
    
  printf("\nMatriz original:\n");
  printMatriz(M, linhas, colunas);
    
  int **MM = moduloMatriz(M, linhas, colunas);
  printf("\nMatriz positiva:\n");
  printMatriz(MM, linhas, colunas);
}

