/*
 * funciones.c
 *
			int Sumar1(int, int);
			int Sumar2(void);
			void Sumar3(int, int);
			void Sumar4(void);
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

//◄------------- int Sumar1(int, int); ----------►
int Sumar1(int valor1, int valor2){
	int resultado;

	resultado = valor1+valor2;
	return resultado;
}
//◄-------------------- Fin ----------------------►


//◄------------- int Sumar2(void); ----------►
int Sumar2(){

	int num1;
	int num2;
	int resultado;

	printf("\nIngrese un número ");
	scanf("%d",&num1);
	printf("\nIngrese un número ");
	scanf("%d",&num2);

	resultado = num1+num2;

	return	resultado;
}
//◄-------------------- Fin ----------------------►



//◄------------- void Sumar3(int, int); ----------►
void Sumar3(int valor1, int valor2){
	int resultado;

	resultado = valor1+valor2;
	printf("\nUtilizado en la funcion void Sumar3(int, int)");
	printf("El resultado de la suma es %d",resultado);
}
//◄-----------------------------------------------►


//◄--------------- void Sumar4(void); ------------►
void Sumar4(){
	int num1;
	int num2;
	int resultado;

	printf("\nIngrese un número");
	scanf("%d",&num1);
	printf("\nIngrese un número");
	scanf("%d",&num2);

	resultado = num1+num2;

	printf("\nUtilizado en la funcion void Sumar4(void)");
	printf("El resultado de la suma es %d",resultado);
}
//◄--------------------- Fin ----------------------►
