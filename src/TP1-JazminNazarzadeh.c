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
AGREGAR LOS NUMEROS ACTUALES
*/

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define ARRAY_NUMEROS 0

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	//int respuesta;
	int operando1 = 0;
	int operando2 = 0;
	int suma;
	int resta;
	int multiplicacion;
	float division;
	int factorial1;
	int factorial2;

	do{
		/*respuesta= utn_getNumero(&opcion, "Menú: \n1-Ingresar 1° operando A= \n2-Ingresar 2° operando B= \n3-Calcular todas las operaciones\n4-Informar resultados\n5-Salir",
					"Error, el número ingresado no es una opción del menú\n", 1, 5, 3);*/
		printf("Menú: \n1-Ingresar 1° operando A=%d",operando1);
		printf("\n2-Ingresar 2° operando B=%d", operando2);
		printf("\n3-Calcular todas las operaciones\n4-Informar resultados\n5-Salir");
		fflush(stdin);
		scanf("%d", &opcion);

		//if(respuesta == 0){
			switch(opcion){
			case 1:
				utn_getNumero(&operando1, "Ingresar 1° operando: ", "Error. Reingrese 1° operando", -10000, 10000, 2);
				break;
			case 2:
				utn_getNumero(&operando2, "Ingresar 2° operando: ", "Error. Reingrese 2° operando", -10000, 10000, 2);
				break;
			case 3:
				utn_getSuma(operando1, operando2, &suma);
				utn_getResta(operando1, operando2, &resta);
				utn_getMultiplicacion(operando1, operando2, &multiplicacion);
				utn_getDivision(operando1, operando2, &division, "No es posible dividir por cero");
				utn_getFactorial(operando1, &factorial1);
				utn_getFactorial(operando2, &factorial2);

				break;
			case 4:
				printf("Suma: %d \nResta: %d \nMultiplicacion: %d \nDivisión: %.2f \nFactorial del 1°operando: %d \nFactorial del 2°operando %d \n",
						suma, resta, multiplicacion, division, factorial1, factorial2);
				break;
			case 5:
				break;
			}
		//}
	}while(opcion != 5);

	return 0;
}

//division: 1/3= da 0, pero es 0,5
//no sale con la opcion 5


/*
	utn_getOperandoInt(&operando1, "Ingrese el primer operando(desde -10000 hasta 10000)\n", "Error\n", -10000, 10000, 1);
 	 if(respuesta1==0){
		printf("Primer operando: %d \n", operando1);
	}
*/

/*
	utn_getOperandoInt(&operando2, "Ingrese el segundo operando(desde -10000 hasta 10000)\n", "Error\n", -10000, 10000, 1);
 	 if(respuesta2==0){
		printf("Operando2: %d \n", operando2);
	}
*/

/*
	utn_getSuma(operando1, operando2, &resultado);
	if(resultadoSuma==0){
		printf("Suma: %d", resultado);
	}
*/
/*
	utn_getResta(operando1, operando2, &resultado);
	if(resultadoT==0){
		printf("Resta: %d", resultado);
	}
*/
/*
	resultadoT= utn_getMultiplicacion(operando1, operando2, &resultado);
	if(resultadoT==0){
		printf("Multiplicacion: %d", resultado);
	}
*/
/*
	resultadoT= utn_getDivision(operando1, operando2, &resultadoFloat, "No es posible dividir por cero\n");
	if(resultadoT==0){
		printf("Division: %.2f", resultadoFloat);
	}
*/

/*
	resultadoT= utn_getFactorial(operando1, &resultado1);
	if(resultadoT==0){
		printf("Factorial del primer operando: %d \n", resultado1);
	}
*/
