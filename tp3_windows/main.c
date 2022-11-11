#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "parser.h"
#include "inputs.h"
#include "outputs.h"

/****************************************************
    Menu:
	 1. Cargar archivos
	 2. Alta jugador
	 3. Modificacion de jugador
	 4. Baja de jugador
	 5. Listados
	 	 Menu:
	 	 a) Todos los jugadores
	 	 b) Todas las selecciones
	 	 c) Jugadores convocados( unicamente )
	 6. Convocar Jugadores
		Menu:
		a) Convocar:
		b) Quitar de la Seleccion:
	 7. Ordenar y listar.
	 	 Menu:
	 	 1)Jug por nacionalidad.
	 	 2)seleccion por confederacion.
	 	 3)jugador por edad.
	 	 4)jugador por Nombre.
	 8. Generar archivo Binario.
	 9. Cargar archivo binario.
	10. Guardar archivos .CSV
	11. Salir.
*****************************************************/

int main()
{
	setbuf(stdout,NULL);
    int opcion = 0;
//    int cantidad;
//    FILE* archivo;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSeleccion = ll_newLinkedList();

    do{	ejecutarMenu(&opcion);
    	switch( opcion ){
    		case 1:
    			if ( ll_isEmpty(listaJugadores) == 1 ) {
					controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores );
					controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSeleccion );
					printf("\n\nSe cargaron los datos correctamente  \\(^.^)/ .\n");
					limpiarConsola();
    			} else {
    				printf("\nHubo un error al abrir el archivo.\n");
    			}
    			system("pause");

    		break;
    		case 2:// ──────────►  ALTA
    			controller_agregarJugador(listaJugadores);
    		break;
    		case 3:// ──────────►  Modificacion de jugador

    		break;
    		case 4:// ──────────►  ALTA

    		break;
    		case 5:// ──────────►  ALTA
    			controller_listar(listaSeleccion, listaJugadores);
    		break;
    		case 6:// ──────────►  ALTA

    		break;
    		case 7:// ──────────►  ALTA
    			controller_ordenarJugadores(listaJugadores);
    		break;
    		case 8:// ──────────►  ALTA

    		break;
    		case 9:// ──────────►  ALTA

    		break;
    		case 10:// ──────────►  ALTA

    		break;
    		case 11:// ──────────►  ALTA
    			printf("\nSaliendo . . ..\n");
    			system("pause");
    		break;
    	}

    }while(opcion != 11);
//
//	controller_listarJugadores(listaJugadores);
//	controller_listarSelecciones(listaSeleccion);

    //controller_listarJugadores(listaJugadores);
//    cantidad = ll_len(listaJugadores);
//    puts("funciona ok");
//
//    printf(" cantidad de jugadores: %d", cantidad);
//
//    fclose(archivo);
//
//    do{
//        switch(option)
//        {
//            case 1:
//            	controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
//
//                break;
//        }
//    }while(option != 10);

    return 0;
}

