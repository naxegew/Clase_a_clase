/*
 * entidad.h
 *
 *  Created on: 11 dic. 2019
 *      Author: igna
 */


#ifndef entidad_H_INCLUDED
#define entidad_H_INCLUDED

typedef struct
{
int id;
int cInt;//idtipo
float cFloat;//precio
char cChar;//oferta
char cString[300];//descripcion
}Entidad;



Entidad* entidad_new();
Entidad* entidad_newParametros(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldoStr);

//----------sets-----------
int entidad_setId(Entidad *this, int id);
int entidad_setString(Entidad *this, char *cString);
int entidad_setInt(Entidad *this,int cIntStr);
int entidad_setFloat(Entidad *this,float axcFloat);
int entidad_setChar(Entidad *this, char cChar);
int entidad_getNewId(LinkedList* pArrayListEntidad, int *id);
int entidad_getId(Entidad* this,int* id);
int entidad_getInt(Entidad* this, int* cInt);
int entidad_getFloat(Entidad* this, float* cFloat);
int entidad_getChar(Entidad* this, char* cChar);
int entidad_getString(Entidad* this, char* cString);


//----metodos de entidad
Entidad* entidad_findById(LinkedList* pArrayListEntidad);
int entidad_print(Entidad *this);
int modificarEntidadMenu(int *option);
int entidad_criterio(void* var1,void* var2);
int entidadList_init(LinkedList* pArrayListEmployee);
int fnCriterio_Filtrar(void *pElement);
int fnCriterio_map(Entidad* this);
#endif // entidad_H_INCLUDED
