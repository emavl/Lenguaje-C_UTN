#include "inputs.h"

/** \brief Funci�n para "limpar" consola con "\n".
*/
void limpiarConsola(void);
/** \brief Funci�n para separar el menu de la consola con "----".
*/
void mostrarSeparador(void);
/**
 * \fn int menuModificar(int*)
 * \brief menu de las modificaciones.
 * \param opcion
 * \return
 */
int menuModificar(int* opcion);
/**
 * \fn char menuListar(char)
 * \brief menú de listado de jugadores y selecciones. *
 * \param letra
 * \return
 */
int menuListar(int* letra);
/**
 * \fn void ejecutarMenu(int*)
 * \brief menu principal del codigo. *
 * \param opcion
 */
void ejecutarMenu(int *opcion);
/**
 * \fn char menuOrdenar(int*)
 * \brief - menú del ordenamiento. *
 * \param opcion
 * \return
 */
int menuOrdenar(int* opcion);
/**
 * \fn int menuCriterio(int*)
 * \brief - menu del criterio a elegir. *
 * \param opcion
 * \return
 */
int menuCriterio(int* opcion);
/**
 * \fn int menuOrdJug(int*)
 * \brief - menú de ordenamiento de jugadores. *
 * \param opcion
 * \return
 */
int menuOrdJug(int* opcion);
/**
 * \fn int menuConvocar(int*)
 * \brief - menu de convocatoria del jugador *
 * \param opcion
 * \return
 */
int menuConvocar (int* opcion);
/**
 * \fn int menuConvocados(int*)
 * \brief menu de convocatoria de jugadores convocados y sin convocar *
 * \param opcion
 * \return
 */
int menuConvocados(int* opcion);
