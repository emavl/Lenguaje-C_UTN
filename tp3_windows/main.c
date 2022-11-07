#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "parser.h"
#include "inputs.h"
#include "outputs.h"

int main()
{
	setbuf(stdout,NULL);
    int opcion = 0;
//    int cantidad;
//    FILE* archivo;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSeleccion = ll_newLinkedList();
    int resultado;

    resultado = ll_isEmpty(listaJugadores);
    printf("resultado %d",resultado);

    do{	ejecutarMenu(&opcion);
    	switch( opcion ){
    		case 1:
    			if ( ll_isEmpty(listaJugadores) == 1 ) {
					controller_cargarJugadoresDesdeTexto("jugadores.csv",
							listaJugadores);
					printf("\nSe cargaron los datos correctamente  \\(^.^)/ .\n");
    			} else {
    				printf("\nHubo un error al abrir el archivo.\n");
    			}
    		break;
    		case 2:// ──────────►  ALTA

    		break;
    		case 3:// ──────────►  MODIFICACION

    		break;
    		case 4:// ──────────►  ALTA

    		break;
    		case 5:// ──────────►  ALTA

    		break;
    		case 6:// ──────────►  ALTA

    		break;
    	}

    }while(opcion == 7);



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

