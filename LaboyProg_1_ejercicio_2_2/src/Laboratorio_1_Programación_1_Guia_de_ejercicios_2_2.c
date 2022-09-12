/*
 ============================================================================
Name: Emanuel vidal division 1K - ejercicio 2-2

Ingresar 10 números enteros, distintos de cero. Mostrar:
a. Cantidad de pares e impares.
b. El menor número ingresado.
c. De los pares el mayor número ingresado.
d. Suma de los positivos.
e. Producto de los negativos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int main(void) {
	setbuf(stdout,NULL);

	int i = 1;
	int numero = 0;
	int numeroAux = 0;
	int numPares = 0;
	int numImpares = 0;
	int menorNum = 0;
	int mayorPar = 0;
	int productoNeg = 0;

	do {
		printf("ingrese el numero N° %d: ", i);
		fflush(stdin);
		scanf("%d",&numero);
		while ( numero == 0 ){
			fflush(stdin);
			printf("\nError !!! Debe ingresar un numero distinto de 0: ");
			scanf("%d", &numero);
		}
		if (i == 1) {
			menorNum = numero;
			productoNeg = numero;
		}
		if (numero < menorNum) {
			menorNum = numero;
		}
		if (numero % 2 == 0) {
			numPares++; // ------- C a n t i d a d   d e    p a r e s.
			if (numero > mayorPar) {
				mayorPar = numero; //------- p a r   e l   m a y o r.
			}
		} else {
			numImpares++; // ------- C a n t i d a d   d e   i m p a r e s.
		}
		if (numero > 0){
			numeroAux += numero; //---------S u m a    d e   l o s   p o s i t i v o s.
		} else {
			productoNeg *= numero; //-------P r o d u c t o   d e   l o s    n e g a t i v o s.
		}
		i++;
		} while (i < 11);

	printf(" \na. Cantidad de pares %d e impares %d.",numPares,numImpares);
	printf(" \nb. El menor numero ingresado es:  %d",menorNum);
	printf(" \nc. El mayor numero par ingresado es:  %d",mayorPar);
	printf(" \nd. Suma de los numeros positivos es %d",numeroAux);
	printf(" \ne. Producto de los negativos es %d",productoNeg);

	return EXIT_SUCCESS;
}
