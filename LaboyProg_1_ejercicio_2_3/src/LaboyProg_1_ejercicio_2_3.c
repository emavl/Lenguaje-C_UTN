/*
 ============================================================================
 Name        : Laboratorio_1_Programación_1_Guia_de_ejercicios_2_3.c
 Author      : Emanuel vidal division 1K
Debemos alquilar el servicio de transporte para llegar a Mar del Plata con un grupo de personas, de cada persona
debemos obtener los siguientes datos:
 - número de cliente,
 - estado civil ('s' para soltero", 'c' para casado o 'v' viudo),
 - edad( solo mayores de edad, más de 17),
 - temperatura corporal (validar por favor)
 - y genero('f' para femenino, 'm' para masculino, 'o' para no binario).
NOTA: El precio por pasajero es de $600.
Se debe informar (solo si corresponde):
a) La cantidad de personas con estado "viudo" de más de 60 años. ------► LISTO
b) el número de cliente y edad de la mujer soltera más joven. ---------► LISTO
c) cuánto sale el viaje total sin descuento. --------------------------► LISTO
d) si hay más del 50% de los pasajeros que tiene más de 60 años , el precio final tiene un descuento del 25%, que
solo mostramos si corresponde.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {

	setbuf(stdout,NULL);

//    Variables

	int nCliente;
	char estadoCivil;
	int edad;
	int temperatura;
	char genero;


//   calculos - contadotres - promedios

	char rpta;
	int estadoViudo = 0;
	int solteraMasJoven = 0;
	int nClienteJoven = 0;
	int costo = 600;
	int costoTotal = 0;
	int mayoresDeSesenta = 0;
	int resultado;
	int accClientes = 0;
	int descuento;
	int totalConDesc;

	printf("\n||————————————————————————————————————————————————————————————————————————————||");
	printf("\n|| Bienvenidos a transportes del plata donde SU! confort es nuestra prioridad || ");
	printf("\n||————————————————————————————————————————————————————————————————————————————||");
	printf("\n\nAtencion: El precio por pasajero es de $600.");
	printf("\n\n         ◄------ Por favor necesitaremos que nos brinde los siguientes datos ------►            ");
	printf("\n\n                                 Muchas gracias ! ! !              \n\n");
	do{
//       ◄-----------------------   C l i e n t e   -----------------------------►

		printf("\nN° de Cliente por favor: ");
		scanf("%d",&nCliente);
		while ( ((nCliente < 0) || (nCliente > 100) ) && (( nCliente < '0') || ( nCliente > '9')) ){
			fflush(stdin);
			printf("\nError !!! \nreingrese el N° de Cliente: ");
			scanf("%d", &nCliente);
		}
		costoTotal += costo;

//       ◄------------------- E s t a d o    C i v i l ---------------------------►

		printf("\nEstado Civil: ");
		printf("\n- 's': para soltero \n- 'c': para casado \n– 'v': para viudos\n");
		fflush(stdin);
		scanf("%c",&estadoCivil);

		while(!(isdigit(estadoCivil) == 0) || ( estadoCivil != 's' && estadoCivil != 'c' && estadoCivil != 'v')){
			printf("\nError ! Ingrese el tipo de cursada correcta: \n");
			printf("\n- 's': para soltero \n- 'c': para casado \n– 'v': para viudos\n");
			fflush(stdin);
			scanf("%c",&estadoCivil);
		}


//      ◄--------------------- T e m p e r a t u r a ----------------------------►

		printf("\nTemperatura corporal: ");
		scanf("%d",&temperatura);
		while ( ((temperatura < 30) || (temperatura > 40) ) && (( temperatura < '0') || ( temperatura > '9')) ){
			fflush(stdin);
			printf("\nError !!! Ingrese una Temperatura acorde por favor: ");
			scanf("%d", &temperatura);
		}

//      ◄---------------------   G e n e r o   ----------------------------►

		printf("\nGenero, dependiendo de: ");
		printf("\n- f: femenino  \n– m: masculino  \n- o: no binario ");
		fflush(stdin);
		scanf("%c",&genero);

		while((genero != 'f') && (genero != 'm') && (genero != 'o')){
			fflush(stdin);
			printf("\nError !! - Ingrese el sexo correcto: ");
			printf("\n- f: femenino  \n– m: masculino  \n- o: no binario ");
			scanf("%c", &genero);
			}


//      ◄---------------------   E d a d    ----------------------------►

		printf("\nEdad: ");
		scanf("%d", &edad);
		while ((edad < 17) && (edad < 101)) {
			fflush(stdin);
			printf("\nError - Reingrese la edad del Cliente por favor: ");
			scanf("%d", &edad);
		}
		if ((edad > solteraMasJoven) && (estadoCivil == 's')) {
			solteraMasJoven = edad;
			nClienteJoven = nCliente;
		}
		if (edad > 60) {
			mayoresDeSesenta++;
			if (estadoCivil == 'v')  {
				estadoViudo++;
				}
		}
		printf("\nDesea ingresar otra persona ? - rpta s/n ");
		fflush(stdin);
		scanf("%c", &rpta);
		while ((rpta != 's') && (rpta != 'n'))  {
			fflush(stdin);
			printf("ERROR ! debe ingrese 's' o 'n' .");
			scanf("%c", &rpta);
		}
		accClientes++;
	}while( rpta == 's');

	resultado = (mayoresDeSesenta / accClientes) / 100;
	if (resultado > 50) {
		descuento = costoTotal * 0.25;
		totalConDesc = costoTotal - descuento;
	}

	printf("\na) La cantidad de personas con estado viudo de más de 60 años es: %d", estadoViudo);
	printf("\nb) El número de cliente y edad de la mujer soltera más joven es: N° %d y su edad %d",nClienteJoven, solteraMasJoven);
	printf("\nc) El viaje total sin descuento aplicado es de: %d",costoTotal);
	printf("\nd) Habiendo más del 50 porciento de los pasajeros que tiene más de 60 años, el precio final tiene un descuento del 25 porciento ");
	printf("Siendo así un total de $ %d",totalConDesc);

	return EXIT_SUCCESS;
}
