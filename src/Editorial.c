/*
 * Editorial.c
 *
 *  Created on: 26 nov. 2021
 *      Author: tanii
 */
#include "Controller.h"

Editorial* NuevaEditorial(){
	Editorial* unaEditorial=NULL;
	unaEditorial=(Editorial*)calloc(1,sizeof(Editorial));
	return unaEditorial;
}
Editorial* NuevaEditorialParametros(char* idEditorialStr, char* nombreEditorialStr){
	Editorial* unaEditorial=NULL;
	unaEditorial=NuevaEditorial();
	if(unaEditorial!=NULL&&idEditorialStr!=NULL&&nombreEditorialStr!=NULL){
		E_SetIdEditorial(unaEditorial, atoi(idEditorialStr));
		E_SetNombreEditorial(unaEditorial,nombreEditorialStr);
	}
	return unaEditorial;
}
int E_SetNombreEditorial(Editorial* lista, char* nombreEditorial){
	int retorno=0;
	if(lista!=NULL&&nombreEditorial!=NULL){
		strcpy(lista->nombreEditorial,nombreEditorial);
		retorno=1;
	}
	return retorno;
}
int E_GetNombreEditorial(Editorial* lista, char* nombreEditorial){
	int retorno=0;
	 if(lista!=NULL&&nombreEditorial!=NULL){
		 strcpy(nombreEditorial,lista->nombreEditorial);
		 retorno=1;
	 }
	return retorno;
}
int E_SetIdEditorial(Editorial* lista, int idEditorial){
	int retorno=0;
	if(lista!=NULL){
		lista->idEditorial=idEditorial;
		retorno=1;
	}
	return retorno;
}
int E_GetIdEditorial(Editorial* lista, int* idEditorial){
	int retorno=0;
	if(lista!=NULL){
		*idEditorial=lista->idEditorial;
		retorno=1;
	}
	return retorno;
}






