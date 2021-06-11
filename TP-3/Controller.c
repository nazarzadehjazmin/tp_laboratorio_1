#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Employee.h"

		/*
		 * PARA LA LISTA -->ELIMINAR
		 * buscar por id
		 * eliminarlo con delete
		 * desp remove
		 *
		 *
		 * sprintf(cadena, "%d", variableQSeaInt);
		 * --> convierte int a cadena
		 *
		 */

//listar Y LOAD FROM TEXT

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Ruta del archivo a ser cargado
 * \param pArrayListEmployee LinkedList* Puntero al array de empleados
 * \return int [0] EXITO
 * 			   [-1] ERROR: uno o ambos argumentos de la funcion son igual a NULL
 * 			   [-2] ERROR: No se logró abrir el archivo
 *
 */
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
			// devolverlo en el output?
			output = 0;
			fclose(pFile);
		}
		else
		{
			printf("No se puede abrir el archivo\n");
			output = -2;
		}
	}

	/*
	 * abrir arch
	 * parser -->llenar la lista de empleados
	 * setear valor inicial de id(idMax)
	 *
	 */


    return output;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int output = -1;

	if(path != NULL && pArrayListEmployee != NULL)
	{

	}

    return output;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int output = -1;
	char idStr;
	char nombreStr;
	char horasTrabajadasStr;
	char sueldoStr;

	/*
 	 *con new_param
	 *hacer el else y liberar si hubo error (con empleado_delete)
	 *genero el id --> generarNuevoId();
	 *SETEO el id (empleado_setId)
	 *FIJARSE EL DEL COMPA EN LA CLASE 24 (10/6)
	 *
	 *pregunto
	 *genero nuevo id
	 *seteo --> newParam esta el seteo
	 *ll_add
	 */

	if(pArrayListEmployee != NULL)
	{

		if(employee_newParametros("Ingrese el ID:\n", "Ingrese el nombre: \n", "Ingrese horas trabajadas: \n", "Ingrese sueldo:\n"))
		{

		}
	}

    return output;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int output = -1;

	if(pArrayListEmployee != NULL)
	{

	}

    return output;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int output = -1;

	if(pArrayListEmployee != NULL)
	{

	}

    return output;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	//for
	//get
	//1:08   https://drive.google.com/file/d/1ZvllMCEi_u2UtNFR2nvOJyIAxI9dHyrp/view
	int output = -1;
	int i;
	//Employee* pEmployee;

	if(pArrayListEmployee != NULL)
	{
		for(i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			(Employee*)ll_get(pArrayListEmployee, i); //// pEmployee = ...;
			//printf("ID: %s - Nombre: %s - Horas trabajadas: %s - Sueldo: %s \n");
		}
	}

    return output;
}


/*
 *
 *
 *
 *
 */

int controller_listOneEmployee(LinkedList* pArrayEmployee, int index)
{
	int output = -1;
	int* flagError;
	Employee* pEmployee;
	char bufferNombre[QTY_NAME];

	if(pArrayEmployee != NULL && index >= 0)
	{
		pEmployee = (Employee*)ll_get(pArrayEmployee, index); //obtengo la posic
		if(pEmployee != NULL)
		{
			if(employee_getIdTxt(pEmployee, flagError) &&
				employee_getNombre(pEmployee, bufferNombre) &&
				employee_getHorasTrabajadasTxt(pEmployee, flagError) &&
				employee_getSueldoTxt(pEmployee, flagError))//employee_get
			{
				printf();
			}
		}
	}

	return output;
}



/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int output = -1;

	if(pArrayListEmployee != NULL)
	{

	}

    return output;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int output = -1;

	if(path != NULL && pArrayListEmployee != NULL)
	{

	}

    return output;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int output = -1;

	if(path != NULL && pArrayListEmployee != NULL)
	{

	}

    return output;
}

