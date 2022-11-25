#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;
/**
 * \fn Jugador jug_new*()
 * \brief - nos permita trabajar en memoria dinamica.
 * \return - un puntero a jugador
 */
Jugador* jug_new();
/**
 * \fn Jugador jug_newParametros*(char*, char*, char*, char*, char*, char*)
 * \brief - nos permita crear en memoria dinamica el jugador
 * \param idStr - cadena de caracter del ID del jugador
 * \param nombreCompletoStr - Nombre del jugador
 * \param edadStr - cadena de caracter de la edad del jugador.
 * \param posicionStr - posicion del jugador.
 * \param nacionalidadStr - nacionalidad del jugador.
 * \param idSelccionStr - ID de la seleccion a la que pertenece.
 * \return - un puntero a jugador.
 */
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);
/**
 * \fn void jug_delete(Jugador*)
 * \brief - libera la memoria dinamica.
 *
 * \param this
 */
void jug_delete(Jugador* this);
/**
 * \fn int jug_setId(Jugador*, int)
 * \brief - Modifica el ID del jugador
 * \param this
 * \param id
 * \return 0 (exito) -1 (error)
 */
 int jug_setId(Jugador* this,int id);
/**
 * \fn int jug_getId(Jugador*, int*)
 * \brief - Obtiene el ID del jugador.
 * \param this
 * \param id
 * \return 0 (exito) -1 (error)
 */
 int jug_getId(Jugador* this,int* id);
/**
 * \fn int jug_setNombreCompleto(Jugador*, char*)
 * \brief - Modifica el Nombre del jugador
 * \param this
 * \param nombreCompleto
 * \return 0 (exito) -1 (error)
 */
 int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
 /**
   * \fn int jug_getNombreCompleto(Jugador*, char*)
  * \brief - obtiene el nombre del pasajero.
  * \param this
  * \param nombreCompleto
  * \return 0 (exito) -1 (error)
  */
 int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);
/**
 * \fn int jug_setPosicion(Jugador*, char*)
 * \brief - Modifica la posicion del jugador.
 * \param this
 * \param posicion
 * \return 0 (exito) -1 (error)
 */
 int jug_setPosicion(Jugador* this,char* posicion);
 /**
   * \fn int jug_getPosicion(Jugador*, char*)
  * \brief - Obtiene la posicion del jugador.
  * \param this
  * \param posicion
  * \return 0 (exito) -1 (error)
  */
 int jug_getPosicion(Jugador* this,char* posicion);
/**
 * \fn int jug_setNacionalidad(Jugador*, char*)
 * \brief -Modifica la nacionalidad del jugador.
 * \param this
 * \param nacionalidad
 * \return 0 (exito) -1 (error)
 */
 int jug_setNacionalidad(Jugador* this,char* nacionalidad);
 /**
   * \fn int jug_getNacionalidad(Jugador*, char*)
  * \brief - Obtiene la nacionalidad del jugador.
  * \param this
  * \param nacionalidad
  * \return 0 (exito) -1 (error)
  */
 int jug_getNacionalidad(Jugador* this,char* nacionalidad);
/**
 * \fn int jug_setEdad(Jugador*, int)
 * \brief - Modifica la edad del jugador.
 * \param this
 * \param edad
 * \return 0 (exito) -1 (error)
 */
 int jug_setEdad(Jugador* this,int edad);
 /**
   * \fn int jug_getEdad(Jugador*, int*)
  * \brief- Obtiene la edad del jugador.
  *
  * \param this
  * \param edad
  * \return 0 (exito) -1 (error)
  */
 int jug_getEdad(Jugador* this,int* edad);
/**
 * \fn int jug_setIdSeleccion(Jugador*, int)
 * \brief - Modifica la Seleccion del jugador.
 * \param this
 * \param idSeleccion
 * \return 0 (exito) -1 (error)
 */
 int jug_setIdSeleccion(Jugador* this,int idSeleccion);
 /**
   * \fn int jug_getSIdSeleccion(Jugador*, int*)
  * \brief- Obtiene la edad del jugador.
  *
  * \param this
  * \param idSeleccion
  * \return 0 (exito) -1 (error)
  */
 int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);
/**
 * \fn int jug_print(Jugador*)
 * \brief - Muestra un jugador.
 * \param this
 * \return
 */
 int jug_print(Jugador* this);
/**
 * \fn int jug_sigId(int)
 * \brief - abre un archivo en modo escritura, al cual
 * le escribo un nuevo valor llamado siguiente ID.
 * \param id - recibe el ID con el que comienza
 * \return 1 (exito) 0 (error)
 */
 int jug_sigId(int id);
 /**
   * \fn int jug_idDisponible(char*)
  * \brief - abre un archivo en modo lectura, el cual
  *  retorna el id en formato cadena
  * \param id
  * \return 1 (exito) 0 (error).
  */
 int jug_idDisponible(char* id);
/**
 * \fn int jug_add(LinkedList*, int*)
 * \brief me permite agregar un elemento a la lista.
 *
 * \param pArrayListJugador
 * \param id
 * \return 1 (exito) 0 (error).
 */
 int jug_add(LinkedList* pArrayListJugador, int* id);
/**
 * \fn void borrarJugador(Jugador*)
 * \brief - libera la memoria dinamica que utiliza el elemento.
 * \param this
 */
void borrarJugador(Jugador *this);

// >>>--------------------►     O r d e n a m i e n t o.

//	>-----►	 E d a d .
/**
 * \fn int jug_compNacionalidad(void*, void*)
 * \brief -  compara 2 parametros para saber su
 * diferencia el uno con el otro. en este caso la nacionalidad
 * \param jugador1
 * \param jugador2
 * \return retorna la comparacion entre el auxiliares.
 */
int jug_compNacionalidad(void* jugador1, void* jugador2);
/**
 * \fn int jug_compEdad(void*, void*)
 * \brief -  compara 2 parametros para saber su
 * diferencia el uno con el otro. en este caso laedad.
 * \param jugador1
 * \param jugador2
 * \return
 */
int jug_compEdad(void* jugador1, void* jugador2);
/**
 * \fn int jug_compNombre(void*, void*)
 * \brief-  compara 2 parametros para saber su
 * diferencia el uno con el otro. en este caso la nombre.
 * \param jugador1
 * \param jugador2
 * \return
 */
int jug_compNombre(void* jugador1, void* jugador2);

// >>--------------►  S o r t
/**
 * \fn void jug_opcNacionalidad(LinkedList*)
 * \brief - Ordena los elementos de la lista, en este caso la nacionalidad
 * utilizando la funcion ll_sort de la lista enlasada, con un criterio (orden)
 *  recibido como parametro.
 * \param pArrayListJugador
 */
void jug_opcNacionalidad(LinkedList *pArrayListJugador);
/**
 * \fn void jug_opcEdad(LinkedList*)
 * \brief - Ordena los elementos de la lista, en este caso la edad
 * utilizando la funcion ll_sort de la lista enlasada, con un criterio (orden)
 *  recibido como parametro. *
 * \param pArrayListJugador
 */
void jug_opcEdad(LinkedList *pArrayListJugador);
/**
 * \fn void jug_opcNombre(LinkedList*)
 * \brief- Ordena los elementos de la lista, en este caso el nombre
 * utilizando la funcion ll_sort de la lista enlasada, con un criterio (orden)
 *  recibido como parametro.
 *
 * \param pArrayListJugador
 */
void jug_opcNombre(LinkedList *pArrayListJugador);

// >>>--------------------►    M o d i f i c a c i o n .
/**
 * \fn int jug_modificacion(LinkedList*)
 * \brief - modifico los parametros del jugador
 * como: nombre - edad - posicion - nacionalidad.
 * \param pArrayListaJugador
 * \return
 */
int jug_modificacion(LinkedList* pArrayListaJugador);
/**
 * \fn int jug_buscarId(LinkedList*, int)
 * \brief devuelve el jugador buscado por ID.
 *  utilizando dentro la funcion ll_get.
 * \param pArrayListaJugador
 * \param id
 * \return int - retorna el indice.
 */
int jug_buscarId(LinkedList* pArrayListaJugador, int id );
/**
 * \fn int jug_opcModificarNombreCompleto(int, Jugador*)
 * \brief - modifico el nombre del elemento.
 * \param index - indice pasado por valor.
 * \param auxiliar puntero a la estructura Jugador
 * \return 1 (exito) 0 (error).
 */
int jug_opcModificarNombreCompleto( int index, Jugador* auxiliar);
/**
 * \fn int jug_opcModificarEdad(Jugador*)
 * \brief - modifico la edad del elemento.
 * \param auxiliar puntero a la estructura Jugador.
 * \return 1 (exito) 0 (error).
 */
int jug_opcModificarEdad( Jugador* auxiliar);
/**
 * \fn int jug_opcModificarPosicion(int, Jugador*)
 * \brief - modifico la posicion del elemento.
 * \param index - indice
 * \param auxiliar puntero a la estructura Jugador.
 * \return 1 (exito) 0 (error).
 */
int jug_opcModificarPosicion( int index, Jugador* auxiliar);
/**
 * \fn int jug_opcModificarNacionalidad(int, Jugador*)
 * \brief - modifico la nacionalidad del elemento.
 * \param index - indice
 * \param auxiliar puntero a la estructura Jugador.
 * \return 1 (exito) 0 (error).
 */
int jug_opcModificarNacionalidad( int index, Jugador* auxiliar);

// >>>--------------------►    					B a j a .
/**
 * \fn int jug_baja(LinkedList*)
 * \brief - baja de un elemento .
 * \param pArrayListaJugador
 * \return  1 (exito) 0 (error).
 */
int jug_baja(LinkedList* pArrayListaJugador);

// -------- convocados
/**
 * \fn int jug_convocados(LinkedList*, LinkedList*)
 * \brief - funcion para la convocatoria de jugadores
 * \param pArrayListaJugador
 * \param pArrayListSeleccion
 * \return 1 (exito) 0 (error).
 */
int jug_convocados(LinkedList* pArrayListaJugador, LinkedList *pArrayListSeleccion);
/**
 * \fn int jug_convocarSelec(Jugador*, LinkedList*)
 * \brief - acomoda y muestra los paises en orden
 * de menor a mayor utilizando el id ( de 1 a 32 ).
 * \param auxJug
 * \param pArrayListSeleccion
 * \return 1 (exito) 0 (error).
 */
int jug_convocarSelec(  Jugador* auxJug, LinkedList *pArrayListSeleccion);
/**
 * \fn int jug_opcPaisSeleccion(Jugador*, LinkedList*)
 * \brief asigno un ID del pais a utilizar
 * \param auxJug puntero a estructura jugador
 * \param pArrayListSeleccion
 * \return 1 (exito) 0 (error).
 */
int jug_opcPaisSeleccion( Jugador* auxJug, LinkedList *pArrayListSeleccion);
/**
 * \fn int jug_convocadoUnicamente(LinkedList*)
 * \brief recorro con un for obteniendo los jugadores
 * convocados unicamente
 * \param pArrayListaJugador
 * \return 1 (exito) 0 (error).
 */
int jug_convocadoUnicamente(LinkedList* pArrayListaJugador);
/**
 * \fn int jug_quitarSeleccion(Jugador*, LinkedList*, LinkedList*)
 * \brief
 *
 * \param auxJug
 * \param pArrayListaJugador
 * \param pArrayListSeleccion
 * \return
 */
int jug_quitarSeleccion(Jugador *auxJug, LinkedList *pArrayListaJugador, LinkedList *pArrayListSeleccion);

#endif // jug_H_INCLUDED
