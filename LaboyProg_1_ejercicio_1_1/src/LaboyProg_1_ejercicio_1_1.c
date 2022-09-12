/*
 ============================================================================
 Name        : GuiaSabados_ejercicio_1_1.c
 Author      : Emanuel vidal division 1K

 Ejercicio 1-1: Ingresar dos números enteros, sumarlos y mostrar el resultado.

  Ejemplo:
Si ingresamos 3 y 2 el programa mostrará: “La suma entre 3 y 2 da como resultado 5”
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	setbuf(stdout, NULL);

    int n1;
    int n2;
    int n3;
    int resultado;

    printf("Introduzca el primer numero (entero): ");
    fflush(stdin);
    scanf("%d", &n1);
    printf("Introduzca el segundo numero (entero): ");
    fflush(stdin);
    scanf("%d", &n2);

    resultado = n1 + n2 ;
    printf("La suma es:  %d", resultado);

    return 0;
}

