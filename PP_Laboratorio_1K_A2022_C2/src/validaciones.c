/*
 * validaciones.c
 *
 *  Created on: 2 oct. 2022
 *      Author: Ema
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "input.h"

int validarString(char cadena[], int len, char errorMensaje[]){
	int i;
	int retorno = -1;
	if (cadena != NULL && len > 0)
	{
		for (i=0;i<len && cadena[i] != '\0';i++)
		{
			while((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] == '+' || cadena[i] == '-')
					&& (cadena[i] < 'A' || cadena[i] > 'Z')
					&& cadena[i] != ' ') {
				printf("%s",errorMensaje);
				fflush(stdin);
				scanf("%[^\n]",cadena);
				break;
			}

		}
	}
	return retorno;
}

int validarNumero(char numero[]){ // listo

	if (numero != NULL && strlen(numero) > 0) {
		for (int i = 0; numero[i] != '\0'; i++) {
			while ( ( numero[i] == '+' || numero[i] == '-')
					|| ( (numero[i] > '9' || numero[i] < '0') ) ){
				//printf("%s", errorMensaje);
				return 0;
				break;
			}
		}
	}
	return 1;
}

int validarFloat(char cadena[]) {
	int retorno;
	int contadorPunto = 0;
	int i = 0;

	if (cadena != NULL && strlen(cadena) > 0) {
		retorno = 1;
		while (cadena[i] != '\0') {

			if (cadena[i] == '/' || cadena[i] < '.' || cadena[i] > '9'
					|| contadorPunto > 1) {
				return 0;
				break;
			}
			if (cadena[i] == '.') {
				contadorPunto++;
			}
			i++;
		}

	} else {
		return 0;
	}
	return retorno;

}


