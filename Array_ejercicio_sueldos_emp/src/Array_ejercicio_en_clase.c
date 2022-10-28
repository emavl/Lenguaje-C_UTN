/*
 ============================================================================
 Name        : Array_ejercicio_en_clase.c
 Author      :
 Version     : Clase 5
 Copyright   : 
 Description : De los 10 empleados de una fábrica se registra:
	- número de legajo (coincidente con el índice)
	- edad
	- sueldo
	- Se pide ingresar los datos consecutivamente y
	- calcular el sueldo promedio.
============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define T 2 // defino el macro

int main(void)
{
		setbuf(stdout,NULL);

		int legajo[T];
		int edad[T];
		int sueldo[T];
		int i;
		int promedios;

		inicializarArray(edad,T);
		inicializarArray(sueldo,T);
		inicializarArray(legajo,T);

	//_________Ingreso los datos______________

		for(i=0;i<T;i++)
		{
			numArray(legajo, "\nIngrese el numero de legajo del empleado por favor:  ", 1);
			numArray(edad, "Ingrese la edad : ", 1);
			numArray(sueldo, "Ingrese el sueldo : ", 1);
		}
		printArray(sueldo, T);
		promedios = promedioArray(sueldo, T);
		printf("\nEl promedio de los sueldos es %d",promedios);

		return 0;
}
