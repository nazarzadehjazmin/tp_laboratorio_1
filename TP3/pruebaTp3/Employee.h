#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "LinkedList.h"
#define ERROR_MSG "Error, reingrese el dato\n"
#define QTY_REINTENTO 5
#define MIN_ID 1
#define MAX_ID 3000
#define NAME_LEN 120
#define MIN_HSTRABAJADAS 0
#define MAX_HSTRABAJADAS 10000
#define MIN_SUELDO 0
#define MAX_SUELDO 1000000

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


/**
 * \brief Reserva espacio en memoria para un empleado
 * \param void
 * \return Employee*
 *
 */
Employee* employee_new();


/**
 *  \brief Valida los campos y los carga en una variable Employee (todo como cadena de caracteres)
 * \param char* idStr
 * \param char* nombreStr
 * \param char* horasTrabajadasStr
 * \return Employee* this
 *
 */
Employee* employee_newParametrosTxt(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);


/**
 *  \brief Valida los campos y los carga en una variable Employee
 * \param int id
 * \param char* nombre
 * \param int horasTrabajadas
 * \param int sueldo
 * \return Employee* this
 *
 */
Employee* employee_newParametros(int id, char* nombre, int horasTrabajadas, int sueldo);


/**
 *  \brief Libera el espacio reservado en memoria para un empleado
 * \param Employee* this
 * \return void
 *
 */
void employee_delete();


/**
 * \brief Carga el id en el campo del empleado
 * \param this Employee* Puntero a empleado
 * \param id int Id a cargar
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int employee_setId(Employee* this, int id);


/**
 * \brief Obtiene el id del empleado
 * \param this Employee* Puntero a empleado
 * \param id int* Puntero al espacio donde va a guardar el id obtenido
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int employee_getId(Employee* this, int* id);


/**
 * \brief Carga el id en el campo del empleado (tratado como texto) y valida que el dato sea correcto
 * \param this Employee* Puntero a empleado
 * \param id char* Puntero al id que va a cargar
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int employee_setIdTxt(Employee* this, char* id);


/**
 * \brief Obtiene el id del empleado (tratado como texto)
 * \param this Employee*
 * \param flagError int*
 * \return int [-1] ERROR, [id] EXITO - retorna el id si funciona correctamente
 *
 */
char* employee_getIdTxt(Employee* this, int* flagError);


/**
 * \brief Verifica que la cadena sea solo numeros
 * \param id char* Puntero al id
 * \return int[-1] ERROR, [0] EXITO
 *
 */
int isValidIdTxt(char* id);


/**
 * \brief Carga un nombre en el campo nombre del empleado. Valida que el dato sea correcto
 * \param this Employee* Puntero a empleado
 * \param nombre char* Puntero al nombre a ser cargado
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int employee_setNombre(Employee* this, char* nombre);


/**
 * \brief Obtiene el nombre del empleado
 * \param this Employee* Puntero a empleado
 * \param nombre char* Puntero al nombre a ser cargado
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int employee_getNombre(Employee* this, char* nombre);


/**
 * \brief Verifica que la cadena sea un nombre
 * \param name char* Puntero al nombre
 * \return int[-1] ERROR, [0] EXITO
 *
 */
int isValidNombre(char* name);


/**
 * \brief Carga las horas trabajadas en el campo del empleado
 * \param this Employee* Puntero a empleado
 * \param horasTrabajadas int Horas trabajadas a cargar
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas);


/**
 * \brief Obtiene las horas trabajadas del empleado
 * \param this Employee* puntero a empleado
 * \param horasTrabajadas int* Puntero al espacio donde se van a guardar las horas trabajadas obtenidas
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas);


/**
 * \brief Verifica que las horas trabajadas sean 0 o mas
 * \param horasTrabajadas int Puntero a las horas trabajadas
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int isValidHorasTrabajadas(int horasTrabajadas);


/**
 * \brief Carga las horas trabajadas en el campo del empleado (tratado como texto) y valida que el dato sea correcto
 * \param this Employee* Puntero a empleado
 * \param horasTrabajadas char* Puntero a las horas trabajadas que va a guardar
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int employee_setHorasTrabajadasTxt(Employee* this, char* horasTrabajadas);


/**
 * \brief Obtiene las horas trabajadas del empleado (tratado como texto)
 * \param this Employee* Puntero a empleado
 * \param flagError int*
 * \return int [-1] ERROR, [0] EXITO
 *
 */
char* employee_getHorasTrabajadasTxt(Employee* this, int* flagError);

/**
 * \brief Verifica que la cadena sea solo numeros
 * \param horasTrabajadas char* Puntero a las horas trabajadas
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int isValidHorasTrabajadasTxt(char* horasTrabajadas);


/**
 * \brief Carga el sueldo en el campo del empleado
 * \param this Employee* Puntero a empleado
 * \param sueldo int Sueldo a cargar
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int employee_setSueldo(Employee* this, int sueldo);


/**
 * \brief Obtiene el sueldo del empleado
 * \param this Employee* Puntero a empleado
 * \param sueldo int* Puntero al espacio donde va a guardar el sueldo obtenido
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int employee_getSueldo(Employee* this, int* sueldo);


/**
 * \brief Verifica que el sueldo sea 0 o mas
 * \param sueldo int Puntero al sueldo
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int isValidSueldo(int sueldo);


/**
 * \brief Carga el sueldo en el campo del empleado (tratado como texto) y valida que el dato sea correcto
 * \param this Employee* Puntero que contiene la direccion de memoria donde esta almacenado el empleado
 * \param sueldo char* Puntero al sueldo que va a guardar
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int employee_setSueldoTxt(Employee* this, char* sueldo);


/**
 * \brief Obtiene el sueldo del empleado (tratado como texto)
 * \param this Employee* Puntero que contiene la direccion de memoria donde esta almacenado el empleado
 * \param flagError int*
 * \return int[-1] ERROR, [0] EXITO
 *
 */
char* employee_getSueldoTxt(Employee* this, int* flagError);

/**
 * \brief Verifica que la cadena sea solo numeros
 * \param sueldo char* Puntero al sueldo
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int isValidSueldoTxt(char* sueldo);

/**
 * \brief Busca el id de un empleado en la lista
 * \param pArrayListEmployee LinkedList* Puntero a la lista
 * \param id int* Puntero al id
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int employee_findId(LinkedList* pArrayListEmployee, int* id);

//int employee_findMaximumId(LinkedList* pArrayEmployee);


/**
 * \brief Pide los datos del empleado y le da un id
 * \param nombre char* Puntero al nombre
 * \param horasTrabajadas int* Puntero a las horas trabajadas
 * \param sueldo int* Puntero al sueldo
 * \param id int* Puntero al id
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int employee_upload(char nombre[], int* horasTrabajadas, int* sueldo, int* id);


/**
 * \brief Trae todos los gets (para obtener los datos del empleado)
 * \param pEmployee Employee* Puntero al empleado
 * \param nombre char* Puntero al nombre
 * \param horasTrabajadas int* Puntero a las horas trabajadas
 * \param sueldo int* Puntero al sueldo
 * \param id int* Puntero al id
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int employee_getAllTheGets(Employee* pEmployee, char nombre[], int* horasTrabajadas, int* sueldo, int* id);


/** \brief Imprime un empleado
 * \param pEmpleado Employee* Puntero al empleado
 * \return int[-1] ERROR, [0] EXITO
 *
 */
int employee_printEmployee(Employee* pEmployee);


/** \brief Trae de un archivo el ultimo id utilizado
 * \param id char* Puntero al id
 * \return int[-1] ERROR, [0] EXITO
 *
 */
int employee_getLastId(char* id);


/** \brief Incrementa el ultimo id utilizado
 * \param id char* Puntero al id
 * \return int[-1] ERROR, [0] EXITO
 *
 */
int employee_increaseLatestId(char* id);


/** \brief Guarda en un archivo el ultimo id utilizado
 * \param id char* Puntero al id
 * \return int[-1] ERROR, [0] EXITO
 *
 */
int employee_saveLatestId(int id);


/**
 * \brief Compara los id de dos empleados
 * \param firstEmployee void* Puntero al primer empleado a comparar
 * \param secondEmployee void* Puntero al segundo empleado a comparar
 * \return int [0] si los id son iguales, [1] Si el id del primer empleado es mayor al del segundo, [-1] Si el id del primer empleado es menor al del segundo
 *
 */
int employee_compareById(void* firstEmployee, void* secondEmployee);


/**
 * \brief Compara los nombres de dos empleados
 * \param firstEmployee void* Puntero al primer empleado a comparar
 * \param secondEmployee void* Puntero al segundo empleado a comparar
 * \return int [0] si los nombres son iguales, [numero > 0]  Si el nombre del primer empleado es mayor al del segundo, [numero < 0]  Si el nombre del primer empleado es menor al del segundo
 *
 */
int employee_compareByName(void* firstEmployee, void* secondEmployee);


/**
 * \brief Compara la cantidad de horas trabajadas de dos empleados
 * \param firstEmployee void* Puntero al primer empleado a comparar
 * \param secondEmployee void* Puntero al segundo empleado a comparar
 * \return int [0] si la cantidad de horas trabajadas de los empleados son iguales, [1] Si la cantidad de horas trabajadas del primer empleado es mayor al del segundo, [-1] Si la cantidad de horas trabajadas del primer empleado es menor al del segundo
 *
 */
int employee_compareByWorkedHours(void* firstEmployee, void* secondEmployee);


/**
 * \brief Compara los sueldos de dos empleados
 * \param firstEmployee void* Puntero al primer empleado a comparar
 * \param secondEmployee void* Puntero al segundo empleado a comparar
 * \return int [0] si los sueldos son iguales, [1] Si el sueldo del primer empleado es mayor al del segundo, [-1] Si el sueldo del primer empleado es menor al del segundo
 *
 */
int employee_compareBySalary(void* firstEmployee, void* secondEmployee);



#endif
