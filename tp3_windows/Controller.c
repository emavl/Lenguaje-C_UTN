#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "inputs.h"
#include "outputs.h"


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador) {
	int retorno = -1;
	FILE* pFIle;

	pFIle = fopen(path, "r");

	if (pFIle != NULL) {
	 parser_JugadorFromText(pFIle, pArrayListJugador);
	} else {
		printf("Error al abrir el archivo\n");
	}
		fclose(pFIle);

	return retorno;
}
/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador) {
	FILE* pFile;
	int validarParseo = 0;

	pFile = fopen(path, "rb");
	if(pFile != NULL)
	{
		validarParseo = parser_JugadorFromBinary(pFile, pArrayListJugador);
	}
	fclose(pFile);

	return validarParseo;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador) {

	int retorno = 0, id;
	if ( pArrayListJugador != NULL ) {
		limpiarConsola();
		mostrarSeparador();
		printf("Alta de Jugadores\n");
		mostrarSeparador();
		if ( jug_add(pArrayListJugador, &id) == 1) {
			printf("Se ha dado de alta correctamente");
		}

	} else	{
		printf("No se ha dado de alta un nuevo pasajero");
	}

	jug_sigId(id);


	return retorno;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	return 1;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador) {
	int retorno = 1, i, cantidad;
	Jugador* auxjug;
	cantidad = ll_len(pArrayListJugador);

	for(i = 0; i < cantidad; i++){
		auxjug = (Jugador*) ll_get(pArrayListJugador, i);
		jug_print(auxjug);
	}

	return retorno;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList *pArrayListJugador) {

	int retorno = -1;
	LinkedList *clon;
	if (pArrayListJugador != NULL) {
		clon = ll_clone(pArrayListJugador);

		if (pArrayListJugador != NULL) {
			jug_Ordenamiento(clon);
		}
	}

	return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador){
	FILE* pFile;
	int retorno;
	pFile = fopen(path, "wb");
	if(pFile == NULL)
	{
		printf("\nNo se puedo abrir el archivo.\n");
		retorno = 0;
	}

	Node* indice = pArrayListJugador->pFirstNode;

	for(; indice != NULL; indice = indice->pNextNode)
	{
		fwrite(indice->pElement,sizeof(Jugador),1,pFile);
	}
	fclose(pFile);

	return retorno;

}


/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion) {
	int retorno = -1;
	FILE* pFIle;

	pFIle = fopen(path, "r");

	if (pFIle != NULL) {
		if ( parser_SeleccionFromText(pFIle, pArrayListSeleccion) == 0 ){
			printf("parseo correcto");
		}
	} else {
		printf("Error al abrir el archivo\n");
	}
		fclose(pFIle);

	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion){
	int retorno = 1, i, cantidad;
	Seleccion* auxSeleccion;
	cantidad = ll_len(pArrayListSeleccion);

	for(i = 0; i < cantidad; i++){
		auxSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
		Seleccion_print(auxSeleccion);
	}

	return retorno;
}
/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
    return 1;
}

int controller_listar(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador ) {

	int opcion ;
		do{	menuListar(&opcion);
		switch (opcion) {
			case 1:
				controller_listarJugadores(pArrayListJugador);
				break;
			case 2:
				controller_listarSelecciones(pArrayListSeleccion);
				break;
			case 3:

				break;
			case 4:

			default:
				break;
		}
	}while(opcion != 'd');

	return 0;
}

//int controller_convocados(LinkedList* pArrayListJugador ) {
//
//	Jugador* convocados = NULL;
//	for (    )
//
//
//	return 0;
//}
