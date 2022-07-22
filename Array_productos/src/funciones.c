#include "funciones.h"
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

void getChar(char input[], char mensaje[], char mensajeError[]) {

	printf("%s", mensaje);
	scanf("%s", input);
	for (int i = 0; i < sizeof(input); ++i) {
		while (isalpha(input[i]) == 0) {
			printf("%s", mensajeError);
			scanf("%s", input);
		}
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


