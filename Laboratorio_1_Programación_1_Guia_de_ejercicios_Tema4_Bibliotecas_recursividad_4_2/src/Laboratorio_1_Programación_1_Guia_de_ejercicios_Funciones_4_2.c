/*
 ============================================================================
 Name        : Laboratorio_1_Programación_1_Guia_de_ejercicios_Funciones_4_2.c
 Author      : Emanuel vidal division 1K

 Description :Realizar un programa que permita la carga de temperaturas en celsius y fahrenheit , validando que
	las temperaturas ingresadas estén entre el punto de congelación y ebullición del agua para cada
	tipo de escala.
	Las validaciones se hacen en una biblioteca.
	Las funciones de transformación de fahrenheit a celsius y de celsius a fahrenheit se hacen en otra
	biblioteca.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#include "transformacion.h"

int main(void) {
	setbuf(stdout, NULL);

	int valor;

	valor = CargaTemperatura();
	pasajeValor(valor);

	return EXIT_SUCCESS;
}
