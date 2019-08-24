#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"list.h"
//////////////////////////////////////////
Employees* deleteLast(Employees *last)
{
    Employees *p = NULL;

    if(last != NULL)
    {
    p = last->pprev;

    free(last);
    last = NULL;

    if(p != NULL)
        p->pnext = NULL;
    }
    return p;
}
//////////////////////////////////////////
void saveList(Employees *p, char *file)
{
    FILE *pf = fopen(file, "wb");

    while(p != NULL)
    {
        fwrite(p, sizeof(Employees), 1, pf);
        p = p->pnext;
    }
    fclose(pf);
}
//////////////////////////////////////////
void printList(Employees *p)
{
    while(p != NULL)
    {
        print(p);
        p = p->pnext;
    }
}
//////////////////////////////////////////
Employees* addEnd(Employees *p, Employees *last)
{
    Employees *pAdd = (Employees*)malloc(sizeof(Employees));
    *pAdd = *p;

    if(last == NULL)
        last = pAdd;
    else
    {
        last->pnext = pAdd;
        pAdd->pprev = last;
        last = pAdd;
    }

    return last;
}
/////////////////////////////////////////
void getUser(Employees *p)
{
    Employees tmp;

    printf("Enter the name: \n");
    fflush(stdin);
    fgets(tmp.fname, MAXFNAME, stdin);
    tmp.fname[strlen(tmp.fname)-1] = '\0';
    printf("Enter salary: \n");
    scanf("%lf", &tmp.salary);
    printf("Enter the age of the employee: \n");
    scanf("%d", &tmp.age);

    tmp.pnext = tmp.pprev = NULL;

    *p = tmp;
}
/////////////////////////////////////////
void print(Employees *p)
{
    printf("\n************************\n");
    printf("Name:\t %s\n", p->fname);
    printf("Salary:\t %g\n", p->salary);
    printf("Age:\t %d\n", p->age);
    printf("\n************************\n");
}
/////////////////////////////////////////
