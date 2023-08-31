#include <iostream>
const int ELEMENTOS = 3;

void print(int m[][ELEMENTOS]) {
    std::cout << "Matriz após a soma das linhas:" << std::endl;
    for (int i = 0; i < ELEMENTOS; i++) {
        std::cout << m[1][i] << " ";
    }
}


void soma(int m[][ELEMENTOS]){
    for(int i = 0; i < 3; i++){
         m[1][i] = m[0][i] + m[1][i];
    }
    print(m);
}

void multi(int m[][ELEMENTOS]) {
    for (int i = 0; i < ELEMENTOS; i++) {
        m[1][i] = m[0][i] * m[1][i];
    }
    print(m);
}


int main() {
  int matriz[2][ELEMENTOS] = {{3, 2, 1}, {4, 5, 6}};
  int N = 3;
  soma(matriz);
  multi(matriz);
}
