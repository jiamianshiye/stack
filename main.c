#include <stdio.h>

#include "stackObj.h"
#include "common.h"

#include "maze.h"

#include "hanoi.h"

#include <time.h>
#include <sys/time.h>
struct StackObjArr stkobj;
int main(int argc, char *argv[])
{
#if 0
    struct timeval vp, va;
    gettimeofday(&vp, NULL);
    hanoi();
    gettimeofday(&va, NULL);
    printf("Cost of time : %d ms\n", (va.tv_sec - vp.tv_sec)*1000 + (va.tv_usec - vp.tv_usec)/1000);
#endif
#if 1
    stkInit(&stkobj, 128);

    maze_work(&stkobj);

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
    p = msg3;
    stkPush(&stkobj, p, strlen(p));
    p = msg4;
    stkPush(&stkobj, p, strlen(p));
    DEBUG_O("%s\n", p);
    stkPop(&stkobj, p);
#endif


    return 0;
}

