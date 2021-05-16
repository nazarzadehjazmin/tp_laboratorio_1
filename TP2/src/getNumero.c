#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int utn_myGets(char* pString, int longitud);
static int utn_getInt(int* pResultado);
static int utn_esNumerica(char* pString, int limite);

/**
 * \brief
 * \param
 * \return
 */

static int utn_getInt(int* pResultado){
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
 * \brief
 * \param
 * \return
 */
int utn_getNumero(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos){
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


/**
 * \brief
 * \param
 * \return
 */
static int utn_myGets(char* pString, int limite){
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
 * \brief
 * \param
 * \return
 */
static int utn_esNumerica(char* pString, int limite){
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


