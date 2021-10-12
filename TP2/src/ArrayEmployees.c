#include "ArrayEmployees.h"

static int generateNewId(void);

static int generateNewId(void)
{
	static int id = 5;
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
		   utn_getFloat(&buffer.salary, "\nSalario: ", ERROR_MSG, 0, 1000000.5, QTY_REINTENTO) == 0 &&
		   utn_getNumero(&buffer.sector, "\nSector: ", ERROR_MSG, 0, 400, QTY_REINTENTO) == 0)
		{
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

		if(utn_getNumero(&id, "\nSeleccione el id del empleado a dar de baja: ", ERROR_MSG, 1, QTY_EMPLOYEE, QTY_REINTENTO) == 0)
		{
			index = findEmployeeById(list, len, id);

			if(index != -1 && list[index].isEmpty == FALSE)
			{
				if(utn_getContinuar(&respuesta, CONTINUAR, ERROR_MSG, QTY_REINTENTO) == 0 &&
				  (respuesta == 'Y' || respuesta == 'y'))
				{
					list[index].isEmpty = TRUE;
				}
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


int sortEmployees(Employee* list, int len, int order)
{
	int output = -1;

	if(list != NULL && len > 0)
	{

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

		if(utn_getNumero(&idIngresado, "\nSeleccione el id del empleado a modificar: ", ERROR_MSG, 1, QTY_EMPLOYEE, QTY_REINTENTO) == 0)
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
								if(utn_getNombre(buffer.name, "\nNuevo nombre: ", ERROR_MSG, NAME_LEN, QTY_REINTENTO) == 0)
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
								if(utn_getNombre(buffer.name, "\nNuevo nombre: ", ERROR_MSG, NAME_LEN, QTY_REINTENTO) == 0)
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
								if(utn_getNombre(buffer.name, "\nNuevo nombre: ", ERROR_MSG, NAME_LEN, QTY_REINTENTO) == 0)
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
		addEmployee(list, len, 2, "Pedro", "Gomez", 13000, 2);
		addEmployee(list, len, 3, "Sonia", "Loria", 13000, 3);
		addEmployee(list, len, 4, "Pablo", "Alvarez", 13000, 2);
		addEmployee(list, len, 5, "Sofia", "Sanchez", 13000, 1);

		output = 0;
	}

	return output;
}
