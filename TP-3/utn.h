#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos);

int utn_getFlotante(float* pResultado, char* pMensaje, char* pMensajeError, float minimo, float maximo, int reintentos);

int utn_getNombre(char* pResultado, char* pMensaje, char* pMensajeError, int reintentos, int limite);

int utn_getDescripcion(char* pResultado, char* mensaje, char* mensajeError, int reintentos, int limite);
#endif /* UTN_H_ */
