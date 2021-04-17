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
	int flagOperaciones = 0;
	int contadorOperando1 = 0;
	int contadorOperando2 = 0;

	do{
		respuestaMenu = utn_getMenu(&opcion, "Error, ingrese una opcion del menu\n", 1, 5, 1, operando1, operando2);

		if(respuestaMenu == 0){
			switch(opcion){
			case 1:
				system("cls");
				if(utn_getNumero(&operando1, "Ingresar 1° operando: \n", "Error. Reingrese 1° operando\n", -10000, 10000, 2)==0){
					contadorOperando1++;
				}

				break;
			case 2:
				system("cls");
				if(utn_getNumero(&operando2, "Ingresar 2° operando: \n", "Error. Reingrese 2° operando\n", -10000, 10000, 2)==0){
					contadorOperando2++;
				}
				break;
			case 3:
				system("cls");
				if(contadorOperando1 == 1 && contadorOperando2 == 1){
					flagOperaciones = 1;
				}

				if(flagOperaciones == 1){
					utn_getSuma(operando1, operando2, &suma);
					utn_getResta(operando1, operando2, &resta);
					utn_getMultiplicacion(operando1, operando2, &multiplicacion);
					respuestaDivision = utn_getDivision(operando1, operando2, &division, "Error. No se puede dividir por 0. Vuelva a ingresar el segundo operando\n");

					if(operando1 >= 0 && operando2 >= 0){
						utn_getFactorial(operando1, &factorial1);
						utn_getFactorial(operando2, &factorial2);
					}else{
						printf("Error, no se puede calcular el factorial. Reingrese operandos positivos\n");
					}
				}else{
					printf("Error. No ha ingresado los 2 operandos.\nPor favor, reingreselos con las opciones 1 y 2\n");
				}
				break;
			case 4:
				system("cls");
				if(flagOperaciones == 1){
					if(respuestaDivision == 0 && operando1 >= 0 && operando2 >= 0){
						printf("Suma: %d \nResta: %d \nMultiplicacion: %d \nDivisión: %.2f \nFactorial del 1°operando: %d \nFactorial del 2°operando %d \n",
								suma, resta, multiplicacion, division, factorial1, factorial2);
					}else{
						printf("Error. No se pudo calcular la division y/o el factorial, vuelva a ingresar los operandos\n");
					}
				}else{
					printf("Error. No ha ingresado los 2 operandos.\nPor favor, reingreselos con las opciones 1 y 2\n");
				}
				break;
			}
		}
	}while(opcion != 5);

	return 0;
}


