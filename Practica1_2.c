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
  for(int i=4; i<25; i=i+4){
    if(!strcmp(ei,tabla[i]))
    aux = i;
  }

  if(!strcmp(c,tabla[1]))
    *ef = tabla[aux+1];
  else if(!strcmp(c,tabla[2]))
    *ef = tabla[aux+2];
  else if(!strcmp(c,tabla[3]))
    *ef = tabla[aux+3];
}

int edoAcep(char estado[], char *finales[]){
  int res = 1;
  for(int i=0; i<2; i++){ // Compara todos los estados de aceptacion
    if(!strcmp(estado, finales[i])){
      res = 0;
      break;
    }
  }
  return res;
}


int main() {
  char *matriz[] = {  " ", "a", "b", "c",         // Declaracion de matriz delta
                      "s0", "s1", "-", "s2",
                      "s1", "-", "s3", "-",
                      "s2", "-", "-", "-",
                      "s3", "s4", "-", "s2",
                      "s4", "-", "s5", "-",
                      "s5", "s4", "-", "s2" };

  char *finales[] = { "s2", "s3" };
  char cadena[N];
  char *estado = "s0";  // Se inicializa en s0
  int i = 0;

  printf("Introduce una cadena de la forma \"ab|(ab)*c\" : ");
  scanf("%s", cadena);

  char aux = cadena[0];   // Se inicializa en el primer caracter de la cadena
  char car[] = { aux, '\0' };

  while ( (strcmp(car,"\0")) != 0 ) {   // mientras no sea fin de cadena

    delta( estado, car, matriz , &estado );  // se asigna a estado el estado al que es mandado con ese caracter
    aux = sigCar( cadena, &i );    // Se recorre la cadena
    char aux2[] = { aux, '\0' };
    strcpy( car,aux2 );

    if( !(strcmp(estado,"-")) )  // Se compara si se llego a un estado de error
      break;
  }

  if(!(strcmp(estado,"-")))
    printf("Error\n");
  else if(!edoAcep(estado, finales))
    printf("Exito\n");
  else
  printf("Error\n");

  return 0;
}
