/*
 * estructuras.c
 *
 *  Created on: 4 oct. 2022
 *      Author: Ema
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "input.h"
#define LIBRE 0
#define OCUPADO 1

static int idNuevo(void);

int altaLibros(eLibro libros[],int tam,int idLibro,eAutor autores[], eEdit  editoriales[]) {

	int retorno;
	int indice;
	retorno = 0;//Si la lista está llena

	indice = buscarIdLibre(libros,tam);

	if(indice > -1)
	{
		libros[indice].idLibro = idNuevo();
		PedirCadena(libros[indice].titLibro, tam, "\nIngrese el titulo del libro ");
		libros[indice].fechaPub.dia = PedirEntero("\nIngrese el dia por favor ","\nError ingrese un valor menor a 31 ",0,31);
		libros[indice].fechaPub.mes = PedirEntero("\nIngrese el mes por favor ","\nError ingrese un valor menor a 31 ",0,12);
		libros[indice].fechaPub.anio = PedirEntero("\nIngrese el año por favor ","\nError ingrese un valor menor a 31 ",0,9999);
		libros[indice].importe = PedirFlotante("\nIngrese el importe por favor ", "Error - valor no valido" , 0.01, 1000000);
		libros[indice].idAutor = autores[indice].idAutor;
		libros[indice].idEditorial = editoriales[indice].idEdit;
		libros[indice].estado = OCUPADO;
	    retorno = 1; // SALIO BIEN
	}

	return retorno;
}
static int idNuevo(void)
{
    static int contador=0;
    contador++;
    return contador;
}
int buscarIdLibre(eLibro Libros[],int tam) {

	int indice;
	indice = -1; // Si no encuentra un usuario inactivo-> Si el array está lleno.
	if (Libros != NULL && tam > 0 ){
		for(int i=0; i <tam; i++)
		{
		   if(Libros[i].estado == LIBRE)
		   {
			   indice = i;
			   break;
		   }
		}
	}
	return indice;
}
void printAltas(eLibro libros[],int tam) {
   if(VerificarLleno(libros,tam) == 1) {
		printf(" _______________________________________________________________\n"
			   "|%-5s|%-15s|%-15s|%-13s|%-10s|\n"
			   "|=====|===============|===============|=============|==========|",
			     "ID",     "Nombre",      "ID-Editorial",     "Importe",  "fecha"  );
	   for(int i=0; i<tam; i++) {
		   if(libros[i].estado == OCUPADO)
		   {
				printf("\n|  %d   %s              %d         %d/%d/%d    $%.2f ", libros[i].idLibro,
						libros[i].titLibro, libros[i].idEditorial,
						libros[i].fechaPub.dia, libros[i].fechaPub.mes,
						libros[i].fechaPub.anio, libros[i].importe);
		   }
	   }
		printf("\n|_____|_______________|_______________|_____________|_____|_____|_____|\n");
   } else {
	   printf("No hay empleados para mostrar de de alta primero");
   }
}
void printAutor(eAutor autores[],int tam) {

   if(VerificarAutor(autores, tam) == 1) {
		printf(" ___________________________________________________\n"
			   "|  %-3s|          %-11s    |  %-15s  |\n"
			   "|=====|=========================|===================|",
			     "ID ",     "Autor",      "ID-Nacionalidad" );

	   printf("\n|  %d  | %s     |         %d         | ", autores[0].idAutor ,autores[0].autor, autores[0].idnacionalidad);
	   printf("\n|  %d  | %s  |         %d         | ", autores[1].idAutor ,autores[1].autor, autores[1].idnacionalidad);
	   printf("\n|  %d  | %s          |         %d         | ", autores[2].idAutor ,autores[2].autor, autores[2].idnacionalidad);
	   printf("\n|  %d  | %s       |         %d         | ", autores[3].idAutor ,autores[3].autor, autores[3].idnacionalidad);
	   printf("\n|  %d  | %s             |         %d         | ", autores[4].idAutor ,autores[4].autor, autores[4].idnacionalidad);
	   printf("\n|  %d  | %s             |         %d         | ", autores[5].idAutor ,autores[5].autor, autores[5].idnacionalidad);
	   printf("\n|  %d  | %s          |         %d         | ", autores[6].idAutor ,autores[6].autor, autores[6].idnacionalidad);
	   printf("\n|  %d  | %s         |         %d         | ", autores[7].idAutor ,autores[7].autor, autores[7].idnacionalidad);
	   printf("\n|  %d  | %s     |         %d         | ", autores[8].idAutor ,autores[8].autor, autores[8].idnacionalidad);
	   printf("\n|  %d | %s          |         %d         | ", autores[9].idAutor ,autores[9].autor, autores[9].idnacionalidad);


		printf("\n|_____|_________________________|___________________|\n");
   } else {
	   printf("No hay empleados para mostrar de de alta primero");
   }
}
void printEdit(eEdit editoriales[],int tam)
{
   if(VerificarEdit(editoriales, tam) == 1)
   {
	   printf("\nID editorial\t\t Editorial \n\n");
		for (int i = 0; i < tam; i++)
	   {
		   if(editoriales[i].idEdit >= OCUPADO)
		   {
			   printf("  %d \t\t\t %s \n", editoriales[i].idEdit ,editoriales[i].edit);
		   }
	   }
   }
   else
   {
	   printf("No hay empleados para mostrar de de alta primero");
   }
}
void printPais(ePais pais[],int tam){

	if( VerificarPais( pais, tam) == 1 ){

			printf("\nEl Los paises son - \n");
		for(int i=0; i<tam; i++) {
			if(pais[i].idPais == OCUPADO){
			printf("%s",pais[i].pais);
			}
		}
	}
}
int VerificarPais(ePais pais[],int tam) {
	int retorno;
	retorno = 0;

	for (int i = 0; i < tam; i++) {
		if (pais[i].idPais >= OCUPADO) {
			retorno = 1;
			break;
		}
	}

	return retorno;
}
int VerificarAutor(eAutor autores[], int tam) {
	int retorno;
	retorno = 0;

	for (int i = 0; i < tam; i++) {
		if (autores[i].idAutor >= OCUPADO) {
			retorno = 1;
			break;
		}
	}

	return retorno;
}
int VerificarEdit(eEdit editoriales[], int tam) {
	int retorno;
	retorno = 0;

	for (int i = 0; i < tam; i++) {
		if (editoriales[i].idEdit >= OCUPADO) {
			retorno = 1;
			break;
		}
	}

	return retorno;
}
int buscarId(eLibro libros[], int tam, int idABuscar) {
	int indice;
	indice = -1;

	for (int i = 0; i < tam; i++) {
		if (libros[i].estado == OCUPADO && libros[i].idLibro == idABuscar) {
			indice = i;
			break;
		}
	}

	return indice;
}
int modificarFecha(eLibro libros[],int tam) {

	int idAModificar, indiceAModificar, confirmacion;
	int retorno;

	retorno = -1;//Si no encontro al empleado

	idAModificar = PedirEntero("\nIngrese id del libro para modificar su fecha de publicacion: ","Error ingrese un valor correcto",0,50);
	indiceAModificar = buscarId(libros, tam, idAModificar);

	if(indiceAModificar > -1)
	{
	   confirmacion = PedirEntero("Usuario encontrado ¿Desea modificar al usuario? 1 si 0 no", "Error - ingrese un valor correcto", 0,1);
	   if(confirmacion == 1)
	   {
			libros[indiceAModificar].fechaPub.dia = PedirEntero("\nIngrese el dia por favor","\nError ingrese un valor menor a 31 ",0,31);
			libros[indiceAModificar].fechaPub.mes = PedirEntero("\nIngrese el mes por favor","\nError ingrese un valor menor a 31 ",0,12);
			libros[indiceAModificar].fechaPub.anio = PedirEntero("\nIngrese el año por favor","\nError ingrese un valor menor a 31 ",0,9999);
		   retorno = 1;//Salió bien
	   }
	   retorno = 0;//Si cancelo la operación
	}
	return retorno;
}
int modificarTitulo(eLibro libros[],int tam) {

	char tituloModificado[tam];
	int idAModificar, indiceAModificar, confirmacion, retorno;

	retorno = -1;//Si no encontro al empleado

	idAModificar = PedirEntero("\nIngrese id del libro a modificar: ","Error - ingrese un valor correcto",0,50);
	indiceAModificar = buscarId(libros, tam, idAModificar);

	if(indiceAModificar > -1)
	{
	   PedirCadena(tituloModificado,31,"\nIngrese el titulo del libro: ");
	   retorno = 0;//Si cancelo la operación
	   confirmacion = PedirEntero("Usuario encontrado ¿Desea modificar al usuario? 1 si 0 no", "Error - ingrese un valor correcto", 0,1);
	   if(confirmacion == 1)
	   {
		   strcpy(libros[indiceAModificar].titLibro,tituloModificado);
		   retorno = 1;//Salió bien
	   }
	}

	return retorno;

}
int modificarImporte(eLibro libros[], int tam) {

	int idAModificar, indiceAModificar, confirmacion;
	int retorno;

	retorno = -1; //Si no encontro al empleado

	idAModificar = PedirEntero(
			"\nIngrese id del libro para modificar su importe: ",
			"Error - ingrese un valor correcto", 0, 50);
	indiceAModificar = buscarId(libros, tam, idAModificar);

	if (indiceAModificar > -1) {
		retorno = 0; //Si cancelo la operación
		confirmacion = PedirEntero(
				"Usuario encontrado ¿Desea modificar al usuario? 1 si 0 no",
				"Error - ingrese un valor correcto", 0, 1);
		if (confirmacion == 1) {
			libros[indiceAModificar].importe = PedirFlotante("\nIngrese un nuevo importe ",
					"\nError !!! valor no valido", 0.01, 1000000000);
			retorno = 1; //Salió bien
		}
	}
	return retorno;
}
int modificarAutor(eLibro libros[],int tam,eAutor autores[]) {

	int idAModificar, indiceAModificar, confirmacion, idAutor;
	int retorno;

	retorno = -1;//Si no encontro al empleado

	idAModificar = PedirEntero("\nIngrese id del libro para modificar el id de Autor: ","Error - ingrese un valor correcto",0,50);
	indiceAModificar = buscarId(libros, tam, idAModificar);

	if(indiceAModificar > -1)
	{

	   retorno = 0;//Si cancelo la operación
	   confirmacion = PedirEntero("Usuario encontrado ¿Desea modificar al usuario? 1 si 0 no","Error - ingrese un valor correcto",0,1);
	   if(confirmacion == 1)
	   {
		   printf("\nIngrese el id del autor");
		   printAutor(autores, 10);
		   scanf("%d",&idAutor);
		   libros[indiceAModificar].idAutor = idAutor;
		   retorno = 1;//Salió bien
	   }
	}
	return retorno;
}
int modificarEditorial(eLibro libros[],int tam,eEdit  editoriales[]) {

	int idAModificar, indiceAModificar, confirmacion, idEdit;
	int retorno;

	retorno = -1;//Si no encontro al empleado

	idAModificar = PedirEntero("\nIngrese id del libro para modificar su editorial: ","Error - ingrese un valor correcto",0,50 );
	indiceAModificar = buscarId(libros, tam, idAModificar);

	if(indiceAModificar > -1)
	{
		idEdit = PedirEntero("Ingrese el ID de la editorial a modificar por favor: ","Error - ingrese un valor correcto",0,50);
	   retorno = 0;//Si cancelo la operación
	   confirmacion = PedirEntero("Usuario encontrado ¿Desea modificar al usuario? 1 si 0 no","Error - ingrese un valor correcto",0,1);
	   if(confirmacion == 1)
	   {
		   printf("\nIngrese el id de la editorial");
		   printEdit(editoriales, 5);
		   scanf("%d",&idEdit);
		   retorno = 1;//Salió bien
	   }
	}
	return retorno;
}
int VerificarLleno(eLibro libros[],int tam){

	int retorno;
	retorno = 0;

	for(int i=0; i<tam; i++)
    {
	   if(libros[i].estado == OCUPADO)
	   {
		   retorno = 1;
		   break;
	   }
    }

	return retorno;
}


//printf("\nIngrese el id de la Editorial");
//printf( "\n1 - Clave Librum"
//	    "\n2 - Club 5"
//	    "\n3,- Planeta"
//		"\n4,- Larousee"
//		"\n5,- Hilos");
//scanf("%d",idAutor);
//printf("\nIngrese el id del autor");
//printf( "\n1 - William Shakespeare"
//	    "\n2 - Gabriel Garcia Marquez"
//	    "\n3,- Edgar Alan Poe"
//		"\n4,- Jorge Luis Borges"
//		"\n5,- J.R.Tolkien"
//		"\n6,- J.K Rowling"
//		"\n7,- Julio Cortazar"
//		"\n8,- Agatha Christie"
//		"\n9,- Adolfo Bioy Casares"
//		"\n10,- Ernesto Sabato");
//scanf("%d",idAutor);
