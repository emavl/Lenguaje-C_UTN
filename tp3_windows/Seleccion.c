/*
 * Seleccion.c
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Seleccion.h"

void selec_delete(Seleccion* this) {
	if ( this != NULL) {
		free(this);
	}
}
Seleccion* selec_new() {
	Seleccion* pSeleccion;
	pSeleccion = (Seleccion*) malloc(sizeof(Seleccion));
	return pSeleccion;
}
Seleccion* selec_newParametros(char *idStr, char *paisStr,
		char *confederacionStr, char *convocadosStr) {
	int id;
	Seleccion* pSeleccion;

	if( idStr != NULL && paisStr != NULL && confederacionStr != NULL &&
			convocadosStr != NULL  ) {

		pSeleccion = selec_new();

		if ( pSeleccion != NULL) {
			selec_setConvocados(pSeleccion, atoi(convocadosStr));
			if( (id = atoi(idStr)) > 0 ) pSeleccion ->id;
			if (paisStr != NULL) strcpy(pSeleccion->pais,paisStr);
			if ( confederacionStr != NULL ) strcpy(pSeleccion->confederacion,confederacionStr);
		} else {
			printf("Error ! !  - pSeleccion es = a NULL");
		}
	}
	return pSeleccion;
}

int selec_getId(Seleccion* this, int* id) {
	int retorno = -1;
	if ( this != NULL && id > 0) {
		*id = this ->id;
		retorno = 0;
	}
	return retorno;
}
int selec_getPais(Seleccion* this, char* pais) {
	int retorno = -1;
	if ( this != NULL && pais != NULL) {
		strcpy(pais,this->pais);
			retorno = 0;
		}
	return retorno;
}
int selec_getConfederacion(Seleccion* this, char* confederacion) {
	int retorno = -1;
	if ( this != NULL && confederacion != NULL) {
		strcpy(confederacion,this->confederacion);
			retorno = 0;
		}
	return retorno;
}
int selec_getConvocados(Seleccion* this, int* convocados) {
	int retorno = -1;
	if ( this != NULL && convocados > 0) {
		*convocados = this ->convocados;
		retorno = 0;
	}
	return retorno;
}


int selec_setConvocados(Seleccion* this, int convocados) {
	int retorno = -1;
	if ( this != NULL && convocados > 0) {
		 this ->convocados = convocados;
		retorno = 0;
	}
	return retorno;
}
