#include <stdio.h>
#include "maze.h"
#include "stackObj.h"
#include "common.h"

#include "hanoi.h"

void hanoi_cbx(int *pa)
{
    printf("[%d]", *pa);
}
static move(struct StackObjArr *psrc, int num,  struct StackObjArr *pdest)
{
    int memb;
    int i = 0;
    for(i = 0; i < num; i++){
        if(stkPop(psrc, &memb) == 0)
            stkPush(pdest, &memb, sizeof(int));
    }
//    printf("move %s-%d to %s \n", psrc->arr_name, memb, pdest->arr_name);
}

static void process(int num, struct StackObjArr *pstkA, struct StackObjArr *pstkB
                    , struct StackObjArr *pstkC)
{
    if(num == 1){
        move(pstkA, 1, pstkC);
//        stkPrint(pstkA, hanoi_cbx);
//        stkPrint(pstkB, hanoi_cbx);
//        stkPrint(pstkC, hanoi_cbx);
    }else{
        process(num - 1, pstkA, pstkC, pstkB);
        move(pstkA, 1, pstkC);
        process(num - 1, pstkB, pstkA, pstkC);
    }

}

int hanoi()
{
    //construct three stack A and B and C
    struct StackObjArr stkA, stkB, stkC;
    int stkIndex;

    stkInit(&stkA, HANOI_NUMS);
    stkSetName(&stkA, "SA");
    stkInit(&stkB, HANOI_NUMS);
    stkSetName(&stkB, "SB");
    stkInit(&stkC, HANOI_NUMS);
    stkSetName(&stkC, "SC");

    for(stkIndex = HANOI_NUMS; stkIndex > 0; stkIndex--){
        stkPush(&stkA, &stkIndex, sizeof(int));
    }
//    stkPrint(&stkA, hanoi_cbx);
//    stkPrint(&stkB, hanoi_cbx);
//    stkPrint(&stkC, hanoi_cbx);
    process(HANOI_NUMS, &stkA, &stkB, &stkC);
//    stkPrint(&stkC, hanoi_cbx);
}


