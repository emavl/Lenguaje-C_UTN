/*
 ============================================================================
 Name        : Array_cargaAleatoria.c
 Author      : Emanuel vidal division 1K
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 1000
int main(void) {
	setbuf(stdout,NULL);

	int edad[TAM], i, leg[TAM];
	float sueldo[TAM];
	char seguir;
	int estado[TAM];

	for (i = 0; i < TAM; ++i) {
			estado[i] = 0;
	}
//      hasta acá es una carga secuencial, validando si hay
//         algun dato guardado en la posicion de memoria
	for (i = 0; i < TAM; ++i) {
		if( estado[1] == 0){
			printf("Ingrese Legajo");
			scanf("%d",&leg[i]);
			printf("Ingrese Edad");
			scanf("%d",&edad[i]);
			printf("Ingrese el sueldo");
			scanf("%d",&sueldo[i]);
			estado[i] = 1;
			break;
		}
	}

	for (i = 0; i < TAM; ++i) {
		if( estado[1] == 0){
			printf("Ingrese Legajo");
			scanf("%d",&leg[i]);
			printf("Ingrese Edad");
			scanf("%d",&edad[i]);
			printf("Ingrese el sueldo");
			scanf("%d",&sueldo[i]);
			estado[i] = 1;

			printf("Cargar otro dato [s|n]");
			scanf("%d",&seguir);
			if(seguir == 'n'){
				break;
			}
		}
	}



	return EXIT_SUCCESS;
}
