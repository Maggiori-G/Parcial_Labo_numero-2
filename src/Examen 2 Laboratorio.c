/*
 ============================================================================
 Name        : Examen.c
 Author      : Maggiori, Gianni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
int main(void){
	setbuf(stdout,NULL);
	int opcion;
	LinkedList* listaLibros=ll_newLinkedList();
	LinkedList* listaEditoriales=ll_newLinkedList();
	do{
		ImprimirOpciones();
		opcion=PedirOpcion("\n\nQue accion desea realizar?\n", 1, 7);
		switch(opcion){
		case 1:
			if(Controller_CargarArchivoDeLibros(listaLibros)){
				printf("\nArchivo cargado con exito...\n");

			}
			else{
				printf("\nNo se pudo cargar el archivo, intente de nuevo\n");
			}
		break;
		case 2:
			if(Controller_CargarArchivoDeEditoriales(listaEditoriales)){
				printf("\nArchivo cargado con exito...\n");
			}
			else{
				printf("\nNo se pudo cargar el archivo, intente de nuevo\n");
			}
		break;
		case 3:
			if(!ll_len(listaLibros)||!ll_len(listaEditoriales)){
				printf("Faltan cargar archivos...");
				break;
			}
			else{
				Controller_OrdenarPor(listaLibros);
			}
		break;
		case 4:
			if(!ll_len(listaLibros)||(!ll_len(listaEditoriales))){
				printf("No se cargaron libros, imposible generar listas...");
				break;
			}
			else{
				Controller_ListarLibros(listaLibros,listaEditoriales);
			}
		break;
		case 5:
			if(!ll_len(listaLibros)||(!ll_len(listaEditoriales))){
				Controller_FiltrarPor(listaLibros, listaEditoriales);
			}
		break;
		case 6:
			if(!ll_len(listaLibros)||(!ll_len(listaEditoriales))){
				printf("No se cargaron libros, imposible generar listas...");
			}
			else{
				Controller_Mapear(listaLibros, listaEditoriales);
			}
		break;
		}
	}while(opcion!=7);
	printf("\n\n\nMuchas gracias por utilizar este programa que no sirve para mucho que digamos lol...\n");
	return EXIT_SUCCESS;
}
