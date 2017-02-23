/* Practica 1: Diseño de un analizador lexico
para la ER "ab|(ab)*c" */
#include <stdio.h>
#include <string.h>
#define N 64

char sigCar(char[], int*);

char sigCar(char cad[], int *i){
  *i = (*i + 1);
  char c = cad[*i];
  return c;
}

int main() {
  char matriz[][7] = {" ", "a", "b", "c",
                      "s0", "s1", "-", "s2",
                      "s1", "-", "s3", "-",
                      "s2", "-", "-", "-",
                      "s3", "s4", "-", "s2",
                      "s4", "-", "s5", "-",
                      "s5", "s4", "-", "s2"};

                      
  return 0;
}
