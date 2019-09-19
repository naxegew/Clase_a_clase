/*
 * utn.h
 *
 *  Created on: 29 ago. 2019
 *      Author: alumno
 */

#ifndef UTN_H_
#define UTN_H_

struct S_Persona
{
	char nombre[100];
	int dni;
	int edad;
	int isEmpty;
};
typedef struct S_Persona Persona;



int getNumero(int *pvalor, int max, int min, int reintentos);
int getNumeroProfe(int *pNumero, int rangoMax, int rangoMin, int reintentos);
int getArrayInt(int *pArray,int limite,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos);
int getStr(char charStr[], int length, char *pMensaje);
int getInt(	int *pResultado,char *pMensaje,char *pMensajeError,
			int minimo,int maximo,int reintentos);

int printArrayInt(int *pArray , int limite);
int getArrayInt(	int *pArray,int limite,char *pMensaje,char *pMensajeError,
					int minimo,int maximo,int reintentos);
int getMaxArray(int *pArray, int limite, int *maximo, int *iMaximo);
int getMinArray(int *pArray, int limite, int *minimo, int *iMinimo);
int getIntFromString(char Array[], int length, int *respuesta);
int isArrayOfNumbers(char Array[], int length);
int isArrayOfNumbersNeg(char Array[], int length);
#endif /* UTN_H_ */
