/*
 * Input.h
 *
 *  Created on: 25 nov. 2021
 *      Author: Maggiori, Gianni
 */

#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
int PedirEntero(char mensaje[]);
float PedirFlotante(char mensaje[], char mensajeError[]);
int PedirTexto(char cadena[], char mensaje[], int tam);
int ValidarCadenaNombres(char cadena[]);
int Pedir(char cadena[], char mensaje[],int tam);
int PedirOpcion(char mensaje[], int min, int max);
void ImprimirOpciones();
int PedirArchivo(char archivo[],char mensaje[]);
#endif /* INPUT_H_ */
