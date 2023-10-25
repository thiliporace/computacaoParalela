#include <stdio.h>
#include <math.h>

double f(double x){
  return exp(x);
}

int main(void){
  double b = 2,a = 0,n = 1000;
  double h = (b-a)/n;
  double approx = (f(a) + f(b))/2.0;
  for (int i = 1;i <= n-1;i++){
    double x_i = a + i*h;
    approx += f(x_i);
  }
  approx = h*approx;
  printf("Valor aproximado para a area do trapezio: %f\n", approx);
}
