/*
 * lib_tp2.h
 *
 *  Created on: 26 sep. 2019
 *      Author: alumno
 */

#ifndef LIB_TP2_H_
#define LIB_TP2_H_



int getStr(char charStr[], int length, char *pMensaje);
int getFloat(float *pResultado,char *pMensaje,char *pMensajeError,float minimo,float maximo,int reintentos);
int getInt(	int *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos);
int loadNewEmployee(char name[], char lastName[],int length,float *salary,
		int *sector,char *pMsgName, char *pMsgLastName,
		char *pMsgSalary, char *pMsgErrorSalary,float minSalary, float maxSalary,
		int maxtrySalary,char *pMsgSector, char *pMsgErrorSector, int minSector,
		int maxSector, int maxtrySector);
#endif /* LIB_TP2_H_ */
