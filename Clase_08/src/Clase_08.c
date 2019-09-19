/*
 ============================================================================
 Name        : clase_07.c
 Author      : Ignacio Canay
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define LENGTH 100

int alta(Persona lista[],int length,char *pMensajeNombre, char *pMensajeEdad,char *pError, char *pMensajeDni);
int menu(int *pOpcion);
int main(void)
{

int i=0;
int opcion;
Persona lista[5];

do{
	menu(&opcion);
	if(opcion==1)
	{
		alta(lista,2,"ingrese nombre","ingrese edad", "error","ingrese dni");
	}
	if(opcion==4)
	{
	for(i=0;i<2;i++)
	{
	printf("\nnombre: %s \tdni: %d \tedad: %d", lista[i].nombre, lista[i].dni, lista[i].edad);
	}
	}

}while(opcion!=6);




	///buscar espacio libre en la lista y variable para saber si esta vacia la posicion de la lista
	//datos a ingresar en la lista: nombre, edad, dni, isempty
	// el menu tiene que dejar: alta baja modificar listar, ordenar

}

int menu(int *pOpcion)
{
	int retorno=-1;
	int opcion;

	do{
		printf("\t***AGENDA DE CONTACTOS***"
				"\nIngrese el numero de la opcion deseada");
		printf("\n1.-Alta de contacto"
				"\n2.-Baja de contacto"
				"\n3.-Modificar contacto"
				"\n4.-Listar contactos"
				"\n5.-Ordenar Contactos"
				"\n6.-Salir");
		scanf("%d",&opcion);


		switch(opcion)
			{
			case 1:
				opcion =1;
				 break;
			case 2:
				opcion =2;
				break;
			case 3:
				opcion =3;
				break;
			case 4:
				opcion=4;
				break;
			case 5:
				opcion=5;
				break;
			case 6:
				opcion=6;
				printf("saliendo");

				break;
			default:
				printf("Eliga una opcion entre 1 y 5");
				break;
			}
				}while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4 && opcion!=5 && opcion!=6);

	*pOpcion=opcion;
	return retorno;


}

int alta(Persona lista[],int length,char *pMensajeNombre, char *pMensajeEdad,char *pError, char *pMensajeDni)
{
	int i;

	int edad;
	int dni;
	int retorno=-1;

	for(i=0;i<2;i++)
	{
	getStr(lista[i].nombre,length,pMensajeNombre);
	getInt(&edad,pMensajeEdad,pError,1,120,3);
	lista[i].edad=edad;
	getInt(&dni,pMensajeDni,pError,5000000,50000000,3);
	lista[i].dni=dni;
	lista[i].isEmpty=1;
	}
	retorno=0;
	return retorno;
}

int baja(Persona lista[], int length, char *pMensajeBaja)
{
int i=0;
int id;
printf("A quien desea dar de baja?");
for(i=0;i<length;i++)
{
if(lista[i].isEmpty==0)
{
//saltarse este elemento y no mostrarlo abajo
}
printf("id:%d nombre: %s"i+1,lista[i].nombre);
}
printf("ingrese un id");
scanf("%d",id);
id--;
lista[id].isEmpty=0;
return 0;
}

int isEmpty(Persona lista[], int length, int valor)
{
int i=0;
	for(i=0;1<length;i++)
	{
		if(lista[i].isEmpty==valor)
		{
		return i;
		}

	}

return 0;
}

