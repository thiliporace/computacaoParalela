#include <iostream>

void transposta(int v[][3], int m[][2], int colunas, int linhas) {
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      m[i][j] = v[j][i];
    }
  }
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      std::cout << m[i][j] << "\n";
    }
  }
}

int main() {
  const int linhas = 3;
  const int colunas = 2;
  int v[colunas][linhas] = {{1, 2, 3}, {4, 5, 6}};
  int m[linhas][colunas];

  transposta(v, m, colunas, linhas);
}
