#include <stdio.h>
#include <stdlib.h>


int PedirNumeros (char mensaje[], char mensajeError[], int min, int max);
void initArray(int lista[],int tamanio);
void cargarArray(int list[], char* mensaje, char* errorMensaje, int size);
void numPosyNeg(int lista[],int tamanio, int* pos, int* neg);
void SumatoriaPares(int lista[], int tamanio,int* Pares,int* maximoImpar);
void mostrar(int lista[],int tamanio);
void ordenamiento(int list[], int size);
