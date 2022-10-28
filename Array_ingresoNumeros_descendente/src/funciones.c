/*
 * funciones.c
 *
 *  Created on: 5 sep. 2022
 *      Author: Emaaaaaaa !!!!
 */
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void initArray(int list [], int size) {
	for (int i = 0; i < size; ++i) {
		list[i]=0;
	}
}

//------------------------------------------

void cargarArray(int list[], int size){

    for (int i = 0; i < size; i++){
    		printf("Ingrese un numero ");
			scanf("%d",&list[i]);
    }
}

//------------------------------------------

void mostrarArray(int lista[],int size){
	for (int i = 4; i > -1; i--) {
		printf("\nLos nuemeros son %d ", lista[i]);
	}
}
/*
 * para carga aleatoria
 *while(respuesta =='s'{
	printf(ingrese el indice a ingresar)
	scanf("%d", &indice;

	printf("INgrese el valor a ingresar)
	scanf("%d",lista[indice];
	}
 */
