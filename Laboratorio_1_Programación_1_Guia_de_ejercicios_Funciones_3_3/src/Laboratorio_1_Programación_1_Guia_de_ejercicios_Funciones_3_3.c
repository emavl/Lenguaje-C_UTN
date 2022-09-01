/*
 ============================================================================
 Name        : Laboratorio_1_Programación_1_Guia_de_ejercicios_Funciones_3_3.c
 Author      : Emanuel vidal division 1K 

 Description :Crear una funcion que pida el entero y lo retorne.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int pedirNumero();

int main(void) {
	setbuf(stdout,NULL);

	int valorRetornado;

	valorRetornado = pedirNumero();
	printf("El valor retornado es: %d",valorRetornado);

	return EXIT_SUCCESS;
}

int pedirNumero() {

	int num;
	printf("Ingrese un numero: ");
	scanf("%d",&num);

	return num;
}
