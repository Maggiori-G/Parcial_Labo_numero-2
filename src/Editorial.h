/*
 * Editorial.h
 *
 *  Created on: 25 nov. 2021
 *      Author: Maggiori, Gianni
 */

#ifndef EDITORIAL_H_
#define EDITORIAL_H_
#include "LinkedList.h"
#include "Libros.h"
#include "Input.h"
struct{
	int idEditorial;
	char nombreEditorial[100];
}typedef Editorial;
/// @brief constructor de espacio en memoria de un puntero a editorial
/// @return retorna el puntero a editorial si encontro espacio en memoria o null
Editorial* NuevaEditorial();
/// @brief toma por parametro los datos como string y los introduce en un puntero a editorial usando los setters
/// @param idEditorialStr id de la editorial
/// @param nombreEditorial nombre editorial
/// @return retorna un null si no pudo generar un puntero a editorial en memoria o el puntero creado con los datos introducidos
Editorial* NuevaEditorialParametros(char* idEditorialStr, char* nombreEditorial);
/// @brief Toma el dato que le llega por parametros y se lo asigna a lista.
/// @param lista puntero a la lista
/// @param nombreEditorial
/// @return retorna 0 por default o 1 si pudo hacer el get de id
int E_SetNombreEditorial(Editorial* lista, char* nombreEditorial);
/// @brief Guarda lo que tenga lista dentro del tipo de dato, pasado por parametros.
/// @param lista puntero a la lista
/// @param nombreEditorial
/// @return retorna 0 por default o 1 si pudo hacer el get de id
int E_GetNombreEditorial(Editorial* lista, char* nombreEditorial);
/// @brief Toma el dato que le llega por parametros y se lo asigna a lista.
/// @param lista puntero a la lista
/// @param idEditorial
/// @return retorna 0 por default o 1 si pudo hacer el get de id
int E_SetIdEditorial(Editorial* lista, int idEditorial);
/// @brief Guarda lo que tenga lista dentro del tipo de dato, pasado por parametros.
/// @param lista puntero a la lista
/// @param idEditorial
/// @return retorna 0 por default o 1 si pudo hacer el get de id
int E_GetIdEditorial(Editorial* lista, int* idEditorial);

#endif /* EDITORIAL_H_ */
