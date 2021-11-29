/*
 * Parser.c
 *
 *  Created on: 26 nov. 2021
 *      Author: tanii
 */
#include "Controller.h"
int Parser_LibrosDelArchivo(FILE* archivo , LinkedList* listaLibros){
	Libro* auxLibro;
	int retorno=0;
	char id[150];
	char titulo[150];
	char autor[150];
	char precio[150];
	char idEditorial[150];
	if(archivo!=NULL&&listaLibros!=NULL){
		fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,autor,precio,idEditorial);
		while(!feof(archivo)){
			fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,autor,precio,idEditorial);
			auxLibro=NuevoLibroParametros(id,titulo,autor,precio,idEditorial);
			ll_add(listaLibros, auxLibro);
			retorno=1;
		}
	}
    return retorno;
}
int Parser_EditorialesDelArchivo(FILE* archivo, LinkedList* listaEditoriales){
	int retorno=0;
	char idEditorial[100];
	char nombreEditorial[100];
	Editorial* auxEditorial;
	if(archivo!=NULL&&listaEditoriales!=NULL){
		fscanf(archivo,"%[^,],%[^\n]\n",idEditorial,nombreEditorial);
		while(!feof(archivo)){
			fscanf(archivo,"%[^,],%[^\n]\n",idEditorial,nombreEditorial);
			auxEditorial=NuevaEditorialParametros(idEditorial, nombreEditorial);
			ll_add(listaEditoriales, auxEditorial);
			retorno=1;
		}
	}
	return retorno;
}

