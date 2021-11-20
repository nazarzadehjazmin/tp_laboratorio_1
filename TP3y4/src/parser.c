#include "parser.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int output = -1;
	char bufferId[CHAR_QTY];
	char bufferNombre[CHAR_QTY];
	char bufferHsTrabajadas[CHAR_QTY];
	char bufferSueldo[CHAR_QTY];
	Employee* pEmployee = NULL;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferHsTrabajadas, bufferSueldo);
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferHsTrabajadas, bufferSueldo) == 4)
			{
				pEmployee = employee_newParametrosTxt(bufferId, bufferNombre, bufferHsTrabajadas, bufferSueldo);
				if(pEmployee != NULL)
				{
					output = ll_add(pArrayListEmployee, pEmployee);
					//0 = ok
				}
			}
			/*else
			{
				break;
			}*/

		}while(!feof(pFile));

	}

	fclose(pFile);
    return output;
}


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int output = -1;
	Employee* pEmployee;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			pEmployee = employee_new();
			if(pEmployee != NULL &&
			   fread(pEmployee, sizeof(Employee), 1, pFile) == 1 &&
			   ll_add(pArrayListEmployee, pEmployee) == 0)
			{
				output = 0;
			}
			else
			{
				employee_delete(pEmployee);
				//break;
			}
		}while(!feof(pFile));

	}
	fclose(pFile);
	return output;
}
