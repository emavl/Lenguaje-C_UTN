/*
 * input.c
 *
 *  Created on: 1 oct. 2022
 *      Author: Ema
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int verificarConfirmacion(char* mensaje)
{
	int retorno = -1;
	char respuesta;

	pedirCaracter(&respuesta, mensaje);
	if(respuesta == 's' || respuesta == 'S')
	{
		retorno = 0;
	}
	return retorno;
}

//◄─────────────────  C H A T  ───────────────────────►
int utn_getChar ( char* pResultado, char* mensaje, char* mensajeError, int reintentos)
{
	char aux[256];
	int retorno = 0;
	if(pResultado != NULL)
	{
		while(reintentos > 0)
		{
			reintentos--;
			fflush(stdin);
			printf ( "%s" ,mensaje);
			if(getChar(aux)==1)
			{
				strcpy(pResultado,aux);
				retorno = 1;
				break;
			}
			printf("%s",mensajeError);
		}
		if(reintentos < 1)
		{
			retorno= 0;
		}
	}
	SizeString(pResultado);
	return retorno;
}
int getChar ( char * pResultado)
{
	int retorno = 0;
	char buffer[256];
	if (pResultado != NULL)
	{
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumericaChar(buffer) == 1) {
			strcpy(pResultado, buffer);
			retorno = 1;
		}
	}
	return retorno;

}
int myGets(char *cadena, int longitud) {
	if (cadena != NULL && longitud > 0
			&& fgets(cadena, longitud, stdin) == cadena) {
		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n') {
			cadena[strlen(cadena) - 1] = '\0';
		}
		return 0;
	}
	return -1;
}
int esNumericaChar(char *cadena) {
	int retorno;
	int i = 0;

	if (cadena != NULL && strlen(cadena) > 0) {
		retorno = 1;
		while (cadena[i] != '\0') {
			if (cadena[i] >= '0' && cadena[i] <= '9') {
				retorno = 0;
				break;
			}
			i++;
		}

	} else {
		retorno = 0;
	}
	return retorno;

}
int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max)
{
	int retorno = -1;
	char buffer[256];
	int tam;

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && max > 0)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);
		tam = strlen(buffer);

		while(tam > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%[^\n]", buffer);
			tam = strlen(buffer);
		}

		strcpy(cadena, buffer);
		retorno = 0;
	}

	return retorno;
}
int pedirCaracter(char *caracter, char *mensaje) {
	int retorno = -1;

	if (caracter != NULL && mensaje != NULL) {
		printf("%s", mensaje);
		fflush(stdin);
		*caracter = getchar();
		retorno = 0;
	}

	return retorno;
}
int isChar(char string[]) {
	int isOk = 0;
	int stringTam = strlen(string);

	if (stringTam == 0) {
		isOk = -1;
	} else if (stringTam > 0) {
		for (int i = 0; i < stringTam; i++) {
			if ((isdigit(string[i]) == 1) || (isalpha(string[i]) == 0)) {
				isOk = -1;
				break;
			}
		}
	}

	return isOk;
}
int getString(char input[], int tam)
{
    char auxString[tam];
    int isOk = -1;

    if (input != NULL && tam > 0)
    {
        fflush(stdin);
        fgets(auxString,tam,stdin);
        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= tam)
        {
            strncpy(input, auxString, tam);
            isOk=0;
        }
    }
    return isOk;
}

int SizeString(char string[]) {
	int isOk = -1;
	int i = 0;

	if (string != NULL) {
		strlwr(string);
		string[0] = toupper(string[0]);
		while (string[i] != '\0') {
			if (string[i] == ' ') {
				string[i + 1] = toupper(string[i + 1]);
				isOk = 0;
			}
			i++;
		}
	}
	return isOk;
}
int utn_getString(char input[], char mensaje[], char mensajeError[], int tam,
		int reintentos) {
	int isOk = 1;
	char auxString[tam];

	if (input != NULL && mensaje != NULL && mensajeError != NULL && tam > 0
			&& reintentos >= 0) {
		do {
			printf("%s", mensaje);
			if (!(getString(auxString, tam)) && !(isChar(auxString))) {
				strncpy(input, auxString, tam);
				isOk = 0;
				break;
			} else {
				printf("%s", mensajeError);
				reintentos--;
			}

		} while (reintentos >= 0);
	}
	return isOk;
}
int utn_getCaracter(char *resultado, char *mensaje, char *mensajeError,
		char minimo, char maximo, int reintentos) {
	int retorno = -1;
	char bufferCaracter;

	if (resultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {
		do {
			printf("%s", mensaje);
			fflush(stdin);

			scanf("%c", &bufferCaracter);

			if (bufferCaracter >= minimo && bufferCaracter <= maximo) {
				*resultado = bufferCaracter;
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);
				reintentos--;
			}
		} while (reintentos >= 0);
	}
	return retorno;
}
//------------------------------  N u m e r o s  ------------------------------


int esNumerico(char str[]) {
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] < '0' || str[i] > '9')
			return 0;
		i++;
	}
	return 1;
}

int getStringNumeros(char mensaje[], char input[]) {
	char aux[256];

    printf("%s",mensaje);
    fflush(stdin);
    scanf ("%[^\n]", aux);;
	if (esNumerico(aux)) {
		strcpy(input, aux);
		return 1;
	}
	return 0;
}



int getValidInt(char requestMessage[], char errorMessage[], int lowLimit,
		int hiLimit) {
	char auxStr[256];
	int auxInt;
	while (1) {
		if (!getStringNumeros(requestMessage, auxStr)) {
			printf("%s\n", errorMessage);
			fflush(stdin);
			continue;

		}
		auxInt = atoi(auxStr);
		if (auxInt < lowLimit || auxInt > hiLimit) {
			printf(
					"El numero del debe ser mayor o igual  a %d y menor o igual a %d\n",
					lowLimit, hiLimit);
			continue;

		}
		return auxInt;

	}

}






int isInt(char input[])
{
    int isOk = 0;
    int i = 0;
    int stringTam = strlen(input); //devuelve la longitud de la cadena sin contar el nulo final \0

    for(i=0; i<stringTam ;i++)
    {
    	if(input[i]< '0' || input[i]> '9' )
        {
    		isOk=-1;
            break;
        }
    }
    return isOk;
}

int getInt(int* input)
{
    char auxString[30];
    int retorno = 0;

    if(!(getString(auxString,sizeof(auxString))) && !(isInt(auxString)))
    {
    	*input=atoi(auxString);
    	retorno = 1;
    }
    return retorno;
}

//int utn_getInt(short *input, char mensaje[], char mensajeError[], int min,
//		int max, int reintentos) {
//	int isOk = -1;
//	int auxInt;
//
//	if (mensaje != NULL && mensajeError != NULL
//			&& min <= max&& reintentos >= 0 && input != NULL) {
//		do {
//			reintentos--;
//			printf("%s", mensaje);
//			fflush(stdin);
//			if (!(getInt(&auxInt)) && auxInt >= min && auxInt <= max) {
//				fflush(stdin);
//				*input = auxInt;
//				isOk = 0;
//				break;
//			} else {
//				printf("%s ", mensajeError);
//			}
//		} while (reintentos >= 0);
//	}
//	return isOk;
//}
//-----------------------------------FLOAT-----------------------------------
int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max)
{
	int retorno = -1;
	int numeroIngresado;

	if(entero != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &numeroIngresado);

		while(numeroIngresado < min || numeroIngresado > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%d", &numeroIngresado);
		}

		*entero = numeroIngresado;
		retorno = 0;
	}

	return retorno;
}
int isFloat(char input[])
{
    int isOk = 0;
    int i;
    int stringTam = strlen(input);

    for(i=0; i<stringTam ;i++)
    {
        if((input[i]< '0' || input[i]> '9' ) && (input[i]!='.'))
        {
        	isOk = -1;
            break;
        }
    }

    return isOk;
}

int getFloat(float* input)
{
    char auxString[200];
    int isOk =-1;

    if(!(getString(auxString,200)) && !(isFloat(auxString)))
    {
        *input = atof(auxString); //CONVIERTE A FLOAT LA CADENA
        isOk = 0;
    }

    return isOk;
}

int utn_getFloat(float* input, char mensaje[], char mensajeError[], float min, float max, int reintentos)
{
    int isOk = -1;
    float auxFloat;

    if(input != NULL && mensaje != NULL && mensajeError != NULL && min <= max && reintentos >= 0)
    {
        do
        {
        	printf("%s", mensaje);
        	if(!(getFloat(&auxFloat)) && auxFloat >= min && auxFloat <= max)
        	{
        		*input= auxFloat;
        		isOk = 0;
        		break;
        	}
        	else
        	{
        		printf("%s ",mensajeError);
        		reintentos--;
        	}
        }
        while(reintentos >= 0);
    }
    return isOk;
}
