/*
 * ArrayEmployees.h
 *
 *  Created on: 26 sep. 2019
 *      Author: alumno
 */


struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;


#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
int addEmployees(Employee list[], int length,int id, char name[], char lastName[],int strLength, float salary, int sector);
int printEmployees(Employee list[], int length);


#endif /* ARRAYEMPLOYEES_H_ */
