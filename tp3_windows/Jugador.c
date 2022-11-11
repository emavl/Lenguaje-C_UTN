/*
 * jugador.c
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "parser.h"
#include "inputs.h"
#include "outputs.h"

#define TRUE 1
#define FALSE 0

void jug_delete(Jugador* this){
	if ( this != NULL) {
		free(this);
	}
}
Jugador* jug_new() {
	Jugador* auxP;
	auxP = (Jugador*) malloc(sizeof(Jugador));
	return auxP;
}
Jugador* jug_newParametros(char *idStr, char *nombreCompletoStr, char *edadStr,
		char *posicionStr, char *nacionalidadStr, char *idSelccionStr) {

	Jugador* pJugadores;

	if( idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL &&
		posicionStr != NULL && nacionalidadStr != NULL && idSelccionStr != NULL ) {

		pJugadores = jug_new();

		if ( pJugadores != NULL) {
			jug_setId(pJugadores, atoi(idStr));
			jug_setNombreCompleto(pJugadores, nombreCompletoStr);
			jug_setEdad(pJugadores, atoi(edadStr));
			jug_setPosicion(pJugadores, posicionStr);
			jug_setNacionalidad(pJugadores, nacionalidadStr);
			jug_setIdSeleccion(pJugadores, atoi(idSelccionStr));
		} else {
			printf("Error ! !  - pJugadors es = a NULL");
		}
	}
	return pJugadores;
}

int jug_setId(Jugador* this,int id) {
	int retorno = -1;
	if ( this != NULL && id > 0) {
		this ->id = id;
			retorno = 0;
		}
	return retorno;
}
int jug_getId(Jugador* this,int* id){
	int retorno = -1;
	if ( this != NULL && id > 0) {
		*id = this ->id;
		retorno = 0;
	}
	return retorno;
}

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto) {
	int retorno = -1;
	if ( this != NULL && nombreCompleto != NULL) {
			strcpy(this->nombreCompleto,nombreCompleto);
			retorno = 0;
		}
	return retorno;
}
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto){
	int retorno = -1;
	if ( this != NULL && nombreCompleto != NULL) {
		strcpy(nombreCompleto,this->nombreCompleto);
			retorno = 0;
		}
	return retorno;
}

int jug_setPosicion(Jugador* this,char* posicion) {
	int retorno = -1;
	if ( this != NULL && posicion != NULL) {
			strcpy(this->posicion,posicion);
			retorno = 0;
		}
	return retorno;
}
int jug_getPosicion(Jugador* this,char* posicion){
	int retorno = -1;
	if ( this != NULL && posicion != NULL) {
		strcpy(posicion,this->posicion);
			retorno = 0;
		}
	return retorno;
}

int jug_setNacionalidad(Jugador* this,char* nacionalidad) {
	int retorno = -1;
	if ( this != NULL && nacionalidad != NULL) {
			strcpy(this->nacionalidad,nacionalidad);
			retorno = 0;
		}
	return retorno;
}
int jug_getNacionalidad(Jugador* this,char* nacionalidad){
	int retorno = -1;
	if ( this != NULL && nacionalidad != NULL) {
		strcpy(nacionalidad,this->nacionalidad);
			retorno = 0;
		}
	return retorno;
}

int jug_setEdad(Jugador* this,int edad) {
	int retorno = -1;
	if ( this != NULL && edad > 0 ) {
		this->edad = edad ;
			retorno = 0;
		}
	return retorno;
}
int jug_getEdad(Jugador* this,int* edad){
	int retorno = -1;
	if ( this != NULL && edad > 0 ) {
			*edad = this ->edad;
			retorno = 0;
		}
	return retorno;
}

int jug_setIdSeleccion(Jugador* this,int idSeleccion){
	int retorno = -1;
	if ( this != NULL && idSeleccion >= 0) {
			this->idSeleccion = idSeleccion;
			retorno = 0;
		}
	return retorno;
}
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion) {
	int retorno = -1;
	if ( this != NULL && *idSeleccion >= 0) {
		*idSeleccion = this->idSeleccion;
			retorno = 0;
		}
	return retorno;
}

//─────────────────  P r i n t ───────────────────►

int jug_print(Jugador* this){

	char nombreComp[25], posicion[25], nacionalidad[50];
	int id, idSeleccion, edad;


	if ( this != NULL) {
			jug_getId(this, &id);
			jug_getNombreCompleto(this, nombreComp);
			jug_getPosicion(this, posicion);
			jug_getNacionalidad(this, nacionalidad);
			jug_getEdad(this, &edad);
			jug_getSIdSeleccion(this, &idSeleccion);
			printf("%5d |%35s |%4d |%20s |%30s |%4d\n",id,nombreComp,edad,posicion,nacionalidad,idSeleccion);
		} else {
			printf("\nla memoria esta llena ");
		}

	return 1;
}

//───────────────── A r c h i v o  - I D  ───────────────────►

int jug_idDisponible(char* idStr)
{
	int retorno = 0;
	FILE* archivo = NULL;
	archivo = fopen("idJugador.txt", "r");

	if ( archivo != NULL  ) {
		do{
		 fscanf(archivo,"%[^\n]\n",idStr);
		 retorno = 1;
		} while ( feof(archivo) == 0);

		fclose(archivo);
	} else {
		printf("no se puede abrir archivo");
		fclose(archivo);
	}

	return retorno;
}

int jug_sigId(int id) {
	int retorno = 0, siguienteId;;
	FILE* archivo = NULL;
	archivo = fopen("idJugador.txt", "w");

	siguienteId = id;
	siguienteId++;
	if( archivo != NULL) {
		fprintf(archivo,"%d",siguienteId);
		fclose(archivo);
		retorno = 1;
		printf("\n\n Siguiente id cargado");
	} else {
		printf("problema con el archivo no se pudo abrir");
	}
	return retorno;
}

//─────────────────  A l t a  ───────────────────►


int jug_add(LinkedList* pArrayListJugador, int* id)
{
	char idStr[10], edadStr[10], idSeleccion[10] = "0",
	nombreCompleto[100], posicion[30], nacionalidad[30], respuesta[4];
	int retorno = 0, edadAux;

	Jugador* nuevo = NULL;

	if (pArrayListJugador != NULL && id != NULL) {
		nuevo = jug_new();

		if (nuevo != NULL) {
			jug_idDisponible(idStr);
			 *id = atoi(idStr);
			printf("\nEl nuevo Jugador obtendra la ID: %d\n", *id);
			fflush(stdin);
			utn_getChar(nombreCompleto, "\nIngrese el nombre por favor ────► ", "\nError !  - ingrese unu valor valido ", 4);
			edadAux = getValidInt("\nIngrese la edad ────► ", "\nError - ingrese un valor acorde", 17, 50);
			itoa(edadAux, edadStr, 10);
			fflush(stdin);
			utn_getChar(posicion,
					"\nIngrese su posicion siendo \n.Aqueros\n.Defensores\n.Mediocampistas\n.delanteros\n  ────►  ",
					"\nERROR. Ingrese su posicion siendo \n.Aqueros\n.Defensores\n.Mediocampistas\n.delanteros\n  ────►  ",
					3);
			utn_getChar(nacionalidad, "\nIngrese su nacionalidad por favor ────► ", "Error !  - ingrese unu valor valido ", 3);

			nuevo = jug_newParametros(idStr, nombreCompleto, edadStr, posicion, nacionalidad, idSeleccion);

			jug_print(nuevo);
			utn_getChar(respuesta, "\n¿Esta seguro que desea guardar este pasajero? [si/no]\n", "\nRespuesta invalida, ingrese [si/no]\n", 3);
			if (!(stricmp(respuesta, "si"))) {
				ll_add(pArrayListJugador, nuevo);
				printf("\njugador cargado correctamente.");
				retorno = 1;
			} else {
				borrarJugador(nuevo);
			}
		} else {
			printf("\nReintente nuevamente");
		}
	} else {
		printf("No hay espacio para un nuevo pasajero");
	}

	return retorno;
}

void borrarJugador(Jugador *this) {
	if (this != NULL) {
		free(this);
		this = NULL;
	}
}

int jug_convocados ( LinkedList* pArrayListJugador ) {


	return 0;
}

// >>>--------------------►     O r d e n a m i e n t o.

int jug_compNacionalidad(void* jugador1, void* jugador2) {
	int resultado = -1;
	char auxJugador1[128];
	char auxJugador2[128];
	Jugador* p1 = NULL;
	Jugador* p2 = NULL;

	if(jugador1!=NULL && jugador2!=NULL)
	{
		p1 = (Jugador*) jugador1;
		p2 = (Jugador*) jugador2;

		jug_getNacionalidad(p1, auxJugador1);
		jug_getNacionalidad(p2, auxJugador2);

		resultado = strcmp(auxJugador1,auxJugador2);
	}

	return resultado;
}

int jug_porEdad(void* jugador1, void* jugador2)
{
	int resultado = -1, edad1, edad2;
	char auxJugador1[30];
	char auxJugador2[30];
	Jugador* p1 = NULL;
	Jugador* p2 = NULL;

	if(jugador1!=NULL && jugador2!=NULL)
	{
		p1 = (Jugador*) jugador1;
		p2 = (Jugador*) jugador2;

		jug_getEdad(p1, &edad1);
		jug_getEdad(p2, &edad2);

		itoa(edad1, auxJugador1,30);
		itoa(edad2, auxJugador2,30);

		resultado = strcmp(auxJugador1,auxJugador2);
	}

	return resultado;
}

void jug_opcNacionalidad(LinkedList *clon) {
	int orden;
	orden = menuCriterio(&orden);

	if (!ll_sort(clon, jug_compNacionalidad, orden)) {
		if (orden) {
			printf("\nSe ha ordenado la lista por Nacionalidad de A-Z\n");
		} else {
			if (!orden) {
				printf(
						"\n\nSe ha ordenado la lista por Nacionalidad de Z-A\n\n");
			}
		}
	}
}

void jug_opcEdad(LinkedList *clon) {
	int orden;
	orden = menuCriterio(&orden);

	if (!ll_sort(clon, jug_porEdad, orden)) {
		if (orden) {
			printf("\nSe ha ordenado la lista de edad mayor a menor\n");
		} else {
			if (!orden) {
				printf(
						"\n\nSe ha ordenado la lista menor a mayor\n\n");
			}
		}
	}
}
int jug_Ordenamiento(LinkedList* clon)
{
	int retorno = -1;
	int opcion;
	char confirmar[4];
	strcpy(confirmar,"no");
	do
	{
		limpiarConsola();
		 menuOrdenar(&opcion);
		switch(opcion)
		{
			case 1:
				jug_opcNacionalidad(clon);
				controller_listarJugadores(clon);
				system("pause");
			break;
			case 2:

				system("pause");
			break;
			case 3:
				jug_opcEdad(clon);
				controller_listarJugadores(clon);
				system("pause");
			break;
			case 4:

			break;
			case 5:
				ll_deleteLinkedList(clon);
			break;
		}
	}while( opcion != 5 );
	return retorno;
}


