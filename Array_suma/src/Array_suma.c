/*
 ============================================================================
 Name        :Array_suma
 Author      : Ema
 Version     :
 Copyright   : "el proceso de compilacion consta de 3 pasos ( preprocesador - compilador - linkeador )
 Description :
 Pedir el ingreso de 5 números. Mostrarlos y
 calcular la sumatoria de los mismos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define T 5
int main(void)
{
	setbuf(stdout,NULL);
	int arrayNumeros[T];
	int sumatoria = 0;
	int promedioSuma = 0;

	ingresaEnteros(arrayNumeros,T);
	sumatoria = sumaEnteros(arrayNumeros,T);
	promedioSuma = promedioArray(arrayNumeros, T);

	printf("\nLa suma es %d:  y el promedio es %d: ",sumatoria,promedioSuma);

	return 0;
}
