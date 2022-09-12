/*
 ============================================================================
 Author      : Emanuel vidal division 1K
 Description : Realizar un programa en donde se puedan utilizar los prototipos
  de la función Sumar en sus 4 combinaciones.

int Sumar1(int, int);
int Sumar2(void);
void Sumar3(int, int);
void Sumar4(void);
 ============================================================================
 */
// coment
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {
	setbuf(stdout,NULL);
//◄------------- int Sumar1(int, int); ----------►

	int num1;
	int num2;
	int resultado;
	int resultado2;
	printf("\nIngrese un número ");
	scanf("%d", &num1);
	printf("\nIngrese un número ");
	scanf("%d", &num2);
	resultado = Sumar1(num1, num2);
	printf("\nUtilizado en la funcion int Sumar1(int, int)");
	printf("El resultado de la suma es %d", resultado);

//◄-------------- int Sumar2(void); --------------►
	resultado2 = Sumar2();

//◄-------------- void Sumar3(int, int); --------------►
	Sumar3(num1, num2);

//◄-------------- void Sumar4(void); --------------►
	Sumar4();

	return EXIT_SUCCESS;
}


