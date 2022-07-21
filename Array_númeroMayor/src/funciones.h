/*
 * funciones.h
 *
 *  Created on: 21 jul. 2022
 *      Author: Emaaaaaaa !!!!
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
/**
 *
 * @param list - Array
 * @param size - Tamaño
 */
void initArray(int list [], int size);
/**
 *
 * @param list - array.
 * @param size - Tamaño.
 */
void cargarArray(int list[], int size);
/**
 *
 * @param mensaje - mensaje del usuario.
 * @param mensajeError - mensaje de error.
 * @return numero.
 */
int getNumber(char mensaje[], char mensajeError[]);
/**
 *
 * @param list - Array.
 * @return - retorna el valor mayor.
 */
int mayorNumero(int list[]);

#endif /* FUNCIONES_H_ */
