/*  JAZMÍN NAZARZADEH, 1°H
	TP1
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones

a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)

4. Informar resultados

a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”

• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.

• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)

• Deberán contemplarse los casos de error (división por cero, etc)

• Documentar todas las funciones

VALIDAR QUE NO INGRESE LETRAS
*/

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

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

	do{

		respuestaMenu = utn_getMenu(&opcion, "Error, ingrese una opcion del menu\n", 1, 5, 1, operando1, operando2);

		if(respuestaMenu == 0){
			switch(opcion){
			case 1:
				utn_getNumero(&operando1, "Ingresar 1° operando: \n", "Error. Reingrese 1° operando\n", -10000, 10000, 2);
				break;
			case 2:
				utn_getNumero(&operando2, "Ingresar 2° operando: \n", "Error. Reingrese 2° operando\n", -10000, 10000, 2);
				break;
			case 3:
				utn_getSuma(operando1, operando2, &suma);
				utn_getResta(operando1, operando2, &resta);
				utn_getMultiplicacion(operando1, operando2, &multiplicacion);
				respuestaDivision = utn_getDivision(operando1, operando2, &division, "Error. Vuelva a ingresar los operandos\n");
				utn_getFactorial(operando1, &factorial1);
				utn_getFactorial(operando2, &factorial2);

				break;
			case 4:
				if(respuestaDivision == 0){
					printf("Suma: %d \nResta: %d \nMultiplicacion: %d \nDivisión: %.2f \nFactorial del 1°operando: %d \nFactorial del 2°operando %d \n",
							suma, resta, multiplicacion, division, factorial1, factorial2);
				}else{
					printf("Suma: %d \nResta: %d \nMultiplicacion: %d \nDivisión: Error \nFactorial del 1°operando: %d \nFactorial del 2°operando %d \n",
							suma, resta, multiplicacion, factorial1, factorial2);
				}

				break;
			}
		}
	}while(opcion != 5);

	return 0;
}




