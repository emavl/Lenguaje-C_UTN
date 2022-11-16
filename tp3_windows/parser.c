#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "parser.h"


/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador) {
	int retorno = 0, cantidad = 0;
	char id[10], nombreComp[25], edad[10] ,posicion[25],
	nacionalidad[50],	idSeleccion[10];
	Jugador* auxJugador = NULL;

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",id,nombreComp,edad,posicion,nacionalidad,idSeleccion);

	if ( pFile != NULL && pArrayListJugador != NULL ) {
		do{

		cantidad = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",id,nombreComp,edad,posicion,nacionalidad,idSeleccion);

		if ( cantidad == 6 ) {

			auxJugador = jug_newParametros(id, nombreComp, edad, posicion, nacionalidad, idSeleccion);

			if(auxJugador != NULL) {
				ll_add(pArrayListJugador, auxJugador);
				retorno = 1;
			}
		}

		}while ( !feof(pFile) );
	}

    return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador){

	int retorno = 1;
	Jugador* auxJugador;// = Passenger_new();
	int cant;

	while(!feof(pFile))
	{
		retorno = 0;
		auxJugador = jug_new();
		//Leo en binario y pongo los datos en lectura
		cant=fread(auxJugador,sizeof(Jugador),1,pFile);
		if (cant != 1) {
			if (feof(pFile)) {
				break;
			} else {
				printf("No leyo el ultimo registro");
				break;
			}
		} else {
			if (auxJugador != NULL) {
				ll_add(pArrayListJugador, auxJugador);
			}
		}
	}


    return retorno;
}

/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion){
	int retorno = 0, cantidad = 0;
	char  id[10], convocados[10], pais[25], confederacion[25];

	Seleccion* auxSeleccion = NULL;

		cantidad = fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^\n]\n",
					id, pais, confederacion, convocados);

	if ( pFile != NULL && pArrayListSeleccion != NULL ) {
		do{

			cantidad = fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^\n]\n",
						id, pais, confederacion, convocados);

		if ( cantidad == 4 ){
			auxSeleccion = selec_newParametros(id, pais, confederacion, convocados);
			if(auxSeleccion != NULL) {
				ll_add(pArrayListSeleccion, auxSeleccion);
				retorno = 1;
			}
		  }

		}while ( !feof(pFile) );
	}

    return retorno;
}

