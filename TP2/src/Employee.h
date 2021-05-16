#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#define EMPLOYEE_QTY 1000
#define FREE 0
#define TAKEN 1
#define REMOVE -1
#define CHARACTERS_QTY 51

typedef struct
{
	int id;
	char name[CHARACTERS_QTY];
	char lastName[CHARACTERS_QTY];
	float salary;
	int sector;
	int isEmpty;
}Employee;

int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char* name,char* lastName, float salary, int sector);
int findEmployeeById(Employee* list, int len, int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
void printOneEmployee(Employee oneEmployee);
int printEmployees(Employee* list, int length);
int createNewId(void);
int findEmptyIndex(Employee* list, int len);

#endif /* EMPLOYEE_H_ */
