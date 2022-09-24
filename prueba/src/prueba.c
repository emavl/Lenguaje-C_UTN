/*
 ============================================================================
				M o d u l o       d  e       p u e b a
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>



#define size 10

/*
 *firma o protodipo es llamada la funcion.

TipoDeDato nombreFuncion (tipo parametroUno, tipo parametroDos);

 */
int ejecutarMenu(int *numero, float *hospedaje, float *comida,
				float *transporte, int *arqueros, int *defensores,
				int *mediocampistas,int *delanteros);

char subMenu(char *letra);
char subMenu2(char *letra, int *arq, int *def, int *medioC, int *del);
char subMenu3(char *letra);

void cargaCostos(float *hospedaje, float *comida, float *transporte);

int cargaJugadores(int *camiseta, int *arquero, int *defensor,
				   int *mediocampista, int *delantero, int *AFC,
				   int *CAF, int *CONCACAF,	int *CONMEBOL, int *UEFA, int *OFC);

int getNumeros(float *pNumero, char *mensaje, char *mensajeError);

int getRangNum(int *pNumero, char *mensaje, char *mensajeError, int minimo,
		int maximo);


int main(void) {

	int opcion = 0;

	float costHospedaje = 0.00;
	float costComida = 0.00;
	float costTransporte = 0.00;
	int camiseta = 0;
	int arqueros = 0;
	int defensores = 0;
	int medioCampistas = 0;
	int delanteros = 0;
	int AFC = 0;
	int CAF = 0;
	int CONCACAF = 0;
	int	CONMEBOL = 0;
	int UEFA = 0;
	int OFC = 0;

	 do{

		switch (ejecutarMenu(&opcion, &costHospedaje, &costComida, &costTransporte, &arqueros, &defensores, &medioCampistas, &delanteros)) {
			case 1:
				cargaCostos(&costHospedaje, &costComida, &costTransporte);
				break;
			case 2:
				cargaJugadores(&camiseta, &arqueros, &defensores, &medioCampistas, &delanteros, &AFC, &CAF, &CONCACAF, &CONMEBOL, &UEFA, &OFC);
				break;
			case 3:

				break;
			case 4:

				break;
			case 5:
					printf("Gracias por utilizar nuestros servicios ♥");
				break;

			default:
				printf("\nLa opcion no es valida\n");

			}

		} while (opcion != 5);



	setbuf(stdout,NULL);

	return EXIT_SUCCESS;
}

int ejecutarMenu(int *numero, float *hospedaje, float *comida,
		float *transporte, int *arqueros, int *defensores, int *medioCampistas,
		int *delanteros) {


	for (int i = 0; i < 63; ++i)
		printf("—");
	printf(
			"\n\n||             (Menu principal) - Bienvenidos a Mundial Qatar 2022®                ||\n ");
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


	printf("\n\n    ____________________________________\n");
	printf("1)-    Ingrese una opcion - por favor ♥ \n");
	printf("    ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");

	printf("\na) Costos de Hospedaje ");
	printf("\nb) Costo de comida ");
	printf("\nc) Costo de Transporte ");
	printf("\nd) Volver al menú anterior ");
	fflush(stdin);
	scanf("%c", letra);

	return *letra;
}

char subMenu2(char *letra, int *arq, int *def, int *medioC, int *del){


	printf("\n\n    _____________________________________\n");
	printf("1)-       Ingrese una opcion del jugador   \n");
	printf("    ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");

	printf("\na) N° de Camiseta");
	printf("\nb) Arquero ———————————► %d/2", *arq);
	printf("\nc) Defensores ————————► %d/8", *def);
	printf("\nd) Medio Campistas ———► %d/8", *medioC);
	printf("\ne) Delanteros ————————► %d/4", *del);
	printf("\nf) Confederacion ");
	fflush(stdin);
	scanf("%c", letra);

	return *letra;
}

char subMenu3(char *letra){


	printf("\n\n    _____________________________________\n");
	printf("1)-         Ingrese su Confederacion        \n");
	printf("    ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");

	printf("\na) AFC - Asia ");
	printf("\nb) CAF - Africa ");
	printf("\nc) CONCACAF - Zona Norte ");
	printf("\nd) CONMEBOL - Sud America ");
	printf("\ne) UEFA - Europa ");
	printf("\nf) OFC - Oceania ");
	printf("\ng) Menú anterior ");
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

int getRangNum(int *pNumero, char *mensaje, char *mensajeError,
		int minimo, int maximo) {

		int retorno = 0;

		printf(mensaje);
		scanf("%d", pNumero);
		while((*pNumero < minimo) || (*pNumero > maximo)){
			printf(mensajeError);
			scanf("%d", pNumero);
			retorno = 1;
		}


	return retorno;
}



void cargaCostos(float *hospedaje, float *comida, float *transporte){

	char letra = ' ';
	float auxFloat = 0;

	do {
		switch (subMenu(&letra)) {
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
		default:
			printf("\nLa opcion no es valida\n");
		}

	} while (letra != 'd');

}

int cargaJugadores(int *camiseta, int *arquero, int *defensor,
		int *mediocampista, int *delantero, int *AFC, int *CAF, int *CONCACAF, int *CONMEBOL, int *UEFA, int *OFC) {

	int retorno = 0;
	char letra = ' ';
	int auxJugador = 0, conf = 0, accArq = 0, accDef = 0, accMedio = 0, accDel = 0;
	do {
		do{
			switch (subMenu2(&letra, &accArq, &accDef, &accMedio, &accDel)) {
				case 'a':
					getRangNum(&auxJugador, "\n\nIngrese Camiseta ———►",
							"\nError !! - ingrese un valor correcto ", 0, 100);
						*camiseta += auxJugador;
					break;
				case 'b':
					if ( accArq < 2){
					getRangNum(&auxJugador, "\n\nIngrese Arquero ———►",
							"\nError !! - ingrese un valor correcto ", 0, 2);
						 accArq += auxJugador;
						*arquero += auxJugador;
					} else {
						printf("\n\nSe completo el cupo de arqueros !!!!!");
					}
					break;
				case 'c':
					if (accDef < 8) {
						getRangNum(&auxJugador, "\n\nIngrese Defensor ———►",
								"\nError !! - ingrese un valor correcto", 0, 8);
						accDef += auxJugador;
						*defensor += auxJugador;
					} else {
						printf("\n\nSe completo el cupo de Defensores !!!!!");
					}
					break;
				case 'd':
					if (accMedio < 8) {
					getRangNum(&auxJugador, "\n\nIngrese Mediocampista ———►",
							"\nError !! - ingrese un valor correcto", 0, 8);
						accMedio += auxJugador;
						*mediocampista += auxJugador;
					} else {
						printf("\n\nSe completo el cupo de Mediocampistas !!!!!");
					}
					break;
				case 'e':
					if (accDel < 4) {
						getRangNum(&auxJugador, "\n\nIngrese Delantero ———►",
								"\nError !! - ingrese un valor correcto ", 0, 4);
						accDel += auxJugador;
						*delantero += auxJugador;
					} else {
						printf("\n\nSe completo el cupo de Delanteros !!!!!");
					}
					break;
				case 'f':
					break;
				default:
					printf("\nLa opcion no es valida\n");
				}
		}while( letra != 'f');

	conf = *arquero + *defensor + *mediocampista + *delantero;

		switch (subMenu3(&letra)) {
		case 'a':
			*AFC = conf;
			accArq = 0, accDef = 0, accMedio = 0, accDel = 0;
			break;
		case 'b':
			*CAF = conf;
			accArq = 0, accDef = 0, accMedio = 0, accDel = 0;
			break;
		case 'c':
			*CONCACAF = conf;
			accArq = 0, accDef = 0, accMedio = 0, accDel = 0;
			break;
		case 'd':
			*CONMEBOL = conf;
			accArq = 0, accDef = 0, accMedio = 0, accDel = 0;
			break;
		case 'e':
			*UEFA = conf;
			accArq = 0, accDef = 0, accMedio = 0, accDel = 0;
			break;
		case 'f':
			*OFC = conf;
			accArq = 0, accDef = 0, accMedio = 0, accDel = 0;
			break;
		default:
			printf("\nLa opcion no es valida\n");
		}
		printf("confederaciones AFC %d CAF %d CONCACAF %d CONMEBOL %d UEFA %d OFC %d", *AFC, *CAF, *CONCACAF, *CONMEBOL, *UEFA, *OFC);
	} while (letra != 'g');




	return retorno;
}
