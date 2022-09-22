/*
 * input.c
 *
 *  Created on: 16 sep. 2022
 *      Author: Ema
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//  ___________________________ S o l i c i t u d     a l    U s u a r i o ____________________

float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}
// ================================================

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}
// ================================================

char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

//=================================================

int getNumber(int *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo)
{
	int buffer;
	int retorno = 0;
	if ((pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo) && ((*pResultado < 0) || (*pResultado > 5))
			&& ((*pResultado < '0') || (*pResultado > '9'))) {

			printf("%s", mensaje);
			scanf("%d", &buffer);
			if ((buffer > minimo) && (buffer <= maximo)) {
				*pResultado = buffer;
				retorno = 1;
			} else {
				printf("%s", mensajeError);
			}

	}
	return retorno;
}
// ================================================
int getCharacter(char *pResultado, char *mensaje, char *mensajeError,
		char minimo, char maximo)
{
	int buffer;
	int retorno = 0;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo)
	{
			printf("%s", mensaje);
			scanf("%d", &buffer);
			if ((buffer > minimo) && (buffer <= maximo))
			{
				*pResultado = buffer;
				retorno = 1;
			} else {
				printf("%s", mensajeError);
			}
	}
	return retorno;
}
// ================================================
char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}
// ================================================



// ____________________________ V a l i d a c i o n e s _____________________________

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}
// ================================================

int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}
// ================================================

int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}
// ================================================

int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}











