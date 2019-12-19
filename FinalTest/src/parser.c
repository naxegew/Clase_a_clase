/*
 * parser.c
 *
 *  Created on: 11 dic. 2019
 *      Author: igna
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn_lib.h"
#include "LinkedList.h"
#include "entidad.h"
#include "parser.h"
#include "Controller.h"

int parser_EntidadFromText(FILE* pFile, LinkedList *pArrayEntidad)
{
	int retorno=-1,r;
	char idStr[128],intStr[128],floatStr[128],StringStr[128],charStr[128],header[500];
	Entidad* entidad;

	fscanf(pFile,"%[^\n]\n", header);
	printf("\n%s",header);

	    while(!feof(pFile))
	    {
	        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,StringStr,floatStr,intStr);
	        entidad=entidad_newParametros(idStr,StringStr,floatStr,intStr);
	       printf("\n%s %s %s %s",idStr,StringStr,floatStr,intStr);
	        if(r==4)
	        {
	            if(entidad!=NULL)
	            {
	                ll_add(pArrayEntidad,entidad);
	                retorno=0;
	            }
	        }
	    }




	return retorno;
}
int parser_EntidadFromBinary(FILE* pFile, LinkedList *pArrayListEntidad)
{
	int retorno =-1;
	int len;
	int i;
	int r;
	Entidad* entidad;
	int id;
	int cInt;
	float cFloat;
	char cChar;
	char cString[300];


	if(pFile!=NULL && pArrayListEntidad != NULL)
	{
		do
		{
		entidad = entidad_new();
		r=fread(entidad,sizeof(Entidad),1,pFile);
			if(r==1)
			{
			ll_add(pArrayListEntidad,entidad);
			}
		}while(!feof(pFile));

		len = ll_len(pArrayListEntidad);
		printf("se leyo del archivo...");
		for(i=0;i<len;i++)
		{
			entidad = ll_get(pArrayListEntidad,i);
			printf("\n|%d |%d||%.2f||%c||%s|",entidad->id,entidad->cInt,entidad->cFloat,entidad->cChar,entidad->cString);
		}
	}
	return retorno;
}
