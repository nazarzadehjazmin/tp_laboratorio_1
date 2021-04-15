/*  JAZMÍN NAZARZADEH, 1°H
	TP1
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Solicita un número al usuario, lo valida, verifica y devuelve el resultado
 * \param pResultado Puntero al resultado. Aquí se guarda el número ingresado por el usuario
 * \param pMensaje Puntero al mensaje a ser mostrado
 * \param pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \param minimo Valor mínimo para el ingreso de números
 * \param maximo Valor máximo para el ingreso de números
 * \param reintentos Cantidad de reintentos en caso de error
 * \return 0 si la función fue exitosa, -1 si da error
 */
int utn_getNumero(int *pResultado, char *pMensaje, char *pMensajeError, int minimo, int maximo, int reintentos){
	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && minimo <= maximo && reintentos >= 0){
		do{
			printf("%s", pMensaje);
			fflush(stdin);
			scanf("%d", &bufferInt);

			if(bufferInt >= minimo && bufferInt <= maximo){
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			printf("%s", pMensajeError);
			reintentos--;

		}while(reintentos>=0);
	}

	return retorno;
}


/**
 * \brief
 * \param
 * \return
 */


/*	printf("Menú: \n1-Ingresar 1° operando A=%d",operando1);
	printf("\n2-Ingresar 2° operando B=%d", operando2);
	printf("\n3-Calcular todas las operaciones\n4-Informar resultados\n5-Salir");
	fflush(stdin);
	scanf("%d", &opcion);*/

/*
int utn_getMenu(char *pMensaje){
	int retorno = 0;
	int bufferInt;

	printf("%s", pMensaje);
	fflush(stdin);
	scanf("%d", &bufferInt);
	printf("%d", bufferInt);

	return retorno;
}
*/



/**
 * \brief A partir de 2 números, realiza una suma
 * \param operandoA Primer número que ingresó el usuario previamente
 * \param operandoB Segundo número que ingresó el usuario previamente
 * \param pResultado Puntero donde se guardará la suma
 * \return 0 si la función fue exitosa, -1 si da error
 */

int utn_getSuma(int operandoA, int operandoB, int *pResultado){
	int retorno = -1;

	if(pResultado != NULL){
		*pResultado = operandoA + operandoB;
		retorno=0;
	}

	return retorno;
}


/**
 * \brief A partir de 2 números, realiza una resta
 * \param operandoA Primer número que ingresó el usuario previamente
 * \param operandoB Segundo número que ingresó el usuario previamente
 * \param pResultado Puntero donde se guardará la resta
 * \return 0 si la función fue exitosa, -1 si da error
 */
int utn_getResta(int operandoA, int operandoB, int *pResultado){
	int retorno = -1;

	if(pResultado != NULL){
		*pResultado = operandoA - operandoB;
		retorno = 0;
	}

	return retorno;
}


/**
 * \brief A partir de 2 números, realiza una multiplicación
 * \param operandoA Primer número que ingresó el usuario previamente
 * \param operandoB Segundo número que ingresó el usuario previamente
 * \param pResultado Puntero donde se guardará la multiplicación
 * \return 0 si la función fue exitosa, -1 si da error
 */
int utn_getMultiplicacion(int operandoA, int operandoB, int *pResultado){
	int retorno = -1;

	if(pResultado != NULL){
		*pResultado = operandoA * operandoB;
		retorno = 0;
	}

	return retorno;
}


/**
 * \brief A partir de 2 números, realiza una división. Valida si el divisor es 0
 * \param operandoA Primer número que ingresó el usuario previamente
 * \param operandoB Segundo número que ingresó el usuario previamente
 * \param pResultado Puntero donde se guardará la división
 * \param pMensajeError  Puntero al mensaje a ser mostrado en caso de error
 * \return 0 si la función fue exitosa, -1 si da error
 */
int utn_getDivision(int operandoA, int operandoB, float *pResultado, char *pMensajeError){
	int retorno;

	if(pResultado != NULL && pMensajeError != NULL && operandoB != 0){
		*pResultado = operandoA / operandoB;
		retorno = 0;
	}else{
		printf("%s", pMensajeError);
		retorno = -1;
	}

	return retorno;
}


/**
 * \brief A partir de 1 número, realiza el factorial.
 * \param operandoA Primer número que ingresó el usuario previamente
 * \param pResultadoA Puntero donde se guardará el factorial
 * \return 0 si la función fue exitosa, -1 si da error
 */

int utn_getFactorial(int operandoA, int *pResultadoA){
	int retorno = -1;
	int i;
	int acumuladorFactorialA=1;

	if(pResultadoA != NULL){
		for(i = 1; i <= operandoA; i++){
			acumuladorFactorialA*=i;
		}
		*pResultadoA = acumuladorFactorialA;
		retorno = 0;
	}

	return retorno;
}

