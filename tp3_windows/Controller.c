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
	int retorno = 0;
	FILE* pFIle;

	pFIle = fopen(path, "r");

	if (pFIle != NULL) {
	 if ( parser_JugadorFromText(pFIle, pArrayListJugador) == 1 ){
		 retorno = 1;
	 }
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
			retorno = 1;
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
int controller_editarJugador(LinkedList* pArrayListJugador){
	int retorno = 0;

	if (pArrayListJugador != NULL) {

		printf("\n\nModificacion de jugadores\n");

		if (jug_modificacion(pArrayListJugador) == 1) {
			retorno = 1;
			system("pause");
		} else {
			printf("\nNo se han podido actualizar los datos\n\n");
			system("pause");
		}
	}
	return retorno;
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
	int retorno = 0;
	int opcion;
	int i=0;

	if(pArrayListJugador!=NULL)
	{
		mostrarSeparador();
		printf("Baja de jugadores \n");
		opcion = getValidInt("\n¿Cuantos jugadores desea dar de baja?: ", "\nError, reingrese: ", 1, 10);
		do
		{
			if ( jug_baja(pArrayListJugador) == 1 )
			{
				retorno = 1;
			}
			i++;
		}while(opcion!=i);
	}

    return retorno;
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
	printf("\n____________________________________________________________________________________________________\n" );
	printf("%5s |%25s |%4s |%20s  |%20s |%15s|\n", "Id", "N o m b r e    ", "edad",
			"p o s i c i o n", "nacionalidad", "idSeleccion");
	printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
	for(i = 0; i < cantidad; i++){
		auxjug = (Jugador*) ll_get(pArrayListJugador, i);
		jug_print(auxjug);
	}
	printf("______|__________________________|_____|______________________|_____________________|_______________|\n" );

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
	int retorno = 0, cantidad = 0;
	FILE* pFile = NULL;

	int id, edad, idSeleccion;
	char nombreCompleto[100], posicion[30], nacionalidad[30];

	pFile = fopen(path,"w");

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		fprintf(pFile,"id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");

		Node* indice = pArrayListJugador->pFirstNode;

		for(; indice != NULL; indice = indice->pNextNode)
		{
			 jug_getId(indice->pElement,&id);
			 jug_getNombreCompleto(indice->pElement,nombreCompleto);
			 jug_getEdad(indice->pElement,&edad);
			 jug_getPosicion(indice->pElement,posicion);
			 jug_getNacionalidad(indice->pElement,nacionalidad);
			 jug_getSIdSeleccion(indice->pElement,&idSeleccion);

			cantidad = fprintf(pFile,"%d,%s,%d,%s,%s,%d\n",
			id, nombreCompleto, edad, posicion, nacionalidad,idSeleccion);

			if(!cantidad)
			{
				retorno = 0;
				fclose(pFile);
				return retorno;
			}

		}

		retorno = 1;
		fclose(pFile);
	} else {
		printf("\nNo se puedo abrir el archivo.\n");
		retorno = 0;
	}


	return retorno;
}


/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){
	int retornoOk = 0; // se tiene que poner en 1 cuando todo salga bien

	FILE* archivo = NULL;// Actualmente contiene basura
	Jugador* simpleJugador = NULL;
	Seleccion* simpleSeleccion = NULL;

	int auxLenJug = ll_len(pArrayListJugador);
	int auxLenSec = ll_len(pArrayListSeleccion);

	char nombreConfederacionInput[100];
	char nombreConfederacionVali[100];
	int idSeleccionJug;
	int idSeleccion;
	int valiExistConfe;

	controller_listarSelecciones(pArrayListSeleccion);

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
        controller_listarSelecciones(pArrayListSeleccion);
        getStringLetras("\nIngrese el nombre de la confederacion en MAYUSCULAS para el listado de sus jugadores convocados: ",confElegida);

        archivo = fopen(path, "wb");

        // Terminamos de perdir //
        for (int i = 0; i < auxLenJug; i++)
        {
        	simpleJugador = (Jugador*)ll_get(pArrayListJugador,i);
        	jug_getSIdSeleccion(simpleJugador,&idSeleccionJug);

        	if (idSeleccionJug > 0)
        	{
        		for(int k = 0; k < auxLenSec; k++)
        		{
        			simpleSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, k);

        			selec_getId(simpleSeleccion, &idSeleccion); // obtenemos el id de la confe
        			if(idSeleccionJug == idSeleccion)
        			{
        				selec_getConfederacion(simpleSeleccion, nombreConfederacionVali); // obtenemos el nombre de la confederacion

        				if(stricmp(nombreConfederacionInput,nombreConfederacionVali) == 0)
        				{
        					//printf("\n* ka04 *\n");
        					fwrite(simpleJugador,sizeof(Jugador), 1, archivo);
        					retornoOk = 1;
        				}
        			}

        		}
        	}
        }
	}
	fclose(archivo);
	// archivos
	return retornoOk;
}


int controller_cargarArchivoBinario(char *path, LinkedList *pArrayListJugador) {
	int retorno = 0;

	FILE *archivo = NULL;
	Jugador *auxJugador = NULL;

	archivo = fopen(path, "rb");

	if (archivo != NULL) {
		ll_clear(pArrayListJugador);

		do {
			auxJugador = jug_new();
			fread(auxJugador, sizeof(Jugador), 1, archivo);
			if (feof(archivo)) {
				free(auxJugador);
				break;
			}
			ll_add(pArrayListJugador, auxJugador);
			retorno = 1;
		} while (feof(archivo) == 0);

		fclose(archivo);
	}

	controller_listarJugadores(pArrayListJugador);

	return retorno;
}


/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char *path, LinkedList *pArrayListSeleccion) {
	int retorno = 0;
	FILE *pArch;

	pArch = fopen(path, "r");

	if (pArch != NULL) {
		if (parser_SeleccionFromText(pArch, pArrayListSeleccion) == 1) {
			retorno = 1;
		}
	} else {
		printf("Error al abrir el archivo\n");
	}
	fclose(pArch);

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


/** \brief Listar selecciones -
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion){

	int retorno = 0, i, cantidad;

	Seleccion* auxSeleccion;

	cantidad = ll_len(pArrayListSeleccion);
	printf("\n________________________________________________________________\n" );
		printf("%5s |%20s |%20s |%4s |\n", "Id","P a i s", " Confederacion", " convocados");
		printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
	for(i = 0; i < cantidad; i++){
		auxSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
		Seleccion_print(auxSeleccion);
	}

	return retorno;
}



/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion){

	FILE* pFile = NULL;

	int id, convocados, retorno = 0,cantidad = 0;
	char pais[30],confederacion[30];

	pFile = fopen(path,"w");

	if(pFile != NULL && pArrayListSeleccion != NULL)
	{
		fprintf(pFile,"id,pais,confederacion,convocados\n"); // escribimos cabe

		Node* indice = pArrayListSeleccion->pFirstNode;

		for(; indice != NULL; indice = indice->pNextNode)
		{
			selec_getId(indice->pElement,&id);
			selec_getPais(indice->pElement, pais);
			selec_getConfederacion(indice->pElement,confederacion);
			selec_getConvocados(indice->pElement,&convocados);

			cantidad = fprintf(pFile,"%d,%s,%s,%d\n",
			id, pais, confederacion, convocados);

			if(!cantidad)
			{
				retorno = 0;
				fclose(pFile);
				return retorno;
			}

		}

		retorno = 1;
		fclose(pFile);

	} else {
		printf("\nNo se puedo abrir el archivo.\n");
		retorno = 0;
	}

	return retorno;
}

/**
 * \fn int controller_listar(LinkedList*, LinkedList*)
 * \brief -
 *
 * \param pArrayListSeleccion
 * \param pArrayListJugador
 * \return
 */
int controller_listar(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador ) {

	int opcion , retorno;
	if ( pArrayListSeleccion != NULL && pArrayListJugador != NULL ) {
		//do{
			menuListar(&opcion);
				switch (opcion) {
					case 1:
						controller_listarJugadores(pArrayListJugador);
						break;
					case 2:
						controller_listarSelecciones(pArrayListSeleccion);
						break;
					case 3:
						if( jug_convocadoUnicamente(pArrayListJugador) == 1 ) {
							retorno = 1;
						} else {
							printf("\nNo hay jugadores convocados\n");
						}
						break;
					case 4:

					default:
						break;
				}
		//	}while(opcion != 4);
	} else {
		printf(" error ..");
	}


	return retorno;
}

// >>>--------------------►     O r d e n a m i e n t o.

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList *pArrayListJugador) {

 int retorno = 0;
 int opcion;

	do
	{
		limpiarConsola();
		 menuOrdJug(&opcion);
		switch(opcion)
		{
			case 1://     >>>--------------------►            N a c i o n a l i d a d.
				jug_opcNacionalidad(pArrayListJugador);
				controller_listarJugadores(pArrayListJugador);
				system("pause");
			break;
			case 2://     >>>--------------------►                 			 E d a d .
				jug_opcEdad(pArrayListJugador);
				controller_listarJugadores(pArrayListJugador);
				system("pause");
			break;
			case 3://     >>>--------------------►                  	 N o m b r e .
				jug_opcNombre(pArrayListJugador);
				controller_listarJugadores(pArrayListJugador);
			break;
			case 4:
				ll_deleteLinkedList(pArrayListJugador);
			break;
		}
	}while( opcion != 4 );

	return retorno;
}
/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList *pArrayListSeleccion) {

	printf("\nPor lo pront Usted puede ordenar solamente\n "
			"Seleccion por confederacion \n"
			"disculas molestias - gracias (^.^) \n\n\n");
	system("pause");
	Seleccion_opcConfederacion(pArrayListSeleccion);
	controller_listarSelecciones(pArrayListSeleccion);



	return 0;
}


int controller_Ordenamiento(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion ) {


	int retorno = -1;
	int opcion;

	do
	{
		limpiarConsola();
		 menuOrdenar(&opcion);
		switch(opcion)
		{
			case 1:
				controller_ordenarJugadores(pArrayListJugador);
			break;
			case 2:
				controller_ordenarSelecciones(pArrayListSeleccion);
			break;
			case 3:

			break;
		}
	}while( opcion != 3 );
	return retorno;
}

// >>>--------------------►     C o n v o c a d o s .

int controller_convocados(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion) {

	int retorno = 0, opcion;

	Jugador* auxJug = NULL;

	limpiarConsola();
	 do{
		 menuConvocados(&opcion);
		switch(opcion)
		{
			case 1:
				jug_convocados(pArrayListJugador, pArrayListSeleccion);
			break;
			case 2:
				if ( jug_quitarSeleccion(auxJug, pArrayListJugador, pArrayListSeleccion) == 0 ) {
					printf("\n\n No se pudieron quitar los convocados\n\n");
				}
			break;
			case 3:

			break;
		}
	 }while( (opcion < 1 ) || (opcion > 3) );
	return retorno;
}
