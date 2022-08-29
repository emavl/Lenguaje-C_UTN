#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//------------------------------------------

void initArray(int list [], int size) {
	for (int i = 0; i < size; ++i) {
		list[i]=0;
	}
}

//------------------------------------------

int getNumber(char mensaje[], char mensajeError[]){
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

    for (int i = 0; i < size; i++){
      list[i] = getNumber("\nIngrese un numero por favor: ",
		      "Error! ingrese numero valido");
    }
}

//------------------------------------------

void mayorNumero(int array[],int* pnumero) {

	if (pnumero != NULL && array != NULL) {
		for (int i = 0; i < sizeof(array); ++i) {
			if (array[i] > *pnumero) {
				*pnumero = array[i];
			}
		}
	}
}
