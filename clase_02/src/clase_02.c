/*
 ============================================================================
 Name        : clase_02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//ejercicio pidiendo si quiere seguir ingresando datos
int calculoMaximoyMinimo(int cantidadNumerosSolicitados, int *resultadoMaximo, int *resultadoMinimo);
int main (void){
	char respuesta;
	int numeroIngresado;


	do
	{
	printf("\ningrese un numero:");
	scanf("%d", &numeroIngresado);

	printf("\ndesea seguir ingresando numeros?(1(si) o 0(no))");
	scanf("%d", &respuesta);


		while(respuesta !=  1 && respuesta != 0)
		{
		printf("\nError ingrese s o n:");
		scanf("%d", &respuesta);
		}
	printf("respuesta correcta");

	}while(respuesta == 1);
return 0;
}
int calculoMaximoyMinimo(int *pcantidadNumerosSolicitados, int *resultadoMaximo, int *resultadoMinimo)
{

}






/* ejercicio con for, pidiendo cantidad primero
int calculoMaximoyMinimo(int cantidadNumerosSolicitados, int *resultadoMaximo, int *resultadoMinimo);

int main(void) {

	int cantidadNumerosSolicitados;
	int resultadoMaximo;
	int resultadoMinimo;
	// #define CANTIT 5

	printf("\ningrese cantidad de datos: ");
	scanf("%d", &cantidadNumerosSolicitados);

	calculoMaximoyMinimo(cantidadNumerosSolicitados, &resultadoMaximo, &resultadoMinimo);


	printf("\n el numero maximo es: %d ", resultadoMaximo);
	printf("\n el numero minimo es: %d", resultadoMinimo);
	return 0;
}
int calculoMaximoyMinimo(int cantidadNumerosSolicitados, int *resultadoMaximo, int *resultadoMinimo)
{
	int flag = 0;
	int numeroIngresado;
	int i;
	int maximo;
	int minimo;

	for(i = cantidadNumerosSolicitados; i >=1; i--)
	{

		printf("\ningrese un numero: ");
		__fpurge(stdin);
		scanf("%d", &numeroIngresado);
		if(flag == 0)
		{
			*resultadoMaximo = numeroIngresado;
			*resultadoMinimo = numeroIngresado;
			flag=1;

		}
		if(numeroIngresado>maximo)
		{
			*resultadoMaximo = numeroIngresado;
			printf("nuevo maximo!");

		}
		if(numeroIngresado<minimo)
		{
			*resultadoMinimo = numeroIngresado;
			printf("nuevo minimo!");
		}


	}
	return 0;
}

 */
