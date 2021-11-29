/*
 * Libros.c
 *
 *  Created on: 25 nov. 2021
 *      Author: Maggiori, Gianni
 */
#include "Controller.h"
Libro* NuevoLibro(){
	Libro* unLibro=NULL;
	unLibro=(Libro*)calloc(1,sizeof(Libro));
	return unLibro;
}
Libro* NuevoLibroParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* idEditorialStr){
	Libro* unLibro=NULL;
	unLibro=NuevoLibro();
	if(unLibro!=NULL&&idStr!=NULL&&tituloStr!=NULL&&autorStr!=NULL&&precioStr!=NULL){
		L_SetIdLibros(unLibro, atoi(idStr));
		L_SetTituloLibros(unLibro, tituloStr);
		L_SetAutorLibros(unLibro, autorStr);
		L_SetPrecioLibros(unLibro, atof(precioStr));
		L_SetIdEditorial(unLibro, atoi(idEditorialStr));
	}
	return unLibro;
}
int L_SetIdLibros(Libro* lista, int id){
	int retorno=0;
	if(lista!=NULL){
		lista->id=id;
		retorno=1;
	}
	return retorno;
}
int L_GetIdLibros(Libro* lista, int* id){
	int retorno=0;
	if(lista!=NULL&&id!=NULL){
		*id=lista->id;
		retorno=1;
	}
	return retorno;
}
int L_SetTituloLibros(Libro* lista, char* titulo){
	int retorno=0;
	if(lista!=NULL&&titulo!=NULL){
		strcpy(lista->titulo,titulo);
		retorno=1;
	}
	return retorno;
}
int L_GetTituloLibros(Libro* lista, char* titulo){
	int retorno=0;
	if(lista!=NULL&&titulo!=NULL){
		strcpy(titulo,lista->titulo);
		retorno=1;
	}
	return retorno;
}
int L_SetAutorLibros(Libro* lista, char* autor){
	int retorno=0;
	if(lista!=NULL&&autor!=NULL){
		strcpy(lista->autor,autor);
		retorno=1;
	}
	return retorno;
}
int L_GetAutorLibros(Libro* lista, char* autor){
	int retorno=0;
	if(lista!=NULL&&autor!=NULL){
		strcpy(autor,lista->autor);
		retorno=1;
	}
	return retorno;
}
int L_SetPrecioLibros(Libro* lista, float precio){
	int retorno=0;
	if(lista!=NULL){
		lista->precio=precio;
		retorno=1;
	}
	return retorno;
}
int L_GetPrecioLibros(Libro* lista, float* precio){
	int retorno=0;
	if(lista!=NULL&&precio!=NULL){
		*precio=lista->precio;
		retorno=1;
	}
	return retorno;
}
int L_SetIdEditorial(Libro* lista, int idEditorial){
	int retorno=0;
	if(lista!=NULL){
		lista->idEditorial=idEditorial;
		retorno=1;
	}
	return retorno;
}
int L_GetIdEditorial(Libro* lista, int* idEditorial){
	int retorno=0;
	if(lista!=NULL){
		*idEditorial=lista->idEditorial;
		retorno=1;
	}
	return retorno;
}
int L_OrdenarLibrosPorID(void* pPrimerLibro, void* pSegundoLibro){
	int retorno=-1;
	int primerID;
	int segundoID;
	Libro* primerLibro;
	Libro* segundoLibro;
	primerLibro=(Libro*)pPrimerLibro;
	segundoLibro=(Libro*)pSegundoLibro;
	L_GetIdLibros(primerLibro,&primerID);
	L_GetIdLibros(segundoLibro,&segundoID);
	if(primerID>segundoID){
		retorno=1;
	}
	else{
		if(primerID==segundoID){
			retorno=0;
		}
	}
	return retorno;
}
int L_OrdenarLibrosPorTitulo(void* pPrimerLibro, void* pSegundoLibro){
	int retorno=-1;
	char primerTitulo[150];
	char segundoTitulo[150];
	Libro* primerLibro;
	Libro* segundoLibro;
	primerLibro=(Libro*)pPrimerLibro;
	segundoLibro=(Libro*)pSegundoLibro;
	L_GetTituloLibros(primerLibro,primerTitulo);
	L_GetTituloLibros(segundoLibro,segundoTitulo);
	retorno=strcmp(primerTitulo,segundoTitulo);
	return retorno;
}
int L_OrdenarLibrosPorAutor(void* pPrimerLibro, void* pSegundoLibro){
	int retorno=-1;
	char primerAutor[150];
	char segundoAutor[150];
	Libro* primerLibro;
	Libro* segundoLibro;
	primerLibro=(Libro*)pPrimerLibro;
	segundoLibro=(Libro*)pSegundoLibro;
	L_GetAutorLibros(primerLibro,primerAutor);
	L_GetAutorLibros(segundoLibro,segundoAutor);
	retorno=strcmp(primerAutor,segundoAutor);
	return retorno;
}
int L_OrdenarLibrosPorPrecio(void* pPrimerLibro, void* pSegundoLibro){
	int retorno=-1;
	float primerPrecio;
	float segundoPrecio;
	Libro* primerLibro;
	Libro* segundoLibro;
	primerLibro=(Libro*)pPrimerLibro;
	segundoLibro=(Libro*)pSegundoLibro;
	L_GetPrecioLibros(primerLibro,&primerPrecio);
	L_GetPrecioLibros(segundoLibro,&segundoPrecio);
	if(segundoPrecio>primerPrecio){
		retorno=0;
	}
	else{
		if(primerPrecio==segundoPrecio){
			retorno=1;
		}
	}
	return retorno;
}
int L_FiltrarPorEditorialPlaneta(void* pElemento){
	int retorno=0;
	int idEditorial;
	Libro* auxLibro;
	auxLibro=(Libro*)pElemento;
	L_GetIdEditorial(auxLibro,&idEditorial);
	if(idEditorial==1){
		retorno=1;
	}
	return retorno;
}
int L_FiltrarPorEditorialSigloXXI(void* pElemento){
	int retorno=0;
	int idEditorial;
	Libro* auxLibro;
	auxLibro=(Libro*)pElemento;
	L_GetIdEditorial(auxLibro,&idEditorial);
	if(idEditorial==2){
		retorno=1;
	}
	return retorno;
}
int L_FiltrarPorEditorialPearson(void* pElemento){
	int retorno=0;
	int idEditorial;
	Libro* auxLibro;
	auxLibro=(Libro*)pElemento;
	L_GetIdEditorial(auxLibro,&idEditorial);
	if(idEditorial==3){
		retorno=1;
	}
	return retorno;
}
int L_FiltrarPorEditorialMinotauro(void* pElemento){
	int retorno=0;
	int idEditorial;
	Libro* auxLibro;
	auxLibro=(Libro*)pElemento;
	L_GetIdEditorial(auxLibro,&idEditorial);
	if(idEditorial==4){
		retorno=1;
	}
	return retorno;
}
int L_FiltrarPorEditorialSalamandra(void* pElemento){
	int retorno=0;
	int idEditorial;
	Libro* auxLibro;
	auxLibro=(Libro*)pElemento;
	L_GetIdEditorial(auxLibro, &idEditorial);
	if(idEditorial==5){
		retorno=1;
	}
	return retorno;
}
int L_FiltrarPorEditorialPenguin(void* pElemento){
	int retorno=0;
	int idEditorial;
	Libro* auxLibro;
	auxLibro=(Libro*)pElemento;
	L_GetIdEditorial(auxLibro,&idEditorial);
	if(idEditorial==6){
		retorno=1;
	}
	return retorno;
}
void* L_GenerarDescuentos(void* pElemento){
	Libro* auxLibro=NULL;
	int id;
	char titulo[150];
	char autor[150];
	float precio;
	int idEditorial;
	float precioFinal;
	char idStr[300];
	char precioFinalStr[300];
	char idEditorialStr[300];
	if(pElemento!=NULL){
		L_GetIdEditorial(pElemento,&idEditorial);
		L_GetPrecioLibros(pElemento,&precio);
		L_GetAutorLibros(pElemento,autor);
		L_GetTituloLibros(pElemento, titulo);
		L_GetIdLibros(pElemento, &id);
		sprintf(idStr,"%i",id);
		sprintf(precioFinalStr,"%.2f",precio);
		sprintf(idEditorialStr,"%i",idEditorial);
		if(idEditorial==1&&precio>=300){
			precioFinal=precio*0.80;
			sprintf(precioFinalStr,"%.2f",precioFinal);
		}
		else{
			if(idEditorial==2&&precio<=200){
				precioFinal=precio*0.90;
				sprintf(precioFinalStr,"%.2f",precioFinal);
			}
		}
		auxLibro=NuevoLibroParametros(idStr, titulo, autor, precioFinalStr, idEditorialStr);
	}
	return auxLibro;
}























