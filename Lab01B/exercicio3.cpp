#include <iostream>
#include <string>

int main(){
  int entry = 15;
  int inicio = 0,fim = entry;
  int vet[entry];
  std::string espaco = " ";
  for (int i = 0;i < entry;i++){
    vet[i] = i+1;
  }
  if (entry%2 == 1){
    for (int i = 0;i < entry/2+1;i++){
      for (int j = inicio;j < fim;j++){
        std::cout << vet[j];
      }
      inicio++;
      fim--;
      std::cout << "\n";
      for (int j = 0;j < inicio;j++){
        std::cout << " ";
      }
    }
  }
}
