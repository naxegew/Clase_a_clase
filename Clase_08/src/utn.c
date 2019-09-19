/*
 * utn.c
 *
 *  Created on: 29 ago. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

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
int getStr(char charStr[], int length, char *pMensaje)
{

char buffer[100];
printf("%s", pMensaje);
__fpurge(stdin);
fgets(buffer, sizeof(buffer),stdin);

strncpy(charStr,buffer,sizeof(buffer));
	return 0;
}

int getInt(	int *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int buffer;
	do
	{
		printf("%s",pMensaje);
		__fpurge(stdin);
		if(scanf("%d",&buffer)==1 && buffer >= minimo && buffer <= maximo)
		{
			*pResultado = buffer;
			retorno = 0;
			break;
		}
		printf("%s",pMensajeError);
		reintentos--;
	}while(reintentos >= 0);
	return retorno;
}
int printArrayInt(int *pArray , int limite)
{
	int retorno = -1;
	int i;
	printf("\nDEBUG\n");
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			printf("\n\t%i",pArray[i]);
		}
		retorno = 0;
	}
	return retorno;
}
int getArrayInt(	int *pArray,
					int limite,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos)
{
	int retorno = -1;
	int buffer;
	int i=0;
	char respuesta;
	printf("\nDEBUG\n");
	if(pArray != NULL && limite > 0)
	{
		do
		{

			if(	getInt(	&buffer,
						pMensaje,
						pMensajeError,
						minimo,
						maximo,
						reintentos) == 0)
			{
				pArray[i] = buffer;
				i++;
				if(i == limite)
				{
					break;
				}
			}

			printf("Continuar (s/n)? \n");
			__fpurge(stdin); // fflush(stdin)
			scanf("%c",&respuesta);
		}while(respuesta != 'n');
		retorno = i;
	}
	return retorno;
}
int getMaxArray(int *pArray, int limite, int *maximo, int *iMaximo)
{
	int i;
	int aiMaximo;
	int retorno =-1;
	int aMaximo;

	if(pArray != NULL && limite > 0)
	{
		for(i=0; i<limite;i++)
		{
			if(i==0)
			{
		 aMaximo =pArray[i];
		 aiMaximo = i;
		// printf("entro");

			}
			if(pArray[i]>aMaximo)
			{
			 aMaximo =pArray[i];
			 aiMaximo=i;
			}
		}
	}
	*maximo=aMaximo;
	*iMaximo = aiMaximo;

	retorno =0;
	return retorno;
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
int getIntFromString(char Array[], int length, int *respuesta)
{
int retorno = -1;
	printf("ingrese un numero: ");
	fgets(Array,length, stdin);
	length =strlen(Array);
	if(isArrayOfNumbers(Array, length)==-1)
	{
		printf("Ingreso algo que no es un numero");
		return retorno;
	}else
	{
	*respuesta=atoi(Array);
	}
	return 0;
}
int isArrayOfNumbers(char Array[], int length)
{
	int retorno = 0;
	int i;

	for(i=0;i<length-1;i++)
	{
		if(Array[i]<'0' || Array[i]>'9')
		{
			if(i==0 && Array[i]=='+')
			{
				continue;
			}

			retorno =-1;
			break;
		}
		retorno=0;
		break;
	}

	return retorno;
}

int getIntNegFromString(char Array[], int length, int *respuesta)
{
int retorno = -1;
	printf("ingrese un numero: ");
	fgets(Array,length, stdin);
	length =strlen(Array);
	if(isArrayOfNumbersNeg(Array, length)==-1)
	{
		printf("Ingreso algo que no es un numero");
		return retorno;
	}else
	{
	*respuesta=atoi(Array);
	}
	return 0;
}
int isArrayOfNumbersNeg(char Array[], int length)
{
	int retorno = 0;
	int i;

	for(i=0;i<length-1;i++)
	{
		if(Array[i]<'0' || Array[i]>'9')
		{
			if(i==0 && Array[i]=='-')
			{
				continue;
			}
		}
		retorno=0;
		break;
	}

	return retorno;
}
