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
								 "7. Ordenar y listar.\n"
								 "8. Generar archivo Binario.\n"
								 "9. Cargar archivo binario.\n"
								"10. Guardar archivos .CSV\n"
								"11. Salir\n"
								 "-------------------------------------\n"
								 "Ingrese una opcion: ",
								 "-------------------------------------\n"
								 "1. Cargar archivos\n"
								 "2. Alta jugador\n"
								 "3. Modificacion de jugador\n"
								 "4. Baja de jugador\n"
								 "5. Listados\n"
								 "6. Convocar Jugadores\n"
								 "8. Generar archivo Binario.\n"
								 "9. Cargar archivo binario.\n"
								"10. Guardar archivos .CSV\n"
								"11. Salir\n"
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
							 "Ingrese una opcion: "
							 "-------------------------------------\n",
							 "-------------------------------------\n"
							 "Opcion invalida, reingrese:  "
							 "-------------------------------------\n"
							"\na) Nombre\n"
							"\nb) Edad\n"
							"\nc) Posicion\n"
							"\nd) Nacionalidad\n"
							"\ne) volver atras\n", 'a', 'e', 3);

}
int menuListar(int* opcion) {

	pedirEntero(opcion, "-------------------------------------\n"
						"\n1) Todos los Jugadores"
						"\n2) Todas las selecciones."
						"\n3) Jugadores convocados ( unicamente )"
						"\n4) volver atras\n"
						 "-------------------------------------\n"
						 "Ingrese una opcion: ",
						 "-------------------------------------\n"
						 "Opcion invalida, reingrese\n\n  "
						"\n1) Todos los Jugadores."
						"\n2) Todas las selecciones."
						"\n3) Jugadores convocados ( unicamente )"
						"\n4) volver atras\n"
						 "-------------------------------------\n", 1, 4);
	return 0;
}

int menuOrdenar(int* opcion) {

	pedirEntero(opcion, "-------------------------------------\n"
									 "Menu de Ordenamiento:\n\n"
									 "1) Jug por nacionalidad.\n"
									 "2) seleccion por confederacion.\n"
									 "3) jugador por edad.\n"
									 "4) jugador por Nombre.\n"
									 "5) volver atras\n"
									 "-------------------------------------\n"
									 "Ingrese una opcion: ",
									 "-------------------------------------\n"
									 "1) Jug por nacionalidad.\n"
									 "2) seleccion por confederacion.\n"
									 "3) jugador por edad.\n"
									 "4) jugador por Nombre.\n"
									 "5) volver atras\n"
									 "-------------------------------------\n"
									 "Opcion invalida, reingrese: ", 1, 5);
	return 0;
}
int menuCriterio()
{
	int opciones;

	pedirEntero(&opciones,  "\n >>>>----------------► Criterio  \n"
							"0. Listado descendente.\n"
							"1. Listado ascendente.\n"
							"-------------------------------------\n"
							"Ingrese una opcion: ",
							"-------------------------------------\n"
							"0. Listado descendente.\n"
							"1. Listado ascendente.\n"
							"-------------------------------------\n"
							"Opcion invalida, reingrese: ", 0, 1);

	return opciones;
}
