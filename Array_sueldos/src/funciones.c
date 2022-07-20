//------------ F u n c i o n e s . C -------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


static void inicializarArray(int* lista[], int size);

//----------------------------------------------------

void numArray(int lista[], char *mensaje, int size) {
	inicializarArray(&lista, size);
	int i;
	if (mensaje != NULL) {
		for (i = 0; i < size; i++){ // el array va siempre acompañado de un for

			printf("%s", mensaje);
			scanf("%d", &lista[i]);
			break;
		}
	}
}

//----------------------------------------------------

float promedioArray ( int Array[], int size ){

	int i;
	float resultado;
	int  suma=0;

	for ( i=0; i < size ; i++){
		suma += Array[i];
	}
	resultado =((float) suma ) / size;

	return resultado;
}

//----------------------------------------------------

static void inicializarArray(int* lista[], int size) {
	int i;

	for (i = 0; i < size; i++) {
		lista[i] = 0;
	}
}

//----------------------------------------------------

void printArray(int array[],int size)
{
	int i;
	for ( i=0; i< size; i++)
	{
		printf ("%d", array[i]);
	}
}
