#include <stdio.h>

#include "stackObj.h"
#include "common.h"

struct StackObjArr stkobj;
int main(int argc, char *argv[])
{
    stkInit(&stkobj, 3);
#if 0
    char msg1[10]="hello";
    char msg2[10]="world";
    char msg3[10]="empty";
    char msg4[10]="full";
    void *p = msg1;
    stkPush(&stkobj, p, strlen(p));
    DEBUG_O("%s\n", p);

    DEBUG_O("%s\n", p);
    stkPop(&stkobj, p);
#endif


    return 0;
}

