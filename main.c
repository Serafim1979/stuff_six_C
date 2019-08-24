#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"list.h"

int main()
{
    int n = 0;
    Employees emp;
    Employees *first=NULL, *last = NULL;

    label:
    printf("Selected action: \n");
    printf(" 1. Add\n 2. Delete last\n");
    printf(" 3. Save\n 4. Load\n");
    printf(" 5. Print\n 6. Find\n");
    printf(" 7. Exit\n");

    scanf("%d", &n);

    switch(n)
    {
    case 1: getUser(&emp);
            last = addEnd(&emp, last);
            if(first == NULL)
                first = last;
        break;
    case 2: last = deleteLast(last);
            if(last == NULL)
                    first == NULL;
        break;
    case 3: saveList(first, "list.dat");
        break;
    case 4:
        break;
    case 5: printList(first);
        break;
    case 6:
        break;
    case 7: exit(0);
        break;
    }
    goto label;

    return 0;
}
