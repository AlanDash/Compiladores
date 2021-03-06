/* Practica 1: Diseño de un analizador lexico
para la ER "(a|b)*a(a|b)(a|b)" */
#include <stdio.h>
#include <string.h>
#define N 64

char sigCar(char[], int*);
void delta(char[], char [], char *[] ,char**);
int edoAcep(char[], char *[]);

char sigCar(char cad[], int *i){
  *i = (*i + 1);
  char c = cad[*i];
  return c;
}

void delta(char ei[], char c[], char *tabla[], char **ef){
  int aux = 0;
  for(int i=3; i<28; i=i+3){
    if(!strcmp(ei,tabla[i])){
    aux = i;
    break;
    }
  }

  if(!strcmp(c,tabla[1]))
    *ef = tabla[aux+1];
  else if(!strcmp(c,tabla[2]))
    *ef = tabla[aux+2];
}

int edoAcep(char estado[], char *finales[]){
  int res = 1;
  for(int i=0; i<4; i++){ // Compara todos los estados de aceptacion
    if(!strcmp(estado, finales[i])){
      res = 0;
      break;
    }
  }
  return res;
}


int main() {
  char *matriz[] = {  " ", "a", "b",
                      "g11", "g12", "g11",
                      "g12", "g5", "g6",
                      "g5", "g7", "g8",
                      "g7", "g7", "g8",
                      "g6", "g9", "g10",
                      "g8", "g9", "g10",
                      "g10", "g12", "g11",
                      "g9", "g5", "g6" };

  char *finales[] = { "g10", "g9", "g8", "g7" };
  char cadena[N];
  char *estado = "g11";  // Se inicializa en g11
  int i = 0;

  printf("Introduce una cadena de la forma \"(a|b)*a(a|b)(a|b)\" : ");
  scanf("%s", cadena);
  char aux = cadena[0];   // Se inicializa en el primer caracter de la cadena
  char car[] = { aux, '\0' };

  while ( (strcmp(car,"\0")) != 0 ) {   // mientras no sea fin de cadena

    delta( estado, car, matriz , &estado );  // se asigna a estado el estado al que es mandado con ese caracter
    aux = sigCar( cadena, &i );    // Se recorre la cadena
    char aux2[] = { aux, '\0' };
    strcpy( car,aux2 );

  }

  if(!edoAcep(estado, finales))
    printf("Exito\n");
  else
  printf("Error\n");

  return 0;
}
