/*
 ============================================================================
 Emanuel vidal division 1K - Funciones_3_2

Crear una función que permita determinar si un número es par o no. La función retorna 1 en caso
afirmativo y 0 en caso contrario. Probar en el main.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int pedirNumero(int num);

int main(void) {
	setbuf(stdout,NULL);

	int numero;

	printf("Ingrese un numero: ");
	scanf("%d",&numero);
	if (pedirNumero(numero) == 1){
		printf("El numero es par");
	} else {
		printf("El numero es impar");
	}

	return EXIT_SUCCESS;
}

int pedirNumero(int num) {

	if (num % 2 == 0) {
		return 1;
	} else {
	return 0;
	}

}
