#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define QTY_NAME 128
typedef struct
{
    int id;
    char nombre[QTY_NAME];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

void employee_setearValorInicialDeId(int id);
int employee_generarId(void);

//ID
int employee_setId(Employee* this, int id);
int employee_getId(Employee* this, int* id);

//ID TXT
int employee_setIdTxt(Employee* this, char* id);
char* employee_getIdTxt(Employee* this, int* flagError);
int isValidIdTxt(char* id);

//NOMBRE
int employee_setNombre(Employee* this, char* nombre);
int employee_getNombre(Employee* this, char* nombre);
int isValidNombre(char* name);

//HORAS TRABAJADAS
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas);
int isValidHorasTrabajadas(int horasTrabajadas);

//HORAS TRABAJADAS TXT
int employee_setHorasTrabajadasTxt(Employee* this, char* horasTrabajadas);
char* employee_getHorasTrabajadasTxt(Employee* this, int* flagError);
int isValidHorasTrabajadasTxt(char* horasTrabajadas);

//SUELDO
int employee_setSueldo(Employee* this, int sueldo);
int employee_getSueldo(Employee* this, int* sueldo);
int isValidSueldo(int sueldo);

//SUELDO TXT
int employee_setSueldoTxt(Employee* this, char* sueldo);
char* employee_getSueldoTxt(Employee* this, int* flagError);
int isValidSueldoTxt(char* sueldo);

#endif // employee_H_INCLUDED
