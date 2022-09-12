/*
 ============================================================================
  Emanuel vidal - Division 1K
Ejercicio 1-3: ingresar 3 numeros y mostrar el numero del medio, solo si existe. En caso de que no
exista también informarlo.
Ejemplo:
1 5 3 el 3 es del medio
5 1 5 no hay numero del medio
3 5 1 el 3 es del medio
3 1 5 el 3 es del medio
5 3 1 el 3 es del medio
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

	int num1;
	int num2;
	int num3;

	  printf ("\nIngrese un numero por favor: ");
	  scanf ("%d", &num1);

	  printf ("\nIngrese otro numero por favor: ");
	  scanf ("%d", &num2);

	  printf ("\nIngrese otro numero por favor: ");
	  scanf ("%d", &num3);


	    if (num3 == num2 || num2 == num1 || num3 == num1) {
				printf("\nNo hay numero del medio");
			} else {
				if (num1 > num2) {
					if (num1 < num3) {
						printf("\nNumero %d es el del medio", num1);
					} else if (num3 < num2) {
						printf("\nNumero %d es el del medio", num2);
					} else {
						printf("\nNumero %d es el del medio", num3);
						}
			} else {
				if (num2 < num3) {
					printf("\nNumero %d es el del medio", num2);
				} else if (num3 < num1) {
					printf("\nNumero %d es el del medio", num1);
				} else {
					printf("\nNumero %d es el del medio", num3);
				}

		}
	}

	return EXIT_SUCCESS;
}
