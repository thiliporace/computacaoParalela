#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int **criaMatriz(int **M, int linhas, int colunas) {
  M = new int *[linhas];
  for (int i = 0; i < linhas; i++) {
    M[i] = new int[colunas];
  }
  return M;
}

int **preencheMatriz(int **M, int linhas, int colunas) {
  int n;
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      M[i][j] = rand() % 199;
    }
  }
  return M;
}

int **multiplicaLinha(int **M, int linhas, int colunas) {
  int linha, n;
  cout << "Qual linha deseja multiplicar?  ";
  cin >> linha;
  cout << "E por qual número? ";
  cin >> n;
  for (int i = 0; i < colunas; i++) {
    M[linha - 1][i] *= n;
  }
  return M;
}

int **multiplicaColuna(int **M, int linhas, int colunas) {
  int coluna, n;
  cout << "Qual coluna deseja multiplicar?  ";
  cin >> coluna;
  cout << "E por qual número? ";
  cin >> n;
  for (int i = 0; i < linhas; i++) {
    M[i][coluna - 1] *= n;
  }
  return M;
}

void printMatriz(int **M, int linhas, int colunas) {
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
        cout << setw(3) << M[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  int aux;
  int linhas = 2 + (rand() % 10);
  int colunas = 2 + (rand() % 10);
  int **M = nullptr;
    
  M = criaMatriz(M, linhas, colunas);
  M = preencheMatriz(M, linhas, colunas);
  cout << "\nMatriz original:\n";
  printMatriz(M, linhas, colunas);
    
    
  cout << "\n" << "Você deseja multiplicar uma linha ou uma coluna? Digite 1 para linha e 2 para coluna: ";
  cin >> aux;
    
  if (aux == 1)
    multiplicaLinha(M, linhas, colunas);
  else
    multiplicaColuna(M, colunas, linhas);
  cout << "Matriz alterada: " << "\n";
  printMatriz(M, linhas, colunas);

  for (int i = 0; i < linhas; i++) {
    delete[] M[i];
  }
  delete[] M;

}

