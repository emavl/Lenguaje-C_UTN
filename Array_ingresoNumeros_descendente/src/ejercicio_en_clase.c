/*
 ============================================================================
 Name        : Ejercicio_5_0.c
 Author      : Emanuel vidal division 1K

Pedir cinco números y mostrarlos desde el último que pedi hasta el primero

Por ejemplo:

Pedí
3-5-2-4-7

Tengo que devolver
7-4-2-5-3


 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAM 5

int main(void) {
	setbuf(stdout,NULL);

	int aNumeros[TAM];

	initArray(aNumeros,TAM);
	cargarArray(aNumeros, TAM);
	mostrarArray(aNumeros, TAM);



	return 0;
}
