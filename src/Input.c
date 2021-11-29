/*
 * Input.c
 *
 *  Created on: 25 nov. 2021
 *      Author: Maggiori, Gianni
 */
#include "Input.h"

int PedirOpcion(char mensaje[], int min, int max){
	int opcion;
	printf(mensaje);
	fflush(stdin);
	scanf("%i",&opcion);
	while(opcion<min||opcion>max){
		printf("ERROR\n");
		printf(mensaje);
		fflush(stdin);
		scanf("%i",&opcion);
	}
	return opcion;
}
void ImprimirOpciones(){
	printf("\n");
	printf("\t\t\t\t\t\t\t===================================\n");
	printf("\t\t\t\t\t\t\tAPLICACION PARA EL MANEJO DE LIBROS\n");
	printf("\t\t\t\t\t\t\t===================================\n");
	printf("=====\n");
	printf("MENU:\n");
	printf("=====\n");
	printf("\n1-Cargar la lista de libros");
	printf("\n2-Cargar la lista de editoriales");
	printf("\n3-Ordenar las editoriales");
	printf("\n4-Mostrar la lista de libros");
	printf("\n5-Imprimir la lista de libros por EDITORIAL");
	printf("\n6-Generar descuentos");
	printf("\n7-Salir");
	}
int PedirEntero(char mensaje[])
{
	char numero[1000];
	int entero;
	int largo;
	int resultado;
	int i;
	do
	{
		printf(mensaje);
		fflush(stdin);
		gets(numero);
		largo=strlen(numero);
		for(i=0;i<largo;i++)
		{
			if((i==0&&numero[i]=='-')||(isdigit(numero[i])==1))
			{
				resultado=1;
			}
			else
			{
				resultado=0;
				printf("\nERROR\n");
				break;
			}
		}
	}while(resultado==0);
	entero=atoi(numero);
	return entero;
}
float PedirFlotante(char mensaje[], char mensajeError[])
{
	char numero[10000];
	int largo;
	int contadorDePuntos=0;
	float flotante;
	int resultado;
	int i;
	do
	{
		printf(mensaje);
		fflush(stdin);
		gets(numero);
		largo=strlen(numero);
		for(i=0;i<largo;i++)
		{
			if((isdigit(numero[i])==1)||(i==0&&numero[i]=='-')||(i!=0&&numero[i]=='.'))
			{
				resultado=1;
				if(numero[i]=='.')
				{
					contadorDePuntos++;
					if(contadorDePuntos>1)
					{
						resultado=0;
						break;
					}
				}
			}
			else
			{
				resultado=0;
				printf(mensajeError);
				break;
			}
		}
	}while(resultado==0);
	flotante=atof(numero);
	return flotante;
}
int Pedir(char cadena[], char mensaje[],int tam)
{
	printf(mensaje);
	fflush(stdin);
	fgets(cadena,tam,stdin);
	cadena[strlen(cadena)-1]='\0';
	return 0;
}
int ValidarCadenaNombres(char cadena[])
{
	int retorno=1;
	int largo;
	largo=strlen(cadena);
	for(int i=0;i<largo;i++)
	{
		if((i==0&&cadena[i]==32))
		{
			retorno=0;
			break;
		}
	}
	if(retorno==1)
	{
		strlwr(cadena);
	}
	return retorno;
}
int PedirTexto(char cadena[], char mensaje[], int tam)
{
	int retorno=-1;
	do
	{
		Pedir(cadena, mensaje, tam);
		if(ValidarCadenaNombres(cadena)==1)
		{
			retorno=1;
		}
		else
		{
			printf("\nERROR\n");
		}
	}while(retorno==-1);
	return retorno;
}
int PedirArchivo(char archivo[],char mensaje[]){
	int retorno=0;
//	int largo;
	printf(mensaje);
	fflush(stdin);
	scanf("%s",archivo);
//	largo=strlen(archivo);
//	for(int i=0;i<largo;i++){
//		if(i==0&&archivo[0]==32){
//			printf("\nERROR\nReingrese el nombre del archivo que desea cargar\n\n");
//			fflush(stdin);
//			scanf("%s",archivo);
//			break;
//		}
//		else{
//			retorno=1;
//			break;
//		}
//	}
	return retorno;
}
