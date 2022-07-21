/*
 ============================================================================
 Name        : Ejercicio2.c

 Description : ingresar 3 números y mostrar cuál de los tres es el mayor.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){

	setbuf(stdout,NULL);

	int numeroUno;
	int numeroDos;
	int numeroTres;

	printf("Ingrese un numero:");
	scanf("%d", &numeroUno);

	printf("Ingrese otro numero");
	scanf("%d", &numeroDos);

	printf("Ingrese otro numero:");
	scanf("%d", &numeroTres);

	if (numeroUno > numeroDos && numeroUno > numeroTres) {
		printf("El numero mayor es:%d", numeroUno);
	} else if (numeroDos > numeroTres) {
		printf("El numero mayor es:%d", numeroDos);
	} else {
		printf("El numero mayor es:%d", numeroTres);
	}


	return 0;
}
