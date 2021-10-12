//JAZMIN NAZARZADEH
//TP2

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define MENU_OPTIONS "\n1-Alta \n2-Modificar \n3-Baja \n4-Informar \n5-Salir"
#define EMPTY_LIST "\nNo hay empleados en la lista. Dé uno de alta con la opcion 1\n"

int main(void) {
	setbuf(stdout, NULL);
	Employee employeeList[QTY_EMPLOYEE];
	int menuOption;
	int id;
	int optionCase1;

	if(initEmployees(employeeList, QTY_EMPLOYEE) == 0)
	{
		do
		{
			if(utn_getNumero(&menuOption, MENU_OPTIONS, ERROR_MSG, 1, 5, QTY_REINTENTO) == 0)
			{
				switch(menuOption)
				{
					case 1:
							do
							{
								if(utn_getNumero(&optionCase1, "\n1-Hardcodear empleados \n2-Cargar empleado \n3-Volver al menu principal", ERROR_MSG, 1, 3, QTY_REINTENTO) == 0)
								{
									switch(optionCase1)
									{
										case 1:
											if(hardcodearData(employeeList, QTY_EMPLOYEE) == 0)
											{
												printEmployees(employeeList, QTY_EMPLOYEE);
											}
											break;
										case 2:
											if(uploadEmployee(employeeList, QTY_EMPLOYEE, &id) == 0 &&
											   printEmployees(employeeList, QTY_EMPLOYEE) == 0)
											{
												printf("\nEmpleado cargado exitosamente");
											}
											else
											{
												printf("\nNo se ha podido cargar el empleado");
											}
											break;
									}
								}
							}while(optionCase1 != 3);


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
							if(removeEmployee(employeeList, QTY_EMPLOYEE, id) == 0)
							{
								printf("\nEmpleado eliminado exitosamente");
							}
							else
							{
								printf("\nEl empleado no se ha podido eliminar");
							}
						}
						else
						{
							printf(EMPTY_LIST);
						}
						break;
					case 4:
						if(isEmployeesListEmpty(employeeList, QTY_EMPLOYEE) == 0)
						{

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
