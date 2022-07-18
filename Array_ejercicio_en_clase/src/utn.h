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
* ============================================================
*/


#ifndef FUNCIONES_H_  // esta para no repetir cuando defino prototipos
#define FUNCIONES_H_


//============== Arrays ====================
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
 * @param tamanio - Tama�o del array.
 */
void numArray(int lista[],char * mensaje,int tamanio);
/**
 * @brief Imprime los valores de un array.
 * @param array
 * @param size - tama�o
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
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
int getInt(char mensaje[]);

/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
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
 * \brief Genera un n�mero aleatorio
 * \param desde N�mero aleatorio m�nimo
 * \param hasta N�mero aleatorio m�ximo
 * \param iniciar Indica si se trata del primer n�mero solicitado 1 indica que si
 * \return retorna el n�mero aleatorio generado
 *
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar);
//====================================================

/**
 * \brief Verifica si el valor recibido es num�rico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */

int esNumerico(char str[]) ;

/**
 * \brief Verifica si el valor recibido contiene solo n�meros, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[]);
/**
 * \brief Verifica si el valor recibido contiene solo letras y n�meros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y n�meros, y 0 si no lo es
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
 * \param input Array donde se cargar� el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);
/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int getStringNumeros(char mensaje[],char input[]);

// ========- Calculos -=============
/**
 * @brief  Suma los enteros de un Array
 * @param lista - Array  a utilizar por el usuario.
 * @param size - tama�o.
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
