#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

#define ELEMENTS 3

int main(void) {
	setbuf(stdout, NULL);
	int r;
	Employee arrayEmployees[ELEMENTS];
	int index;
	int id;
	char name[CHARACTERS_QTY];
	char lastName[CHARACTERS_QTY];
	float salary;
	int sector;


	r = initEmployees(arrayEmployees, ELEMENTS);
	if(r == 0){
		printf("init ok\n");
	}

	addEmployee(arrayEmployees, ELEMENTS, id, name, lastName, salary,sector);

	index = findEmployeeById(arrayEmployees, ELEMENTS, 9);
	if(index >= 0)
	{
		printf("findEmployee ok");
	}

	removeEmployee(arrayEmployees, ELEMENTS, id);
	return EXIT_SUCCESS;
}
