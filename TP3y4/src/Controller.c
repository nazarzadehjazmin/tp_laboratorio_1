#include "Controller.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int output = -1;
	FILE* pFile;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			parser_EmployeeFromText(pFile, pArrayListEmployee);
			output = 0;
			printf("Carga de datos en el archivo exitosa\n");
			fclose(pFile);
		}
		else if(ll_isEmpty(pArrayListEmployee) == 0)//tiene elementos
		{
				printf("Se realizó la carga de datos en el archivo en otra oportunidad\n");
				output = -2;
		}
			else
		{
			printf("No se puede abrir el archivo\n");
			output = -3;
		}
	}

    return output;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int output = -1;
	FILE* pFile;


	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "rb");
		if(pFile != NULL)
		{
			parser_EmployeeFromBinary(pFile, pArrayListEmployee);
			output = 0;
			printf("Carga de datos en el archivo exitosa\n");
			fclose(pFile);
		}
		else if(ll_isEmpty(pArrayListEmployee) == 0)
		{
			printf("Se realizó la carga de datos en el archivo en otra oportunidad\n");
			output = -2;
		}
		else
		{
			printf("No se puede abrir el archivo\n");
			output = -3;
		}
	}

    return output;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int output = -1;
	Employee* pEmployee;
	int id;
	char nombre[NAME_LEN];
	int horasTrabajadas;
	int sueldo;
	char continuar;

	if(pArrayListEmployee != NULL)
	{
		if(employee_upload(nombre, &horasTrabajadas, &sueldo, &id) == 0)
		{
			pEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
			if(pEmployee != NULL &&
			   utn_getContinuar(&continuar, CONTINUE_MSG, ERROR_MSG, QTY_REINTENTO) == 0 &&
			   (continuar == 'y' || continuar == 'Y'))
			{
				employee_saveLatestId(id);
				ll_add(pArrayListEmployee, pEmployee);
				printf("Empleado cargado exitosamente\n");
				output = 0;
			}
			else
			{
				employee_delete(pEmployee);
				printf("El empleado no ha sido cargado\n");
			}
		}

	}


    return output;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int output = -1;
	Employee* pEmployee;
	Employee buffer;
	int index;
	int option;
	char continuar;

	if(pArrayListEmployee != NULL &&
	   ll_isEmpty(pArrayListEmployee) == 0 &&
	   controller_ListEmployee(pArrayListEmployee) == 0 &&
	   utn_getNumero(&buffer.id, "Ingrese el id del empleado a modificar: \n", ERROR_MSG, MIN_ID, MAX_ID, 5) == 0)
	{
		index = employee_findId(pArrayListEmployee, &buffer.id);
		if (index != -1)
		{
			pEmployee = (Employee*) ll_get(pArrayListEmployee, index);
			if (pEmployee != NULL)
			{
				do
				{
					if (utn_getNumero(&option, "\nQue desea modificar? \n1-Nombre \n2-Horas trabajadas \n3-Sueldo \n4.Volver al menu principal\n",
							ERROR_MSG, 1, 4, QTY_REINTENTO) == 0)
					{
						switch (option)
						{
							case 1:
								if (utn_getNombre(buffer.nombre, "Nuevo nombre: \n", ERROR_MSG, NAME_LEN, QTY_REINTENTO) == 0 &&
									utn_getContinuar(&continuar, CONTINUE_MSG, ERROR_MSG, QTY_REINTENTO) == 0 &&
									 (continuar == 'y' || continuar == 'Y'))
								{
									employee_setNombre(pEmployee, buffer.nombre);
									printf(EDIT_SUCCESS);
								}
								else
								{
									printf(EDIT_ERROR);
								}

								break;
							case 2:
								if (utn_getNumero(&buffer.horasTrabajadas, "\nNueva cantidad de horas trabajadas: \n", ERROR_MSG, MIN_HSTRABAJADAS, MAX_HSTRABAJADAS, QTY_REINTENTO) == 0 &&
									utn_getContinuar(&continuar, CONTINUE_MSG, ERROR_MSG, QTY_REINTENTO) == 0 &&
									(continuar == 'y' || continuar == 'Y'))
								{
									employee_setHorasTrabajadas(pEmployee, buffer.horasTrabajadas);
									printf(EDIT_SUCCESS);
								}
								else
								{
									printf(EDIT_ERROR);
								}

								break;
							case 3:
								if (utn_getNumero(&buffer.sueldo, "\nNuevo sueldo: ", ERROR_MSG, MIN_SUELDO, MAX_SUELDO, QTY_REINTENTO) == 0 &&
									utn_getContinuar(&continuar, CONTINUE_MSG, ERROR_MSG, QTY_REINTENTO) == 0 &&
									(continuar == 'y' || continuar == 'Y'))
								{
									employee_setSueldo(pEmployee, buffer.sueldo);
									printf(EDIT_SUCCESS);
								}
								else
								{
									printf(EDIT_ERROR);
								}

								break;
						}
					}
				}while (option != 4);
				output = 0;
			}
		}
	}

    return output;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int output = -1;
	int idIngresado;
	int index;
	char continuar;
	Employee* pEmployee;

	if(pArrayListEmployee != NULL &&
	   ll_isEmpty(pArrayListEmployee) == 0)
	{
		controller_ListEmployee(pArrayListEmployee);
	   if(utn_getNumero(&idIngresado, "Ingrese el id a remover: \n", ERROR_MSG, MIN_ID, MAX_ID, QTY_REINTENTO) == 0)
	   {
			index = employee_findId(pArrayListEmployee, &idIngresado);
			pEmployee = (Employee*) ll_get(pArrayListEmployee, index);
			printf("Empleado a eliminar: \n");
			if(employee_printEmployee(pEmployee) == 0 &&
			  utn_getContinuar(&continuar, CONTINUE_MSG, ERROR_MSG, QTY_REINTENTO) == 0 &&
			  (continuar == 'y' || continuar == 'Y'))
			{
				ll_remove(pArrayListEmployee, index);
				employee_delete(pEmployee);
				printf("El empleado ha sido eliminado exitosamente\n");
				output = 0;
			}
		}
		else
		{
			printf("No se ha podido eliminar el empleado\n");
		}
	}

    return output;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int output = -1;
	Employee* pEmployee;
	int len;

	if(pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0)
	{
		len = ll_len(pArrayListEmployee);
		printf("ID - Nombre - HorasTrabajadas - Sueldo\n");
		for(int i = 0; i < len; i++)
		{
			pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			employee_printEmployee(pEmployee);
		}
		output = 0;
	}

    return output;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int output = -1;
	int criteria;
	int order;

	if(pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0 &&
	   utn_getNumero(&criteria, "Criterio de ordenamiento:\n1-Id \n2-Nombre \n3-Horas trabajadas \n4-Sueldo \n5-Volver al menu principal\n", ERROR_MSG, 1, 5, QTY_REINTENTO) == 0)
	{
		do
		{
			if(utn_getNumero(&order, "Orden: \n0-Descendente \n1-Ascendente \n2-Volver al menu principal", ERROR_MSG, 0, 2, QTY_REINTENTO) == 0)
			{
				switch(criteria)
				{
				case 1:
					printf(SORT_MSG);
					ll_sort(pArrayListEmployee, employee_compareById, order);
					break;
				case 2:
					printf(SORT_MSG);
					ll_sort(pArrayListEmployee, employee_compareByName, order);
					break;
				case 3:
					printf(SORT_MSG);
					ll_sort(pArrayListEmployee, employee_compareByWorkedHours, order);
					break;
				case 4:
					printf(SORT_MSG);
					ll_sort(pArrayListEmployee, employee_compareBySalary, order);
					break;
				}
				controller_ListEmployee(pArrayListEmployee);
				printf("\nOrdenamiento exitoso\n\n");
			}
			else
			{
				printf("No se ha podido realizar el ordenamiento\n");
			}
		}
		while(order != 2);

		output = 0;
	}

    return output;
}


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int output = -1;
	FILE* pFile = NULL;
	Employee* pEmpleado;
	int len;
	int id;
	char nombre[NAME_LEN];
	int horasTrabajadas;
	int sueldo;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
			for(int i = 0; i < len; i++)
			{
				pEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
				if(employee_getAllTheGets(pEmpleado, nombre, &horasTrabajadas, &sueldo, &id) == 0)
				{
					fprintf(pFile,"%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
				 }
			}
			printf(SAVE_DATA);
			output = 0;
		}

	}
	fclose(pFile);
    return output;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int output = -1;
	FILE* pFile = NULL;
	Employee* pEmpleado;
	int len;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		pFile = fopen(path, "wb");
		for(int i = 0; i < len; i++)
		{
			pEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
			fwrite(pEmpleado, sizeof(Employee), 1, pFile);
		}
		printf(SAVE_DATA);
		output = 0;
	}
	fclose(pFile);
    return output;
    //ruta para que aparezca => 1, 9, 2, 9
}



