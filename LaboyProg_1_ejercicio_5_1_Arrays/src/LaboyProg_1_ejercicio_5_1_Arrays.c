/*
 ============================================================================
 Name        : Arrays_guia_de_ejercicios_5_1.c
 Author      : Emanuel vidal division 1K
 Description : Pedir el ingreso de 5 números. Mostrarlos y calcular la sumatoria de los mismos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define size 5

int main(void) {
	setbuf(stdout,NULL);

	int aNumeros[size];
	int resultado;
	initArray(aNumeros,size);
	cargarArray(aNumeros, size);
	resultado = sumatoria(aNumeros, size);


	printf("La suma de los numeros es: %d",resultado);

	return EXIT_SUCCESS;
}
