#ifndef LIST_H_
#define LIST_H_

#define MAXFNAME 56

//////////////////////////////////////////////
struct tagEmployees
{
    char fname[MAXFNAME];
    double salary;
    int age;

    struct tagEmployees *pnext, *pprev;
};
typedef struct tagEmployees Employees;
//////////////////////////////////////////////
void getUser(Employees *p);
void print(Employees *p);
Employees* addEnd(Employees *p, Employees *last);
void printList(first);
void saveList(Employees *first, char *file);
Employees* deleteLast(Employees *last);

#endif // LIST_H_
