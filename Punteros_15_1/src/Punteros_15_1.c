/*
 ============================================================================
	Realizar el ordenamiento de un vector de enteros.
	Para ello deberán crear una función que se encargue de realizar
	el intercambio de los dos valores que se van a ordenar (función swap),
	que solo puede recibir dos parámetros.
 ============================================================================
 */

#include "funciones.h"
#define SIZE 5

int main(void) {
	setbuf(stdout,NULL);
	int numeros [] = {8,3,1,7,2};
	ordenamiento(numeros, SIZE);

	return EXIT_SUCCESS;
}
