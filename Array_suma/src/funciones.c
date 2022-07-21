/*
 * funciones.c
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
//___________________Ingresa Array de numeros__________________________

void ingresaEnteros(int lista[],int tamanio)
{
	int i;

	for(i=0;i<tamanio;i++) // el array va siempre acompañado de un for
	{
		printf("\nIngrese un numero por favor: ");
		scanf("%d", &lista[i]);
	}
}
//_______________________Suma valores__________________________

int sumaEnteros(int lista[],int tamanio)
{

	int i;
	int acumulador = 0;
// valor de comienzo; condicion; accion
	for(i=0;i<tamanio;i++)
	{
		acumulador+= lista[i];
	}

	return acumulador;
}
//________________________Promedio_______________________________

float promedioArray ( int Array[], int size ){

	int i;
	float resultado;
	int  suma=0;

	for ( i=0; i < size ; i++){
		suma += Array[i];
	}
	resultado =((float) suma ) / size;

	return resultado;
}
