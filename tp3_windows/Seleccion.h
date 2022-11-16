#include "LinkedList.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"


#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
}Seleccion;

Seleccion* selec_new();
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);
void selec_delete();

int selec_getId(Seleccion* this,int* id);
int selec_getPais(Seleccion* this,char* pais);
int selec_getConfederacion(Seleccion* this,char* confederacion);


int selec_setConvocados(Seleccion* this,int convocados);
int selec_getConvocados(Seleccion* this,int* convocados);

void Seleccion_print(Seleccion* this);
void Seleccion_printPais(LinkedList* pArrayListSeleccion);
void Seleccion_printSoloPais(Seleccion* this);

void Seleccion_opcConfederacion(LinkedList* pArrayListSeleccion);
int Seleccion_compConfederacion(void* Seleccion1, void* Seleccion2);

int Seleccion_compConfederacion(void* Seleccion1, void* Seleccion2);
void Seleccion_opcConfederacion(LinkedList* pArrayListSeleccion) ;

int Seleccion_compararID(void* Seleccion1, void* Seleccion2);
int jug_compPaisDeSeleccion(void* Seleccion1, void* Seleccion2);

#endif // selec_H_INCLUDED
