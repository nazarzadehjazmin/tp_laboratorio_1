#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "getNumero.h"
#include "getFloat.h"
#include "getDescripcion.h"

/** \brief To indicate that all position in the array are empty,
 * 		this function put the flag (isEmpty) in TRUE in all
 * 		position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int initEmployees(Employee* list, int len)
{
	int i;
	int outcome = -1;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (list != NULL && len > 0)
	{
		//RECORRO TODO EL ARRAY
		for (i = 0; i < len; i++)
		{
			//SET ESTADO DE "LIBRE"
			list[i].isEmpty = FREE;
		}
		outcome = 0;
	}
	return outcome;
}


/** \brief add in a existing list of employees the values received as parameters
 * 			in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name char*
 * \param lastName char*
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
 *			free space] - (0) if Ok
 *
 */

int addEmployee(Employee* list, int len, int id, char* name,char* lastName, float salary, int sector)
{
	int outcome = 0;
	Employee auxEmployee;
	int emptyIndex;
	char auxName[CHARACTERS_QTY];
	char auxLastName[CHARACTERS_QTY];
	float auxSalary;
	int auxSector;

	//BUSCO ESPACIO EN ARRAY
	emptyIndex = findEmptyIndex(list, len);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (emptyIndex >= 0) {
		//PIDO DATOS - CARGO Gen AUXILIAR
		if(utn_getDescripcion(auxName, "Name: \n", "Error\n", 2, CHARACTERS_QTY) == 0 &&
				utn_getDescripcion(auxLastName, "Last name: \n", "Error\n", 2, CHARACTERS_QTY) == 0 &&
				utn_getFlotante(&auxSalary, "Salary: \n", "Error\n", 1.1, 100000.1, 2) == 0 &&
				utn_getNumero(&auxSector, "Sector: \n", "Error\n", 1, 1000, 2) == 0)
		{
			id = createNewId();
			auxEmployee.isEmpty = TAKEN;


			name = auxName;
			lastName = auxLastName;
			salary = auxSalary;
			sector = auxSector;

			list[emptyIndex] = auxEmployee;
		}

		outcome = 1;
	}
	else
	{
		printf("There is not an empty index, we can not add another employee\n");
	}

	return outcome;
}


/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
 *			pointer received or employee not found]
 *
 */

int findEmployeeById(Employee* list, int len, int id)
{
	int outcome = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (list != NULL && len > 0)
	{
		//RECORRO TODO EL ARRAY
		for (i = 0; i < len; i++)
		{
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (list[i].id == id && list[i].isEmpty == TAKEN)
			{
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				outcome = i;
				break;
			}
		}
	}

		return outcome;
}


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
 * 			find a employee] - (0) if Ok
 *
 */

int removeEmployee(Employee* list, int len, int id)
{
	//modificado
	int outcome = 0;
	int idToChange;
	int indexFound;
	int flag = 0;

	//LISTO TODOS LOS Gen
	if(printEmployees(list, len) == 0)
	{
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Gen PARA DAR DE BAJA
	if(flag)
	{
		//PIDO ID A DAR DE BAJA
		if(utn_getNumero(&idToChange, "Enter ID to remove\n", "Error, try again\n", 1, EMPLOYEE_QTY, 1) == 0)
		{
			indexFound = findEmployeeById(list, len, idToChange);
		}

		if(indexFound >= 0)
		{
		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
			list[indexFound].isEmpty = REMOVE;
		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
			outcome = 1;
		}
	}

	return outcome;
}


/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int sortEmployees(Employee* list, int len, int order)
{
	return 0;
}


/** \brief Prints the content of just one employee
 *
 * \param list Employee*
 * \param length int
 * \return void
 *
 */

void printOneEmployee(Employee oneEmployee)
{
	//AGREGAR LOS CAMPOS FALTANTES
	printf("ID %d - NAME: %s - LAST NAME: %s - SALARY: %.2f - SECTOR %d", oneEmployee.id, oneEmployee.name, oneEmployee.lastName, oneEmployee.salary, oneEmployee.sector);
}


/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */

int printEmployees(Employee* list, int length)
{
	//ARREGLAR
	int i;
	int outcome = 0;
	int quanty = 0;

	//CABECERA
	printf("\n\t> EMPLOYEES LIST\n");
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (list != NULL && length > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < length; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (list[i].isEmpty == TAKEN) {
				//MUESTRO UN SOLO Gen
				printOneEmployee(list[i]);
				//CONTADOR DE Gen
				quanty++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Gen PARA MOSTRAR (ARRAY SIN ALTAS)
	if (quanty > 0) {
		outcome = 1;
	}

	return outcome;
}


/**
 * \brief Creates a new id for a new client,
 * \param void
 * \return int Return value of the new id
 *
 */

int createNewId(void)
{
	static int id = 0; // NO ES LOCAL DE LA FUNCION
	id++;

	return id;
}


/**
 * \brief Searches for an empty index in the array, checks if the flag(isEmpty) is true or not and saves the first index found.
 * \param list Employee* Pointer to array of clients
 * \param len int Array length
 * \return int Return value of the first empty index found or -1 if it's an error (invalid length, NULL pointer or if there isn't more available space)
 *
 */
int findEmptyIndex(Employee* list, int len)
{
	int outcome = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty)
			{
				outcome = i;
				break;
			}
		}
	}
	return outcome;
}


//////////////////////////////////////////////////////////////////////////////////////////////////
//                              SETS & GETS

/*
int employee_setName(Employee* this, char* name)
{
	int outcome = -1;

	if(this != NULL && name != NULL && isValidNombre(name) )
	{
		strcpy(this->name, name);
		outcome = 0;
	}
	return outcome;
}

char* empleado_getNombre(Employee* this, int* flagError)
{
	*flagError = -1;
	char* auxName= NULL;

	if(this != NULL && flagError != NULL )
	{
		auxName = this->name;
		*flagError = 0;
	}
	return auxName;
}
*/


