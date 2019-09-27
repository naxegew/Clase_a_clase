/*
 * ArrayEmployees.c
 *
 *  Created on: 26 sep. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "ArrayEmployees.h" // va aca?

int initEmployees(Employee list[],int length)
{
	int retorno =-1;
	int i;
	if(list!=NULL && length>0)
	{
		for(i=0;i>length;i++)
		{
			list[i].isEmpty =1;
		}
		retorno =0;
	}

	return retorno;
}
int addEmployees(Employee list[], int length,int id, char name[], char lastName[],int strLength, float salary, int sector)
{
int retorno =-1;

strncpy(list[id].name, name,strLength);
strncpy(list[id].lastName,lastName,strLength);
list[id].salary=salary;
list[id].sector=sector;
list[id].isEmpty=0;
return retorno;

}

int printEmployees(Employee list[], int length)
{
	int i;
	for(i=0;i<length;i++)
	{
		printf("id empleado: %d.",list[i].id);
		printf("nombre: %s",list[i].name);
		printf("apellido: %s",list[i].lastName);
		printf("nombre: %.2f",list[i].salary);
		printf("nombre: %d",list[i].sector);
	}

	return 0;
}
