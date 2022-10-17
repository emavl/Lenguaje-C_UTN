/*
 * funciones.c
 *
 *  Created on: 17 oct. 2022
 *      Author: Ema
 */
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void ordenamiento(int *numeros,int size){

	int i, j;
	for (i = 0; i < size - 1; ++i) {
		for (j = i + 1; j < size; ++j) {
			if (*(numeros+i) > *(numeros+j)) {
				funcionSwap( &(*(numeros + j)), &(*(numeros + i)) );
			}
		}
	}

		printf("\nlos numeros ordenados son: ");
	for ( i = 0; i < size ; i++){
		printf("%d-",numeros[i]);
	}
}

void funcionSwap(int* primerValor,int* segundoValor)
{
	int aux;
    if(primerValor != NULL && segundoValor != NULL)
    {
    	aux = *segundoValor;
    	*segundoValor = *primerValor;
    	*primerValor = aux;
    }

}
