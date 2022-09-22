/*
 ============================================================================
				M o d u l o       d  e       p u e b a
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define size 10

/*
 *firma o protodipo es llamada la funcion.

TipoDeDato nombreFuncion (tipo parametroUno, tipo parametroDos);

 */
int ejecutarMenu(int *numero, float *hospedaje, float *comida,
		float *transporte, int *arqueros, int *defensores, int *mediocampistas,
		int *delanteros);
int getNumeros(float *pNumero, char *mensaje, char *mensajeError);
char subMenu(char *letra);
void cargaCostos(float *hospedaje, float *comida, float *transporte);
//int ejecutarMenu2(int numero);
int main(void) {
	setbuf(stdout,NULL);

	int opcion = 0;

//	int subMenu;
	float costHospedaje = 0.00;
	float costComida = 0.00;
	float costTransporte = 0.00;
	int arqueros = 0;
	int defensores = 0;
	int medioCampistas = 0;
	int delanteros = 0;

	 do{
		 ejecutarMenu(&opcion, &costHospedaje, &costComida, &costTransporte, &arqueros, &defensores, &medioCampistas, &delanteros);

		switch ( opcion ) {
			case 1:
				cargaCostos(&costHospedaje, &costComida, &costTransporte);

				break;
			case 2:

				break;
			case 3:

				break;
			case 4:

				break;
			case 5:

				break;

			default:
				printf("\nLa opcion no es valida\n");

			}

		} while (opcion != 5);




	return EXIT_SUCCESS;
}

int ejecutarMenu(int *numero, float *hospedaje, float *comida,
		float *transporte, int *arqueros, int *defensores, int *medioCampistas,
		int *delanteros) {


	for (int i = 0; i < 63; ++i)
		printf("—");
	printf(
			"\n\n||             Menu principal  - Bienvenidos ®                ||\n ");
	for (int i = 0; i < 63; ++i)
		printf("—");

	printf("\n\n■        ■ ■    ■ ■    ■ ■    ■ ■    ■ ■    ■ ■    ■ ■        ■\n");

	printf("\n  ◄------------- Complete los siguientes datos por favor -------------► \n\n");
	printf("    ___________________________________\n");
	printf("1)- Ingreso de costos de Mantenimiento\n");
	printf("    ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
		printf("\na) Costos de Hospedaje ———► $%.2f",*hospedaje);
		printf("\nb) Costo de comida ———————► $%.2f",*comida);
		printf("\nc) Costo de Transporte ———► $%.2f\n", *transporte);
	printf("\n    ___________________");
	printf("\n2)- carga de jugadores \n");
	printf("    ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
		printf("\nf) Arqueros ——————————————► %d",*arqueros);
		printf("\ng) Defensores ————————————► %d",*defensores);
		printf("\nh) Mediocampistas ————————► %d",*medioCampistas);
		printf("\ni) Delanteros ————————————► %d\n",*delanteros);
	printf("\n    ___________________________");
	printf("\n3)- Realizar todos los calculos \n"
			"    ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n"
			"   _____________________________"
			"\n4- Informar todos los resultados\n"
			"   ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n"
			"\n5- salir -----► ");
	scanf("%d", numero);

	return* numero;

}

char subMenu(char *letra){


	printf("\n\n    ___________________________________\n");
	printf("1)-         Ingrese una opcion \n");
	printf("    ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");

	printf("\na) Costos de Hospedaje ");
	printf("\nb) Costo de comida ");
	printf("\nc) Costo de Transporte ");
	printf("\nd) Volver al menú anterior ");
	fflush(stdin);
	scanf("%c", letra);

	return *letra;
}

int getNumeros(float *pNumero, char *mensaje, char *mensajeError) {



	if ((pNumero != NULL && mensaje != NULL && mensajeError != NULL)) {

		printf(mensaje);
		scanf("%f", pNumero);
		while (*pNumero < 0) {
			printf(mensajeError);
			scanf("%f", pNumero);
		}

	}

	return 0;
}


void cargaCostos(float *hospedaje, float *comida, float *transporte){


	char letra = ' ';
	float auxFloat = 0;

	do {
		subMenu(&letra);

		switch(letra) {
			case 'a':
				getNumeros(&auxFloat,
						"\nIngrese los costos de hospedaje por favor ———► ",
						"Error !!!, ingrese un dato valido por favor");
						*hospedaje += auxFloat;

				break;
			case 'b':
				getNumeros(&auxFloat,
						"\nIngrese los costos de comida por favor ———► ",
						"\nError !!!, ingrese un dato valido por favor");
						*comida += auxFloat;
				break;
			case 'c':
				getNumeros(&auxFloat,
						"\nIngrese los costos de Transporte por favor ———► ",
						"\nError !!!, ingrese un dato valido por favor");
						*transporte += auxFloat;
				break;
			case 'd':
				 break;
				default: printf("\nLa opcion no es valida\n");
			}

	} while (letra != 'd');


}

