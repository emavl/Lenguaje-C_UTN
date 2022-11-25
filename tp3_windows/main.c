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
	 1. Cargar archivos  ──────► completo
	 2. Alta jugador  ──────► completo
	 3. Modificacion de jugador ──────► completo
	 4. Baja de jugador ──────► completo
	 5. Listados ──────► completo
	 6. Convocar Jugadores  ──────► completo
	 7. Ordenar y listar. ──────► completo
	 8. Generar archivo Binario. ──────► completo
	 9. Cargar archivo binario. ──────► completo
	10. Guardar archivos .CSV. ──────► completo
	11. Salir.
*****************************************************/

int main()
{
	setbuf(stdout,NULL);
    int opcion = 0, id = 371;
    FILE* archivo = NULL;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSeleccion = ll_newLinkedList();

    do{	ejecutarMenu(&opcion);
    	switch( opcion ){
    		case 1:
    			if ( ll_isEmpty(listaJugadores) == 1 ) {
    				archivo = fopen("idJugador.txt", "w");
    				fprintf(archivo,"%d",id);
    				fclose(archivo);

					if ( (controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores ) == 1) &&
					(controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSeleccion ) == 1) )
					{
						printf("\n\nSe cargaron los datos correctamente  \\(^.^)/ .\n");
					}

					limpiarConsola();
    			} else {
    				printf("\nHubo un error al abrir el archivo.\n");
    			}
    			system("pause");

    		break;
    		case 2:// ──────────►  Alta
    			if ( ll_isEmpty(listaJugadores) == 1 ){
    				printf("\nDebe cargar los archivos primero\n");
    				system("pause");
    			} else {
    				if ( controller_agregarJugador(listaJugadores) == 1){
    				printf("\nSe ha dado de alta correctamente");
    				}
    			}
    		break;
    		case 3:// ──────────►  Modificacion de jugador
    			if ( ll_isEmpty(listaJugadores) == 1 ){
    				printf("\nDebe cargar los archivos primero\n");
    				system("pause");
    			} else {
    				if( controller_editarJugador(listaJugadores) == 1){
    					printf("\nSe ha modificado con exito\n\n");
    				}
    			}
    		break;
    		case 4:// ──────────►  Baja de jugador
    			if ( ll_isEmpty(listaJugadores) == 1 ){
					printf("\nDebe cargar los archivos primero\n");
					system("pause");
				} else {
					if ( controller_removerJugador(listaJugadores) == 1) {
						printf("\nBaja realizada con exito\n");
					}
				}
    		break;
    		case 5:// ──────────►  Listados
    			if ( ll_isEmpty(listaJugadores) == 1 ){
					printf("\nDebe cargar los archivos primero\n");
					system("pause");
				} else {
    			controller_listar(listaSeleccion, listaJugadores);
				}
    		break;
    		case 6:// ──────────►  Convocar Jugadores
    			if ( ll_isEmpty(listaJugadores) == 1 ){
					printf("\nDebe cargar los archivos primero\n");
					system("pause");
				} else {
					if ( controller_convocados(listaJugadores, listaSeleccion) == 1){
						printf("\nConvocados realizado con exito\n");
					}
				}
    		break;
    		case 7:// ──────────►  Ordenar y listar.
    			if ( ll_isEmpty(listaJugadores) == 1 ){
					printf("\nDebe cargar los archivos primero\n");
					system("pause");
				} else {
    			controller_Ordenamiento(listaJugadores, listaSeleccion);
				}
    		break;
    		case 8:// ──────────►  Generar archivo Binario.
    			if ( ll_isEmpty(listaJugadores) == 1 ){
					printf("\nDebe cargar los archivos primero\n");
					system("pause");
				} else {
					controller_guardarJugadoresModoBinario("jugadoresBin.b", listaJugadores);
				}
    		break;
    		case 9:// ──────────►  Cargar archivo binario.
    			if ( ll_isEmpty(listaJugadores) == 1 ){
					printf("\nDebe cargar los archivos primero\n");
					system("pause");
				} else {
					controller_cargarArchivoBinario("jugadoresBin.b", listaJugadores);
				}
    		break;
    		case 10:// ──────────►  Guardar archivos .CSV
    			if ( ll_isEmpty(listaJugadores) == 1){
					printf("\nDebe cargar los archivos primero\n");
					system("pause");
				} else {
					controller_guardarSeleccionesModoTexto("selecciones.csv", listaSeleccion);
					controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores);
				}
    		break;
    		case 11:// ──────────►  Salir.
    			printf("\nSaliendo . . .\n");
    			system("pause");
    		break;
    	}

    }while(opcion != 11);


    return 0;
}

