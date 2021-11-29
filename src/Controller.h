/*
 * Controller.h
 *
 *  Created on: 26 nov. 2021
 *      Author: tanii
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "Editorial.h"
#include "Libros.h"
#include "Input.h"
#include "Parser.h"
#include "LinkedList.h"
/// @brief Abre un archivo y llama al parser que convierte los datos del archivo y los suma al array
/// de libros
/// @param lista puntero a la LL de libros
/// @return return 0 por default y 1 si logro leer y parsear el archivo y agregarlo al array
int Controller_CargarArchivoDeLibros(LinkedList* lista);
/// @brief Abre un archivo y llama al parser que convierte los datos del archivo y los suma al array de editoriales
/// @param lista puntero a la LL de editoriales
/// @return return 0 por default y 1 si logro leer y parsear el archivo y agregarlo al array
int Controller_CargarArchivoDeEditoriales(LinkedList* lista);
/// @brief busca en la lista de editoriales un id pasado por parametro
/// @param listaEditoriales puntero a la lista donde tiene que buscar
/// @param id el id que quiero que busque
/// @return returna un NULL si no lo encontro, y retorna el puntero a una editorial si lo encontro
Editorial* Controller_BuscarEditorial(LinkedList* listaEditoriales, int id);
/// @brief Imprime en pantalla la lista de libros con cada uno sus respectivas editoriales
/// @param listaLibros puntero a la LL de libros
/// @param listaEditoriales puntero a la LL de editoriales
/// @return retorna 0 por default y 1 si esta bien y pudo imprimir sin problema
int Controller_ListarLibros(LinkedList* listaLibros,LinkedList* listaEditoriales);
/// @brief Ordena la lista de libros segun la opcion de ordenamiento que ingrese el usuario
/// @param listaLibros puntero a la LL de libros
/// @return retorna 0 por default y 1 si la lista no es un NULL y pudo ordenar
int Controller_OrdenarPor(LinkedList* listaLibros);
/// @brief Guarda una LL en un nuevo archivo y le pide al usuario que ingrese el nombre del archivo que desea guardar
/// @param lista el puntero LL
/// @return retorna 0 por default y 1 si pudo guardar la LL recibida
int Controller_GuardarLista(LinkedList* lista);
/// @brief Filtra la lista de libros por editoriales y devuelve una nueva LL filtrada segun elija el usuario
/// @param listaLibros puntero a la LL de libros
/// @return retorna NULL por default o una nueva LL creada con el filter
LinkedList* Controller_FiltrarPor(LinkedList* listaLibros, LinkedList* listaEditoriales);
/// @brief Crea, mapea y guarda una nueva linkedlist en relacion a ll_map
///
/// @param listaLibros puntero a la lista de libros
/// @param listaEditoriales puntero a la lista de editoriales
/// @return 0 por default, y 1 si logro crear, mapear y guardar la nueva linkedlist modificada
int Controller_Mapear(LinkedList* listaLibros, LinkedList* listaEditoriales);

#endif /* CONTROLLER_H_ */
