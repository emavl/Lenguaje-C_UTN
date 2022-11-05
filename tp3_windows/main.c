#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "parser.h"

int main()
{
	setbuf(stdout,NULL);
//    int option = 0;
//    int cantidad;
//    FILE* archivo;
    LinkedList* listaJugadores = ll_newLinkedList();

    controller_cargarJugadoresDesdeTexto("jugadores.csv", listaJugadores);
    controller_listarJugadores(listaJugadores);
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

