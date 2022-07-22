/*
 ============================================================================
 Name        : Array_productos.c

programa - Se piden tres nombre de producto, y los precios de cada producto ingresado,
sacar el precio bruto(la    bruto de los tres sin impuestos), el promedio de los precios
y el precio final total más iva(21%), pedir un porcentaje de descuento y aplicarlo al precio final
, mostrar todos los datos calculados e ingresados por alerta. (solo una alerta en el código).
Los datos se piden por prompt.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define size 10

int main(void) {
	setbuf(stdout,NULL);

	char productoUno[size];
	char productoDos[size];
	char productoTres[size];

	int precioUno = 0;
	int precioDos = 0;
	int precioTres = 0;
	int descuento = 0;
	int bruto = 0;
	float promedio = 0;
	float precioFinalIva = 0;
	float resultado = 0;

	getChar(productoUno, "\nIngrese el nombre del 1° producto por favor: ",
			"\nError !!! - ingrese un numbre valido:  ");
	precioUno = getNumber("\nIngrese el precio del producto por favor: ",
			"\nError !!! - ingrese un número valido:  ");
	getChar(productoDos, "\nIngrese el nombre del 2° producto por favor: ",
			"\nError !!! - ingrese un numbre valido:  ");
	precioDos = getNumber("\nIngrese el precio del producto por favor: ",
			"\nError !!! - ingrese un número valido  ");
	getChar(productoTres, "\nIngrese el nombre del 3° producto por favor: ",
			"\nError !!! - ingrese un numbre valido  ");
	precioTres = getNumber("\nIngrese el precio del producto por favor: ",
			"\nError !!! - ingrese un número valido  ");

	bruto = (precioUno + precioDos + precioTres);
	promedio = (bruto / 3);
	precioFinalIva = (bruto * 1.21);

	//tomo el % de decuento


	printf("\nIngrese porcentaje de descuendo a aplicar: ");
	scanf("%d", &descuento);

	//agrego calculos
	descuento = precioFinalIva * (descuento/ 100);

	resultado = precioFinalIva - descuento;

	printf("\n------------------------------------------------------");
	printf("\nEl primer producto es %s y su precio es de $ %d",productoUno, precioUno);
	printf("\nEl segundo producto es %s y su precio es de $ %d",productoDos,precioDos);
	printf("\nEl tercer producto es %s y su precio es de $ %d",productoTres,precioTres);
	printf("\nEl total bruto es: $ %d",bruto);
	printf("\nEl precio promedio es: $ %.2f", promedio);
	printf("\nEl precio final con el descuento + IVA es: $ %.2f",resultado);
	printf("\n------------------------------------------------------\n");

	return EXIT_SUCCESS;
}







