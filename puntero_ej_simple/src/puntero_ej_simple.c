/*
 ============================================================================
 Name        : puntero_ej_simple.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdin,NULL);

	int numero = 20;
	printf("El valor de la variable número es: %d",numero);
	printf("\nEl espacio en memoria es: %p",&numero);
	printf("\nEl almacenamiento o tamaño que ocupa es: %d Bytes",sizeof(numero));



	return EXIT_SUCCESS;
}
