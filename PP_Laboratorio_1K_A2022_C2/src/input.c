/*
 * input.c
 *
 *  Created on: 1 oct. 2022
 *      Author: Ema
 */


#include "estructuras.h"
#include "input.h"
#include "validaciones.h"

#define LIBRE 0
#define OCUPADO 1
#define SIZE 50

void progPrincipal(){

	int idLibro = 0;
	int numero;
	char opcionListar = ' ', opcionModificar = ' ';
	eLibro libros[SIZE];

	eAutor autores[] = { { 1, "William Shakespeare", 1 }, { 2,	"Gabriel Garcia Marquez", 2 },
			{ 3, "Edgar Alan Poe", 3 }, { 4,"Jorge Luis Borges", 4 }, { 5, "J.R.Tolkien", 1 },
			{ 6,"J.K Rowling", 1 }, { 7, "Julio Cortazar", 4 }, { 8,"Agatha Christie", 1 },
			{ 9, "Adolfo Bioy Casares", 4 }, { 10,"Ernesto Sabato", 4 } };
	eEdit editoriales[] = { { 1, "Clave Librum" }, { 2, "Club 5" }, { 3,"Planeta" }, { 4, "Larousse" }, { 5, "Hilos" } };
	ePais paises[] = { { 1, "Inglaterra" }, { 2, "Colombia" }, { 3, "EEUU" }, {	4, "Argentina" } };

	do{

			switch(ejecutarMenu(&numero))
			{
			   case 1://										─────────────────► Alta
				   if(altaLibros(libros, SIZE, idLibro, autores, editoriales) == 1)
				   {
					   printf("\n\nSe dio de alta correctamente !\n");
					 system("pause");
				   }
				   else
				   {
					   printf("\nLo siento la lista está llena");
				   }
				   break;

			   case 2: //										 ─────────────────► Modificacion

				  do
				  {
					  switch( menuModificar(opcionModificar) )
					  {
					  	  case 'a':
					  		  printAltas(libros, SIZE);
					  		    switch(modificarTitulo(libros, SIZE)) // ─────────────────► Mod - titulo
									{
										case -1:
											printf("\nEl usuario no existe no se puede modificar");
											break;
										case 0:
											printf("Operacion cancelada");
											break;
										case 1:
											printf("El nombre se modifico con exito");
											break;
									}
									break;

					  	  case 'b':
					  		  switch(modificarFecha(libros, SIZE)) // ─────────────────► Mod - fecha
									{
										case -1:
											printf("El usuario no existe no se puede modificar");
											break;
										case 0:
											printf("Operacion cancelada");
											break;
										case 1:
											printf("El nombre se modifico con exito");
											break;
									}
								  break;
					  	  case 'c':
					  		switch(modificarImporte(libros, SIZE)) // ─────────────────► Mod - importe
									{
										case -1:
											printf("El usuario no existe no se puede modificar");
											break;
										case 0:
											printf("Operacion cancelada");
											break;
										case 1:
											printf("El nombre se modifico con exito");
											break;
									}
								  break;
					  	  case 'd':
					  		switch(modificarAutor(libros, SIZE, autores)) // ─────────────────► Mod - autor
								{
									case -1:
										printf("El usuario no existe no se puede modificar");
										break;
									case 0:
										printf("Operacion cancelada");
										break;
									case 1:
										printf("El nombre se modifico con exito");
										break;
								}
							  break;
					  		case 'e':
								switch(modificarEditorial(libros, SIZE, editoriales)) // ─────────────────► Mod - Edit
									{
										case -1:
											printf("El usuario no existe no se puede modificar");
											break;
										case 0:
											printf("Operacion cancelada");
											break;
										case 1:
											printf("El nombre se modifico con exito");
											break;
									}
								  break;
						  case 'f':
								  break;
					  	  default:
							   printf("Opcion invalida\n");
					  	  break;
					  }
				  }while(opcionModificar != 'f');

				   break;

			   case 3: //										 ─────────────────► Baja
				   //if(BajaEmpleado(libros,SIZE) == 1)
//				   {
//					   printf("Se dio de baja correctamente");
//				   }
//				   else
//				   {
//					   printf("El legajo no existe");
//				   }
				  break;

			   case 4: // ─────────────────► Informar

				   break;

			   case 5: // ─────────────────► Listar
				   do{
					   switch(menuListar(opcionListar)){
					   	   case 'a':
					   		   printEdit(editoriales, 5);
					   		   break;
					   	   case 'b':
					   		   printPais(paises, 4);
					   		   break;
					   	   case 'c':
					   		   printAutor(autores, 10);
					   		system("\n\npause");
					   		   break;
					   	   case 'd':
					   		   break;
					   	   case 'e':
					   		   break;
					   	   case 'f':
					   		   break;
					   }
				   }while(opcionListar != 'f');
				   break;
			   case 6:
				   printf("SALIR\n");
				   break;

			}

		}while(numero != 6);



}
int ejecutarMenu(int *numero) {

	printf("\n\n");
	for (int i = 0; i < 70; ++i)
		printf("—");
	printf("\n||                  Bienvenidos al Administrador de libros®           ||\n ");
	for (int i = 0; i < 70; ++i)
		printf("—");

	printf("\n\n   ■        ■ ■    ■ ■    ■ ■    ■ ■    ■ ■    ■ ■    ■ ■        ■\n");

	printf("\n  ◄------------- Complete los siguientes datos por favor -------------► \n\n");

	printf("\n1) - Altas"
			"\n2) - Modificacion"
			"\n3) - Baja"
			"\n4) - Informar"
			"\n5) - Listar "
			"\n6) - Salir\n");
	printf("\n opcion ———►  ");
	scanf("%d", numero);

	return* numero;

}
char menuModificar(char letra) {

	printf("\na) Título "
			"\nb) Fecha de publicación "
			"\nc) Importe "
			"\nd) Autor "
			"\ne) Editorial"
			"\nf) salir"	);
	fflush(stdin);
	scanf("%c", &letra);
	return letra;
}
char menuListar(char letra) {

	printf( "\na) Editoriales"
			"\nb) Paises"
			"\nc) Autores"
			"\nd) Listado completo"
			"\ne) Libros Ordenados"
			"\nf) salir\n"	);
	printf("\n opcion ———►  ");
	fflush(stdin);
	scanf("%c", &letra);
	return letra;
}
int PedirCadena(char cadena[],int len,char mensaje[]){

	int retorno;
	char buffer[1024];
	int largoBuffer;

	retorno = 0;

	printf("%s",mensaje);
	fflush(stdin);
	scanf("%[^\n]",buffer);
 	validarString(buffer, len,"Error - Ingrese un nombre correcto");
	largoBuffer = (int)strlen(buffer);

	if(len > largoBuffer)
	{
		strcpy(cadena,buffer);
		retorno = 1;
	}


	return retorno;
}
int PedirEntero(char *mensaje, char *mensajeError,int minimo, int maximo){

	char numero[128];
	int auxNum;
	do{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]", numero);
		auxNum = atoi(numero);
		if (( (auxNum < minimo) || (auxNum > maximo ) || ( (validarNumero( numero)) == 0) )) {
			printf("%s", mensajeError);
			auxNum = 0;
		}
	}while(auxNum == 0);

	return auxNum;
}
float PedirFlotante(char *mensaje, char *mensajeError,int minimo, int maximo){

	char numero[128];
	float auxNum;
	do{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]", numero);
		auxNum = atof(numero);
		if (( (auxNum < minimo) || (auxNum > maximo ) || ( (validarFloat( numero)) == 0) )) {
			printf("%s", mensajeError);
			auxNum = 0;
		}
	}while(auxNum == 0);

	return auxNum;
}
