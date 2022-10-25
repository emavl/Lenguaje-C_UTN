/*
 ============================================================================
 Name        : Ordenamiento.c
 Author      : Emanuel vidal division 1K
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main(void) {
	setbuf(stdout,NULL);

	int i;
	int j;
	int numeros [] = {8,3,1,7,2};
	int aux;


//    ◄------  ordenamiento ascendente  -------►

	for (i = 0; i < TAM - 1; ++i) { // menos 1 por que no llega al final


		for (j = i + 1; j < TAM; ++j) {
			if (numeros[i] > numeros[j]) {
				aux = numeros[i];
				numeros[i] = numeros[j];
				numeros[j] = aux;

			}

		}
	}

	for ( i = 0; i < TAM ; i++){
		printf("\nlos numeros ordenados son: %d",numeros[i]);
	}


	return EXIT_SUCCESS;
}
