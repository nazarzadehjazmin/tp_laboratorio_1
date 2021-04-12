
#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int *pResultado, char *pMensaje, char *pMensajeError, int minimo, int maximo, int reintentos);
int utn_getSuma(int operandoA, int operandoB, int *pResultado);
int utn_getResta(int operandoA, int operandoB, int *pResultado);
int utn_getMultiplicacion(int operandoA, int operandoB, int *pResultado);
int utn_getDivision(int operandoA, int operandoB, float *pResultado, char *pMensajeError);
int utn_getFactorial(int operandoA, int *pResultadoA);

#endif /* UTN_H_ */
