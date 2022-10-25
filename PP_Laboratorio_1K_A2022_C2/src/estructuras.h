/*
 * estructuras.h
 *
 *  Created on: 4 oct. 2022
 *      Author: Ema
 */

#ifndef ESTRUCTURAS_H_
#define ESTRUCTURAS_H_
#define TAM 51


typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct{
	int idPais;             // autoincremental.
	char pais[TAM];        // pais al que corresponde
}ePais;

typedef struct{
	int idEdit;             // autoincremental.
	char edit[TAM];        // Nombre editorial.
}eEdit;

typedef struct{
	int idAutor;            // autoincremental.
	char autor[TAM];       // nombre Autor.
	int idnacionalidad;
}eAutor;

typedef struct {
	int idLibro;            // autoincremental.
	char titLibro[TAM];		// validar !!
	eFecha fechaPub;   		// validar !!
	float importe; 			// validar !!
	int idAutor;
	int idEditorial;
	int estado;
}eLibro;
//
int buscarIdLibre(eLibro Libros[],int tam);
int buscarId(eLibro libros[],int tam,int idABuscar);

void printAltas(eLibro libros[],int tam);
void printAutor(eAutor autores[],int tam);
void printEdit(eEdit editoriales[],int tam);
void printPais(ePais pais[],int tam);

int VerificarAutor(eAutor autores[], int tam);
int VerificarEdit(eEdit editoriales[], int tam);
int VerificarPais(ePais pais[],int tam);
int VerificarLleno(eLibro libros[],int tam);


int modificarFecha(eLibro libros[],int tam);
int modificarTitulo(eLibro libros[],int tam);
int modificarImporte(eLibro libros[],int tam);
int modificarAutor(eLibro libros[],int tam, eAutor autores[]);
int modificarEditorial(eLibro libros[],int tam, eEdit  editoriales[]);

int altaLibros(eLibro libros[],int tam,int idLibro,eAutor autores[], eEdit  editoriales[]);

#endif /* ESTRUCTURAS_H_ */


