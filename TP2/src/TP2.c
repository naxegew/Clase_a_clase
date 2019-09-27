/*
 ============================================================================
 Name        : TP2.c
 Author      : Ignacio Canay
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "ArrayEmployees.h"
#include "lib_tp2.h"

#define LIMITE 1000
#define LIMSTR 51

int main(void) {
Employee listaEmpleados[LIMITE];
char name[LIMSTR];
char lastName[LIMSTR];
float salary;
int sector;
int id;


loadNewEmployee(name,lastName,LIMSTR,&salary,&sector,"Ingrese Nombre del empleado",
		"Ingrese apellido del empleado","ingrese salario del empleado",
		"El salario debe estar entre $14000 y $55000",14000,55000,5,
		"ingrese el numero del sector","los sectores son del 1 al 5",1,5,5);

addEmployees(listaEmpleados,LIMITE,id,name,lastName,LIMSTR,salary,sector);
printEmployees(listaEmpleados,LIMITE);

	return EXIT_SUCCESS;
}
