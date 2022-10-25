/*
 ============================================================================
 Name        : punteros.c
 Author      : laboratorio/programacion clase 4 parte 2
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {
	setbuf(stdout,NULL);

	int a = 20;
	int b = 2;
	int retHuboError;
	float direccion_de_memoria;

	printf("\nla direccion de resultado en el main es :  %p", &direccion_de_memoria);

	retHuboError = dividir(a, b, &direccion_de_memoria);

	if(retHuboError == 0)
	{
		printf("\n no se puede dividir");
	}else{
		printf("\nResultado es : %f", direccion_de_memoria);
	}

	return EXIT_SUCCESS;
}
