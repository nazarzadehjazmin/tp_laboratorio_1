//MAL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int utn_getFloat(float* pResultado);
static int utn_esFlotante(char* pString, int limite);
static int utn_myGets(char* pString, int longitud);
/*
 * \brief Lee stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un maximo de 'longitud-1' caracteres
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (exito) si se obtiene una cadena, sino -1 (error)
 */


static int utn_myGets(char* pString, int longitud){
	int retorno = -1;
	char bufferString[4096];

	if(pString != NULL && longitud > 0){
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL){
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] == '\n'){
				bufferString[strnlen(bufferString, sizeof(bufferString))-1] = '\0';
			}

			if(strnlen(bufferString, sizeof(bufferString)) <= longitud){
				strncpy(pString, bufferString, longitud);
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

static int utn_getFloat(float* pResultado){
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
 * \brief
 * \param
 * \return
 */

static int utn_esFlotante(char* pString, int limite){
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
 * \brief
 * \param
 * \return
 */
int utn_getFlotante(float* pResultado, char* pMensaje, char* pMensajeError, float minimo, float maximo, int reintentos){
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





