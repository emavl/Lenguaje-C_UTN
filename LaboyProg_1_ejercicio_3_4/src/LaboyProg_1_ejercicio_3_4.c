/*
 ========================================================================================================
 Name        : Laboratorio_1_Programación_1_Guia_de_ejercicios_Funciones_3_4.c
 Author      : Emanuel vidal division 1K

 Description : Especializar la funcion anterior para que permita validar el entero ingresado en un rango
 ========================================================================================================
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
	printf("Ingrese un numero mayor a 12 y menor a 60: ");
	scanf("%d",&num);
	while ((num > 60) || (num < 12)) {
		printf("Error !! debe ingresar un \n numero mayor a 12 y menor a 60: ");
		scanf("%d", &num);
	}
	return num;
}
