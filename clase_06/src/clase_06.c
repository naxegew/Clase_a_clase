/*
 ============================================================================
 Name        : clase_06.c
 Author      : Ignacio Canay
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include <stdio_ext.h>

#define CANT_EL 4

int cargarSetDatos(int *aLegajo, char *aSexo, int *aEdad, int *nota1P, int *nota2P, float *aPromedio, int limite);
int mostrarEstudiante(int aLegajo, char aSexo, int aEdad, int aNotaP1, int aNotaP2, float aPromedio);
int mostrarEstudiantes(int *aLegajo, char *aSexo, int *aEdad, int *aNotaP1, int *aNotaP2, float *aPromedio, int limite);

int main(void) {

	int legajo[CANT_EL];
	char sexo[CANT_EL];
	int edad[CANT_EL];
	int nota1P[CANT_EL];
	int nota2P[CANT_EL];
	float promedio[CANT_EL];

	cargarSetDatos(legajo, sexo, edad, nota1P, nota2P, promedio, CANT_EL);
	mostrarEstudiantes(legajo, sexo, edad, nota1P, nota2P, promedio, CANT_EL);
}

int cargarSetDatos(int *aLegajo, char *aSexo, int *aEdad, int *nota1P, int *nota2P, float *aPromedio, int limite)
{
	int i;
	int buffer;
	for( i=0; i<limite; i++)
	{
		if(getInt(&buffer, "+Ingrese el legajo del alumno: ", "Error", 1, 100, 2)==0)
		{
			aLegajo[i]=buffer;
		}else
		{
			aLegajo[i]=0;
		}
		printf("ingrese el sexo:");
		__fpurge(stdin);
		scanf("%c", &aSexo[i]);
		printf("ingrese la edad del alumno: ");
		__fpurge(stdin);
		scanf("%d", &aEdad[i]);
		printf("ingrese la nota del primer parcial del alumno: ");
		__fpurge(stdin);
		scanf("%d", &nota1P[i]);
		printf("ingrese la nota del segundo parcial del alumno: ");
		__fpurge(stdin);
		scanf("%d", &nota2P[i]);
		aPromedio[i] = (((float)nota1P[i]+nota2P[i])/2);



	}
return 0;
}

int mostrarEstudiante(int aLegajo, char aSexo, int aEdad, int aNotaP1, int aNotaP2, float aPromedio)
{

	printf("\n%d	%c	%d	%d	%d	%.2f", aLegajo, aSexo, aEdad, aNotaP1, aNotaP2, aPromedio);

	return 0;
}
int mostrarEstudiantes(int *aLegajo, char *aSexo, int *aEdad, int *aNotaP1, int *aNotaP2, float *aPromedio, int limite)
{
int i;
printf("\nLegajo 	sexo	edad	nota1P	nota2P	promedio ");
for(i=0;i<limite; i++)
{
	mostrarEstudiante(aLegajo[i],aSexo[i], aEdad[i], aNotaP1[i], aNotaP2[i], aPromedio[i]);

}
	return 0;
}



