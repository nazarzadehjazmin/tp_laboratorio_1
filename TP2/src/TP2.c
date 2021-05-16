#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "getNumero.h"

#define ELEMENTS 3
#define OPTION_MESSAGE "1-Add client \n2-Modify client \n3-Remove client \n4-Report\n"
#define ERROR_MESSAGE "Error, try again\n"

int main(void)
{
	setbuf(stdout, NULL);
	Employee arrayEmployees[ELEMENTS];
	int option;
	int id;
	char name[CHARACTERS_QTY];
	char lastName[CHARACTERS_QTY];
	float salary;
	int sector;


	if(utn_getNumero(&option, OPTION_MESSAGE, ERROR_MESSAGE, 1, 5, 2) == 0)
	{
		switch(option)
		{
			case 1:
				addEmployee(arrayEmployees, ELEMENTS, id, name, lastName, salary, sector);
				break;
			case 2:

				break;
			case 3:
				removeEmployee(arrayEmployees, ELEMENTS, id);
				break;
			case 4:
				break;
		}
	}

	return EXIT_SUCCESS;
}
