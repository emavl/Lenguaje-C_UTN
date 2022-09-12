/*
 * transformacion.c
 *
 *  Created on: 1 sep. 2022
 *      Author: Emaaaaaaa !!!!
 */
#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#include "transformacion.h"

void pasajeValor(int valor){

	char letra;
	float resultado;
	printf("\n||————————————————————————————————————————————————————————————————————————————||");
	printf("\n||                Que valor de temperatura desea trasformar                   || ");
	printf("\n||————————————————————————————————————————————————————————————————————————————||");
	printf("\n\n");
	printf("\na) -----► fahrenheit a Celsius ");
	printf("\nb) -----► celsius a fahrenheit ");
	fflush(stdin);
	scanf("%c", &letra);
	if (letra == 'a') { //-------------------------► farenheit
		resultado = (valor - 32) * 0.5556;
		printf("\nEl valor ingresado en fahrenheit y pasado a Celsius es: %.2f",resultado);
	} else {
		if (letra == 'b') { // --------------------► Celsius
			resultado = (valor * 1.8) + 32;
			printf("\nEl valor ingresado en Celsius y pasado a fahrenheit es: %.2f°",resultado);
		}
	}
}

