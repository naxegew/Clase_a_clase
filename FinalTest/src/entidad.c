/*
 * entidad.c
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
#include "Controller.h"
#include "entidad.h"

Entidad* entidad_new() {
	Entidad *entidad;
	entidad = (Entidad*) malloc(sizeof(Entidad));
	if (entidad == NULL) {
		printf("no hay memoria");
	}

	return entidad;
}

Entidad* entidad_newParametros(char *idStr, char *cStringStr,
		char *cFloatStr, char *cIntStr) {
	Entidad *entidad;
	int axId, axcIntStr;
	char axcChar = 'n';
	float axcFloatStr;

	entidad = (Entidad*) malloc(sizeof(Entidad));
	if (entidad == NULL) {
		printf("no hay memoria");
	}
	//conversiones
	axId = atoi(idStr);
	axcIntStr = atoi(cIntStr);
	axcFloatStr = atof(cFloatStr);

	//sets
	entidad_setId(entidad, axId);
	entidad_setString(entidad, cStringStr); //set Tipo String
	entidad_setInt(entidad, axcIntStr); //set Tipo Int
	entidad_setFloat(entidad, axcFloatStr); // set Tipo Float
	entidad_setChar(entidad,axcChar); //set Tipo char

	return entidad;
}
int entidad_setId(Entidad *this, int id)
{
	int retorno = -1;

	if (this != NULL && id > 0) {
		this->id = id;
		retorno = 0;
	}

	return retorno;
}
int entidad_setString(Entidad *this,char *cString)
{
	int retorno = -1;

	if (cString != NULL && strlen(cString) > 0) {
	strncpy(this->cString, cString, strlen(cString));
	retorno = 0;

	}

	return retorno;

}
int entidad_setInt(Entidad *this,int cInt)
{
	int retorno = -1;

	if (this != NULL && cInt > 0) {
		this->cInt = cInt;
		retorno = 0;
	}

	return retorno;
}
int entidad_setFloat(Entidad *this,float cFloat)
{
	int retorno = -1;

	if (this != NULL && cFloat > 0) {
		this->cFloat = cFloat;
		retorno = 0;

	}

	return retorno;
}

int entidad_setChar(Entidad *this, char cChar)
{
	int retorno =-1;
	if(this != NULL){
		this->cChar = cChar;
		retorno = 0;
	}
	return retorno;
}

int entidad_getNewId(LinkedList* pArrayListEntidad, int *id)
{
	int retorno = -1;
	int axId;

	axId = ll_len(pArrayListEntidad)+1;

	*id=axId;

	return retorno;
}

Entidad* entidad_findById(LinkedList* pArrayListEntidad)
{
	Entidad* retorno = NULL;
	Entidad* pEntidad;
	int i,id;
	int len;
	len=ll_len(pArrayListEntidad);
	printf("\nel largo de la lista es: %d", len);

	getInt(&id,"\nIngrese el Id a Buscar","\nerror ingreso un numero de id invalido",0,len+1,3);

	for(i=0;i<len;i++)
	{
		pEntidad=ll_get(pArrayListEntidad, i);
		if(pEntidad->id == id)
		{

			retorno = pEntidad;
		}
	}

	return retorno;
}
int entidad_print(Entidad *this)
{
	int retorno =-1;
	printf("\n| id  |\t int \t|float| char | string ");
	printf("\n|%4d| %d\t |%.2f\t| %c || %s |", this->id,this->cInt,this->cFloat, this->cChar,this->cString);


	return retorno;

}
int modificarEntidadMenu(int *option)
{
	int retorno = -1;
	int buffer;
	printf("\nQue desea hacer con este empleado?");
	printf("\n1.-Modificar int");
	printf("\n2.-Modificar float.");
	printf("\n3.-Modificar char.");
	printf("\n4.-Modificar String.");
	printf("\n5.-Salir.");
	getInt(&buffer, "\nIngrese la opcion deseada.", "\nOpcion incorrecta.", 1, 5,3);

	*option = buffer;
	return retorno;
}
int entidad_criterio(void* var1,void* var2)
{

	Entidad* entidad1 = (Entidad*)var1;
	Entidad* entidad2 = (Entidad*)var2;
	int tipo1, tipo2;
	int retorno=0;

	entidad_getInt(entidad1,&tipo1);
	entidad_getInt(entidad2,&tipo2);

if(tipo1>tipo2)
{
	retorno =-1;
}else if(tipo1<tipo2)
{
	retorno =1;
}

	return retorno;
}
int entidadList_init(LinkedList* pArrayListEmployee)
{
	return ll_clear(pArrayListEmployee);
}
int fnCriterio_Filtrar(void *pElement)
{
	Entidad *entidad = (Entidad*) pElement;

	int retorno = 0;
	 int datoCriterio;
	entidad_getInt(entidad,&datoCriterio);

		if(datoCriterio==1)
		{

			retorno =1;
		}else
		{
		 retorno=-1;
		}

	return retorno;
}

int entidad_getId(Entidad* this,int *id)
{
	int retorno = -1;
	if (this != NULL && id != NULL) {
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}
int entidad_getInt(Entidad* this, int* cInt)
{
	int retorno = -1;
	if (this != NULL && cInt != NULL) {
		*cInt = this->cInt;
		retorno = 0;
	}

	return retorno;
}
int entidad_getFloat(Entidad* this, float* cFloat)
{
	int retorno = -1;
	if (this != NULL && cFloat != NULL) {
		*cFloat = this->cFloat;
		retorno = 0;
	}

	return retorno;
}
int entidad_getChar(Entidad* this, char* cChar)
{
	int retorno = -1;
	if (this != NULL && cChar != NULL) {
		*cChar = this->cChar;
		retorno = 0;
	}

	return retorno;
}
int entidad_getString(Entidad* this, char* cString)
{
	int retorno = -1;

	if (this != NULL && cString != NULL) {
		strcpy(cString, this->cString);
		retorno = 0;
	}

	return retorno;
}

int fnCriterio_map(Entidad* this)
{
	int retorno =-1;
	int dato;
	float precio;
	if(this != NULL)
	{
		entidad_getInt(this,&dato);
		entidad_getFloat(this,&precio);
		if(dato==2)
		{
			entidad_setChar(this,'s');
			retorno=1;
		}else if(dato==1 && precio >20000)
		{
			entidad_setChar(this,'d');
			retorno=1;
		}

	}
	return retorno;

}
