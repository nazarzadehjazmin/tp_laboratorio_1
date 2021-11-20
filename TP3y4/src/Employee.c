#include "Employee.h"

//static int employee_generateNewId(LinkedList* pArrayEmployee);
//static int employee_findMaximumId(LinkedList* pArrayEmployee);

Employee* employee_new(void)
{
	return (Employee*)malloc(sizeof(Employee));
	//calloc te inicializa todos los bytes en 0
}


Employee* employee_newParametrosTxt(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* this = NULL;

	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		this = employee_new();
		if(this != NULL)
		{
			if(employee_setNombre(this, nombreStr) != 0 ||
			   employee_setHorasTrabajadasTxt(this, horasTrabajadasStr) != 0 ||
			   employee_setSueldoTxt(this, sueldoStr) != 0 ||
			   employee_setIdTxt(this, idStr) != 0)
			{
				employee_delete(this);
				this = NULL;
			}
		}
	}
	return this;
}


Employee* employee_newParametros(int id,char* nombre,int horasTrabajadas, int sueldo)
{
	Employee* this = NULL;

	if(id >= 0 && nombre != NULL && horasTrabajadas >= 0 && sueldo >= 0)
	{
		this = employee_new();
		if(this != NULL)
		{
			if(employee_setNombre(this, nombre) != 0 ||
				employee_setHorasTrabajadas(this, horasTrabajadas) != 0 ||
				employee_setSueldo(this, sueldo) != 0 ||
				employee_setId(this, id) != 0)
			{
				employee_delete(this);
				this = NULL;
			}
		}

	}
	return this;
}

void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////   ID   ///////////////////////////////////////////////////////

int employee_setId(Employee* this, int id)
{
	int output = -1;

	if(this != NULL && id >= 0)
	{
		this->id = id; //te agrega el dato
		output = 0;
	}
	return output;
}


int employee_getId(Employee* this, int* id)
{
	int output = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id; //te trae el dato
		output = 0;
	}

	return output;
}



//////////////////////////////ID TXT


int employee_setIdTxt(Employee* this, char* id)
{
	int output = -1;

	if(this != NULL && id != NULL && isValidIdTxt(id) == 1)
	{
		this->id = atoi(id);
		output = 0;
	}

	return output;
}


char* employee_getIdTxt(Employee* this, int* flagError)
{
	*flagError = -1;
	char* bufferId = NULL;

	if(this != NULL && flagError != NULL)
	{
		sprintf(bufferId, "%d", this->id);
		*flagError = 0;
	}
	return bufferId;
}


int isValidIdTxt(char* id)
{
	int retorno = 0;

	if(id != NULL && utn_esNumerica(id, sizeof(id)) != -1)
	{
		retorno = 1;
	}

	return retorno;
}


////////////////////////////////NOMBRE


int employee_setNombre(Employee* this, char* nombre)
{
	int output = -1;
	if(this != NULL && nombre != NULL && isValidNombre(nombre) == 1)
	{
		strncpy(this->nombre, nombre, NAME_LEN);
		output = 0;
	}
	return output;
}


int employee_getNombre(Employee* this, char* nombre)
{
	int output = -1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre, this->nombre, NAME_LEN);
		output = 0;
	}
	return output;
}


int isValidNombre(char* name)
{
	int output = 0;

	if(name != NULL && validarNombre(name, NAME_LEN) == 1)
	{
		output = 1;
	}

	return output;
}


////////////////////////////HORAS TRABAJADAS

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
	int output = -1;

	if(this != NULL && isValidHorasTrabajadas(horasTrabajadas) == 1)
	{
		this->horasTrabajadas = horasTrabajadas;
		output = 0;
	}
	return output;
}


int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
	int output = -1;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		output = 0;
	}
	return output;
}


int isValidHorasTrabajadas(int horasTrabajadas)
{
	int retorno = 0;

	if(horasTrabajadas >= 0)
	{
		retorno = 1;
	}

	return retorno;
}



////////////////////////////HORAS TRABAJADAS TXT

int employee_setHorasTrabajadasTxt(Employee* this, char* horasTrabajadas)
{
	int output = -1;
	if(this != NULL && horasTrabajadas != NULL && isValidHorasTrabajadasTxt(horasTrabajadas) == 1)
	{
		this->horasTrabajadas = atoi(horasTrabajadas);
		output = 0;
	}
	return output;
}


char* employee_getHorasTrabajadasTxt(Employee* this, int* flagError)
{
	*flagError = -1;
	char* bufferHorasTrabajadas = NULL;

	if(this != NULL && flagError != NULL)
	{
		sprintf(bufferHorasTrabajadas,"%d", this->horasTrabajadas);
		*flagError = 0;
	}
	return bufferHorasTrabajadas;
}


int isValidHorasTrabajadasTxt(char* horasTrabajadas)
{
	int output = 0;

	if(horasTrabajadas != NULL && utn_isNumerico(horasTrabajadas) == 1)
	{
		output = 1;
	}

	return output;
}

////////////////////////////SUELDO

int employee_setSueldo(Employee* this, int sueldo)
{
	int output = -1;
	if(this != NULL && isValidSueldo(sueldo) == 1)
	{
		this->sueldo = sueldo;
		output = 0;
	}
	return output;
}


int employee_getSueldo(Employee* this, int* sueldo)
{
	int output = -1;
	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		output = 0;
	}
	return output;
}


int isValidSueldo(int sueldo)
{
	int output = 0;

	if(sueldo >= 0 && sueldo < 20000000)
	{
		output = 1;
	}

	return output;
}



////////////////////////////SUELDO TXT

int employee_setSueldoTxt(Employee* this, char* sueldo)
{
	int output = -1;
	if(this != NULL && sueldo != NULL && isValidSueldoTxt(sueldo) == 1)
	{
		this->sueldo = atoi(sueldo);
		output = 0;
	}
	return output;
}


char* employee_getSueldoTxt(Employee* this, int* flagError)
{
	*flagError = -1;
	char* bufferSueldo = NULL;
	if(this != NULL && flagError != NULL)
	{
		sprintf(bufferSueldo,"%d", this->sueldo);
		*flagError = 0;
	}
	return bufferSueldo;
}


int isValidSueldoTxt(char* sueldo)
{
	int output = 0;

	if(sueldo != NULL && utn_isNumerico(sueldo) == 1)
	{
		output = 1;
	}

	return output;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int employee_findId(LinkedList* pArrayListEmployee, int* id)
{
	int output = -1;
	int len;
	Employee* bufferEmployee;
	int bufferId;

	if(pArrayListEmployee != NULL && id != NULL)
	{
		len = ll_len(pArrayListEmployee);

		for(int i = 0; i < len; i++)
		{
			bufferEmployee = (Employee*) ll_get(pArrayListEmployee, i); //unboxing
			employee_getId(bufferEmployee, &bufferId);
			if(bufferEmployee != NULL && bufferId == *id)
			{
				output = i;
				break;
			}
		}
	}
	return output;
}


/*static int employee_findMaximumId(LinkedList* pArrayEmployee)
{
	int output = -1;
	Employee* pEmployee;
	int len;
	int id;
	static int maxId;

	if(pArrayEmployee != NULL)
	{
		len = ll_len(pArrayEmployee); //devuelve la cant de elementos que tengo en la lista
		for(int i = 0; i < len; i++)
		{
			pEmployee = (Employee*)ll_get(pArrayEmployee, i); //devuelve el empleado en el indice i
			employee_getId(pEmployee, &id); //trae el id
			if(i == 0 || id > maxId)
			{
				maxId = id;
			}
		}
		output = maxId;
	}

	return output;
}

*/

/*
static int employee_generateNewId(LinkedList* pArrayEmployee)
{
	int output = -1;
	static int id;

	if(pArrayEmployee != NULL) //&& ll_isEmpty(pArrayEmployee) == 0)
	{
		id = employee_findMaximumId(pArrayEmployee);
		id++;
		output = id;
	}

	return output;
}
*/


/*int employee_upload(LinkedList* pArrayEmployee, char nombre[], int* horasTrabajadas, int* sueldo, int* id)
{
	int output = -1;

	if(pArrayEmployee != NULL && nombre != NULL && horasTrabajadas != NULL && sueldo != NULL && id != NULL)
	{
		if(utn_getNombre(nombre, "\nNombre: ", ERROR_MSG, NAME_LEN, QTY_REINTENTO) == 0 &&
		   utn_getNumero(horasTrabajadas, "\nHoras trabajadas: ", ERROR_MSG, MIN_HSTRABAJADAS, MAX_HSTRABAJADAS, QTY_REINTENTO) == 0 &&
		   utn_getNumero(sueldo, "\nSueldo: ", ERROR_MSG, MIN_SUELDO, MAX_SUELDO, QTY_REINTENTO) == 0)
		{
			*id = employee_generateNewId(pArrayEmployee);
			output = 0;
		}
	}
	return output;
}*/

int employee_upload(char nombre[], int* horasTrabajadas, int* sueldo, int* id)
{
	int output = -1;
	char bufferId[345];

	if(nombre != NULL && horasTrabajadas != NULL && sueldo != NULL && id != NULL)
	{
		if(utn_getNombre(nombre, "\nNombre: ", ERROR_MSG, NAME_LEN, QTY_REINTENTO) == 0 &&
		   utn_getNumero(horasTrabajadas, "\nHoras trabajadas: ", ERROR_MSG, MIN_HSTRABAJADAS, MAX_HSTRABAJADAS, QTY_REINTENTO) == 0 &&
		   utn_getNumero(sueldo, "\nSueldo: ", ERROR_MSG, MIN_SUELDO, MAX_SUELDO, QTY_REINTENTO) == 0)
		{
			employee_getLastId(bufferId);
			*id = employee_increaseLatestId(bufferId);
			output = 0;
		}
	}
	return output;
}


int employee_getAllTheGets(Employee* pEmployee, char nombre[], int* horasTrabajadas, int* sueldo, int* id)
{
	int output = -1;

	if(pEmployee != NULL && nombre != NULL && horasTrabajadas != NULL && sueldo != NULL && id != NULL)
	{
		if(employee_getId(pEmployee, id) == 0 &&
		   employee_getNombre(pEmployee, nombre) == 0 &&
		   employee_getHorasTrabajadas(pEmployee, horasTrabajadas) == 0 &&
		   employee_getSueldo(pEmployee, sueldo) == 0)
		{
			output = 0;
		}
	}

	return output;
}

int employee_printEmployee(Employee* pEmployee)
{
	int output = -1;
	char nombre[NAME_LEN];
	int horasTrabajadas;
	int sueldo;
	int id;

	if(pEmployee != NULL &&
	   employee_getAllTheGets(pEmployee, nombre, &horasTrabajadas, &sueldo, &id) == 0)
	{
		printf("%d - %s - %d - %d\n", id, nombre, horasTrabajadas, sueldo);
		output = 0;
	}

	return output;
}


int employee_getLastId(char* id)
{
	int output = -1;
	FILE* pFile;

	pFile = fopen("id.csv", "r");

	if(pFile != NULL && id != NULL)
	{
		fscanf(pFile, "%[^\n]\n", id);
		fclose(pFile);
		output = 0;
	}
	return output;
}


int employee_increaseLatestId(char* id)
{
	int output = -1;
	int bufferId;

	if(id != NULL)
	{
		bufferId = atoi(id);
		bufferId++;
		//itoa(bufferId, id, 10); // 10 = base decimal
								//me lo guarda en id
		output = bufferId;
	}
	return output;
}


int employee_saveLatestId(int id)
{
	int output = -1;
	FILE* pFile;

	pFile = fopen("id.csv", "w");

	if(pFile != NULL && id > 0)
	{
		fprintf(pFile, "%d\n", id);
		fclose(pFile);
		output = 0;
	}
	return output;
}


int employee_compareById(void* firstEmployee, void* secondEmployee)
{
	int output = 0; //iguales hasta que se demuestre lo contrario
	int idFirstEmployee;
	int idSecondEmployee;
	Employee* pFirstEmployee = (Employee*) firstEmployee;
	Employee* pSecondEmployee = (Employee*) secondEmployee;

	if(firstEmployee != NULL && secondEmployee != NULL)
	{
		employee_getId(pFirstEmployee, &idFirstEmployee);
		employee_getId(pSecondEmployee, &idSecondEmployee);
		if(idFirstEmployee > idSecondEmployee)
		{
			output = 1;//de menor a mayor > ASC
		}
		else if(idFirstEmployee < idSecondEmployee)
		{
			output = -1;//de mayor a menor < DESC
		}
	}

	return output;
}

int employee_compareByName(void* firstEmployee, void* secondEmployee)
{
	int output = 0;
	Employee* pFirstEmployee = (Employee*) firstEmployee;
	Employee* pSecondEmployee = (Employee*) secondEmployee;
	char firstName[128];
	char secondName[128];

	if (firstEmployee != NULL && secondEmployee != NULL)
	{
		employee_getNombre(pFirstEmployee, firstName);
		employee_getNombre(pSecondEmployee, secondName);
		output = strcmp(firstName, secondName);
	}

	return output;
}



int employee_compareByWorkedHours(void* firstEmployee, void* secondEmployee)
{
	int output = 0;
	Employee* pFirstEmployee;
	Employee* pSecondEmployee;
	int firstWorkedHours;
	int secondWorkedHours;

	if (firstEmployee != NULL && secondEmployee != NULL)
	{
		pFirstEmployee = (Employee*) firstEmployee;
		pSecondEmployee = (Employee*) secondEmployee;

		employee_getHorasTrabajadas(pFirstEmployee, &firstWorkedHours);
		employee_getHorasTrabajadas(pSecondEmployee, &secondWorkedHours);
		if(firstWorkedHours > secondWorkedHours)
		{
			output = 1;
		}
		else if(firstWorkedHours < secondWorkedHours)
		{
			output = -1;
		}
	}

	return output;
}

int employee_compareBySalary(void* firstEmployee, void* secondEmployee)
{
	int output = 0;
	Employee* pFirstEmployee;
	Employee* pSecondEmployee;
	int firstSalary;
	int secondSalary;

	if (firstEmployee != NULL && secondEmployee != NULL)
	{
		pFirstEmployee = (Employee*) firstEmployee;
		pSecondEmployee = (Employee*) secondEmployee;

		employee_getHorasTrabajadas(pFirstEmployee, &firstSalary);
		employee_getHorasTrabajadas(pSecondEmployee, &secondSalary);
		if(firstSalary > secondSalary)
		{
			output = 1;
		}
		else if(firstSalary < secondSalary)
		{
			output = -1;
		}
	}

	return output;
}
