/*
 ============================================================================
 Name        : Array_Guia_de_ejercicios_5_2.c
 Author      : Emanuel vidal division 1K

 Description : Pedir el ingreso de 10 números enteros entre -1000 y 1000. Determinar:

	a) Cantidad de positivos y negativos.
	b) Sumatoria de los pares.
	c) El mayor de los impares.
	d) Listado de los números ingresados.
	e) Listado de los números pares.
	f) Listado de los números de las posiciones impares.

Anexo 5-2

	g) Los números que se repiten
	h) Los positivos creciente y los negativos de manera decreciente
	Se deberán utilizar funciones y vectores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define size 10

int main(void) {
	setbuf(stdout,NULL);

	int ingresoNum[size];
	int positivos = 0;
	int negativos = 0;
	int numerosPares;
	int maximoImpar;

	initArray(ingresoNum, size);
	cargarArray(ingresoNum, "Ingrese un numero por favor: ","Error ! , reingrese el número por favor", size);
	numPosyNeg(ingresoNum, size, &positivos, &negativos);
	SumatoriaPares(ingresoNum, size, &numerosPares, &maximoImpar);
	mostrar(ingresoNum, size);
	ordenamiento(ingresoNum, size);

	return EXIT_SUCCESS;
}
