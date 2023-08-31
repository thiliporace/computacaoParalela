#include <iostream>
#include <cstring>
const int POSICAO = 3;

void remove(char str[100])
{
	int tamanho = strlen(str);
	for (int i = POSICAO - 1; i < tamanho;) {
		str[i] = str[i + 1];
		i++;
	}
	std::cout << str << std::endl;
}

int main() {
	char Str[100]  = { "ABdDUIAHDddadDKJ92" };
	remove(Str);
}
