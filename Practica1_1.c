/* Practica 1: Diseño de un analizador lexico
para la ER "ab|(ab)*c" */
#include <stdio.h>
#include <string.h>
#define N 64

char sigCar(char[], int*);

char sigCar(char cad[], int* i){
  *i = (*i + 1);
  char c = cad[*i];
  return c;
}

int main() {
  
  return 0;
}
