#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// ================ S t a t i c    F u n c t i o n =================

static int esNumerica(char *cadena, int limite);
static int getInt(int *pResultado);
static int esFlotante(char *cadena, int limite);
static int getNombre(char* pResultado, int longitud);
static int getFloat(float *pResultado);
static int getNombre(char* pResultado, int longitud);
static int getString(char *cadena, int longitud);
static int esNombre(char *cadena, int limite);


/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 * \param *cadena Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 */
int myGets(char *cadena, int longitud) {

	int retorno = -1;
	char bufferString[256];

	if(cadena != NULL && longitud > 0)	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString),stdin)!=NULL)	{

			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] =='\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1]='\0';
			}

			if(strnlen(bufferString,sizeof(bufferString))<= longitud )
			{
				strncpy(cadena, bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

// ================================================

/**
 * \brief Obtiene un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getInt(int *pResultado) {
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL && myGets(buffer, sizeof(buffer)) == 0
			&& esNumerica(buffer, sizeof(buffer))) {

		*pResultado = atoi(buffer);
		retorno = 0;
	}

	return retorno;
}

// ================================================

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 */
static int esNumerica(char *cadena, int limite) {
	int i;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0) {
		for (i = 0; i < limite && cadena[i] != '\0'; i++) {
			if (i == 0 && (cadena[i] == '+' || cadena[i] == '-')) {
				continue;
			}
			if (cadena[i] > '9' || cadena[i] < '0') {
				retorno = 0;
				break;
			}

		}
	}
	return retorno;
}

// ================================================

static int getFloat(float *pResultado) {
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL && myGets(buffer, sizeof(buffer)) == 0
			&& esFlotante(buffer, sizeof(buffer))) {
		*pResultado = atof(buffer);
		retorno = 0;
	}

	return retorno;
}

// ================================================

 //INICIALIZAR ARRAY FLOAT
float inicializalArrayFloat(float *arrayFloat, int tam, float inicializar) {

	float retorno = -1;
	if (arrayFloat != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			arrayFloat[i] = inicializar;

		}
	}

	return retorno;
}

// ================================================

 static int esFlotante(char *cadena, int limite) {
	int i;
	int retorno = 1;
	int contadorPuntos=0;

	for (i = 0; i < limite && cadena[i] != '\0'; i++) {
		if (cadena[i] < '0' || cadena[i] > '9') {
			if (cadena[i] == '.') {
				contadorPuntos++;
				if (contadorPuntos > 1) {
					retorno = 0;
					break;
				}
			} else {
				if (i == 0 && (cadena[i] != '+' && cadena[i] != '-')) {
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
 }

 // ================================================

static int getNombre(char* pResultado, int longitud)
{
	int retorno=-1;
	char bufferString[4096];

	if(pResultado != NULL)
	{
		if(getString(bufferString,sizeof(bufferString))== 0 &&
			esNombre(bufferString,sizeof(bufferString)) &&
			strnlen(bufferString,sizeof(bufferString))< longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno=0;
		}
	}

	return retorno;
}

// ================================================

static int getString(char *cadena, int longitud)
{

	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString),stdin)
				)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] =='\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1]='\0';
			}

			if(strnlen(bufferString,sizeof(bufferString))<= longitud )
			{
				strncpy(cadena, bufferString,longitud);
				retorno=0;
			}
		}
	}


	return retorno;
}

// ================================================

static int esNombre(char *cadena, int limite)
{
	int i;
	int retorno = 1;
	if (cadena != NULL && limite > 0)
	{
		for (i=0;i<limite && cadena[i] != '\0';i++)
		{

			if((cadena[i]<'a'|| cadena[i]>'z') && (cadena [i]<'A' || cadena[i]>'Z') && cadena[i] != ' ')
			{
				retorno=0;
				break;
			}

		}
	}
	return retorno;
}

//================ F u n c i o n e s  -  UTN ====================

int utn_getNombre(char *pResultado, char *mensaje, char *mensajeError, int longitud, int reintentos) {
	int retorno = -1;
	char bufferString[4096];

	while (reintentos >= 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getNombre(bufferString, sizeof(bufferString)) == 0) {

			strncpy(pResultado, bufferString, longitud);
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
	}

	return retorno;
}

// ================================================

int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError,float minimo, float maximo, int reintentos) {
	float bufferFloat;
	int retorno = -1;
	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getFloat(&bufferFloat) == 0 && bufferFloat >= minimo
				&& bufferFloat <= maximo) {
			*pResultado = bufferFloat;
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
	}
	return retorno;

}

// ================================================

// FUNCION DE ORDENAMIENTO DE BURBUJEO

int utn_ordenarArray(int *array, int limite) {
	int nuevoLimite;
	int retorno = -1;
	int flagSwap;
	int contador = 0;
	int buffer;
	if (array != NULL && limite >= 0) {
		nuevoLimite = limite - 1;
		do {
			flagSwap = 0;
			for (int i = 0; i < nuevoLimite; i++) {
				contador++;

				if (array[i] < array[i + 1]) {
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i + 1];
					array[i + 1] = buffer;
				}
			}

			nuevoLimite--;

		} while (flagSwap);

		retorno = contador;
	}

	return retorno;
}

// ================================================

// CALCULAR UN PROMEDIO
int utn_promedio(int *resultado, int arrayInt[], int size) {
	int retorno = -1;
	int acumulador = 0;

	if (arrayInt != NULL && resultado != NULL && size > 0) {
		for (int i = 0; i < size; i++) {
			acumulador = arrayInt[i] + acumulador;

		}

		*resultado = ((float) acumulador) / size;

		retorno = 0;
	}
	return retorno;
}

// ================================================

int utn_getInt(int *pResultado, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos) {
	int bufferInt;
	int retorno = -1;
	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0
			&& bufferInt >= minimo
			&& bufferInt <= maximo)
		{
			*pResultado = bufferInt;
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

// ================================================

// ESTA FUNCION SE ENCARGA DE PEDIR UN CARACTER
int utn_getCharacter(char *resultado, char *mensaje, char *mensajeError,
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

// ================================================

// IMPRIMIR UN ARRAY

void utn_imprimirArray(int arrayInt[], int tam) {
	for (int i = 0; i < tam; i++) {
		printf(" %d \n", arrayInt[i]);
	}
}

//  ___________________________ S o l i c i t u d     a l    U s u a r i o ____________________

float getFloat(char mensaje[]){

    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}
// ================================================

int getInt(char mensaje[]){

    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

// ================================================

char getChar(char mensaje[]){

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

// ================================================

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

// ================================================

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

// ================================================

void printArray(int array[],int size)
{
	int i;
	for ( i=0; i< size; i++)
	{
		printf ("%d", array[i]);
	}
}

// ================================================

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

// ================================================

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











