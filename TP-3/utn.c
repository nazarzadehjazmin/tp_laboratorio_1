#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int utn_myGets(char* pString, int longitud);

//getNumero
static int utn_getInt(int* pResultado);
static int utn_esNumerica(char* pString, int limite);

//getFloat
static int utn_getFloat(float* pResultado);
static int utn_esFlotante(char* pString, int limite);

//getNombre
static int utn_getString(char* pString, int limite);
static int esNombre(char* pString, int limite);

//getDescripcion
static int getDescripcion(char* pResultado, int limite);
static int esDescripcion(char* cadena, int limite);
static int getString(char* pResultado);

////////////////////////////////////////GETNUMERO////////////////////////////////////////

/**
 * \brief Obtiene un numero entero
 * \param int* pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */

static int utn_getInt(int* pResultado)
{
	int retorno = -1;
	char bufferString[400];

	if(pResultado != NULL &&
		utn_myGets(bufferString, sizeof(bufferString)) == 0 &&
		utn_esNumerica(bufferString, sizeof(bufferString)))
	{
		*pResultado = atoi(bufferString);
		retorno = 0;
	}
	return retorno;
}


/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param int* pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param char* pMensaje Es el mensaje a ser mostrado
 * \param char* pMensajeError Es el mensaje de Error a ser mostrado
 * \param int minimo Es el numero maximo a ser aceptado
 * \param int maximo Es el minimo minimo a ser aceptado
 * \param int reintentos Cantidad de veces que puede reingresar los datos en caso de que no hayan sido validos
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumero(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && minimo <= maximo && reintentos >= 0){
		do{
			printf("%s", pMensaje);
			if(utn_getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo){
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			printf("%s", pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}

	return retorno;
}


/*
 * \brief Lee stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un maximo de 'limite-1' caracteres
 * \param char* pString Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param int limite Define el tamaño de cadena
 * \return Retorna 0 (exito) si se obtiene una cadena, sino -1 (error)
 */

static int utn_myGets(char* pString, int limite)
{
	int retorno = -1;
	char bufferString[4000];

	if(pString != NULL && limite > 0){
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL){
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] == '\n'){
				bufferString[strnlen(bufferString, sizeof(bufferString))-1] = '\0';
			}

			if(strnlen(bufferString, sizeof(bufferString)) <= limite){
				strncpy(pString, bufferString, limite);
				retorno = 0;
			}
		}
	}

	return retorno;
}


/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param char* cadena Cadena de caracteres a ser analizada
 * \param int limite Define el tamaño de cadena
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */

static int utn_esNumerica(char* pString, int limite)
{
	int retorno = -1;
	int i;

	if(pString != NULL && limite > 0){
		retorno = 1;
		for(i = 0; i < limite && pString[i] != '\0'; i++){
			if(i == 0 && (pString[i] == '+' || pString[i] == '-')){
				continue;
			}
			if(pString[i] < '0' || pString[i] > '9'){
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}



////////////////////////////////////////////GETFLOAT///////////////////////////////////////

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param float* pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */

static int utn_getFloat(float* pResultado)
{
	int retorno = -1;
	char bufferString[400];

	if(pResultado != NULL &&
		utn_myGets(bufferString, sizeof(bufferString)) == 0 &&
		utn_esFlotante(bufferString, sizeof(bufferString)))
	{
		*pResultado = atof(bufferString);
		retorno = 0;
	}
	return retorno;
}


/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param char* pString Cadena de caracteres a ser analizada
 * \param int limite Define el tamaño de cadena
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */

static int utn_esFlotante(char* pString, int limite)
{
	int retorno = -1;
	int i;
	int contadorPuntos = 0;

	if(pString != NULL && limite > 0){
		retorno = 1;
		for(i = 0; i < limite && pString[i] != '\0'; i++){
			if(i == 0 && (pString[i] == '+' || pString[i] == '-')){
				continue;
			}
			if(pString[i] < '0' || pString[i] > '9'){
				if(pString[i] == '.' && contadorPuntos == 0){
					contadorPuntos++;
				}else{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}


/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param float* pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param char* pMensaje Es el mensaje a ser mostrado
 * \param char* pMensajeError Es el mensaje de Error a ser mostrado
 * \param float minimo Es el numero maximo a ser aceptado
 * \param float maximo Es el minimo minimo a ser aceptado
 * \param int reintentos Cantidad de veces que puede reingresar los datos en caso de que no hayan sido validos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */

int utn_getFlotante(float* pResultado, char* pMensaje, char* pMensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;

	if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && minimo <= maximo && reintentos >= 0){
		do{
			printf("%s", pMensaje);
			if(utn_getFloat(&bufferFloat) == 0 && bufferFloat >= minimo && bufferFloat <= maximo){
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			printf("%s", pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}

	return retorno;
}


//////////////////////////////////////////GETNOMBRE///////////////////////////////////////////

/**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 * \param char* pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param char* pMensaje Es el mensaje a ser mostrado
 * \param char* pMensajeError Es el mensaje de Error a ser mostrado
 * \param int reintentos Cantidad de veces que puede reingresar los datos en caso de que no hayan sido validos
 * \param int limite Es la longitud del array resultado
 * \return Retorna 0 si se obtuvo la cadena de caracteres y -1 si no
 *
 */
int utn_getNombre(char* pResultado, char* pMensaje, char* pMensajeError, int reintentos, int limite)
{
    int retorno=-1;
    char buffer[4000];

    if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && reintentos >= 0 && limite > 0){
    	do{
    		printf("%s", pMensaje);
        	if(utn_getString(buffer,sizeof(buffer)) == 0 && esNombre(buffer,sizeof(buffer)) == 1 &&
        		strnlen(buffer,sizeof(buffer)) < limite){
        		strncpy(pResultado, buffer, limite);
    			retorno = 0;
    			break;
    		}else{
				printf("%s", pMensajeError);
				reintentos--;
    		}
    	}while(reintentos >= 0);
    }
    return retorno;
}


/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 * \param char* pString Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param int limite Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
static int utn_getString(char* pString, int limite)
{
	int retorno = -1;
	char bufferString[4000];

	if(pString != NULL && limite > 0){
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL){
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] == '\n'){
				bufferString[strnlen(bufferString, sizeof(bufferString))-1] = '\0';
			}

			if(strnlen(bufferString, sizeof(bufferString)) <= limite){
				strncpy(pString, bufferString, limite);
				retorno = 0;
			}
		}
	}

	return retorno;
}


/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param char* pString Cadena de caracteres a ser analizada
 * \param int limite Define el tamaño de cadena
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esNombre(char* pString, int limite)
{
	int retorno = 1;
	int i = 0;

	if(pString != NULL && limite > 0){
		for(i = 0; pString[i] != '\0' && i < limite; i++){
			if((pString[i] < 'a' || pString[i] > 'z') && (pString[i] < 'A' || pString[i] > 'Z')){
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

//////////////////////////////////GETDESCRIPCION///////////////////////////////////////

/**
 * \brief Solicita una descripcion al usuario, luego de verificarlo devuelve el resultado
 * \param char* pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param char* mensaje Es el mensaje a ser mostrado
 * \param char* mensajeError Es el mensaje de Error a ser mostrado
 * \param int reintentos Cantidad de veces que puede reingresar los datos en caso de que no hayan sido validos
 * \param int limite Longitud del array resultado
 * \return Retorna 0 si se obtuvo una cadena de caracteres y -1 si no
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
 * \return Retorna 0 (EXITO) si se obtiene una cadena de caracteres y -1 (ERROR) si no
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
 * \param char* cadena Cadena de caracteres a ser analizada
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
 * \param char* pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
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


