#include "inputs.h"

/** \brief Funci�n para "limpar" consola con "\n".
*/
void limpiarConsola(void);
/** \brief Funci�n para separar el menu de la consola con "----".
*/
void mostrarSeparador(void);
/**
 * \fn void menuModificar(char)
 * \brief
 *
 * \param letra
 */
void menuModificar(char letra);
/**
 * \fn char menuListar(char)
 * \brief
 *
 * \param letra
 * \return
 */
int menuListar(int* letra);
/**
 * \fn void ejecutarMenu(int*)
 * \brief
 *
 * \param opcion
 */
void ejecutarMenu(int *opcion);
/**
 * \fn char menuOrdenar(int*)
 * \brief
 *
 * \param opcion
 * \return
 */
int menuOrdenar(int* opcion);
/**
 * \fn int menuCriterio()
 * \brief
 *
 * \return
 */
int menuCriterio();
