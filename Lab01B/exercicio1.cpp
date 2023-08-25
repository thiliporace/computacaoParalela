#include <iostream>

int main() {
  int m[3][3] = {{7,8,9},{2,1,3},{5,6,4}};
  int menor = 99;
  for (int i = 0;i < 3;i++){
    for (int j = 0;j < 3;j++){
      if (menor > m[i][j]) menor = m[i][j];
    }
  }
  std::cout << menor;
}



