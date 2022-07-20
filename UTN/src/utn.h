/*
 *                       F i r m a s    o    P r o t o t i p o s
  *  ============================================================
int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);
int PedirNumeros (char mensaje[], char mensajeError[], int min, int max)

char getNumeroAleatorio(int desde , int hasta, int iniciar);

------- Validaciones -------
int esNumerico(char str[]) ;
int esTelefono(char str[]);
int esAlfaNumerico(char str[]);
int esSoloLetras(char str[]);

--------- Arrays ------
void inicializarArray(int lista[], int tamanio);
void numArray(int lista[], char *mensaje, int tamanio)
void printArray(int array[],int size)
int printArray(int* pArray, int limite);     con punteros
int ordenArray(int* pArray, int limite);

--------  Caracteres -------
void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
 v
------- - Calculos  -----------------
int sumaEnteros(int lista[],int tamanio)
int promedio(int a, int b)
float promedioArray ( int Array[], int size )

-------- Funciones UTN ------------
listo - int utn_getInt(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
listo - int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError,float minimo, float maximo, int reintentos);
listo - int utn_getCharacter(char* resultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);
listo - void utn_printArray(int arrayInt[],int tam);
listo - int utn_promedio(int* resultado,int arrayInt[], int size);
listo  - int utn_ordenarArray(int* array, int limite);
listo - void utn_printArrayFloat(float arrayFloat[], int tam);
listo  - int utn_getString(char *pResultado, char *mensaje, char *mensajeError,int longitud, int reintentos);

int myGets(char *cadena, int longitud);
* ============================================================
*/


#ifndef FUNCIONES_H_  // esta para no repetir cuando defino prototipos
#define FUNCIONES_H_

//============== F u n c i o n e s  -  UTN ====================
/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getInt(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
/**
 * \brief - Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param - pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param - mensaje Es el mensaje a ser mostrado
 * \param - mensajeError Es el mensaje de Error a ser mostrado
 * \param - minimo Es el numero maximo a ser aceptado
 * \param - maximo Es el minimo minimo a ser aceptado
 * \return - Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError,float minimo, float maximo, int reintentos);
/**
 * \brief - Solicita un caracter al usuario, leuego de verificarlo devuelve el resultado
 * \param - pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param - mensaje Es el mensaje a ser mostrado
 * \param - mensajeError Es el mensaje de Error a ser mostrado
 * \param - minimo Es el numero maximo a ser aceptado
 * \param - maximo Es el minimo minimo a ser aceptado
 * \return - Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getCharacter(char* resultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);
/**
 * \brief - Solicita una cadena de caracteres al usuario, luego de verificarlo devuelve el resultado
 * \param - pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param - mensaje Es el mensaje a ser mostrado
 * \param - mensajeError Es el mensaje de Error a ser mostrado
 * \param - longitud Es el tamaño del array
 * \param - reintentos Es la cantidad maxima de reintentos que puede tener el usuario
 * \return - Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getString(char *pResultado, char *mensaje, char *mensajeError,int longitud, int reintentos);

//============== U T N  -   A r r a y s  ====================
/**
 * @brief Imprime un array
 * @param arrayInt - array en cuestion
 * @param tam -  tamanio
 */
void utn_printArray(int arrayInt[],int tam);
/**
 * @brief - Imprime un array Flotante.
 * @param arrayFloat - array a utilizar
 * @param tam -  size.
 */
void utn_printArrayFloat(float arrayFloat[], int tam);
/**
 * @brief  - Ordena un array de manera ascendente o descendente.
 * @param array - Es el puntero al array a ser ordenado.
 * @param limite -  Tamaño
 * @return 0 si esta ok o -1 para indicar error.
 */
int utn_ordenarArray(int* array, int limite);
/**
 * @brief  - Obtiene el promedio de un array.
 * @param resultado - El promedio relaizado pasado por el array
 * @param arrayInt - Array de entero
 * @param size - Tamaño predefinido por el usuario.
 * @return -  0 si esta ok o -1 para indicar error.
 */
int utn_promedio(int *resultado, int arrayInt[], int size);

//==============  A r r a y s  ====================

/**
 * @brief  - Inicializa el array .
 * @param lista - Array a inicializar.
 * @param tamanio - del Array.
 */
void inicializarArray(int lista[], int tamanio);
/**
 * @brief - Cargo los datos de un array.
 * @param lista - Array a utilizar .
 * @param mensaje - lo que solicita el usuario.
 * @param tamanio - Tamaño del array.
 */
void numArray(int lista[],char * mensaje,int tamanio);
/**
 * @brief Imprime los valores de un array.
 * @param array
 * @param size - tamaño
 */
void printArray(int array[],int size);
/**
 * @brief - Imprime a modo DEBUG la informacion de un array de enteros.
 * @param pArray - Es el puntero al array a ser ordenado.
 * @param limite - (size , es la longitud del array).
 * @return - 0 si esta ok o -1 para indicar error.
 */
int printpArray(int* pArray, int limite);
/**
 * @brief - Ordena un array de manera ascendende o descendente los enteros.
 * @param pArray - Es el puntero al array a ser ordenado.
 * @param limite - (size , es la longitud del array).
 * @return - Cantidad de iteraciones necesarias para ordenar, 0 si esta ok o -1 para indicar error.
 */
int ordenArray(int* pArray, int limite);
//========================================
/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 * \param *cadena Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 */
int myGets(char *cadena, int longitud);
/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char mensaje[]);

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char mensaje[]);

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char mensaje[]);
/**
 * @brief
 *
 * @param pResultado -  0 y 1 dependiendo si es correcto o no.
 * @param mensaje - lo que se le solicita al usuario.
 * @param mensajeError - si la validacion no es correcta.
 * @param minimo - valor minimo a validar .
 * @param maximo - valor maximo a validar.
 * @return
 */
int getNumber(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo);
//====================================================
/**
 * @brief
 *
 * @param mensaje - Lo que se le pide al usuario.
 * @param mensajeError - error de ingreso.
 * @param min - valor minimo, para el error.
 * @param max -  valor maximo para el error.
 * @return
 */
int PedirNumeros (char mensaje[], char mensajeError[], int min, int max);

//====================================================
/**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
 * \return retorna el número aleatorio generado
 *
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar);
//====================================================

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumerico(char str[]) ;

/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[]);
/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[]);

// ========- Calculos -=============
/**
 * @brief  Suma los enteros de un Array
 * @param lista - Array  a utilizar por el usuario.
 * @param size - tamaño.
 * @return
 */
int sumaEnteros(int lista[],int size);
/**
 * @brief  promedia 2 numeros enteros
 * @param a
 * @param b
 * @return
 */
int promedio(int a, int b);
/**
 * @brief  Promedia un array
  * @param Array
 * @param size
 * @return
 */
float promedioArray ( int Array[], int size );
/**
 * @brief 	devuelve el promedio pasado por punteros.
 * @param pResultado
 * @param Array
 * @param size
 * @return
 */
float promediopArray (int* pResultado, int Array[], int size );

#endif /* FUNCIONES_H_ */
