//JAZMIN NAZARZADEH
//TP2

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define EMPTY_LIST "\nNo hay empleados en la lista. \nIngrese a la opcion 1 para dar de alta empleados, luego, reingrese la opcion seleccionada\n"

int main(void) {
	setbuf(stdout, NULL);
	Employee employeeList[QTY_EMPLOYEE];
	int menuOption;
	int id = 0;

	if(initEmployees(employeeList, QTY_EMPLOYEE) == 0)
	{
		do
		{
			if(utn_getNumero(&menuOption, "\nMenu principal:\n1-Alta \n2-Modificar \n3-Baja \n4-Informar \n5-Salir", ERROR_MSG, 1, 5, QTY_REINTENTO) == 0)
			{
				switch(menuOption)
				{
					case 1:
						alta_menu(employeeList, QTY_EMPLOYEE);
						break;
					case 2:
						if(isEmployeesListEmpty(employeeList, QTY_EMPLOYEE) == 0 &&
						   ChangeParametersEmployee(employeeList, QTY_EMPLOYEE) == 0)
						{
							printEmployees(employeeList, QTY_EMPLOYEE);
						}
						else
						{
							printf(EMPTY_LIST);
						}
						break;
					case 3:
						if(isEmployeesListEmpty(employeeList, QTY_EMPLOYEE) == 0)
						{
							removeEmployee(employeeList, QTY_EMPLOYEE, id);
						}
						else
						{
							printf(EMPTY_LIST);
						}
						break;
					case 4:

						 if(isEmployeesListEmpty(employeeList, QTY_EMPLOYEE) == 0)
						{
							 informe_menu(employeeList, QTY_EMPLOYEE);
						}
						else
						{
							printf(EMPTY_LIST);
						}
						break;
				}
			}
		}while(menuOption != 5);
	}

	return EXIT_SUCCESS;
}
