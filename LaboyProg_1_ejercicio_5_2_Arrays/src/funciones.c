#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

//◄---------------------- Funciones ----------------------►


void initArray(int lista[], int tamanio) {						// I n i c i a l i z o      a r r a y.
	int i;

	for (i = 0; i < tamanio; i++){
		lista[i] = 0;
	}
}
//---------------------------------------------------------►

void cargarArray(int list[], char* mensaje, char* errorMensaje, int size){          //  C a r g a r     A r r a y.

    for (int i = 0; i < size; i++){
    		do{
    			printf("%s",mensaje);
    			scanf("%d",&list[i]);
    			if(list[i] > 1000 || list[i] < -1000){
				printf("%s",errorMensaje);
				scanf("%d",&list[i]);
    			}
    		}while(list[i] > 1000 || list[i] < -1000);
    }
}

//---------------------------------------------------------►

void numPosyNeg(int lista[], int tamanio, int *pos, int *neg) {   // N u m e r o s   -  y  +    A r r a y
	int i;
	int auxNeg = 0;
	int auxPos = 0;
	for (i = 0; i < tamanio; i++) {
		if (lista[i] >= 0) {
			auxPos++;
			*pos = auxPos;
		} else {
			auxNeg++;
			*neg = auxNeg;
		}
	}
}
//---------------------------------------------------------►

void SumatoriaPares(int lista[], int tamanio, int *Pares, int *pMaximoImpar) {

	int i;
	int accPar = 0;												 //    S u m a t o r i a     A r r a y
	int flagImpar = 0;
	int maximoImpar;

	for (i = 0; i < tamanio; i++) {
		if (lista[i] % 2 == 0) {
			accPar += lista[i];
			*Pares = accPar;
		} else {
			if (flagImpar == 0 || maximoImpar < lista[i]) {
				flagImpar = 1;
				maximoImpar = lista[i];
				*pMaximoImpar = maximoImpar;
			}
		}
	}

}

//---------------------------------------------------------►

void mostrar(int lista[], int tamanio) {					 //         M u e s t r o      A r r a y
	int i;

	printf("\nNumeros ingresados: ");
		for (i = 0; i < tamanio; i++) {
			printf("%d, ", lista[i]);
		}
	printf("\nNumeros pares ingresados: ");
		for (i = 0; i < tamanio; i++) {
			if (lista[i] % 2 == 0) {
				printf("%d, ", lista[i]);
			}

		}
	printf("\nNumeros impares ingresados: ");
		for (i = 0; i < tamanio; i++) {
			if (lista[i] % 2 != 0) {
				printf("\n%d \tposicion: %d", lista[i], i);
			}

		}

}

//---------------------------------------------------------►

void ordenamiento(int list[], int size){

	int i;
	int j;
	int aux;
	int contador = 0;
	for (i = 0; i < size - 1; ++i) {
		if (list[i] > 0) {
			for (j = i + 1; j < size; ++j) {
				if (list[i] > list[j]) {
					aux = list[i];
					list[i] = list[j];
					list[j] = aux;
				}
			}
		}
	}
	printf("\nlos numeros que se repitiron son: ");
	for (i = 0; i < size - 1; i++) {
		if (list[i] == list[i + 1]) {
			contador++;
		}
		if ( contador > 2){
				printf("\nEl numero %d se repitio %d  veces", list[i],
						contador);
				//contador = 0;
		}
		if (contador == 1){
			printf("\nEl numero %d se repitio %d  vez", list[i],
					contador);
		}
	}
	printf("\nlos numeros positivos son: ");
	for (i = 0; i < size; i++) {
		if (list[i] > 0) {
			printf(" %d, ", list[i]);
		}
	}

	printf("\nlos numeros negativos son: ");
	for (i = 0; i < size; i++) {
		if (list[i] < 0) {
			printf(" %d, ", list[i]);
		}
	}

}


