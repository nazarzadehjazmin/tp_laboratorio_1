//JAZMIN NAZARZADEH
//TP2

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define EMPTY_LIST_CLI "\nNo hay empleados en la lista. \nIngrese a la opcion 1 para dar de alta empleados, luego, reingrese la opcion seleccionada\n"

int main(void) {
	setbuf(stdout, NULL);
	Employee employeeList[QTY_CLIENTE];
	int menuOption;
	int id = 0;

	if(initEmployees(employeeList, QTY_CLIENTE) == 0)
	{
		do
		{
			if(utn_getNumero(&menuOption, "\nMenu principal:\n1-Alta \n2-Modificar \n3-Baja \n4-Informar \n5-Salir", ERROR_MSG_L, 1, 5, QTY_REINTENTO) == 0)
			{
				switch(menuOption)
				{
					case 1:
						alta_menuLocalidad(employeeList, QTY_CLIENTE);
						break;
					case 2:
						if(isEmployeesListEmpty(employeeList, QTY_CLIENTE) == 0 &&
						   ChangeParametersEmployee(employeeList, QTY_CLIENTE) == 0)
						{
							printEmployees(employeeList, QTY_CLIENTE);
						}
						else
						{
							printf(EMPTY_LIST_CLI);
						}
						break;
					case 3:
						if(isEmployeesListEmpty(employeeList, QTY_CLIENTE) == 0)
						{
							removeEmployee(employeeList, QTY_CLIENTE, id);
						}
						else
						{
							printf(EMPTY_LIST_CLI);
						}
						break;
					case 4:

						 if(isEmployeesListEmpty(employeeList, QTY_CLIENTE) == 0)
						{
							 informe_menu(employeeList, QTY_CLIENTE);
						}
						else
						{
							printf(EMPTY_LIST_CLI);
						}
						break;
				}
			}
		}while(menuOption != 5);
	}

	return EXIT_SUCCESS;
}
