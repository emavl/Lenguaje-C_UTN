/*
 ============================================================================
 Name        : Determinar_Minimo_y_Maximo.c
 Author      : 
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);
	int maximo;
	int minimo;
	int buffer;
	int i;

// ______Cuando la condicion es 1 itera de forma infinita____
	for(i=0;1;i++) // 3 partes le damos valor ;condicion; lo que va a realizar en este caso incrementar la variable i en 1
	{

		printf("Ingrese un Numero %d:\n",i+1);
		scanf("%d",&buffer);

		if (i == 0) {
			maximo = buffer;
			minimo = buffer;
		} else {
			if (buffer > maximo) {
				maximo = buffer;
			}
			if (buffer < minimo) {
				minimo = buffer;
			}
			if (buffer == 9) {
				printf("listo\n");
				break;
			}
		}

	}
	printf("\nEl numero minimo es: %d y el numero maximo es %d\n",minimo,maximo);
	printf("Fin del programa");


	return 0;
}
