/*
 * operaciones.h
 *
 *  Created on: 24 sep. 2022
 *      Author: Ema
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_

float promedio(int confederacion, int jugadores );
int sumaMant(int costHospedaje, int costComida, int costTransporte);
int sumaJugadores(int arqueros, int defensores, int medioCampistas, int delanteros);
void aumento(float *aumEuropea,float *pDescuento, float promUEFA,int gastoMant);
float aumentoUEFA(float *aumEuropea, float confederacion, float promUEFA,
		int gastoMant, float *pDescuento);

#endif /* OPERACIONES_H_ */
