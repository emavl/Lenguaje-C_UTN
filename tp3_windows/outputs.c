#include "outputs.h"

void limpiarConsola(void)
{
	printf("\n\n\n\n");
}

void mostrarSeparador(void)
{
	printf("--------------\n");
}

void ejecutarMenu(int *opcion) {

	printf("\n\n");
	for (int i = 0; i < 70; ++i)
		printf("—");
	printf("\n||                  Bienvenidos a FIFA world Cup 2022®           ||\n ");
	for (int i = 0; i < 70; ++i)
		printf("—");

	printf("\n\n   ■        ■ ■    ■ ■    ■ ■    ■ ■    ■ ■    ■ ■    ■ ■        ■\n");

	printf("\n  ◄------------- Complete los siguientes datos por favor -------------► \n\n");

	pedirEntero(opcion, "-------------------------------------\n"
								 "1. Cargar archivos\n"
								 "2. Alta jugador\n"
								 "3. Modificacion de jugador\n"
								 "4. Baja de jugador\n"
	    						 "5. Listados\n"
								 "6. Convocar Jugadores\n"
								 "7. Salir\n"
								 "-------------------------------------\n"
								 "Ingrese una opcion: ",
								 "-------------------------------------\n"
								 "1. Cargar archivos\n"
								 "2. Alta jugador\n"
								 "3. Modificacion de jugador\n"
								 "4. Baja de jugador\n"
								 "5. Listados\n"
								 "6. Convocar Jugadores\n"
								 "7. Salir\n"
								 "-------------------------------------\n"
								 "Opcion invalida, reingrese: ", 1, 7);

}

void menuModificar(char letra) {

	   utn_getCaracter(&letra, "\nQue campo desea modificar "
							"-------------------------------------\n"
							"\na) Nombre\n"
							"\nb) Edad\n"
							"\nc) Posicion\n"
							"\nd) Nacionalidad\n"
							"\ne) volver atras\n"
							 "-------------------------------------\n"
							 "Ingrese una opcion: ",
							 "-------------------------------------\n"
							"\na) Nombre\n"
							"\nb) Edad\n"
							"\nc) Posicion\n"
							"\nd) Nacionalidad\n"
							"\ne) volver atras\n"
							 "-------------------------------------\n"
							 "Opcion invalida, reingrese:  ", 'a', 'e', 3);
}
char menuListar(char letra) {

	utn_getCaracter(&letra, "-------------------------------------\n"
							"\na) Todos los Jugadores.\n"
							"\nb) Todas las selecciones."
							"\nc) Jugadores convocados ( unicamente )"
							"\nd) volver atras\n"
							 "-------------------------------------\n"
							 "Ingrese una opcion: ", "-------------------------------------\n"
							"\na) Todos los Jugadores.\n"
							"\nb) Todas las selecciones."
							"\nc) Jugadores convocados ( unicamente )"
							"\nd) volver atras\n"
							 "-------------------------------------\n"
							 "Opcion invalida, reingrese:  ", 'a', 'b', 5);

	return letra;
}
