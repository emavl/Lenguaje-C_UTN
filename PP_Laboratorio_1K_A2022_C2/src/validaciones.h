/*
 * validaciones.h
 *
 *  Created on: 2 oct. 2022
 *      Author: Ema
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * \fn int validarString(char[], int, char[])
 * \brief - Funcio que valida el ingreso de una cadena de caracteres
 *  evitando que sean numeros o espacio en blanco.
 * \param cadena
 * \param len
 * \param errorMensaje
 * \return
 */
int validarString(char cadena[], int len, char errorMensaje[]);
/**
 * \fn int validarNumero(char[])
 * \brief
 *
 * \param numero
 * \return
 */
int validarNumero(char numero[]);
/**
 * \fn int validarFloat(char[])
 * \brief
 *
 * \param cadena
 * \return
 */
int validarFloat ( char cadena[]);

#endif /* VALIDACIONES_H_ */
