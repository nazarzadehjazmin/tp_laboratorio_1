/*  JAZMÍN NAZARZADEH, 1°H
	TP1
*/

#include <stdio.h>
#include <stdlib.h>


/**
 * \brief Solicita un número al usuario, lo valida, verifica y devuelve el resultado
 * \param int* pResultado Puntero al resultado. Aquí se guarda el número ingresado por el usuario
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \param int minimo Valor mínimo para el ingreso de números
 * \param int maximo Valor máximo para el ingreso de números
 * \param int reintentos Cantidad de reintentos en caso de error
 * \return 0 si la función fue exitosa, -1 si da error
 */

int utn_getNumero(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos){
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
 * \brief A partir de 2 números, realiza una suma
 * \param int operandoA Primer número que ingresó el usuario previamente
 * \param int operandoB Segundo número que ingresó el usuario previamente
 * \param int* pResultado Puntero donde se guardará la suma
 * \return 0 si la función fue exitosa, -1 si da error
 */

int utn_getSuma(int operandoA, int operandoB, int* pResultado){
	int retorno = -1;

	if(pResultado != NULL){
		*pResultado = operandoA + operandoB;
		retorno=0;
	}

	return retorno;
}


/**
 * \brief A partir de 2 números, realiza una resta
 * \param int operandoA Primer número que ingresó el usuario previamente
 * \param int operandoB Segundo número que ingresó el usuario previamente
 * \param int* pResultado Puntero donde se guardará la resta
 * \return 0 si la función fue exitosa, -1 si da error
 */

int utn_getResta(int operandoA, int operandoB, int* pResultado){
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

int utn_getMultiplicacion(int operandoA, int operandoB, int* pResultado){
	int retorno = -1;

	if(pResultado != NULL){
		*pResultado = operandoA * operandoB;
		retorno = 0;
	}

	return retorno;
}


/**
 * \brief A partir de 2 números, realiza una división. Valida si el divisor es 0
 * \param int operandoA Primer número que ingresó el usuario previamente
 * \param int operandoB Segundo número que ingresó el usuario previamente
 * \param float* pResultado Puntero donde se guardará la división
 * \param char* pMensajeError  Puntero al mensaje a ser mostrado en caso de error
 * \return 0 si la función fue exitosa, -1 si da error
 */

int utn_getDivision(int operandoA, int operandoB, float* pResultado, char* pMensajeError){
	int retorno;

	if(pResultado != NULL && pMensajeError != NULL && operandoB != 0){
		*pResultado = (float) operandoA / operandoB;
		retorno = 0;
	}else{
		printf("%s", pMensajeError);
		retorno = -1;
	}

	return retorno;
}


/**
 * \brief A partir de 1 número, realiza el factorial.
 * \param int operandoA Primer número que ingresó el usuario previamente
 * \param int* pResultadoA Puntero donde se guardará el factorial
 * \return Devuelve 0 si la función fue exitosa, -1 si da error
 */

int utn_getFactorial(int operandoA, int* pResultadoA){
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

/**
 * \brief Muestra un menu de 5 opciones para calcular operaciones matemáticas de 2 números:
 * 			1 y 2-para pedir números (contiene los valores de los mismos actualizados), 3-calcular operaciones,
 * 			4-informar resultados, 5-salir del menu
 * \param int* pResultado Puntero al resultado. Aquí se guarda el número ingresado por el usuario
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \param int minimo Valor mínimo para el ingreso de números
 * \param int maximo Valor máximo para el ingreso de números
 * \param int reintentos Cantidad de reintentos en caso de error
 * \param int operandoA Primer número que ingresó el usuario
 * \param int operandoB Segundo número que ingresó el usuario
 * \return Devuelve 0 si la función fue exitosa, -1 si da error
 */

int utn_getMenu(int* pResultado, char* pMensajeError, int minimo, int maximo, int reintentos, int operandoA, int operandoB){
	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && pMensajeError != NULL && minimo <= maximo && reintentos >= 0){
		do{
			printf("Menu: \n1-Ingresar primer operando A=%d \n2-Ingresar segundo operando B=%d \n3-Calcular todas las operaciones\n4-Informar resultados\n5-Salir\n",
							operandoA, operandoB);
			fflush(stdin);
			scanf("%d", &bufferInt);

			if(bufferInt >= minimo && bufferInt <= maximo){
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			printf("%s", pMensajeError);
			reintentos--;

			if(reintentos == 0){
				break;
			}

		}while(reintentos >= 0);


	}
	return retorno;
}
