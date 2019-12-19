/*
 ============================================================================
 Name        : FinalTest.c
 Author      : Ignacio Martin Canay
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
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

int main(void) {

LinkedList* listaEntidad = ll_newLinkedList();
LinkedList* listaEntidadFiltrada= ll_newLinkedList();;
int option;
char archivo[128];

do{
mainMenu(&option);

switch(option){
case 1:
	//cargar

	/*
	//cargar ingresando nombre de archivo por consola
	printf("introduzca el nombre del archivo");
	scanf("%s", archivo);
	controller_loadFromText(archivo,listaEntidad);
*/
	//controller_loadFromText("datos_Fin.csv",listaEntidad); //Cargar de Archivo de Texto
	controller_loadFromBinary("el bin",listaEntidad); // Cargar de Archivo Binario
	break;
case 2:

	//ordenar segun tipo

	controller_sortEntidad(listaEntidad);

	break;
case 3:
	controller_ListEntidad(listaEntidad);
	//imprimir
	break;
case 4:
	//funcion map
	ll_map(listaEntidad,fnCriterio_map);

	break;
case 5:

	//filtro

	controller_filtrarLista(listaEntidad, listaEntidadFiltrada);



	break;
case 6:
	//guardar
	controller_saveAsBinary("el bin" ,listaEntidad); // Guardar Binario
	//controller_saveAsText("archivo.txt",listaEntidad);
	break;
case 7:
	//salir
	break;
}
}while(option!=7);





	return EXIT_SUCCESS;
}
