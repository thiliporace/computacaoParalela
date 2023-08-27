#include <iostream>

int main(){
  int m[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
  int multiplicador_linha = 2, multiplicador_col = 3;
  //multiplica a terceira coluna por 3
  for (int i = 0;i < 3;i++){
    m[i][2] = m[i][2]*multiplicador_col;
  }
  //multiplica a segunda linha por 2
  for (int i = 0;i < 3;i++){
    m[1][i] = m[1][i]*multiplicador_linha;
  }
  for (int i = 0;i < 3;i++){
    for (int j = 0;j < 3;j++){
      std::cout << m[i][j] << " ";
    }
    std::cout << "\n";
  }
}
