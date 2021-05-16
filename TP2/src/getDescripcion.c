#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int getDescripcion(char* pResultado, int limite);
static int esDescripcion(char* cadena, int limite);
static int getString(char* pResultado);
static int utn_myGets(char* pString, int limite);

/**
 * \brief Solicita una descripcion al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param int limite Longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getDescripcion(char* pResultado, char* mensaje, char* mensajeError, int reintentos, int limite)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getDescripcion(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < limite)
		{
			strncpy(pResultado, bufferString, limite);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}


/**
 * \brief Obtiene un string valido como descripcion
 * \param char* pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param int limite Longitud del array
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getDescripcion(char* pResultado, int limite){
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL){
    	if(getString(buffer)==0 && esDescripcion(buffer,sizeof(buffer)) && strnlen(buffer,sizeof(buffer))<limite){
    		strncpy(pResultado, buffer, limite);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es una descripcion valida
 * \param cadena Cadena de caracteres a ser analizada
 * \param int limite Longitud del array
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esDescripcion(char* cadena, int limite)
{
	int i = 0;
	int retorno = 1;

	if(cadena != NULL && limite > 0)
	{
		for(i = 0; cadena[i] != '\0' && i < limite; i++)
		{
			if(cadena[i] != '.' && cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] < '0' || cadena[i] > '9' ) )
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}



/**
 * \brief Verifica si la cadena ingresada contiene letras
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
static int getString(char* pResultado){
	int retorno = -1;
	char bufferString[4000];

	if(pResultado != NULL &&
		utn_myGets(bufferString, sizeof(bufferString)) == 0 &&
		esDescripcion(bufferString, sizeof(bufferString))){
			fflush(stdin);
			retorno = 0;
			strncpy(pResultado, bufferString, sizeof(bufferString));
	}
	return retorno;
}


/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'limite - 1' caracteres.
 * \param char* pString Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param int limite Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR)
 *
 */
static int utn_myGets(char* pString, int limite)
{
	int retorno = -1;
	char bufferString[4096];

	if(pString != NULL && limite > 0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString))-1] = '\0';
			}

			if(strnlen(bufferString, sizeof(bufferString)) <= limite)
			{
				strncpy(pString, bufferString, limite);
				retorno = 0;
			}
		}
	}

	return retorno;
}
