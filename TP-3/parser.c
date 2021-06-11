#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "Employee.h"
#include "Validaciones.h"

//PROBAR

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param FILE* pFile Puntero al archivo
 * \param pArrayListEmployee LinkedList* Puntero al array de empleados
 * \return int (el proximo id)
 *
 */

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int output = -1;
	char bufferId[CHAR_QTY];
	char bufferNombre[CHAR_QTY];
	char bufferHsTrabajadas[CHAR_QTY];
	char bufferSueldo[CHAR_QTY];
	int flag = 0;
	int proximoId;
	Employee* pEmployee;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[\n]\n", bufferId, bufferNombre, bufferHsTrabajadas, bufferSueldo) == 4)
			{
				if(flag != 0)
				{
					//printf("%s-%s-%s-%s\n", bufferId, bufferNombre, bufferHsTrabajadas, bufferSueldo);
					pEmployee = employee_newParametros(bufferId, bufferNombre, bufferHsTrabajadas, bufferSueldo);
					if(pEmployee != NULL)
					{
						if(isValidNumberInt(bufferId) == 1 && atoi(bufferId) >= proximoId)
						{
							proximoId = atoi(bufferId)+1;
						}

						ll_add(pArrayListEmployee, pEmployee);
						output = proximoId;
					}
				}

			}
			else
			{
				break;
			}
			flag = 1;
		}while(!feof(pFile));

	}


    return output;
}

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	if(pFile != NULL && pArrayListEmployee != NULL)
	{

	}
    return 1;
}
