//
//  main.cpp
//  exercicio7
//
//  Created by Thiago Liporace on 25/08/23.
//

#include <iostream>
#include <stdio.h>

struct Pessoa {
  float idade,altura,peso;
};

int main() {
    Pessoa pessoa[3];
    int idade[3] = {18,20,25};
    int altura[3] = {150,175,172};
    int peso[3] = {70,50,65};
    
    for (int i = 0;i<3;i++){
        pessoa[i].idade = idade[i];
        pessoa[i].altura = altura[i];
        pessoa[i].peso = peso[i];
    }
    for (int i = 0;i<3;i++){
        std::cout << pessoa[i].idade << "\n" << pessoa[i].altura << "\n" << pessoa[i].peso << "\n";
    }
}

