#include <iostream>
#include <string>

char LETRA = 'a';

void retorna(std::string aux) 
{
	std::size_t found = aux.find(LETRA);
	if (found != std::string::npos)
		std::cout << "Achado em: " << found+1 << "º" << std::endl;
	else
		std::cout << "Nao pertence" << std::endl;
}

int main() {
	std::string aux = { "ABdDUIAHDddadDKJ92" };
	retorna(aux);
}
