/*
 * input.h
 *
 *  Created on: 1 oct. 2022
 *      Author: Ema
 */

#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * \fn void hardcodeDatos(eAutor[], eEdit[])
 * \brief
 *
 * \param autore
 * \param editorial
 */
void hardcodeDatos( eAutor autore[], eEdit editorial[]);
/**
 * \fn int ejecutarMenu(int*)
 * \brief
 *
 * \param numero
 * \return
 */
int ejecutarMenu(int *numero);
/**
 * \fn char menuModificar(char)
 * \brief
 *
 * \param letra
 * \return
 */
char menuModificar(char letra);
/**
 * \fn char menuListar(char)
 * \brief Imprime el menu de para listar libros *
 * \param letra - opcion para navegar dentro del menu
 * \return
 */
char menuListar(char letra);
/**
 * \fn int PedirEntero(char*, char*, int, int)
 * \brief
 *
 * \param mensaje
 * \param mensajeError
 * \param minimo
 * \param maximo
 * \return
 */
int PedirEntero(char *mensaje, char *mensajeError,int minimo, int maximo);
/**
 * \fn float PedirFlotante(char*, char*, int, int)
 * \brief
 *
 * \param mensaje
 * \param mensajeError
 * \param minimo
 * \param maximo
 * \return
 */
float PedirFlotante(char *mensaje, char *mensajeError,int minimo, int maximo);
/**
 * \fn int PedirCadena(char[], int, char[])
 * \brief
 *
 * \param cadena
 * \param len
 * \param mensaje
 * \return
 */
int PedirCadena(char cadena[],int len,char mensaje[]);
/**
 * \fn void progPrincipal()
 * \brief
 *
 */
void progPrincipal();
#endif /* INPUT_H_ */
