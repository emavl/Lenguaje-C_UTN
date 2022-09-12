/*
 ============================================================================
 Name        : Laboratorio_1_Programación_1_Guia_de_ejercicios_Tema4_Bibliotecas_recursividad_4_1.c
 Author      : Emanuel vidal division 1K
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

int main(void) {
	setbuf(stdout,NULL);
	int numero;
	numero = pedirNumero();
	factoria(numero);
	return EXIT_SUCCESS;
}
