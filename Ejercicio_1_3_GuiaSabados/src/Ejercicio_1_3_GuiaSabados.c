/*
 ============================================================================
 Name        : Ejercicio 1-3 guia sabados

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



int main(void) {
	setbuf(stdout,NULL);

//    Variables

	char tipoDeCursada;
	char sexo;
	int materia = 0;
	int nota;
	int legajo;
	int edad;
	char rpta;

//   calculos - contadotres - promedios

	int mejorNota = 0;
//	int legajoNota;
//	int legajoJoven;
	int joven = 0;
	int mayorMat = 0;
//	int legajoCursada;
	int promedioFem;
	int promedioMasc;
	int promedioBin;
	int notasFem = 0;
	int notasMasc = 0;
	int notasBin = 0;
	int accFem = 0;
	int accMas = 0;
	int accBin = 0;




	do{
//---------------------- L e g a j o -------------------------------- listo

		printf("\nIngrese el N° de legajo por favor: ");
		scanf("%d",&legajo);
		while ( ((legajo < 0) || (legajo > 100) ) && (( legajo < '0') || ( legajo > '9')) ){
			fflush(stdin);
			printf("\nError !!! reingrese el legajo: ");
			scanf("%d", &legajo);
		}

//---------------------- C u r s a d a -------------------------------- listo

		printf("\nIngrese el tipo de cursada: ");
		printf("\n- L: libre \n- P: presencial \n– R: remota\n");
		fflush(stdin);
		scanf("%c",&tipoDeCursada);

		while(!(isdigit(tipoDeCursada) == 0) || ( tipoDeCursada != 'L' && tipoDeCursada != 'P' && tipoDeCursada != 'R')){
			printf("\nError ! Ingrese el tipo de cursada correcta: \n");
			printf("\n- L: libre \n- P: presencial \n– R: remota\n");
			fflush(stdin);
			scanf("%c",&tipoDeCursada);
		}

//---------------------- M a t e r i a s ----------------------------- listo

		printf("\nIngrese la cantidad de materias: ");
		fflush(stdin);
		scanf("%d",&materia);

		while ( ((materia < 0) || (materia > 9)) &&
			  (( materia < '0') || (materia > '9')) ) {
			fflush(stdin);
			printf("\nERROR !! deben de ser mayor a 0 y menor a 9: ");
			scanf("%d", &materia);
		}

//------------------------ S e x o  -  A l u m n o  ---------------------------- Listo

		printf("\nIngrese el sexo del Alumno: ");
		printf("\n- F: femenino  \n– M: masculino  \n- O: no binario ");
		fflush(stdin);
		scanf("%c",&sexo);

		while((sexo != 'F') && (sexo != 'M') && (sexo != 'O')){
			fflush(stdin);
			printf("\nError !! - Ingrese el sexo correcto: ");
			printf("\n- F: femenino  \n– M: masculino  \n- O: no binario ");
			scanf("%c", &sexo);
			}

//------------------------- N o t a ---------------------------------

		printf("\nIngrese la nota entre 0 y 10: ");
		scanf("%d",&nota);
		while ( ((nota < 0) || (nota > 10) ) && (( nota < '0') || ( nota > '9')) ){
			fflush(stdin);
			printf("\nError !!! reingrese la nota: ");
			scanf("%d", &nota);
		}
		if (sexo == 'F') {
			if (nota > mejorNota) {
				mejorNota = nota;
				legajoNota = legajo;
			}
		}
		switch(sexo){
			case 'F':
				accFem += nota;
				notasFem++;
				break;
			case 'M':
				accMas += nota;
				notasMasc++;
				break;
			case 'O':
				accBin += nota;
				notasBin++;
				break;
			default: printf("No se ingresaron datos de alumnos");
		}
//------------------------- E d a d  ---------------------------------

		printf("\nIngrese la edad del Alumno: ");
		scanf("%d", &edad);
		while ((edad < 0) && (edad < 101)) {
			fflush(stdin);
			printf("\nError - Reingrese la edad del Alumno: ");
			scanf("%d", &edad);
		}
		if ((edad > joven) && (tipoDeCursada == 'L')) {
			joven = edad;
			legajoJoven = legajo;
		}
		if (materia > mayorMat) {
			mayorMat = edad;
			legajoCursada = legajo;
		}
		printf("\nDesea ingresar otro Alumno - rpta s/n ");
		fflush(stdin);
		scanf("%c", &rpta);
		while ((rpta != 's') && (rpta != 'n'))  {
			fflush(stdin);
			printf("ERROR ! debe ingrese si o no .");
			scanf("%c", &rpta);
		}
	}while( rpta == 's');

// ----------- P r o m e d i o s    y     C a l c u l o s -------------

	promedioFem = accFem / notasFem;
	promedioMasc = accMas / notasMasc;
	promedioBin = accBin / notasBin;

	printf(	"El promedio de notas por sexo es Femenino: %d, Masculino: %d, Binario: %d",
				promedioFem, promedioMasc, promedioBin);


//	if(legajoNota == 0){
//		printf(" No hubo alumno con mayor promedio femenino");
//	}else{
//		printf(	"El Legajo del mejor promedio Femenino es: %d",legajoNota);
//	}
//	if(joven == 0){
//		printf(" No hubo alumno que rinda libre");
//	}else{
//	printf(	"El Legajo del alumno mas joven que rinde libre: %d",legajoJoven);
//	}
//	if(mayorMat == 0){
//		printf(" No hubo alumno con un maximo de materias");
//	}else{
//	printf(	"La edad es %d y el legajo es %d de la persona que cursa mas materias", mayorMat, legajoCursada);
//	}
//	printf(	"El promedio de notas por sexo es Femenino: %d, Masculino: %d, Binario: %d",
//			promedioFem, promedioMasc, promedioBin);

	return EXIT_SUCCESS;
}


