#include <stdio.h>

#include "stackObj.h"
#include "common.h"

struct StackObjArr stkobj;
int main(int argc, char *argv[])
{
    stkInit(&stkobj, 3);
    char msg1[10]="hello";
    char msg2[10]="world";
    char msg3[10]="empty";
    char msg4[10]="full";
    void *p = msg1;
    stkPush(&stkobj, p, strlen(p));
    DEBUG_O("%s\n", p);
    p = msg2;
    stkPush(&stkobj, p, strlen(p));
    DEBUG_O("%s\n", p);
    p = msg3;
    stkPush(&stkobj, p, strlen(p));
    DEBUG_O("%s\n", p);
    p = msg4;
    stkPush(&stkobj, p, strlen(p));
    DEBUG_O("%s\n", p);
    stkPop(&stkobj, p);
    DEBUG_O("%s\n", p);
    stkPop(&stkobj, p);
    DEBUG_O("%s\n", p);
    stkPop(&stkobj, p);
    DEBUG_O("%s\n", p);
    stkPop(&stkobj, p);
    DEBUG_O("%s\n", p);

    return 0;
}

