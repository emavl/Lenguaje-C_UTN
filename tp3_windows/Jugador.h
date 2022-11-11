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

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

void jug_delete(Jugador* this);

 int jug_setId(Jugador* this,int id);
 int jug_getId(Jugador* this,int* id);

 int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
 int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

 int jug_setPosicion(Jugador* this,char* posicion);
 int jug_getPosicion(Jugador* this,char* posicion);

 int jug_setNacionalidad(Jugador* this,char* nacionalidad);
 int jug_getNacionalidad(Jugador* this,char* nacionalidad);

 int jug_setEdad(Jugador* this,int edad);
 int jug_getEdad(Jugador* this,int* edad);

 int jug_setIdSeleccion(Jugador* this,int idSeleccion);
 int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);

 int jug_print(Jugador* this);
 int jug_sigId(int id);
 int jug_idDisponible(char* id);

 int jug_add(LinkedList* pArrayListJugador, int* id);

void borrarJugador(Jugador *this);

// >>>--------------------►     O r d e n a m i e n t o.

 int jug_Ordenamiento(LinkedList* clon);

// >-----► E d a d .
void jug_opcEdad(LinkedList *clon);
 int jug_porEdad(void* jugador1, void* jugador2);

 // >-----► N a c i o n a l i d a d .
void jug_opcNacionalidad(LinkedList *clon);
 int jug_compNacionalidad(void* jugador1, void* jugador2) ;

#endif // jug_H_INCLUDED
