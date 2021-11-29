/*
 * Parser.h
 *
 *  Created on: 26 nov. 2021
 *      Author: tanii
 */

#ifndef PARSER_H_
#define PARSER_H_
#include "Input.h"
#include "LinkedList.h"
#include "Libros.h"
#include "Editorial.h"
/// @brief parsea los datos de un archivo y los guarda en una LL de libros
/// @param archivo es de donde debe leer los datos, lo ingresa el usuario por consola
/// @param listaLibros puntero a la LL de libros
/// @return 0 por default o 1 si pudo parsear los datos
int Parser_LibrosDelArchivo(FILE* archivo , LinkedList* listaLibros);
/// @brief parsea los datos de un archivo y los guarda en una LL de editoriales
/// @param archivo es de donde debe leer los datos, lo ingresa el usuario por consola
/// @param listaEditoriales puntero a la LL de editoriales
/// @return 0 por default o 1 si pudo parsear los datos
int Parser_EditorialesDelArchivo(FILE* archivo, LinkedList* listaEditoriales);

#endif /* PARSER_H_ */
