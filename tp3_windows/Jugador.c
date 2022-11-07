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
#define TRUE 1
#define False 1
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
			jug_setNacionalidad(pJugadores, nombreCompletoStr);
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


















