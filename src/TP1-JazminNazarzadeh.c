/*  JAZMÍN NAZARZADEH, 1°H
	TP1
*/

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define TRUE 1
#define FALSE 0

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int respuestaMenu;
	int operando1=0;
	int operando2=0;
	int suma;
	int resta;
	int multiplicacion;
	float division;
	int factorial1;
	int factorial2;
	int respuestaDivision;
	//int flagOperaciones=1;

	do{

		respuestaMenu = utn_getMenu(&opcion, "Error, ingrese una opcion del menu\n", 1, 5, 1, operando1, operando2);

		if(respuestaMenu == 0){
			switch(opcion){
			case 1:
				system("cls");
				utn_getNumero(&operando1, "Ingresar 1° operando: \n", "Error. Reingrese 1° operando\n", -10000, 10000, 2);
				break;
			case 2:
				system("cls");
				utn_getNumero(&operando2, "Ingresar 2° operando: \n", "Error. Reingrese 2° operando\n", -10000, 10000, 2);
				break;
			case 3:
				system("cls");
				utn_getSuma(operando1, operando2, &suma);
				utn_getResta(operando1, operando2, &resta);
				utn_getMultiplicacion(operando1, operando2, &multiplicacion);
				respuestaDivision = utn_getDivision(operando1, operando2, &division, "Error. Vuelva a ingresar los operandos\n");
				utn_getFactorial(operando1, &factorial1);
				utn_getFactorial(operando2, &factorial2);

				break;
			case 4:
				system("cls");
				if(respuestaDivision == 0){
					printf("Suma: %d \nResta: %d \nMultiplicacion: %d \nDivisión: %.2f \nFactorial del 1°operando: %d \nFactorial del 2°operando %d \n",
							suma, resta, multiplicacion, division, factorial1, factorial2);
				}else{
					printf("Suma: %d \nResta: %d \nMultiplicacion: %d \nDivisión: Error \nFactorial del 1°operando: %d \nFactorial del 2°operando %d \n",
							suma, resta, multiplicacion, factorial1, factorial2);
				}

				//con un flag

				break;
			}
		}
	}while(opcion != 5);

	return 0;
}




