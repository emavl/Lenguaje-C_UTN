#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

//------------------------------------------

void initArray(int list [], int size) {
	for (int i = 0; i < size; ++i) {
		list[i]=0;
	}
}

//------------------------------------------

void cargarArray(int list[], int size){

    for (int i = 0; i < size; i++){
    		printf("\nIngrese un numero ");
			scanf("%d",&list[i]);
    }
}

//------------------------------------------

void mostrarArray(int lista[],int size){
	for (int i = 5; i < size; i--) {
		printf("Los nuemeros son %d ",lista[i]);
	}
}
