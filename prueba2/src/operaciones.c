/*
 * operaciones.c
 *
 *  Created on: 24 sep. 2022
 *      Author: Ema
 */
#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "operaciones.h"

float promedio(int confederacion, int jugadores ) {

	return (float)confederacion/jugadores;
}

int sumaMant(int costHospedaje, int costComida, int costTransporte) {
	return costHospedaje + costComida + costTransporte;
}

int sumaJugadores(int arqueros, int defensores, int medioCampistas, int delanteros) {
	return arqueros + defensores + medioCampistas + delanteros;
}

void aumento(float *aumEuropea, float *pDescuento, float promUEFA,int gastoMant){

	*aumEuropea = gastoMant * 0.35;

	*pDescuento = gastoMant - *aumEuropea;
}




