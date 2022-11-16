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
#include "outputs.h"

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
	Seleccion* pSeleccion = NULL;

	if( idStr != NULL && paisStr != NULL && confederacionStr != NULL &&
			convocadosStr != NULL  ) {

		pSeleccion = selec_new();

		if ( pSeleccion != NULL) {
			if ( ( id = atoi(idStr) ) > 0 ) pSeleccion ->id = id;
			strcpy(pSeleccion->pais,paisStr);
			strcpy(pSeleccion->confederacion,confederacionStr);
			selec_setConvocados(pSeleccion, atoi(convocadosStr));
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
	if ( this != NULL && convocados >= 0) {
		*convocados = this ->convocados;
		retorno = 0;
	}
	return retorno;
}


int selec_setConvocados(Seleccion* this, int convocados) {
	int retorno = -1;
	if ( this != NULL && convocados >= 0) {
		 this ->convocados = convocados;
		retorno = 0;
	}
	return retorno;
}

//─────────────────  P r i n t ───────────────────►

void Seleccion_print(Seleccion* this){

	char pais[25], confederacion[25];
	int id, convocados;

	if ( this != NULL) {
			selec_getId(this, &id);
			selec_getPais(this, pais);
			selec_getConfederacion(this, confederacion);
			selec_getConvocados(this, &convocados);
			printf("%5d |%20s |%20s |%8d    |\n",id,pais,confederacion,convocados);
		} else {
			printf("\nla memoria esta llena ");
		}

}
void Seleccion_printSoloPais(Seleccion* this){

	char pais[25];
	int id, convocados;

	if ( this != NULL) {
			selec_getId(this, &id);
			selec_getPais(this, pais);
			selec_getConvocados(this, &convocados);
			printf("%5d |%15s |  %6d     |\n",id,pais,convocados);
		}
}

void Seleccion_printPais(LinkedList* pArrayListSeleccion){
	int i, cantidad;
	Seleccion* auxSeleccion;
	cantidad = ll_len(pArrayListSeleccion);

	for(i = 0; i < cantidad; i++){
		auxSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
		Seleccion_printSoloPais(auxSeleccion);
	}
}

// >>>--------------------►     O r d e n a m i e n t o.

int Seleccion_compConfederacion(void* Seleccion1, void* Seleccion2) {
	int resultado = -1;
	char auxSeleccion1[128];
	char auxSeleccion2[128];
	Seleccion* p1 = NULL;
	Seleccion* p2 = NULL;

	if(Seleccion1!=NULL && Seleccion2!=NULL)
	{
		p1 = (Seleccion*) Seleccion1;
		p2 = (Seleccion*) Seleccion2;

		selec_getConfederacion(p1, auxSeleccion1);
		selec_getConfederacion(p2, auxSeleccion2);

		resultado = strcmp(auxSeleccion1,auxSeleccion2);
	}

	return resultado;
}


void Seleccion_opcConfederacion(LinkedList* pArrayListSeleccion) {

	int orden;
    menuCriterio(&orden);

	if (!ll_sort(pArrayListSeleccion, Seleccion_compConfederacion, orden)) {
		if (orden) {
			printf("\nSe ha ordenado la lista de Confederaciones de Z-A \n");
		} else {
			if (!orden) {
				printf(
						"\n\nSe ha ordenado la lista de Confederaciones de A-Z \n\n");
			}
		}
	}
}


int Seleccion_compararID(void* Seleccion1, void* Seleccion2)
{
	int resultado = -1, iD1, iD2;
	char auxSeleccion1[30];
	char auxSeleccion2[30];
	Seleccion* p1 = NULL;
	Seleccion* p2 = NULL;

	if(Seleccion1!=NULL && Seleccion2!=NULL)
	{
		p1 = (Seleccion*) Seleccion1;
		p2 = (Seleccion*) Seleccion2;

		selec_getId(p1, &iD1);
		selec_getId(p2, &iD2);


		itoa(iD1, auxSeleccion1,30);
		itoa(iD2, auxSeleccion2,30);

		resultado = strcmp(auxSeleccion1,auxSeleccion2);
	}

	return resultado;
}

int jug_compPaisDeSeleccion(void* Seleccion1, void* Seleccion2) {
	int resultado = -1;
	char auxSeleccion1[128];
	char auxSeleccion2[128];

	Seleccion* p1 = NULL;
	Seleccion* p2 = NULL;

	if (Seleccion1 != NULL && Seleccion2 != NULL)
	{
		p1 = (Seleccion*) Seleccion1;
		p2 = (Seleccion*) Seleccion2;

		strcpy(auxSeleccion1,p1->pais);
		strcpy(auxSeleccion2, p2->pais);

		resultado = strcmp(auxSeleccion1,auxSeleccion2);
	}

	return resultado;
}
