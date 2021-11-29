/*
 * Controller.c
 *
 *  Created on: 26 nov. 2021
 *      Author: tanii
 */
#include "Controller.h"
int Controller_CargarArchivoDeLibros(LinkedList* lista){
	int retorno=0;
	char archivo[250];
	FILE* pFile;
	if(lista!=NULL){
		PedirArchivo(archivo,"\nIngrese el nombre del archivo que desea abrir: ");
		pFile=fopen(archivo,"r");
		if(archivo!=NULL){
			Parser_LibrosDelArchivo(pFile, lista);
			retorno=1;
		}
		fclose(pFile);
	}
	return retorno;
}

int Controller_CargarArchivoDeEditoriales(LinkedList* lista){
	int retorno=0;
	char archivo[250];
	FILE* pFile;
	if(lista!=NULL){
		PedirArchivo(archivo,"\nIngrese el nombre del archivo que desea abrir: ");
		pFile=fopen(archivo,"r");
		if(archivo!=NULL){
			Parser_EditorialesDelArchivo(pFile, lista);
			retorno=1;
		}
		fclose(pFile);
	}
	return retorno;
}
Editorial* Controller_BuscarEditorial(LinkedList* listaEditoriales, int id){
	int tam;
	Editorial* auxEditorial=NULL;
	if(listaEditoriales!=NULL){
		tam=ll_len(listaEditoriales);
		for(int i=0;i<tam;i++){
			auxEditorial=(Editorial*)ll_get(listaEditoriales, i);
			if(auxEditorial!=NULL){
				if(auxEditorial->idEditorial==id){
					break;
				}
			}
		}
	}
	return auxEditorial;
}

int Controller_ListarLibros(LinkedList* lista, LinkedList* listaEditoriales){
	int retorno=0;
	int tam;
	int id;
	char titulo[150];
	char autor[150];
	float precio;
	int idEditorial;
	char nombreEditorial[150];
	Libro* auxLibro;
	Editorial* auxEditorial;
	if(lista!=NULL){
		tam=ll_len(lista);
		if(tam>0){
			printf("\n======================================================================================================================\n");
			printf("ID\t\t|TITULO\t\t\t\t\t|AUTOR\t\t\t|PRECIO\t\t|EDITORIAL");
			printf("\n======================================================================================================================\n");
			for(int i=0;i<tam;i++){
				auxLibro=(Libro*)ll_get(lista, i);
				auxEditorial=Controller_BuscarEditorial(listaEditoriales, auxLibro->idEditorial);
				if(auxLibro!=NULL&&auxEditorial!=NULL){
					L_GetIdLibros(auxLibro, &id);
					L_GetTituloLibros(auxLibro,titulo);
					L_GetAutorLibros(auxLibro,autor);
					L_GetPrecioLibros(auxLibro, &precio);
					L_GetIdEditorial(auxLibro, &idEditorial);
					E_GetNombreEditorial(auxEditorial, nombreEditorial);
					printf("%-16i|%-39s|%-23s|%-15.2f|%-20s|\n",id,titulo,autor,precio,nombreEditorial);
					retorno=1;
				}
			}
		}
	}
	return retorno;
}
int Controller_OrdenarPor(LinkedList* listaLibros){
	int retorno=0;
	int opcion;
	int opcionOrdenamiento;
	if(listaLibros!=NULL){
		retorno=1;
		do{
			printf("\n\n=====================");
			printf("\n\nMenu de Ordenamientos");
			printf("\n\n=====================");
			opcion=PedirOpcion("\n1-Ordenar por ID\n2-Ordenar por TITULO\n3-Ordenar por AUTOR\n4-Ordenar por PRECIO\n5-Salir del menu de ordenamiento\n\n", 1, 5);
			if(opcion!=5){
				opcionOrdenamiento=PedirOpcion("\nSeleccione un orden de ordenamiento. 0 para descendente o 1 para ascendente\n", 0, 1);
			}
			switch(opcion){
			case 1:
				ll_sort(listaLibros, L_OrdenarLibrosPorID, opcionOrdenamiento);
			break;
			case 2:
				ll_sort(listaLibros, L_OrdenarLibrosPorTitulo, opcionOrdenamiento);
			break;
			case 3:
				ll_sort(listaLibros, L_OrdenarLibrosPorAutor, opcionOrdenamiento);
			break;
			case 4:
				ll_sort(listaLibros, L_OrdenarLibrosPorPrecio, opcionOrdenamiento);
			break;
			}
		}while(opcion!=5);
	}
	return retorno;
}
int Controller_GuardarLista(LinkedList* lista){
	int retorno=0;
	char nombreArchivo[250];
	int tam;
	int id;
	char titulo[250];
	char autor[250];
	float precio;
	int idEditorial;
	FILE* pFile;
	Libro* auxLibro;
	if(lista!=NULL){
		tam=ll_len(lista);
		PedirArchivo(nombreArchivo, "\n\nComo desea que se llame el archivo que desea guardar: ");
		pFile=fopen(nombreArchivo,"w");
		fprintf(pFile,"Id,Titulo,Autor,Precio,IdEditorial\n");
		for(int i=0;i<tam;i++){
			auxLibro=(Libro*)ll_get(lista, i);
			if(auxLibro!=NULL){
				L_GetIdLibros(auxLibro, &id);
				L_GetTituloLibros(auxLibro, titulo);
				L_GetAutorLibros(auxLibro, autor);
				L_GetPrecioLibros(auxLibro, &precio);
				L_GetIdEditorial(auxLibro, &idEditorial);
				fprintf(pFile,"%i,%s,%s,%.2f,%i\n",id,titulo,autor,precio,idEditorial);
				retorno=1;
			}
		}
		fclose(pFile);
	}
	return retorno;
}

LinkedList* Controller_FiltrarPor(LinkedList* listaLibros, LinkedList* listaEditoriales){
	LinkedList* auxListaLibros=NULL;
	int opcion;
	if(listaLibros!=NULL){
		do{
			printf("\n\n=============================");
			printf("\n\nMenu de Filtro de editoriales");
			printf("\n\n=============================");
			opcion=PedirOpcion("\n1-Filtrar editorial PLANETA\n2-Filtrar editorial SIGLO XXI EDITORES\n3-Filtrar editorial PEARSON\n4-Filtrar editorial MINOTAURO\n5-Filtrar editorial SALAMANDRA\n6-Filtrar editorial PENGUIN BOOKS\n7-Salir del menu de filtros\n", 1, 7);
			switch(opcion){
			case 1:
				auxListaLibros=ll_filter(listaLibros, L_FiltrarPorEditorialPlaneta);
			break;
			case 2:
				auxListaLibros=ll_filter(listaLibros, L_FiltrarPorEditorialSigloXXI);
			break;
			case 3:
				auxListaLibros=ll_filter(listaLibros, L_FiltrarPorEditorialPearson);
			break;
			case 4:
				auxListaLibros=ll_filter(listaLibros, L_FiltrarPorEditorialMinotauro);
			break;
			case 5:
				auxListaLibros=ll_filter(listaLibros, L_FiltrarPorEditorialSalamandra);
			break;
			case 6:
				auxListaLibros=ll_filter(listaLibros, L_FiltrarPorEditorialPenguin);
			break;
			}
		}while(opcion!=7);
	}
	if(auxListaLibros!=NULL){
		Controller_GuardarLista(auxListaLibros);
		Controller_ListarLibros(auxListaLibros, listaEditoriales);
	}
	return auxListaLibros;
}
int Controller_Mapear(LinkedList* lista, LinkedList* listaEditoriales){
	int retorno=0;
	LinkedList* auxLinkedList;
	if(lista!=NULL){
		auxLinkedList=ll_map(lista, L_GenerarDescuentos);
		if(auxLinkedList!=NULL){
			Controller_GuardarLista(auxLinkedList);
			Controller_ListarLibros(auxLinkedList, listaEditoriales);
			retorno=1;
		}
	}
	return retorno;
}






























