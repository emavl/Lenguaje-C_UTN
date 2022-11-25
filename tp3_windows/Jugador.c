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
#include "Seleccion.h"
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


//   >>>────────────────────────►   C o n s t r u c t o r e s .
Jugador* jug_new() {
	Jugador* auxP;
	auxP = (Jugador*) malloc(sizeof(Jugador));
	return auxP;
}
Jugador* jug_newParametros(char *idStr, char *nombreCompletoStr, char *edadStr,
		char *posicionStr, char *nacionalidadStr, char *idSelccionStr) {

	int validacion;

	Jugador* pJugadores;

	if( idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL &&
		posicionStr != NULL && nacionalidadStr != NULL && idSelccionStr != NULL ) {

		pJugadores = jug_new();

		if ( pJugadores != NULL) {
	    	if ( !(jug_setId(pJugadores, atoi(idStr))) &&
		   		!(jug_setNombreCompleto(pJugadores, nombreCompletoStr)) &&
				!(jug_setEdad(pJugadores, atoi(edadStr))) &&
				!(jug_setPosicion(pJugadores, posicionStr)) &&
				!(jug_setNacionalidad(pJugadores, nacionalidadStr)) &&
				!(jug_setIdSeleccion(pJugadores, atoi(idSelccionStr))))
	    	{
	    		validacion = 6;
	    	}
	    	if ( validacion != 6) {
	    		free(pJugadores);
	    		pJugadores = NULL;
	    	}

		} else {
			printf("Error ! !  - pJugadors es = a NULL");
		}
	}
	return pJugadores;
}

//>>─────────────────►   S e t t e r s   -   g e t t e r s    ◄───────────────────<<

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
	int retorno = 1, id, idSeleccion, edad;


	if ( this != NULL) {
		if ( !(jug_getId(this, &id)) &&
			!(jug_getNombreCompleto(this, nombreComp)) &&
			!(jug_getPosicion(this, posicion)) &&
			!(jug_getNacionalidad(this, nacionalidad)) &&
			!(jug_getEdad(this, &edad)) &&
			!(jug_getSIdSeleccion(this, &idSeleccion) ))
			{
				printf("%5d |%25s |%4d | %20s |%20s | %6d        |\n", id,
						nombreComp, edad, posicion, nacionalidad, idSeleccion);
				retorno = 0;
			}

		} else {
			printf("\nla memoria esta llena ");
		}

	return retorno;
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
	int retorno = 0, siguienteId;
	FILE* archivo = NULL;
	archivo = fopen("idJugador.txt", "w");

	siguienteId = id;
	siguienteId ++;
	if( archivo != NULL) {
		fprintf(archivo,"%d",siguienteId);
		fclose(archivo);
		retorno = 1;
	} else {
		printf("problema con el archivo no se pudo abrir");
	}
	return retorno;
}

//─────────────────  A l t a  ───────────────────►


int jug_add(LinkedList *pArrayListJugador, int *id) {

	char idStr[10], edadStr[10], idSeleccion[10] = "0", nombreCompleto[100],
			posicion[30], nacionalidad[30], respuesta[4];

	int retorno = 0, edadAux, idPregunta;
	Seleccion *auxSeleccion =  NULL;
	Jugador *nuevo = NULL;

	if (pArrayListJugador != NULL && id != NULL) {
		nuevo = jug_new();

		if (nuevo != NULL) {

			jug_idDisponible(idStr);
			*id = atoi(idStr);
			idPregunta = *id;
			printf("\nEl nuevo Jugador obtendra la ID: %d\n", *id);
			fflush(stdin);
			utn_getString2(nombreCompleto, "\nIngrese el nombre por favor ────► ", "\nError !  - ingrese unu valor valido ");
			SizeString(nombreCompleto);
			edadAux = getValidInt("\nIngrese la edad ────► ",
					"\nError - ingrese un valor acorde", 17, 50);
			itoa(edadAux, edadStr, 10);
			do {
				utn_getString2(posicion,"\nIngrese su posicion siendo \n.aqueros\n.defensores\n.mediocampistas\n.delantero\n  ────► ",
						"\nERROR. Ingrese su posicion siendo \n.Aqueros\n.Defensores\n.Mediocampistas\n.delanteros\n  ────►  ");
			} while ((strcmp("arquero", posicion) != 0)
					&& (strcmp("defensor", posicion) != 0)
					&& (strcmp("mediocampista", posicion) != 0)
					&& (strcmp("delantero", posicion) != 0));


			utn_getChar(nacionalidad,
					"\nIngrese su nacionalidad por favor ────► ",
					"Error !  - ingrese unu valor valido ", 3);

			nuevo = jug_newParametros(idStr, nombreCompleto, edadStr, posicion,
					nacionalidad, idSeleccion);

			jug_print(nuevo);
			utn_getChar(respuesta,
					"\n¿Esta seguro que desea guardar este pasajero? [si/no]\n",
					"\nRespuesta invalida, ingrese [si/no]\n", 3);
			if (!(stricmp(respuesta, "si"))) {
				ll_add(pArrayListJugador, nuevo);
				printf("\njugador cargado correctamente.");
				retorno = 1;
			} else {
				*id = idPregunta-1;
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


// ───────── O r d e n a m i e n t o ──────────


//                          >>>--------------------►     N a c i o n a l i d a d.

int jug_compNacionalidad(void* jugador1, void* jugador2) {
	int resultado = -1;
	char auxJugador1[128], auxJugador2[128];

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
//      >>>--------------------►     	  		E d a d.

int jug_compEdad(void* jugador1, void* jugador2)
{
	int resultado = -1, edad1, edad2;
	char auxJugador1[30], auxJugador2[30];

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

//  >>>--------------------►   				  N o m b r e .

int jug_compNombre(void* jugador1, void* jugador2) {
	int resultado = -1;
	char auxJugador1[128], auxJugador2[128];
	Jugador* p1 = NULL;
	Jugador* p2 = NULL;

	if(jugador1!=NULL && jugador2!=NULL)
	{
		p1 = (Jugador*) jugador1;
		p2 = (Jugador*) jugador2;
		jug_getNombreCompleto(p1, auxJugador1);
		jug_getNombreCompleto(p2, auxJugador2);
		resultado = strcmp(auxJugador1,auxJugador2);
	}

	return resultado;
}

// >>>--------------------►     S o r t .

void jug_opcNacionalidad(LinkedList *pArrayListJugador) {
	int orden;

	 menuCriterio(&orden);

	if (!ll_sort(pArrayListJugador, jug_compNacionalidad, orden)) {
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

void jug_opcEdad(LinkedList *pArrayListJugador) {
	int orden;

	 menuCriterio(&orden);

	if (!ll_sort(pArrayListJugador, jug_compEdad, orden)) {
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

void jug_opcNombre(LinkedList *pArrayListJugador) {
	int orden;
	 menuCriterio(&orden);

	if (!ll_sort(pArrayListJugador, jug_compNombre, orden)) {
		if (orden) {
			printf("\nSe ha ordenado la lista de Nombres de ( A - Z ) \n");
		} else {
			if (!orden) {
				printf("\n\nSe ha ordenado la lista de Nombres de ( Z - A )\n\n");
			}
		}
	}
}

// ───────── M o d i f i c a c i o n  ──────────

int jug_modificacion(LinkedList* pArrayListaJugador) {

	int retorno = 0, size, indice, opcion = 0, id;
	Jugador* auxJug = NULL;
	char respuesta[4];

	if ( pArrayListaJugador != NULL ) {

		size = ll_len(pArrayListaJugador);
		controller_listarJugadores(pArrayListaJugador);
		id = getValidInt("\n\nIngrese el ID para modificar ───► ", "Error, ID invalido\n", 1, size);
		indice = jug_buscarId(pArrayListaJugador, id);

		if ( indice > -1 ) {

			auxJug = ( Jugador* ) ll_get(pArrayListaJugador, indice);
			mostrarSeparador();
			jug_print(auxJug);
			mostrarSeparador();
			utn_getString(respuesta, "\n¿Esta seguro que desea editar este jugador?[si/no]\n", "\nRespuesta invalida, ingrese [si/no]\n", 4, 3);

			menuModificar(&opcion);

				switch (opcion) {
				case 1:
					if ( jug_opcModificarNombreCompleto(indice, auxJug) == 1 ) retorno = 1;
					break;
				case 2:
					if ( jug_opcModificarEdad( auxJug) ) retorno = 1;
					break;
				case 3:
					if ( jug_opcModificarPosicion(indice, auxJug) ) retorno = 1;
					break;
				case 4:
					if ( jug_opcModificarNacionalidad(indice, auxJug) ) retorno = 1;
					break;
				case 5:
// 						 V u e l v e    a t r a s.
					break;
				}


		}
	} else	{
		printf("Error. Imposible realizar una modificacion\n");
	}



	return retorno;
}

int jug_opcModificarNombreCompleto( int index, Jugador* auxiliar)
{
	int retorno = 0;
	char nombreCompleto[128];
	int opciones;

		utn_getChar(nombreCompleto, "Ingrese el nuevo nombre ───► ", "Error, nombre invalido\n", 3);
    opciones = getValidInt("\n¿Esta seguro que desea modificarlo? [1/0]\n", "\nRespuesta invalida, ingrese [1/0]\n", 0, 2);
		if(opciones)
		{
			jug_setNombreCompleto(auxiliar, nombreCompleto);
			jug_print(auxiliar);
			retorno = 1;
		}else
		{
			printf("Modificacion cancelada");
		}


	return retorno;
}

int jug_opcModificarEdad( Jugador* auxiliar)
{
	int retorno = 0, opciones, edad;

	edad = getValidInt("\nIngrese la nueva edad ───► " , "\nError, edad invalido", 1, 50);
    opciones = getValidInt("\n¿Esta seguro que desea modificarlo? [1/0]\n", "\nRespuesta invalida, ingrese [1/0]\n", 0, 2);
		if(opciones)
		{
			jug_setEdad(auxiliar, edad);
			jug_print(auxiliar);
			retorno = 1;
		} else	{
			printf("Modificacion cancelada");
		}


	return retorno;
}

int jug_opcModificarPosicion( int index, Jugador* auxiliar)
{
	int retorno = 0;
	char posicion[30];
	int opciones;

		utn_getChar(posicion, "Ingrese la nuevo posicion ───► ", "Error, posicion invalida\n", 3);
    opciones = getValidInt("\n¿Esta seguro que desea modificarlo? [1/0]\n", "\nRespuesta invalida, ingrese [1/0]\n", 0, 2);
		if(opciones)
		{
			jug_setPosicion(auxiliar, posicion);
			jug_print(auxiliar);
			retorno = 1;
		}else
		{
			printf("Modificacion cancelada");
		}


	return retorno;
}

int jug_opcModificarNacionalidad( int index, Jugador* auxiliar)
{
	int retorno = 0;
	char nacionalidad[30];
	int opciones;

		utn_getChar(nacionalidad, "Ingrese la nueva Nacionalidad ───► ", "Error, Nacionalidad invalida\n", 3);
    opciones = getValidInt("\n¿Esta seguro que desea modificarlo? [1/0]\n", "\nRespuesta invalida, ingrese [1/0]\n", 0, 2);
		if(opciones)
		{
			jug_setNacionalidad(auxiliar, nacionalidad);
			jug_print(auxiliar);
			retorno = 1;
		}else
		{
			printf("Modificacion cancelada");
		}


	return retorno;
}

int jug_buscarId(LinkedList* pArrayListaJugador, int id ) {

	int i;
	int len;
	int index;
	Jugador* auxiliar;

	if (pArrayListaJugador != NULL)
	{
		len = ll_len(pArrayListaJugador);

		if (len > 0) {
			for (i = 0; i < len; i++) {
				auxiliar = (Jugador*) ll_get(pArrayListaJugador, i);
				if (auxiliar->id == id) {
					index = i;
					break;
				}
			}
		}
	}

	return index;

}

// ───────── B a j a   -   J u g a d o r   ──────────

int jug_baja(LinkedList* pArrayListaJugador)
{
	int retorno = 0, id, index = -1;
	char respuesta[4];

	Jugador* aux = NULL;

	if(pArrayListaJugador!=NULL)
	{
		controller_listarJugadores(pArrayListaJugador);
		printf("\nIngresese el N° de ID ─────► ");
		 getInt(&id);
		index = jug_buscarId(pArrayListaJugador, id);

		if(index!=-1)
		{
			aux = ll_get(pArrayListaJugador,index);
			jug_print(aux);
			utn_getString(respuesta, "\n¿Esta seguro que desea eliminar este jugador?[si/no]\n", "\nRespuesta invalida, ingrese [si/no]\n", 4, 3);

			if(!(stricmp(respuesta,"si")))
			{
				ll_remove(pArrayListaJugador,index);
				retorno = 1;
			}else
			{
				printf("Baja cancelada\n");
			}
		}else
		{
			printf("No se pudo encontrar el ID\n");
		}
	}

	return retorno;
}

// ───────── C o n v o c a d o s - J u g a d o r e s  ──────────

int jug_convocados(LinkedList *pArrayListaJugador,
		LinkedList *pArrayListSeleccion) {

	Jugador *auxJug = NULL;

	int retorno = 0, indice, id;

	char respuesta[4];
	if (pArrayListaJugador != NULL &&  pArrayListSeleccion != NULL) {

		printf("\naca esta el dramaa");
		controller_listarJugadores(pArrayListaJugador);
		printf("\nIngresese el N° de ID ─────► ");
		getInt(&id);
		indice = jug_buscarId(pArrayListaJugador, id);

		if (indice > -1) {

			auxJug = (Jugador*) ll_get(pArrayListaJugador, indice);
			mostrarSeparador();
			jug_print(auxJug);
			mostrarSeparador();
			utn_getString(respuesta,
					"\n¿Esta seguro que desea modificarlo?[si/no] ───► ",
					"\nRespuesta invalida, ingrese [si/no]\n", 4, 3);
			limpiarConsola();
			if ( !(stricmp(respuesta,"si"))) {
				 jug_convocarSelec(auxJug, pArrayListSeleccion);
				retorno = 1;

			}  else {
				printf(" Cancelando . . .\n");
				system("pause");
			}
		}
	} else {
		printf("Error. Imposible realizar una modificacion\n");
	}

	return retorno;
}

int jug_convocarSelec(  Jugador* auxJug, LinkedList *pArrayListSeleccion) {

	int retorno = 0;
		printf("______________________________________\n");
	printf("%5s |%15s |%12s |\n","id","pais","convocados");
	printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
	ll_sort(pArrayListSeleccion, jug_compPaisDeSeleccion, 1);
	Seleccion_printPais(pArrayListSeleccion);
	printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");

	if ( jug_opcPaisSeleccion( auxJug, pArrayListSeleccion) == 1 ) {
		retorno = 1;
	}

	return retorno;
}



int jug_opcPaisSeleccion( Jugador* auxJug, LinkedList *pArrayListSeleccion) {

	int retorno = 0, idSelecion, convocados;
	char respuesta[4] ;
	Seleccion* auxSelec = NULL;


	idSelecion = getValidInt("Ingrese el ID del pais de la seleccion  ───► ",
			"\nError,valor invalido ", 1, 32);

	auxSelec = (Seleccion*) ll_get(pArrayListSeleccion, idSelecion -1);

	 selec_getConvocados(auxSelec, &convocados);

	if ( convocados < 22) {
		utn_getString(respuesta,
					"\n¿Esta seguro que desea modificarlo?[si/no] ───► ",
					"\nRespuesta invalida, ingrese [si/no]\n", 4, 3);
			limpiarConsola();
			if ( !(stricmp(respuesta,"si"))) {

				jug_setIdSeleccion(auxJug, idSelecion);
				convocados++;
				selec_setConvocados(auxSelec, convocados);
				jug_print(auxJug);
				printf("\nJugador modificado (^_^)/  \n\n");
				system("\npause");

				retorno = 1;
			} else {
				printf("Modificacion cancelada");
			}
	} else {
		printf("\nSe completo el cupo de convocados\n");
	}



	return retorno;
}

int jug_convocadoUnicamente(LinkedList *pArrayListaJugador) {
	int idSeleccion, cantidad, i, retorno = 0;

	Jugador* auxjug = NULL;

	cantidad = ll_len(pArrayListaJugador);

	for (i = 0; i < cantidad; i++) {
		auxjug = (Jugador*) ll_get(pArrayListaJugador, i);

		jug_getSIdSeleccion(auxjug, &idSeleccion);

			if (idSeleccion > 0) {
				jug_print(auxjug);
				retorno = 1;
			}
		}
	return retorno;
}

int jug_quitarSeleccion(Jugador *auxJug, LinkedList *pArrayListaJugador, LinkedList *pArrayListSeleccion) {

	int retorno = 0, idSelecion, size, idNuevo = 0, convocados, idSeleccionJug;
	char respuesta[4];

	Seleccion* auxSelec = NULL;

	if (jug_convocadoUnicamente(pArrayListaJugador) == 1) {

	size = ll_len(pArrayListaJugador);
			idSelecion = getValidInt(
							"\n\nIngrese el ID del jugador para quitarlo de la seleccion  ───► ",
							"\nError,valor invalido ", 1, size);

			auxJug = (Jugador*) ll_get(pArrayListaJugador, idSelecion -1);

			jug_getSIdSeleccion(auxJug, &idSeleccionJug);


			auxSelec = (Seleccion*) ll_get(pArrayListSeleccion, idSeleccionJug -1 );

			selec_getConvocados(auxSelec, &convocados);

			utn_getString(respuesta,
					"\n¿Esta seguro que desea modificarlo?[si/no] ───► ",
					"\nRespuesta invalida, ingrese [si/no]\n", 4, 3);
			limpiarConsola();
			if (!(stricmp(respuesta, "si"))) {

				jug_setIdSeleccion(auxJug, idNuevo);
				convocados--;
				selec_setConvocados(auxSelec, convocados);
				jug_print(auxJug);
				printf("\nJugador modificado (^_^)/  \n\n");
				system("\npause");
				retorno = 1;
			} else {
				printf("Modificacion cancelada");
			}
		} else {
			printf("\n\n No hay jugadores convocados\n\n");
			system("pause");
		}

	return retorno;
}



