/*
 ============================================================================
 Emanuel vidal division 1K - ejercicio 3 - 1 ( funciones )

 Crear una función que muestre por pantalla el número flotante que recibe como parámetro.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void numFlot(float numero);

int main(void) {
	setbuf(stdout,NULL);

	float numDec = 0.25;

	numFlot(numDec);


	return EXIT_SUCCESS;
}

void numFlot(float numero){
	printf("El numero flotante es %.2f",numero);
}
