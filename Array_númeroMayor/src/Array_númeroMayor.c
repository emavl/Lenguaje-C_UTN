/*
 ============================================================================
 Name        : Ejercicio2.c

 Description : ingresar 3 números y mostrar cuál de los tres es el mayor.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

#define size 3

int main(void){

	setbuf(stdout,NULL);

	int aNumeros[size];
	int numero;

	initArray(aNumeros,size);
	cargarArray(aNumeros, size);
	mayorNumero(aNumeros,&numero);
	printf("\nEl mayor numero es %d", numero);

	return 0;
}


