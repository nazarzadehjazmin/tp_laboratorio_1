/*
 ============================================================================
 Name        : TP1-JazminNazarzadeh.c
 Author      : Jazmín Nazarzadeh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

int main(void) {
	setbuf(stdout, NULL);

	float A;
	float B;
	char operacion;
	float resultado;

	printf("Ingrese un primer operando: ");
	scanf("%f", &A);

	printf("Ingrese un segundo operando: ");
	scanf("%f", &B);

	printf("Ingrese operacion (+,-,/,*,!): ");
	fflush(stdin);
	scanf("%c", &operacion);

	switch(operacion){
	case '+':
		resultado=biblio_sumar(A,B);
		break;
//	case '-':
//		break;
//	case '*':
//		break;
//	case '/':
//		break;
//	case '!':
//		break;
	}

	if(resultado==0){
	printf("Suma: %.2f", resultado);
	}

	return EXIT_SUCCESS;
}
