/*
 * input.h
 *
 *  Created on: 24 sep. 2022
 *      Author: Ema
 */

#ifndef INPUT_H_
#define INPUT_H_

int progPrincipal();
int ejecutarMenu(int *numero, float *hospedaje, float *comida,
		float *transporte, int *arqueros, int *defensores, int *medioCampistas,
		int *delanteros);
char subMenu(char *letra);
char subMenu2(char *letra, int *arq, int *def, int *medioC, int *del);
char subMenu3(char *letra);
// carga datos
int getNumeros(float *pNumero, char *mensaje, char *mensajeError);
int getRangNum(int *pNumero, char *mensaje, char *mensajeError,
		int minimo, int maximo);

void cargaCostos(float *hospedaje, float *comida, float *transporte);
int cargaJugadores(int *camiseta, int *arquero, int *defensor,
		int *mediocampista, int *delantero, int *AFC, int *CAF, int *CONCACAF, int *CONMEBOL, int *UEFA, int *OFC);

#endif /* INPUT_H_ */
