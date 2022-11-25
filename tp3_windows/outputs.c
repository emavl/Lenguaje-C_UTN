#include "outputs.h"

void limpiarConsola(void)
{
	printf("\n\n\n\n");
}

void mostrarSeparador(void)
{
	printf("\n------------------------\n");
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
								 "Opcion invalida, reingrese: ", 1,11);

}


int menuModificar(int* opcion) {

	pedirEntero(opcion, "\nQue campo desea modificar \n"
						"-------------------------------------"
						"\n1) Nombre\n"
						"\n2) Edad\n"
						"\n3) Posicion\n"
						"\n4) Nacionalidad\n"
						"\n5) volver atras\n"
						 "-------------------------------------\n"
						 "Ingrese una opcion: ",
						 "Opcion invalida, reingrese:  "
						 "-------------------------------------\n"
						"\n1) Nombre\n"
						"\n2) Edad\n"
						"\n3) Posicion\n"
						"\n4) Nacionalidad\n"
						"\n5) volver atras\n", 1, 5);
	printf("-------------------------------------\n");
	return 0;
}
int menuListar(int* opcion) {

	pedirEntero(opcion, "-------------------------------------\n"
						"\n1) Todos los Jugadores"
						"\n2) Todas las selecciones."
						"\n3) Jugadores convocados ( unicamente )"
						"\n4) volver atras\n"
						 "-------------------------------------\n"
						 "Ingrese una opcion: ",
						 "\n-------------------------------------"
						 "Opcion invalida, reingrese\n\n  "
						"\n1) Todos los Jugadores."
						"\n2) Todas las selecciones."
						"\n3) Jugadores convocados ( unicamente )"
						"\n4) volver atras\n"
						 "-------------------------------------\n", 1, 4);
	return 0;
}

int menuOrdJug(int* opcion) {

	pedirEntero(opcion, "-------------------------------------\n"
									 "Menu de Ordenamiento jugador:\n\n"
									 "1) Jugador por nacionalidad.\n"
									 "2) jugador por edad.\n"
									 "3) jugador por Nombre.\n"
									 "4) volver atras\n"
									 "-------------------------------------\n"
									 "Ingrese una opcion: ",
									 "-------------------------------------\n"
									 "Menu de Ordenamiento jugador:\n\n"
									 "1) Jugador por nacionalidad.\n"
									 "2) jugador por edad.\n"
									 "3) jugador por Nombre.\n"
									 "4) volver atras\n"
									 "-------------------------------------\n"
									 "Opcion invalida, reingrese: ", 1, 5);
	return 0;
}

int menuOrdenar(int* opcion) {

	pedirEntero(opcion, "-------------------------------------\n"
									 "Seleccione lo que desea ordenar:\n\n"
									 "1) Jugadores.\n"
									 "2) Selecciones.\n"
									 "3) volver atras\n"
									 "-------------------------------------\n"
									 "Ingrese una opcion: ",
									 "-------------------------------------\n"
									 "1) Jugadores.\n"
									 "2) Selecciones.\n"
									 "3) volver atras\n"
									 "-------------------------------------\n"
									 "Opcion invalida, reingrese: ", 1, 5);
	return 0;
}
int menuCriterio(int* opcion)
{

	pedirEntero(opcion,"\n >>>>----------------► Criterio  \n"
							"0. Listado ascendente.\n"
							"1. Listado descendente.\n"
							"-------------------------------------\n"
							"Ingrese una opcion: ",
							"-------------------------------------\n"
							"0. Listado ascendente.\n"
							"1. Listado descendente.\n"
							"-------------------------------------\n"
							"Opcion invalida, reingrese: ", 0, 1);


	return 0;
}


int menuConvocados(int* opcion)
{

	pedirEntero(opcion,		"Menu Convocados:\n"
							"1) Convocar:\n"
							"2) Quitar de la Seleccion:\n"
							"3) Salir\n"
							"-------------------------------------\n"
							"Ingrese una opcion: ",
							"-------------------------------------\n"
							"Menu Convocados:\n"
							"1) Convocar:\n"
							"2) Quitar de la Seleccion:\n"
							"3) Salir\n"
							"-------------------------------------\n"
							"Opcion invalida, reingrese: ", 1, 3);


	return 0;
}
