/*
 ============================================================================
 Name        : Ejercicio_1_3_GuiaSabados

 Description : Realizar el algoritmo que permita ingresar los datos de los alumnos de una división de
	la UTN FRA, los datos solicitados son:

	Legajo
	Tipo cursada(L: "libre" - P: "presencial" – R: "remota")
	Cantidad de materias( mas de cero y menos de 8)
	Sexo (F: “femenino” – M: “masculino” , O: “no binario”)
	Nota promedio (entre 0 y 10)
	Edad (validar)

Se debe informar de existir, o informar que no existe , en el caso que corresponda.

	a) El Legajo del mejor promedio femenino.
	b) El legajo del más joven de los alumnos masculinos entre los que dan libre.
	c) El promedio de nota por sexo.
	d) La edad y legajo del que cursa más materias. (Sin importar su género)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max 5

int main(void) {
	setbuf(stdout,NULL);

	char legajo[max];
	char tipoDeCursada[max];
	 int materia;
	char sexo;
	 int nota;
	 int edad;
	 int promedioFem ;
	 int notasFem = 0;
	 int accNotas = 0;
	 int i = 1;



	do{
//---------------------- L e g a j o -------------------------------- listo

		printf("\nIngrese el numero de legajo N° %d: ",i);
		fflush(stdin);
		scanf("%c",&legajo[i]);

		while((legajo[i] < '0' || legajo[i] > '9')) {
			printf("\nError ! Ingrese el numero correcto: ");
			fflush(stdin);
			scanf("%c",&legajo[i]);
		}
//---------------------- C u r s a d a -------------------------------- listo

		printf("\nIngrese el tipo de cursada: ");
		printf("\n- L: libre \n- P: presencial \n– R: remota\n");
		fflush(stdin);
		scanf("%c",&tipoDeCursada[i]);

		while(!(isdigit(tipoDeCursada[i]) == 0) || ( tipoDeCursada[i] != 'L' && tipoDeCursada[i] != 'P' && tipoDeCursada[i] != 'R')){
			printf("\nError ! Ingrese el tipo de cursada correcta: \n");
			printf("\n- L: libre \n- P: presencial \n– R: remota\n");
			fflush(stdin);
			scanf("%c",&tipoDeCursada[i]);
		}
//---------------------- M a t e r i a s ----------------------------- listo

		printf("\nIngrese la cantidad de materias: ");
		fflush(stdin);
		scanf("%d",&materia);
		while ( ((materia < 0) || (materia > 9)) &&
			  (( materia < '0') || (materia > '9')) ) {
			printf("\nERROR !! deben de ser mayor a 0 y menor a 9: ");
			fflush(stdin);
			scanf("%d",&materia);
		}
//------------------------ S e x o  -  A l u m n o  ---------------------------- Listo

		printf("\nIngrese el sexo del Alumno: ");
		printf("\n- F: femenino  \n– M: masculino  \n- O: no binario ");
		fflush(stdin);
		scanf("%c",&sexo);
		while((sexo != 'F') && (sexo != 'M') && (sexo != 'O')){
			printf("\nError !! - Ingrese el sexo correcto: ");
			printf("\n- F: femenino  \n– M: masculino  \n- O: no binario ");
			fflush(stdin);
			scanf("%c",&sexo);
		}
//------------------------- N o t a ---------------------------------

		printf("\nIngrese la nota entre 0 y 10: ");
		scanf("%d",&nota);
		while ( ((nota < 0) || (nota > 11) ) && (( nota < '0') || ( nota > '9')) ){
			printf("\nError !!! reingrese la nota: ");
			fflush(stdin);
			scanf("%d",&nota);
		}
//------------------------- E d a d  ---------------------------------

		printf("\nIngrese la edad del Alumno: ");
		scanf("%d",&edad);
		while((edad < 0) && (edad < 101)){
			printf("\nError - Reingrese la edad del Alumno: ");
			scanf("%d",&edad);
		}
	 i++;
	 }while( i < max);

		if (sexo == 'F') {
			accNotas += nota;
			notasFem++;
		}

promedioFem = accNotas/notasFem;

printf("El promedio %d",promedioFem);

	return EXIT_SUCCESS;
}
