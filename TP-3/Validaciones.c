#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Valida si recibiste uno o mas nombres (posibilita el ingreso de espacios)
 * \param char* pString Puntero a la cadena de caracteres a ser validada
 * \param int limite Longitud de la cadena de caracteres
 * \return -1 en caso de error, 1 (verdadero), 0 (falso)
 */
int isValidName(char* pString, int limite)
{
	int retorno = -1;
	int i;

	if(pString!= NULL && limite > 0)
	{
		for(i = 0; pString[i] != '\0' && i < limite; i++)
		{
			if((pString[i] < 'a' || pString [i] > 'z') && (pString[i] < 'A' || pString[i] > 'Z') && (pString[i] != ' '))
			{
				retorno = 0;
				break;
			}
		}
		retorno = 1;
	}

	return retorno;
}

/*
 * \brief Valida si recibiste un numero entero positivo o negativo
 * \param char* pString Puntero a la cadena de caracteres a ser validada
 * \return -1 en caso de error, 1 (verdadero), 0 (falso)
 */

int isValidNumberInt(char* pString)
{
	int retorno = -1;
	int i = 0;

	if(pString!= NULL)
	{
		if(pString[0] == '-')
		{
			i= 1;
		}

		while(pString[i] != '\0')
		{
			if(pString[i] < '0' || pString[i] > '9')
			{
				retorno = 0;
				break;
			}
			i++;
		}
		retorno = 1;
	}

	return retorno;
}

/*
int isValidNumberInt(char* pString, int limite)
{
	int retorno = -1;
	int i = 0;

	if(pString!= NULL && limite > 0)
	{
		if(pString[0] == '-')
		{
			i= 1;
		}

		for(; pString[i] != '\0' && i < limite; i++)
		{
			if(pString[i] < '0' || pString[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
		retorno = 1;
	}

	return retorno;
}
 */

/*
 * \brief Valida si recibiste un numero flotante positivo o negativo
 * \param char* pString Puntero a la cadena de caracteres a ser validada
 * \return -1 en caso de error, 1 (verdadero), 0 (falso)
 */

int isValidNumberFloat(char* pString)
{
	int retorno = -1;
	int i;
	int contador = 0;

	if(pString!= NULL)
	{
		i = 0;

		if(pString[0] == '-')
		{
			i= 1;
		}

		while(pString[i] != '\0')
		{
			if(pString[i] < '0' || pString[i] > '9')
			{
				if(pString[i] == '.')
				{
					contador++;
				}

				if(contador > 1)
				{
					retorno = 0;
					break;
				}
				else
				{
					retorno = 1;
					break;
				}
			}
			i++;
		}
	}

	return retorno;
}

/*
int isValidNumberFloat(char* pString, int limite)
{
	int retorno = -1;
	int i;
	int contador = 0;

	if(pString!= NULL && limite > 0)
	{
		i = 0;

		if(pString[0] == '-')
		{
			i= 1;
		}

		for(; pString[i] != '\0' && i < limite; i++)
		{
			if(pString[i] < '0' || pString[i] > '9')
			{
				if(pString[i] == '.')
				{
					contador++;
				}

				if(contador > 1)
				{
					retorno = 0;
					break;
				}
				else
				{
					retorno = 1;
					break;
				}
			}
		}
	}

	return retorno;
}
*/


/*
 * \brief Valida si recibiste numeros y letras
 * \param char* pString Puntero a la cadena de caracteres a ser validada
 * \param int limite Longitud de la cadena de caracteres
 * \return -1 en caso de error, 1 (verdadero), 0 (falso)
 */

int isValidAlfanumerico(char* pString, int limite)
{
	int retorno = -1;
	int i;

	if(pString!= NULL && limite > 0)
	{
		for(i = 0; pString[i]!= '\0' && i < limite; i++)
		{
			if((pString[i] < 'a' || pString [i] > 'z') && (pString[i] < 'A' || pString[i] > 'Z') && (pString[i] < '0' || pString[i] > '9'))
			{
				retorno = 0;
				break;
			}
		}
		retorno = 1;
	}

	return retorno;
}

int isValidAlfanumerico2(char* pString)
{
	int retorno = -1;
	int i = 0;

	if(pString!= NULL)
	{
		while(pString[i] != '\0')
		{
			if((pString[i] < 'a' || pString [i] > 'z') && (pString[i] < 'A' || pString[i] > 'Z') && (pString[i] < '0' || pString[i] > '9'))
			{
				retorno = 0;
				break;
			}
			i++; //faltaba
		}
		retorno = 1;
	}

	return retorno;
}


/**
 * \brief Valida si recibiste un dni
 * \param char* pString Puntero a la cadena de caracteres a ser validada
 * \param int limite Longitud de la cadena de caracteres
 * \return -1 en caso de error, 0 en caso de que haya salido bien
 */

int isValidDni(char* pString, int limite)
{
	int retorno = -1;
	int i = 0;
	int contador = 0;

	if(pString!= NULL && limite > 0)
	{
		for(i = 0; pString[i]!= '\0' && i < limite; i++)
		{
			if((pString[i] < '0' || pString[i] > '9') && (pString[0] == '.'))
			{
				if(pString[i] == '.')
				{
					contador++;
				}

				if(contador <= 2)
				{
					retorno = 1;
					break;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}

	return retorno;
}


/*
int contadorDigitos(char* pString)
{
	int retorno = -1;

	if(pString != NULL)
	{
		while()
		{

		}
	}

	return retorno;
}
*/


/*
 * \brief Valida si recibiste un cuit
 * \param char* pString Puntero a la cadena de caracteres a ser validada
 * \param int limite Longitud de la cadena de caracteres
 * \return -1 en caso de error, 1 (verdadero), 0 (falso)
 */

int isValidCuit(char* pString)
{
	int retorno = -1;
	int i = 0;
	int contadorGuion = 0;

	while(pString[i] != '\0'){
		if((pString[i] != '-') && (pString[i] < '0' || pString[i] > '9')){
			retorno=1;
		}

		if(pString[i] == '-'){
			contadorGuion++;
		}

		i++;
	}

	if(contadorGuion == 2){
		retorno = 1;
	}

	return retorno;
}


/**
 * \brief Valida si recibiste un email
 * \param char* pString Puntero a la cadena de caracteres a ser validada
 * \param int limite Longitud de la cadena de caracteres
 * \return -1 en caso de error, 0 en caso de que haya salido bien
 */

int isValidMail(char* pString, int limite)
{
	int i ;
	int retorno = -1;
	int contador = 0;

	if(pString != '\0' && limite > 0) //pString != NULL
	{
		retorno = 0;
		for(i=0; pString[i] != '\0' && i < limite; i++)
		{
			if((pString[i] < 'a' || pString [i] > 'z') && (pString[i] < 'A' || pString[i] > 'Z')  && (pString[i] < '0' || pString[i] > '9')
					&& (pString[i] != '.' || pString[0] == '.') && (pString[i] != '-' || pString[0] == '-') && (pString[i] != '_' || pString[0] == '_'))
			{
				if(pString[i] == '@')
				{
					contador++;

					if(contador>1 || pString[0] == '@')
					{
						retorno = -1;
						break;
					}
				}
				else
				{
					retorno = -1;
					break;
				}
			}
		}
	}
	return retorno;
}


/*
 * \brief Valida si recibiste un numero telefonico
 * \param char* pString Puntero a la cadena de caracteres a ser validada
 * \param int limite Longitud de la cadena de caracteres
 * \return -1 en caso de error, 1 (verdadero), 0 (falso)
 */

int isValidTelefono(char* pString)
{
	int retorno = -1;
	int i = 0;
	int contadorGuion = 0;

	while(pString[i] != '\0'){
		if((pString[i] != ' ') && (pString[i] != '-') && (pString[i] != '+') && (pString[i] < '0' || pString[i] > '9')){
			retorno = 1;
		}

		if(pString[i] == '-'){
			contadorGuion++;
		}

		i++;
	}

	if(contadorGuion == 1){
		retorno= 1;
	}

	return retorno;
}


/*
 * \brief Valida si recibiste una edad
 * \param char* pString Puntero a la cadena de caracteres a ser validada
 * \param int limite Longitud de la cadena de caracteres
 * \return -1 en caso de error, 1 (verdadero), 0 (falso)
 */

int isValidEdad(char* pString)
{
	int retorno = -1;
	int i = 0;

	while(pString[i] != '\0'){
		if((pString[i] < '0' || pString[i] > '9') && (pString[i] > 0 || pString[i] < 130)){
				retorno = 1;
		}
		i++;
	}
	return retorno;
}


/*
 * \brief Valida si recibiste una direccion
 * \param char* pString Puntero a la cadena de caracteres a ser validada
 * \param int limite Longitud de la cadena de caracteres
 * \return -1 en caso de error, 1 (verdadero), 0 (falso)
 */

int isValidDireccion(char* pString)
{
	int retorno = -1;
	int i = 0;

	while(pString[i] != '\0'){
		if((pString[i] != ' ') && (pString[i] != ',') && (pString[i] != '.') && (pString[i] < '0' || pString[i] > '9') && (pString[i] < 'a' || pString[i] > 'z') && (pString[i] < 'A' || pString[i] > 'Z')){
			retorno = 1;
		}
		i++;
	}
	return retorno;
}


/*
 * \brief Valida si recibiste un numero de tarjeta de credito
 * \param char* pString Puntero a la cadena de caracteres a ser validada
 * \param int limite Longitud de la cadena de caracteres
 * \return -1 en caso de error, 1 (verdadero), 0 (falso)
 */

int isValidCreditCard(char* pString)
{
	int retorno = -1;
	int i = 0;

	while(pString[i] != '\0'){
		if(pString[i] < '0' || pString[i] > '9'){
			retorno = 1;
		}
		i++;
	}

	return retorno;
}


