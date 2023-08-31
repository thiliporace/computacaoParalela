#include <iostream>
#include <cstring>

const int POSICAO = 3;
void add(char str[100], char letra)
{
	int tamanho = strlen(str);
	for (int i = tamanho; i > POSICAO; i--) 
		str[i] = str[i - 1];
	str[POSICAO] = letra;
	std::cout << str << std::endl;
}

int main() {
	char letra = 'P';
	char Str[100]  = { "ABdDUIAHDddadDKJ92" };
	add(Str,letra);
}	
