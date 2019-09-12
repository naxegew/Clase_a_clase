/*
 ============================================================================
 Name        : clase_04.c
 Author      : Ignacio Canay
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#define QTY_EDADES 5
int getMaxArray (int *pArray, int limite, int *maximo, int *iMaximo);
int getMinArray(int *pArray, int limite, int *minimo, int *iMinimo);

int main(void) {
	int maximo, iMaximo;

	int edades[QTY_EDADES] = {10, 20, 50, 40, 30};

	getMaxArray(&edades,QTY_EDADES, &maximo, &iMaximo);

	printf("\nel numero maximo es: %d", maximo);
	printf("\ny la posicion en el array es %d", iMaximo);



	return EXIT_SUCCESS;
}
int getMinArray(int *pArray, int limite, int *minimo, int *iMinimo)
{
	int i;
	int aiMinimo;
	int retorno =-1;
	int aMinimo;

	if(pArray != NULL && limite > 0)
	{
		for(i=0; i<limite;i++)
		{
			if(i==0)
			{
		 aMinimo =pArray[i];
		 aiMinimo = i;
		// printf("entro");

			}
			if(pArray[i]>aMinimo)
			{
			 aMinimo =pArray[i];
			 aiMinimo=i;
			}
		}
	}
	*minimo=aMinimo;
	*iMinimo = aiMinimo;

	retorno =0;
	return retorno;
}
//funcion max minimo promedio suma


