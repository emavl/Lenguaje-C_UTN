
#include <stdio.h>
#include <stdlib.h>

int dividir(int operador1, float operador2, float*  direc_de_variable_de_Retorno){

	float resul;
	int huboError;
	if (operador2 != 0) {
		resul = operador1 / operador2;
		(*direc_de_variable_de_Retorno) = resul;
		huboError = 0;
	} else {
		huboError = 1;
	}
	return huboError;
}


