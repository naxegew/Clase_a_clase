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
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define LENGTH 100

struct S_Persona
{
	char nombre[40];
	int dni;
	int edad;
};
typedef struct S_Persona Persona;


int main(void)
{


Persona lista[LENGTH];
int edad,dni;
char nombre[50];
getInt(&edad, "ingrese edad", 1,100,5);
getInt(&dni, "ingrese dni", 1,50000000,5);
//getString(nombre, "ingrese nombre"...) funcion que me tome un string

lista[0].edad=edad;
strncpy(lista[0].nombre,nombre,50);
	return EXIT_SUCCESS;
}

int addPersona(Persona lista[],int length)
{
char nombre[50];
	printf("ingrese el nombre de la persona: ");
	fgets(nombre,length, stdin);
Persona lista[];

	return 0;
}



