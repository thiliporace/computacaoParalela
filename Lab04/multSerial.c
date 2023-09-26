#include <stdio.h>

void multSerial(int v[], int m[][1000], int x[],
                               int linhas, int colunas) {
  for (int i = 0; i < linhas; i++) {
    x[i] =
        0;

    for (int j = 0; j < colunas; j++) {
      x[i] +=
          v[j] * m[i][j];
    }
  }
}

int main() {
  int l = 1000, c = 1000;
  int v[1000];
  int m[1000][1000];
  int x[1000];
  
  for(int i = 0; i < l; i++){
    v[i] = i;
    for(int j = 0; j < c; j++){
      m[i][j] = j;
    }
  }

  multSerial(v, m, x, l, c);
}

