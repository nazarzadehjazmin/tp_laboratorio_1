#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Inputs.h"
#define EMPTY_LIST_ERROR "Error, lista vacía. Cargue los datos primero\n"
#define ALREADY_ENTERED_ERROR "Error, ya ha cargado los datos en el archivo\n"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    char continuar;
    int option1 = 0;
    int option2 = 0;
    int option8 = 0;
    int option9 = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	if(utn_getNumero(&option, "\nMenu: \n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto) \n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario) \n3. Alta de empleado \n4. Modificar datos de empleado \n5. Baja de empleado \n6. Listar empleados \n7. Ordenar empleados \n8. Guardar los datos de los empleados en el archivo data.csv (modo texto) \n9. Guardar los datos de los empleados en el archivo data.csv (modo binario) \n10. Salir\n", "Error, reingrese el dato\n", 1, 10, 5) == 0)
		{
            switch(option)
            {
                case 1:
                	if(option1 == 0)
                	{
                		controller_loadFromText("data.csv",listaEmpleados);
                		option1++;
                		option2 = 1;
                	}
                	else
                	{
                		printf(ALREADY_ENTERED_ERROR);
                	}
                    break;
                case 2:
                	if(option2 == 0)
                	{
                		controller_loadFromBinary("data.bin", listaEmpleados);
                		option2++;
                		option1 = 1;
                	}
                	else
                	{
                		printf(ALREADY_ENTERED_ERROR);
                	}
                	break;
                case 3:
                	if(ll_isEmpty(listaEmpleados) == 0)
					{
                		controller_addEmployee(listaEmpleados);
                		option8 = 0;
                		option9 = 0;
					}
                	else
                	{
                		printf(EMPTY_LIST_ERROR);
                	}
                	break;
                case 4:
                	if(ll_isEmpty(listaEmpleados) == 0)
					{
                		controller_editEmployee(listaEmpleados);
                		option8 = 0;
                		option9 = 0;
					}
                	else
                	{
                		printf(EMPTY_LIST_ERROR);
                	}
                	break;
                case 5:
                	if(ll_isEmpty(listaEmpleados) == 0)
					{
                		controller_removeEmployee(listaEmpleados);
                		option8 = 0;
                		option9 = 0;
					}
                	else
                	{
                		printf(EMPTY_LIST_ERROR);
                	}
                	break;
                case 6:
                	if(ll_isEmpty(listaEmpleados) == 0)
                	{
                		controller_ListEmployee(listaEmpleados);
                	}
                	else
                	{
                		printf(EMPTY_LIST_ERROR);
                	}
                	break;
                case 7:
                	if(ll_isEmpty(listaEmpleados) == 0)
                	{
                		controller_sortEmployee(listaEmpleados);
                	}
                	else
                	{
                		printf(EMPTY_LIST_ERROR);
                	}
                	break;
                case 8:
                	if(ll_isEmpty(listaEmpleados) == 0)
                	{
                		controller_saveAsText("data.csv", listaEmpleados);
                		option8++;
                	}
                	else
                	{
                		printf(EMPTY_LIST_ERROR);
                	}
                	break;
                case 9:
                	if(ll_isEmpty(listaEmpleados) == 0)
                	{
                		controller_saveAsBinary("data.bin", listaEmpleados);
                		option9++;
                	}
                	else
                	{
                		printf(EMPTY_LIST_ERROR);
                	}
                	break;
                case 10:
                	if(ll_isEmpty(listaEmpleados) == 0 && option8 == 0 && option9 == 0)
                	{
                		utn_getContinuar(&continuar, "Desea salir del programa sin guardar?", ERROR_MSG, QTY_REINTENTO);
                	}
                	else
                	{
                		ll_clear(listaEmpleados);
                		ll_deleteLinkedList(listaEmpleados);
                		printf("\nHasta la próxima!\n");
                	}
                	break;
            }
		}
    }while((continuar == 'n' || continuar == 'N') || option != 10);

    return 0;
}

