/*
 * lib_tp2.c
 *
 *  Created on: 26 sep. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "lib_tp2.h"

int getStr(char charStr[], int length, char *pMensaje)
{

char buffer[100];
printf("%s", pMensaje);
__fpurge(stdin);
fgets(buffer, sizeof(buffer),stdin);

strncpy(charStr,buffer,sizeof(buffer));
	return 0;
}
int getFloat(float *pResultado,char *pMensaje,char *pMensajeError,float minimo,float maximo,int reintentos)
{
	int retorno = -1;
	float buffer;
	do
	{
		printf("%s",pMensaje);
		__fpurge(stdin);
		if(scanf("%f",&buffer)==1 && buffer >= minimo && buffer <= maximo)
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

int loadNewEmployee(char name[], char lastName[],int length,float *salary, int *sector,
		char *pMsgName, char *pMsgLastName, char *pMsgSalary, char *pMsgErrorSalary,
		float minSalary, float maxSalary, int maxtrySalary,char *pMsgSector,
		char *pMsgErrorSector, int minSector, int maxSector, int maxtrySector)
{
	int retorno =-1;
	getStr(name,length,pMsgName);
	getStr(lastName,length,pMsgLastName);
	getFloat(salary, pMsgSalary, pMsgErrorSalary, minSalary, maxSalary, maxtrySalary);
	getInt(sector, pMsgSector, pMsgErrorSector, minSector, maxSector, maxtrySector);


	return retorno;
}
