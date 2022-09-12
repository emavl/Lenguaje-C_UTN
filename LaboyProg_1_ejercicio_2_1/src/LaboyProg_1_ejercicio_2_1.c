/*
 ============================================================================
 Emanuel vidal division 1K - ejercicio 1 - 3

 Ejercicio 2-1: Ingresar 5 números enteros calcular y mostrar el promedio de los números. Probar la
 aplicación con distintos valores.

 Ejemplo 1: 3 - 5 - 7 - 9 - 1
 Ejemplo 2: 2 - 1 - 8 -1 - 2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

	int i = 1;
	int numeros = 0;
	int numeroAux = 0;
	int promedio;

	do {
		printf("ingrese el numero N° %d: ", i);
		fflush(stdin);
		scanf("%d",&numeros);

		numeroAux += numeros;
		i++;
	} while (i < 6);

	promedio = numeroAux/5;
	printf(" El Promedio de los numeros es %d",promedio);

	return EXIT_SUCCESS;
}
