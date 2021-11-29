/*
 * Libros.h
 *
 *  Created on: 25 nov. 2021
 *      Author: Maggiori, Gianni
 */

#ifndef LIBROS_H_
#define LIBROS_H_
#include "Controller.h"
struct{
	int id;
	char titulo[150];
	char autor[150];
	float precio;
	int idEditorial;
}typedef Libro;
/// @brief constructor de espacio en memoria de un puntero a libro
/// @return retorna el puntero a libro si encontro espacio en memoria o null
Libro* NuevoLibro();
/// @brief toma por parametro los datos como string y los introduce en un puntero a libro usando los setters
/// @param idStr id
/// @param tituloStr titulo
/// @param autorStr autor
/// @param precioStr precio
/// @param idEditorialStr id de la editorial
/// @return retorna un null si no pudo generar un puntero a libro en memoria o el puntero creado con los datos introducidos
Libro* NuevoLibroParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* idEditorialStr);
/// @brief Toma el dato que le llega por parametros y se lo asigna a lista.
/// @param lista puntero a la lista
/// @param id id
/// @return retorna 0 por default o 1 si pudo setear la id
int L_SetIdLibros(Libro* lista, int id);
/// @brief Guarda lo que tenga lista dentro del tipo de dato, pasado por parametros.
/// @param lista lista puntero a la lista
/// @param id id
/// @return retorna 0 por default o 1 si pudo hacer el get de id
int L_GetIdLibros(Libro* lista, int* id);
/// @brief Toma el dato que le llega por parametros y se lo asigna a lista.
/// @param lista puntero a la lista
/// @param titulo titulo
/// @return retorna 0 por default o 1 si pudo setear el titulo
int L_SetTituloLibros(Libro* lista, char* titulo);
/// @brief Guarda lo que tenga lista dentro del tipo de dato, pasado por parametros.
/// @param lista lista puntero a la lista
/// @param titulo titulo
/// @return retorna 0 por default o 1 si pudo hacer el get de titulo
int L_GetTituloLibros(Libro*lista ,char* titulo);
/// @brief Toma el dato que le llega por parametros y se lo asigna a lista.
/// @param lista puntero a la lista
/// @param autor autor
/// @return retorna 0 por default o 1 si pudo setear el autor
int L_SetAutorLibros(Libro* lista, char* autor);
/// @brief Guarda lo que tenga lista dentro del tipo de dato, pasado por parametros.
/// @param lista lista puntero a la lista
/// @param autor autor
/// @return retorna 0 por default o 1 si pudo hacer el get de autor
int L_GetAutorLibros(Libro* lista, char* autor);
/// @brief Toma el dato que le llega por parametros y se lo asigna a lista.
/// @param lista puntero a la lista
/// @param precio precio
/// @return retorna 0 por default o 1 si pudo setear el precio
int L_SetPrecioLibros(Libro* lista, float precio);
/// @brief Guarda lo que tenga lista dentro del tipo de dato, pasado por parametros.
/// @param lista lista puntero a la lista
/// @param precio precio
/// @return retorna 0 por default o 1 si pudo hacer el get de precio
int L_GetPrecioLibros(Libro* lista, float* precio);
/// @brief Toma el dato que le llega por parametros y se lo asigna a lista.
/// @param lista puntero a la lista
/// @param idEditorial idEditorial
/// @return retorna 0 por default o 1 si pudo setear la id de editorial
int L_SetIdEditorial(Libro* lista, int idEditorial);
/// @brief Guarda lo que tenga lista dentro del tipo de dato, pasado por parametros.
/// @param lista lista puntero a la lista
/// @param idEditorial idEditorial
/// @return retorna 0 por default o 1 si pudo hacer el get de id de editorial
int L_GetIdEditorial(Libro* lista, int* idEditorial);
/// @brief funcion parametro que ordena los libros por id en la funcion ll_sort
/// @param pPrimerLibro pPrimerLibro puntero a void del primer elemento
/// @param pSegundoLibro Libro puntero a void del segundo elemento
/// @return
int L_OrdenarLibrosPorID(void* pPrimerLibro, void* pSegundoLibro);
/// @brief funcion parametro que ordena los libros por titulo en la funcion ll_sort
/// @param pPrimerLibro pPrimerLibro puntero a void del primer elemento
/// @param pSegundoLibro Libro puntero a void del segundo elemento
/// @return
int L_OrdenarLibrosPorTitulo(void* pPrimerLibro, void* pSegundoLibro);
/// @brief funcion parametro que ordena los libros por autor en la funcion ll_sort
/// @param primerLibro pPrimerLibro puntero a void del primer elemento
/// @param segundoLibro Libro puntero a void del segundo elemento
/// @return
int L_OrdenarLibrosPorAutor(void* primerLibro, void* segundoLibro);
/// @brief funcion parametro que ordena los libros por precio en la funcion ll_sort
/// @param pPrimer Libro puntero a void del primer elemento
/// @param pSegundo Libro puntero a void del segundo elemento
/// @return
int L_OrdenarLibrosPorPrecio(void* pPrimerLibro, void* pSegundoLibro);
/// @brief funcion parametro para ll_filter, filtra la lista de libros por editorial planeta
/// @param pElemento puntero a void
/// @return 0 por default o 1 si es igual la id de editorial con la editorial que se desea filtrar
int L_FiltrarPorEditorialPlaneta(void* pElemento);
/// @brief funcion parametro para ll_filter, filtra la lista de libros por editorial siglo xxi
/// @param pElemento puntero a void
/// @return 0 por default o 1 si es igual la id de editorial con la editorial que se desea filtrar
int L_FiltrarPorEditorialSigloXXI(void* pElemento);
/// @brief funcion parametro para ll_filter, filtra la lista de libros por editorial pearson
/// @param pElemento puntero a void
/// @return 0 por default o 1 si es igual la id de editorial con la editorial que se desea filtrar
int L_FiltrarPorEditorialPearson(void* pElemento);
/// @brief funcion parametro para ll_filter, filtra la lista de libros por editorial minotauro
/// @param pElemento puntero a void
/// @return 0 por default o 1 si es igual la id de editorial con la editorial que se desea filtrar
int L_FiltrarPorEditorialMinotauro(void* pElemento);
/// @brief funcion parametro para ll_filter, filtra la lista de libros por editorial salamandra
/// @param pElemento puntero a void
/// @return 0 por default o 1 si es igual la id de editorial con la editorial que se desea filtrar
int L_FiltrarPorEditorialSalamandra(void* pElemento);
/// @brief funcion parametro para ll_filter, filtra la lista de libros por editorial penguin books
/// @param pElemento puntero a void
/// @return 0 por default o 1 si es igual la id de editorial con la editorial que se desea filtrar
int L_FiltrarPorEditorialPenguin(void* pElemento);
/// @brief funcion parametro para ll_map, genera descuentos para distintas editoriales
/// @param pElemento puntero a void
/// @return null por default o un puntero a void de un auxiliar libro
void* L_GenerarDescuentos(void* pElemento);
#endif /* LIBROS_H_ */
