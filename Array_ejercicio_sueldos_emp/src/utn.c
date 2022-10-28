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
// ================================================
int PedirNumeros (char mensaje[], char mensajeError[], int min, int max)
{
  int numero;
  printf ("%s", mensaje);
  scanf ("%d", &numero);
  while (numero < min || numero > max)
    {
      printf ("%s", mensajeError);
      scanf ("%d", &numero);
    }
  return numero;
}
//=================================================

int getNumber(int *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo)
{
	int buffer;
	int retorno = 0;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo) {

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
/*
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if( esSoloLetras(aux) )
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
*/
// ================================================
/*
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
*/
//______________________________ A r r a y s  __________________________________________
void inicializarArray(int lista[], int tamanio) {
	int i;

	for (i = 0; i < tamanio; i++) {
		lista[i] = 0;
	}
}

void numArray(int lista[], char *mensaje, int tamanio) {
	int i;
	if (mensaje != NULL) {
		for (i = 0; i < tamanio; i++) // el array va siempre acompañado de un for
				{
			printf("%s", mensaje);
			scanf("%d", &lista[i]);
			break;
		}
	}
}

int ordenArray(int* pArray, int limite)
{
	int flagSwap;

	int i;
	int contador = 0;
	int retorno = 0;
	int buffer;

	if (pArray != NULL && limite >= 0)
	{
			do
			{
					flagSwap = 0;
			for (i = 0; i < limite - 1; i++)
					{
					  if (pArray[i] < pArray[i + 1])
						{
								flagSwap= 1;
								buffer = pArray[ i ];
								pArray[ i ] = pArray[ i+1];
								pArray[i+1] = buffer;
						}
						contador++;
					}
			}while( flagSwap);
			retorno=contador;
	}

	return retorno;
}
//------------------------------------------------------------------------------
void printArray(int array[],int size)
{
	int i;
	for ( i=0; i< size; i++)
	{
		printf ("%d", array[i]);
	}
}

int printpArray(int* pArray, int limite)
{
	int retorno= -1;
	int i;
	if (pArray != NULL && limite >=0 )
	{
		retorno = 0;
		for(i=0; i<limite;i++)
		{
			printf( "[debug] indice : %d - valor : %d\n", i , pArray[i]);
		}
	}
	return retorno;
}
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
// =============- C a l c u l o s  -======================

int sumaEnteros(int lista[],int tamanio)
{

	int i;
	int acumulador = 0;
// valor de comienzo; condicion; accion
	for(i=0;i<tamanio;i++)
	{
		acumulador+= lista[i];
	}

	return acumulador;
}

int promedio(int a, int b)
{

	int promedio;

	promedio = a/b;

	return promedio;
}

float promedioArray ( int Array[], int size )
{
	int i;
	float resultado;
	int  suma=0;

	for ( i=0; i < size ; i++)
	{
		suma += Array[i];
	}
	resultado =((float) suma ) / size;

	return resultado;
}
// con punteros
float promediopArray (int* pResultado, int Array[], int size )
{
	int i;
	float resultado;
	int  suma=0;
	if ( size>0 && pResultado != NULL && Array != NULL)
	{

		for ( i=0; i < size ; i++)
		{
			suma += Array[i];
		}
	}
	*pResultado =((float) suma ) / size;

	return resultado;
}












