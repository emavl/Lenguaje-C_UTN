/*
 ============================================================================
 Name        : Caluculo de sueldos clase 5.

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
#include "funciones.h"

#define T 2 // defino el macro

int main(void){

		setbuf(stdout,NULL);

		int legajo[T];
		int edad[T];
		int sueldo[T];
		int i;
		int promedio;

	//_________Ingreso los datos______________

		for(i=0;i<T;i++)
		{
			numArray(legajo, "\nIngrese el numero de legajo del empleado por favor:  ", 1);

			numArray(edad, "\nIngrese la edad : ", 1);

			numArray(sueldo, "\nIngrese el sueldo : ", 1);

		}


		promedio = promedioArray(sueldo, T);
		printf("\nEl promedio de los sueldos es %d",promedio);

		return 0;
}



