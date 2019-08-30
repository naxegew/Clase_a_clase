/*
 ============================================================================
 Name        : clase_03.c
 Author      : Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"



int main(void) {
	int numeroIngresado;
	char* t = "el numero ingresado es ";




if(getNumero(&numeroIngresado,120, 1, 5)==0)
{
printf("\n %s%d", t, numeroIngresado);
}
	printf("Supero el numero maximo de intentos");

	return 0;

}



