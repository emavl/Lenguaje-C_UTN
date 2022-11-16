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
 * \brief
 *
 * \param this
 */
void jug_delete(Jugador* this);
/**
 * \fn int jug_setId(Jugador*, int)
 * \brief - Modifica el ID del jugador
 * \param this
 * \param id
 * \return
 */
 int jug_setId(Jugador* this,int id);
/**
 * \fn int jug_getId(Jugador*, int*)
 * \brief - Obtiene el ID del jugador.
 * \param this
 * \param id
 * \return
 */
 int jug_getId(Jugador* this,int* id);
/**
 * \fn int jug_setNombreCompleto(Jugador*, char*)
 * \brief - Modifica el Nombre del jugador
 * \param this
 * \param nombreCompleto
 * \return
 */
 int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
 /**
   * \fn int jug_getNombreCompleto(Jugador*, char*)
  * \brief - obtiene el nombre del pasajero.
  * \param this
  * \param nombreCompleto
  * \return
  */
 int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);
/**
 * \fn int jug_setPosicion(Jugador*, char*)
 * \brief - Modifica la posicion del jugador.
 * \param this
 * \param posicion
 * \return
 */
 int jug_setPosicion(Jugador* this,char* posicion);
 /**
   * \fn int jug_getPosicion(Jugador*, char*)
  * \brief - Obtiene la posicion del jugador.
  * \param this
  * \param posicion
  * \return
  */
 int jug_getPosicion(Jugador* this,char* posicion);
/**
 * \fn int jug_setNacionalidad(Jugador*, char*)
 * \brief -Modifica la nacionalidad del jugador.
 * \param this
 * \param nacionalidad
 * \return
 */
 int jug_setNacionalidad(Jugador* this,char* nacionalidad);
 /**
   * \fn int jug_getNacionalidad(Jugador*, char*)
  * \brief - Obtiene la nacionalidad del jugador.
  * \param this
  * \param nacionalidad
  * \return
  */
 int jug_getNacionalidad(Jugador* this,char* nacionalidad);
/**
 * \fn int jug_setEdad(Jugador*, int)
 * \brief - Modifica la edad del jugador.
 * \param this
 * \param edad
 * \return
 */
 int jug_setEdad(Jugador* this,int edad);
 /**
   * \fn int jug_getEdad(Jugador*, int*)
  * \brief- Obtiene la edad del jugador.
  *
  * \param this
  * \param edad
  * \return
  */
 int jug_getEdad(Jugador* this,int* edad);
/**
 * \fn int jug_setIdSeleccion(Jugador*, int)
 * \brief - Modifica la Seleccion del jugador.
 * \param this
 * \param idSeleccion
 * \return
 */
 int jug_setIdSeleccion(Jugador* this,int idSeleccion);
 /**
   * \fn int jug_getSIdSeleccion(Jugador*, int*)
  * \brief- Obtiene la edad del jugador.
  *
  * \param this
  * \param idSeleccion
  * \return
  */
 int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);
/**
 * \fn int jug_print(Jugador*)
 * \brief - Muestra un jugador.
 * \param this
 * \return
 */
 int jug_print(Jugador* this);

 int jug_sigId(int id);
 int jug_idDisponible(char* id);

 int jug_add(LinkedList* pArrayListJugador, int* id);

void borrarJugador(Jugador *this);

// >>>--------------------►     O r d e n a m i e n t o.

//	>-----►	 E d a d .
int jug_compNacionalidad(void* jugador1, void* jugador2);
int jug_compEdad(void* jugador1, void* jugador2);
int jug_compNombre(void* jugador1, void* jugador2);

// >>--------------►  S o r t
void jug_opcNacionalidad(LinkedList *pArrayListJugador);
void jug_opcEdad(LinkedList *pArrayListJugador);
void jug_opcNombre(LinkedList *pArrayListJugador);

// >>>--------------------►    M o d i f i c a c i o n .

int jug_modificacion(LinkedList* pArrayListaJugador);
int jug_buscarId(LinkedList* pArrayListaJugador, int id );
int jug_opcModificarNombreCompleto( int index, Jugador* auxiliar);
int jug_opcModificarEdad( Jugador* auxiliar);
int jug_opcModificarPosicion( int index, Jugador* auxiliar);
int jug_opcModificarNacionalidad( int index, Jugador* auxiliar);

// >>>--------------------►    					B a j a .

int jug_baja(LinkedList* pArrayListaJugador);

// -------- convocados
int jug_convocados(LinkedList* pArrayListaJugador, LinkedList *pArrayListSeleccion);
int jug_convocarSelec(  Jugador* auxJug, LinkedList *pArrayListSeleccion);
int jug_opcPaisSeleccion( Jugador* auxJug, LinkedList *pArrayListSeleccion);

int jug_convocadoUnicamente(LinkedList* pArrayListaJugador);
int jug_quitarSeleccion( Jugador* auxJug, LinkedList *pArrayListaJugador);

#endif // jug_H_INCLUDED
