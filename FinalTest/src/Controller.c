#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "entidad.h"
#include "Controller.h"
#include "parser.h"
#include "utn_lib.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEntidad) //path archivo, lista a cargar
{

	FILE* pFile;

	pFile = fopen(path,"r");

		if(pFile==NULL)
		{
			printf("El archivo no existe");
			 exit(EXIT_FAILURE);
		}
		ll_clear(pArrayListEntidad);
		parser_EntidadFromText(pFile,pArrayListEntidad);


    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEntidad)
{
	int retorno =-1;
	FILE* pFile;

if(path != NULL && pArrayListEntidad != NULL)
{
	pFile = fopen(path,"rb");

	if(pFile != NULL)
	{
	parser_EntidadFromBinary(pFile,pArrayListEntidad);
	retorno =1;
	}else
	{
		printf("el archivo no pudo abrirse");
	}

}

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEntidad(LinkedList* pArrayListEntidad)
{
	char cChar,cString[128];
	int cInt,id;
	float cFloat;
	Entidad* entidad;

	getStr(cString,128,"ingrese dato tipo string");
	getInt(&cInt, "Ingrese dato tipo int", "Error en el ingreso de datos vuelva a intentar",1,200,3);
	getFloat(&cFloat,1, 200,"ingrese dato tipo float","Error en el ingreso de datos",3);
	entidad_getNewId(pArrayListEntidad,&id);
	getChar(&cChar,"ingrese dato tipo char");
	printf("\n%d | %d  | %.2f  | %c| %s | ", id,cInt,cFloat,cChar,cString);

	entidad = entidad_new();
	entidad_setId(entidad,id);
	entidad_setInt(entidad,cInt);
	entidad_setFloat(entidad,cFloat);
	entidad_setString(entidad,cString);
	entidad_setChar(entidad,cChar);

	ll_add(pArrayListEntidad,entidad);
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEntidad(LinkedList* pArrayListEntidad)
{
	Entidad* entidad;
	int option;
	int buffer;
	float bufferF;
	char axString[128],axChar;
	entidad=entidad_findById(pArrayListEntidad);
	entidad_print(entidad);
	 modificarEntidadMenu(&option);
	 switch(option)
	 {
	 case 1:
		 getInt(&buffer,"Ingrese el int a cambair" ,"Error vuelva a intentar",0,
		 		200,3);
		 entidad_setInt(entidad,buffer);

		 break;
	 case 2:
		 getFloat(&bufferF,0,300,"Ingrese el float","Error vuelva a intentar", 3);
		 entidad_setFloat(entidad,bufferF);

	 		 break;
	 case 3:
		 getChar(&axChar,"ingrese el char");
		 entidad_setChar(entidad,axChar);
	 		 break;
	 case 4:
		 getStr(axString,128,"ingrese el String a cambiar");
		 entidad_setString(entidad,axString);
		 return 1;
	 		 break;
	 default:
	 		 break;

	 }


    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEntidad(LinkedList* pArrayListEntidad)
{
	Entidad* entidad;
	Entidad* axEntidad;
	int len,i;
	char SoN;
	entidad=entidad_findById(pArrayListEntidad);

	len=ll_len(pArrayListEntidad);
	do{
	getChar(&SoN,"\ndesea borrar a este id? (s o n): ");
	}while(SoN!='s' && SoN!='n');

	if(SoN=='s')
	{
		for(i=0;i<len;i++)
		{
			axEntidad = ll_get(pArrayListEntidad,i);

			if(axEntidad == entidad)
			{
				ll_remove(pArrayListEntidad,i);
				printf("\nEl id fue removido con exito.");
				return 0;
			}
		}
	}


    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEntidad(LinkedList* pArrayListEntidad)
{
	int i,len;
	int id,cInt;
	float cFloat;
	char cString[128],cChar;
	Entidad* entidad;

	len =ll_len(pArrayListEntidad);
	for(i=0;i<len;i++)
	{
		entidad =ll_get(pArrayListEntidad,i);
		entidad_getId(entidad,&id);
		entidad_getInt(entidad,&cInt);
		entidad_getFloat(entidad,&cFloat);
		entidad_getString(entidad,cString);
		entidad_getChar(entidad,&cChar);
		printf("\n%d | %s  -\n| %.2f|->",id,cString,cFloat);


		if(cInt==1)
		{
			printf("DESKTOP |");
		}else if(cInt==2)
		{
			printf("LAPTOP |");
		}
		if(cChar=='n')
		{
			printf("NO HAY OFERTA");

		}else if(cChar=='s')
		{
			printf("SIN DATOS");
		}else if(cChar=='d')
		{
			printf("50%% de DESCUENTO");
		}
	}

    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEntidad(LinkedList* pArrayListEntidad)
{

printf("primer printf\n");
	int r = ll_sort(pArrayListEntidad,entidad_criterio,1);
	printf("r vale = %d\n",r);
	controller_ListEntidad(pArrayListEntidad);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEntidad)
{
	FILE* pFile;
	int id,cInt,i;
	float cFloat;
	char cString[128], cChar;
	Entidad* entidad;
	int len;


	if(path != NULL && pArrayListEntidad != NULL)
	{
		pFile = fopen(path,"w+");

			if(pFile==NULL)
			{
				printf("El archivo no existe");
				 exit(EXIT_FAILURE);
			}else
			{
				len = ll_len(pArrayListEntidad);
				fprintf(pFile,"id,int,float,char,string\n");
				for(i=0;i<len;i++)
				{
					entidad =(Entidad*)ll_get(pArrayListEntidad,i);
					entidad_getId(entidad,&id);
					entidad_getString(entidad,cString);
					entidad_getInt(entidad,&cInt);
					entidad_getFloat(entidad,&cFloat);
					entidad_getChar(entidad,&cChar);
					fprintf(pFile,"%d,%d,%.2f,%c,%s\n",id,cInt,cFloat,cChar,cString);
				}
			}

	}


		fclose(pFile);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEntidad)
{
	FILE* pFile;
	int len = ll_len(pArrayListEntidad);
	int i,cantidadEscrita;
	int id,cInt;
	float cFloat;
	char cString[128], cChar;
	Entidad* entidad;
	Entidad entidadAuxiliar;


		pFile = fopen(path,"wb");

			if(pFile==NULL)
			{
				printf("El archivo no existe");
				 exit(EXIT_FAILURE);
			}

			for(i=0;i<len;i++)
			{

				entidad =ll_get(pArrayListEntidad,i);
				entidadAuxiliar.id= entidad->id;
				entidadAuxiliar.cInt=entidad->cInt;
				entidadAuxiliar.cFloat=entidad->cFloat;
				entidadAuxiliar.cChar = entidad->cChar;
				strncpy(entidadAuxiliar.cString,entidad->cString,128);


				/*entidad =(Entidad*)ll_get(pArrayListEntidad,i);
				entidad_getId(entidad,&id);
				entidad_getString(entidad,cString);
				entidad_getInt(entidad,&cInt);
				entidad_getFloat(entidad,&cFloat);
				entidad_getChar(entidad,&cChar);

				entidad_setId(entidadAuxiliar,id);
				entidad_setString(entidadAuxiliar,cString);
				entidad_setInt(entidadAuxiliar,cInt);
				entidad_setFloat(entidadAuxiliar,cFloat);
				entidad_setChar(entidadAuxiliar,cChar);
				*/

					printf("\nse escribio %d, veces",i);

			cantidadEscrita=fwrite(&entidadAuxiliar,sizeof(Entidad),1,pFile);
				if(cantidadEscrita<1)
				{
				printf("error al escribir el archivo .bin");
				}
			}

			fclose(pFile);

    return 1;
}

int controller_filtrarLista(LinkedList* pArrayListEntidad, LinkedList* listaEntidadFiltrada)
{
	int retorno = -1;

	listaEntidadFiltrada  = ll_filter(pArrayListEntidad,fnCriterio_Filtrar,1);
	controller_ListEntidad(listaEntidadFiltrada);
	controller_saveAsText("lista filtrada.txt",listaEntidadFiltrada);

	retorno=1;

	return retorno;
}





