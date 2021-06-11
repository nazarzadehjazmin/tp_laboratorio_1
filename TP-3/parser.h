#ifndef PARSER_H_
#define PARSER_H_
#define CHAR_QTY 250
#include "LinkedList.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee);

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);


#endif /* PARSER_H_ */
