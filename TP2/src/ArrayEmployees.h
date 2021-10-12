#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Inputs.h"

#define TRUE 1
#define FALSE 0
#define ERROR_MSG "Error, reingrese el dato"
#define QTY_EMPLOYEE 1000
#define NAME_LEN 51
#define LASTNAME_LEN 51
#define QTY_REINTENTO 5
#define CHANGE_MENU "\nQue desea modificar?\n1-Nombre \n2-Apellido \n3-Salario \n4-Sector \n5-Volver al menu principal"
#define QTY_SECTOR 100
#define ID_NOEXISTE "\nEl id ingresado no existe"
#define CONTINUAR "Desea continuar?"

//buscar precio mas caro en la fx de mostrar producto mas caro


typedef struct
{
 int id;
 char name[NAME_LEN];
 char lastName[LASTNAME_LEN];
 float salary;
 int sector;
 int isEmpty;
} Employee;


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);


/** \brief Searching an empty index
 * \param list Employee* list Pointer to array of employees
 * \param int len Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - return the empty id if Ok
 *
 */
int findEmptyIndex(Employee* list, int len);


/** \brief Asks the employee's data
 * \param list Employee* list Pointer to array of employees
 * \param int len Array length
 * \param int* id Pointer to id
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - return the empty id if Ok
 *
 */
int uploadEmployee(Employee *list, int len, int* id);


/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);


/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len, int id);


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);


/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);


/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int 0 success, -1 error
 *
 */
int printEmployees(Employee* list, int length);


/** \brief print the content of one employee
 *
 * \param list Employee
 * \param length int
 * \return int 0 success, -1 error
 *
 */
int printAEmployee(Employee* list);


/** \brief changes the different parameters of one employee
 *
 * \param list Employee
 * \param len int
 * \return int 0 success, -1 error
 *
 */
int ChangeParametersEmployee(Employee* list, int len);


/** \brief identifies if there are any employees
 *
 * \param list Employee
 * \param len int
 * \return int 0 success, -1 error
 *
 */
int isEmployeesListEmpty(Employee *list, int len);


int hardcodearData(Employee* list, int len);

#endif
