/*
 * utn.c
 *
 *  Created on: 29 ago. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdlib.h>

int getNumeroProfe(int *pNumero, int rangoMax, int rangoMin, int reintentos)
{
int numero, i;
int retorno= -1; //cargo retorno con error
		//pedido
		printf("Ingrese un numero:");
		scanf("%d", &numero);
		for(i=0;i<reintentos; i++)
		{
			if(numero>=rangoMin && numero<=rangoMax)
			{
				*pNumero = numero;
				retorno=0;
				break;
			}
			else
				printf("naah esta mal");
		}
		return retorno;
}



int getNumero(int *pnumeroIngresado, int max, int min, int reintentos)
{
	int retorno = -1;
	int numeroIngresado;
	int intentoSuperado=0;
	printf("\ningrese un numero: ");
	scanf("%d", &numeroIngresado);

	while (numeroIngresado<min || numeroIngresado>max)
	{
		printf("\nnumero fuera de rango, ingrese numero: ");
		scanf("%d", &numeroIngresado);
	reintentos--;
		if(reintentos ==0)
		{
			intentoSuperado=1;
			break;
		}
	}
	if(intentoSuperado==1)
		{
		*pnumeroIngresado=0;
		return retorno;
		}
	*pnumeroIngresado=numeroIngresado;
	retorno=0;
	return retorno;
}

