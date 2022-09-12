/*
 * operaciones.c
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#include "transformacion.h"

int sumaEnteros(int numUno, int numDos){
	int resul;
	return resul = numUno + numDos;
}




int CargaTemperatura() {

	char letra;
	int temp;
	printf("\n||————————————————————————————————————————————————————————————————————————————||");
	printf("\n||            Seleccione que tipo de temperatura desea ingresar               || ");
	printf("\n||————————————————————————————————————————————————————————————————————————————||");

	printf("\na) -----► fahrenheit ");
	printf("\nb) -----► celsius ");
	fflush(stdin);
	scanf("%c", &letra);
	if (letra == 'a') { //-------------------------► farenheit
		printf("\nIngrese los grados farenheit: ");
		scanf("%d", &temp);
		while (temp < 32 || temp > 212) {
			printf("\nError - debe ingrese la temperatura correspondiente dentro de los 32 a 212 grados");
			scanf("%d", &temp);
		}
	} else {
		if (letra == 'b') { // --------------------► Celsius
			printf("\nIngrese Ingrese los grados Celsius: ");
			scanf("%d", &temp);
			while (temp < 0 || temp > 100) {
				printf(" Error - debe ingrese la temperatura correspondiente dentro de los 0 a 100 grados");
				scanf("%d", &temp);
			}
		}


	}

		return temp;
}
