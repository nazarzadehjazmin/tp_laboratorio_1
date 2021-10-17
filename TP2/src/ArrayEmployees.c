#include "ArrayEmployees.h"


static int generateNewId(void);

static int generateNewId(void)
{
	static int id = 6;
	id++;
	return  id;
}


int initEmployees(Employee* list, int len)
{
	int output = -1;

	if (list != NULL && len > 0)
	{
	  for (int i = 0; i < len; i++)
		{
		  list[i].isEmpty = TRUE;
		}
	  output = 0;
	}
	return output;
}

int findEmptyIndex(Employee *list, int len)
{
	int output = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE)
			{
				output = i;
				break;
			}
		}
	}

	return output;
}

int uploadEmployee(Employee *list, int len, int* id)
{
	int output = -1;
	Employee buffer;

	if(list != NULL && len > 0 && id != NULL && findEmptyIndex(list, len) != -1)
	{
		if(utn_getNombre(buffer.name, "\nNombre del empleado: ", ERROR_MSG, NAME_LEN, QTY_REINTENTO) == 0 &&
		   utn_getNombre(buffer.lastName, "\nApellido del empleado: ", ERROR_MSG, LASTNAME_LEN, QTY_REINTENTO) == 0 &&
		   utn_getFloat(&buffer.salary, "\nSalario: ", ERROR_MSG, 0, QTY_SALARY, QTY_REINTENTO) == 0 &&
		   utn_getNumero(&buffer.sector, "\nSector: ", ERROR_MSG, 0, QTY_SECTOR, QTY_REINTENTO) == 0)
		{
			//*id = 6;
			//(*id)++;
			//buffer.id = (*id);
			buffer.id = generateNewId();
			if(addEmployee(list, len, buffer.id, buffer.name, buffer.lastName, buffer.salary, buffer.sector) == 0)
			{
				output = 0;
			}
		}
	}

	return output;
}

int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	int output = -1;
	int i;

	if(list != NULL && len > 0 && id > 0 && name != NULL && lastName != NULL && salary > 0 && sector > 0)
	{
		i = findEmptyIndex(list, len);
		list[i].id = id;
		strncpy(list[i].name, name, NAME_LEN);
		strncpy(list[i].lastName, lastName, LASTNAME_LEN);
		list[i].salary = salary;
		list[i].sector = sector;
		list[i].isEmpty = FALSE;
		output = 0;

	}

	return output;
}


int findEmployeeById(Employee* list, int len, int id)
{
	int output = -1;

	if(list != NULL && len > 0 && id > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].id == id)
			{
				output = i;
				break;
			}
		}
	}

	return output;
}


int removeEmployee(Employee* list, int len, int id)
{
	int output = -1;
	int index;
	char respuesta;

	if(list != NULL && len > 0)
	{
		printEmployees(list, len);

		if(utn_getNumero(&id, "\nSeleccione el id del empleado a dar de baja: ", ERROR_MSG, 1, QTY_CLIENTE, QTY_REINTENTO) == 0)
		{
			index = findEmployeeById(list, len, id);

			if(index != -1 && list[index].isEmpty == FALSE)
			{
				if(utn_getContinuar(&respuesta, CONTINUAR, ERROR_MSG, QTY_REINTENTO) == 0 &&
				  (respuesta == 'Y' || respuesta == 'y'))
				{
					list[index].isEmpty = TRUE;
					printf("\nEmpleado eliminado exitosamente\n");
					printEmployees(list, len);
				}
				else
				{
					printf(EMPLOYEE_NOTREMOVED);
				}
			}
			else
			{
				printf(ID_NOEXISTE);
				printf(EMPLOYEE_NOTREMOVED);
			}
		}
		output = 0;
	}

	return output;
}


int sortEmployees(Employee* list, int len, int order)
{
	int output = -1;
	int flagSwap = 1;
	int i;
	Employee buffer;
	int nuevoLimite;

	if(list != NULL && len > 0 && (order == UP || order == DOWN))
	{
		nuevoLimite = len-1;
		do{
			flagSwap = 0;
			for(i = 0; i < nuevoLimite ; i++){
				/*if((order == DOWN && strncasecmp(list[i].lastName, list[i+1].lastName,NAME_LEN) < 0) ||
				   (order == UP && strncasecmp(list[i].lastName, list[i+1].lastName,NAME_LEN) > 0) ||
				   (strncasecmp(list[i].lastName, list[i+1].lastName, NAME_LEN) == 0 && list[i].sector > list[i+1].sector))*/
				if((order == UP && (strncasecmp(list[i].lastName, list[i + 1].lastName,NAME_LEN)>0 ||
					(strncasecmp(list[i].lastName, list[i + 1].lastName,NAME_LEN)==0 && list[i].sector > list[i + 1].sector))) ||
					(order == DOWN && (strncasecmp(list[i].lastName, list[i + 1].lastName,NAME_LEN)<0 ||
					(strncasecmp(list[i].lastName, list[i + 1].lastName,NAME_LEN)==0 && list[i].sector < list[i + 1].sector))))
				{
					flagSwap = 1;
					buffer = list[i];
					list[i] = list[i+1];
					list[i+1] = buffer;
				}
			}
			nuevoLimite--;
		}while(flagSwap);
		output = 0;
	}

	return output;
}

int printAEmployee(Employee* list)
{
	int output = -1;

	if(list != NULL && list->isEmpty == FALSE)
	{
		printf("\n%4d %13s %15s %12.2f %10d\n", list->id, list->name, list->lastName, list->salary, list->sector);
		output = 0;
	}

	return output;
}

int printEmployees(Employee* list, int length)
{
	int output = -1;

	if(list != NULL && length > 0)
	{
		printf("\n%4s %13s %15s %12.7s %10s", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
		for(int i = 0; i < length; i++)
		{
			printAEmployee(&list[i]);
		}
		output = 0;
	}

	return output;
}

int ChangeParametersEmployee(Employee* list, int len)
{
	int output = -1;
	int idIngresado;
	int index;
	int option;
	Employee buffer;
	char response;

	if(list != NULL && len > 0)
	{
		printEmployees(list, len);

		if(utn_getNumero(&idIngresado, "\nSeleccione el id del empleado a modificar: ", ERROR_MSG, 1, QTY_CLIENTE, QTY_REINTENTO) == 0)
		{
			index = findEmployeeById(list, len, idIngresado);

			if(index != -1 && list[index].isEmpty == FALSE)
			{
				do
				{
					if(utn_getNumero(&option, CHANGE_MENU, ERROR_MSG, 1, 5, QTY_REINTENTO) == 0)
					{
						switch(option)
						{
							case 1:
								if(utn_getNombre(buffer.name, "\nNuevo nombre: ", ERROR_MSG, NAME_LEN, QTY_REINTENTO) == 0)
								{
									if(utn_getContinuar(&response, CONTINUAR, ERROR_MSG, QTY_REINTENTO) == 0 &&
									  (response == 'Y' || response == 'y'))
									{
										strncpy(list[index].name, buffer.name, NAME_LEN);
										printf("\nEl nombre ha sido modificado exitosamente");
									}
									else
									{
										printf("\nEl nombre no ha sido modificado");
									}
								}
								break;
							case 2:
								if(utn_getNombre(buffer.lastName, "\nNuevo apellido: ", ERROR_MSG, NAME_LEN, QTY_REINTENTO) == 0)
								{
									if(utn_getContinuar(&response, CONTINUAR, ERROR_MSG, QTY_REINTENTO) == 0 &&
									  (response == 'Y' || response == 'y'))
									{
										strncpy(list[index].lastName, buffer.lastName, LASTNAME_LEN);
										printf("\nEl apellido ha sido modificado exitosamente");
									}
									else
									{
										printf("\nEl apellido no ha sido modificado");
									}
								}
								break;
							case 3:
								if(utn_getFloat(&buffer.salary, "\nNuevo salario: ", ERROR_MSG, 1, QTY_SALARY, QTY_REINTENTO) == 0)
								{
									if(utn_getContinuar(&response, CONTINUAR, ERROR_MSG, QTY_REINTENTO) == 0 &&
									  (response == 'Y' || response == 'y'))
									{
										list[index].salary = buffer.salary;
										printf("\nEl salario ha sido modificado exitosamente");
									}
									else
									{
										printf("\nEl salario no ha sido modificado");
									}
								}
								break;
							case 4:
								if(utn_getNumero(&buffer.sector, "\nNuevo sector: ", ERROR_MSG, 1, QTY_SECTOR, QTY_REINTENTO) == 0)
								{
									if(utn_getContinuar(&response, CONTINUAR, ERROR_MSG, QTY_REINTENTO) == 0 &&
									  (response == 'Y' || response == 'y'))
									{
										list[index].sector = buffer.sector;
										printf("\nEl sector ha sido modificado exitosamente");
									}
									else
									{
										printf("\nEl sector no ha sido modificado");
									}
								}
								break;
						}
					}
				}while(option != 5);
			}
			else
			{
				printf(ID_NOEXISTE);
			}
		}
		output = 0;
	}

	return output;
}

int isEmployeesListEmpty(Employee *list, int len)
{
	int output = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				output = 0;
				break;
			}
		}
	}

	return output;
}

int hardcodearData(Employee* list, int len)
{
	int output = -1;

	if(list != NULL && len > 0)
	{
		addEmployee(list, len, 1, "Juan", "Lopez", 15000, 1);
		addEmployee(list, len, 2, "Pedro", "Gomez", 10000, 2);
		addEmployee(list, len, 3, "Sonia", "Loria", 13000, 3);
		addEmployee(list, len, 4, "Pablo", "Alvarez", 12000, 2);
		addEmployee(list, len, 5, "Sofia", "Sanchez", 19000, 1);
		addEmployee(list, len, 6, "Juan", "Lopez", 17000, 2);

		output = 0;
	}

	return output;
}

int informe_menu(Employee* list, int len)
{
	int output = -1;
	int option;
	float totalSalary;
	float averageSalary;
	int employeeQtyAboveAverageSalary;

	if(list != NULL && len > 0)
	{
		do
		{
			if(utn_getNumero(&option, "\n1-Listado de los empleados ordenados alfabéticamente por Apellido y Sector \n2- Total y promedio de los salarios, y cuántos empleados superan el salario promedio \n3-Volver al menu principal", ERROR_MSG, 1, 3, QTY_REINTENTO) == 0)
			{
				switch(option)
				{
					case 1:
						if(informe_submenu(list, len) == 0)
						{
							printf("\nLista ordenada\n");
						}
						break;
					case 2:
						totalSalary = calculateTotalSalary(list, len);
						if(totalSalary != -1 &&
						   calculateAverageSalary(list, len, &averageSalary) == 0 && calculateEmployeesAboveAverageSalaryQty(list, len, &employeeQtyAboveAverageSalary) == 0)
						{
							printf("\nSalario total: %.2f \nSalario promedio: %.2f \nCantidad de empleados que superan el salario promedio: %d", totalSalary, averageSalary, employeeQtyAboveAverageSalary);
						}


						break;
				}
			}
		}while(option != 3);

		output = 0;
	}

	return output;
}

int informe_submenu(Employee* list, int len)
{
	int output = -1;
	int option;

	if(list != NULL && len > 0)
	{
		do
		{
			if(utn_getNumero(&option, "\n1-Ordenar de forma ascendente \n2-Ordenar de forma descendente \n3-Volver al menu", ERROR_MSG, 1, 3, QTY_REINTENTO) == 0)
			{
				switch(option)
				{
					case 1:
						sortEmployees(list, len, UP);
						break;
					case 2:
						sortEmployees(list, len, DOWN);
						break;
				}
				printEmployees(list, len);
			}
		}while(option != 3);

		output = 0;
	}

	return output;
}

int alta_menu(Employee* list, int len)
{
	int output = -1;
	int option;
	int id;
	static int contadorHardcodeo = 0;

	if(list != NULL && len > 0)
	{
		do
		{
			if(utn_getNumero(&option, "\n1-Hardcodear empleados \n2-Cargar empleado \n3-Volver al menu principal", ERROR_MSG, 1, 3, QTY_REINTENTO) == 0)
			{
				switch(option)
				{
					case 1:
						contadorHardcodeo++;

						if(contadorHardcodeo == 1)
						{
							if(hardcodearData(list, len) == 0)
							{
								printEmployees(list, len);
							}
						}
						else
						{
							printf("\nNo puede volver a hardcodear los datos");
						}

						break;
					case 2:
						if(uploadEmployee(list, len, &id) == 0 &&
						   printEmployees(list, len) == 0)
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
		}while(option!= 3);
		output = 0;
	}

	return output;
}

int calculateTotalSalary(Employee* list, int len)
{
	int output = -1;
	float totalSalary = 0;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				totalSalary += list[i].salary;
			}
		}
		output = totalSalary;
	}
	return output;
}

int calculateAverageSalary(Employee* list, int len, float* averageSalary)
{
	int output = -1;
	float totalSalary;
	int employeeQty;

	if(list != NULL && len > 0)
	{
		totalSalary = calculateTotalSalary(list, len);
		if(totalSalary != -1 && calculateEmployeesQty(list, len, &employeeQty) == 0)
		{
			*averageSalary = totalSalary / employeeQty;
		}
		output = 0;
	}

	return output;
}

int calculateEmployeesQty(Employee* list, int len, int* employeeTotalQty)
{
	int output = -1;
	int employeeQty = 0;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				employeeQty++;
			}
		}

		*employeeTotalQty = employeeQty;
		output = 0;
	}

		return output;
}

int calculateEmployeesAboveAverageSalaryQty(Employee* list, int len, int* employeeQtyAboveAverageSalary)
{
	int output = -1;
	float averageSalary;
	int employeeQty = 0;

	if(list != NULL && len > 0)
	{
		calculateAverageSalary(list, len, &averageSalary);

		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].salary > averageSalary)
			{
				employeeQty++;
			}
		}
		*employeeQtyAboveAverageSalary = employeeQty;
		output = 0;
	}

		return output;
}
