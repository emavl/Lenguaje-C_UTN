/*
 * operaciones.c
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

int pedirNumero() {

	int num;
	printf("Ingrese un numero par encontrar su factorial: ");
	scanf("%d",&num);

	return num;
}

void factoria(int numero){

	int i;
	int factorial = 1;
	for (i = 1; i <= numero; ++i) {
		factorial *= i;
	}

	printf("\n El factorial del numero dado es: %d", factorial);

}
