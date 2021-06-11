#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "Validaciones.h"
#include "utn.h"

/*\brief Reserva espacio en memoria para un empleado
 * \param void
 * \return Employee*
 *
 */

Employee* employee_new(void)
{
	return (Employee*)malloc(sizeof(Employee));
}



/* \brief Valida los campos y los carga en una variable Employee
 * \param char* idStr
 * \param char* nombreStr
 * \param char* horasTrabajadasStr
 * \param char* sueldoStr
 * \return Employee* this
 *
 */

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* this;
	this = NULL;
	this = employee_new();

	if(this != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{

		if(employee_setNombre(this, nombreStr) < 0 ||
			employee_setHorasTrabajadasTxt(this, horasTrabajadasStr)  < 0 ||
			employee_setSueldoTxt(this, sueldoStr) < 0 ||
			employee_setIdTxt(this, idStr) < 0)
		{
			employee_delete(this);
			this = NULL;
		}
	}
	return this;
}


/* \brief Libera el espacio reservado en memoria para un empleado
 * \param Employee* this
 * \return void
 *
 */

void employee_delete(Employee* this)
{
	//int output = -1;

	if(this != NULL)
	{
		free(this);
		//output = 0;
	}
	//return output;
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int contador = 0;

/*
 * \brief Genera un id
 * \return el numero de id generado
 */

void employee_setearValorInicialDeId(int id)
{
	contador = id;
}

int employee_generarId(void)
{
	contador++;
	return contador;
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




///////////////////////ID
/*
 * \brief
 * \param
 * \return
 */

int employee_setId(Employee* this, int id)
{
	int output = -1;
	static int maximoId = -1;

	if(this != NULL)
	{
		if(id < 0)
		{
			maximoId++;
			this->id = maximoId;
		}
		else
		{
			if(id > maximoId)
			{
				maximoId = id;
			}
			this->id = id;
		}

		output = 0;
	}

	return output;
}



/*
 * \brief
 * \param
 * \return
 */

int employee_getId(Employee* this, int* id)
{
	int output = -1;

	if(this != NULL)
	{
		*id = this->id;
		output = 0;
	}

	return output;
}



//////////////////////////////ID TXT
/*
 * \brief
 * \param
 * \return [0] EXITO
 * 		   [-1] ERROR
 */

int employee_setIdTxt(Employee* this, char* id)
{
	int output = -1;

	if(this != NULL && id != NULL && isValidIdTxt(id))
	{
		this->id = atoi(id);
		output = 0;
	}

	return output;
}

/*
 	int output = -1;
	static int maximoIdTxt = -1;
	int idInt;

	if(this != NULL && id != NULL)
	{
		idInt = atoi(id);
		output = 0;

		if(idInt < 0)
		{
			maximoIdTxt++;
			this->id = maximoId;
		}
		else
		{
			if(id > maximoId)
			{
				maximoId = id;
			}
			this->id = id;
		}
	}
	return output;
 */


/*
 * \brief
 * \param
 * \return [0] EXITO
 * 		   [-1] ERROR
 */

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



/*
 * \brief
 * \param
 * \return [0] EXITO
 * 		   [-1] ERROR
 */

int isValidIdTxt(char* id)
{
	int retorno = 0;

	if(id != NULL && isValidNumberInt(id) == 1)
	{
		retorno = 1;
	}



	return retorno;
}


////////////////////////////////NOMBRE
/*
 * \brief Carga un nombre en el campo "nombre" del empleado. Previamente valida que el dato sea correcto
 * \param Employee* this Puntero a empleado
 * \param char* nombre Puntero al nombre a ser cargado
 * \return [0] EXITO
 * 		   [-1] ERROR (si el puntero a nombre y/o this son NULL, y/o si el nombre no es dato valido)
 */

int employee_setNombre(Employee* this, char* nombre)
{
	int output = -1;
	if(this != NULL && nombre != NULL && isValidNombre(nombre))
	{
		strncpy(this->nombre, nombre, QTY_NAME);
		output = 0;
	}
	return output;
}


/*
 * \brief Obtiene el nombre del empleado
 * \param Employee* this Puntero a empleado
 * \param char* nombre Puntero al nombre a ser cargado
 * \return [0] EXITO
 * 		   [-1] ERROR (si el puntero a nombre y/o this son NULL)
 */

int employee_getNombre(Employee* this, char* nombre)
{
	int output = -1;
	if(this != NULL && nombre != NULL)
	{
		nombre = this->nombre;
		output = 0;
	}
	return output;
}



/*
 * \brief
 * \param
 * \return
 */

int isValidNombre(char* name)
{
	int output = 0;

	if(name != NULL && isValidAlfanumerico2(name) == 1)
	{
		output = 1;
	}

	return output;
}


////////////////////////////HORAS TRABAJADAS
/*
 * \brief
 * \param
 * \return
 */

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
	int output = -1;
	if(this != NULL && isValidHorasTrabajadas(horasTrabajadas))
	{
		this->horasTrabajadas = horasTrabajadas;
		output = 0;
	}
	return output;
}



/*
 * \brief
 * \param
 * \return
 */

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




/*
 * \brief
 * \param
 * \return
 */

int isValidHorasTrabajadas(int horasTrabajadas)
{
	int retorno = 0;

	if(horasTrabajadas > 0)
	{
		retorno = 1;
	}

	return retorno;
}



////////////////////////////HORAS TRABAJADAS TXT
/*
 * \brief
 * \param
 * \return
 */

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



/*
 * \brief
 * \param
 * \return
 */

char* employee_getHorasTrabajadasTxt(Employee* this, int* flagError)
{
	*flagError = -1;
	char* bufferHorasTrabajadas = NULL;
	if(this != NULL && flagError != NULL)
	{
		//auxPrecioUnidad = this->precioUnidad;
		sprintf(bufferHorasTrabajadas,"%d", this->horasTrabajadas);
		*flagError = 0;
	}
	return bufferHorasTrabajadas;
}



/*
 * \brief
 * \param
 * \return
 */

int isValidHorasTrabajadasTxt(char* horasTrabajadas)
{
	int output = 0;

	if(horasTrabajadas != NULL && isValidNumberInt(horasTrabajadas) == 1)
	{
		output = 1;
	}

	return output;
}

////////////////////////////SUELDO
/*
 * \brief
 * \param
 * \return
 */

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



/*
 * \brief
 * \param
 * \return
 */

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



/*
 * \brief
 * \param
 * \return
 */

int isValidSueldo(int sueldo)
{
	int output = 0;

	if(sueldo > 0)
	{
		output = 1;
	}

	return output;
}



////////////////////////////SUELDO TXT
/*
 * \brief
 * \param
 * \return
 */

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



/*
 * \brief
 * \param
 * \return
 */

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



/*
 * \brief
 * \param
 * \return
 */

int isValidSueldoTxt(char* sueldo)
{
	int output = 0;

	if(sueldo != NULL && isValidNumberInt(sueldo) == 1)
	{
		output = 1;
	}

	return output;
}
