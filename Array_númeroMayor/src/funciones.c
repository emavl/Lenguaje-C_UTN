#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

//------------------------------------------

void initArray(int list [], int size) {
	for (int i = 0; i < size; ++i) {
		list[i]=0;
	}
}

//------------------------------------------

int getNumber(char mensaje[], char mensajeError[]) {
	int numero;
	printf("%s", mensaje);
	scanf("%d", &numero);
	while (isdigit(numero) == 1) {
		printf("%s", mensajeError);
		scanf("%d", &numero);
	}
	return numero;
}

//------------------------------------------

void cargarArray(int list[], int size){
    int i;
    for (i = 0; i < size; i++){
      list[i] = getNumber("\nIngrese un numero por favor: ",
		      "Error! ingrese numero valido");
    }
}

//------------------------------------------

int mayorNumero(int list[]) {
	int numero = 0;
	for (int i = 0; i < sizeof(list); ++i) {
		if (list[i] > numero) {
			numero = list[i];
		}
	}
	return numero;
}
