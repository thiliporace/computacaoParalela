#include <iostream>

int main() {
  float notas[3] = {5.5,3.2,9.3};
  float media = (notas[0]+notas[1]+notas[2])/3;
  float MA = (notas[0]+notas[1]*2+notas[2]*3+media)/7;
  if (MA >= 9) std::cout << "A";
  else if ((9 > MA) && (MA >= 7.5)) std::cout << "B";
  else if ((7.5 >  MA) && (MA >= 6)) std::cout << "C";
  else if ((6 > MA) && (MA >= 4)) std::cout << "D";
  else if (MA < 4) std::cout << "E";
}
