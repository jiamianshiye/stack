#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "stackObj.h"

int stkInit(struct StackObjArr *pObjArr, int num)
{
//    int i = 0;
    if(pObjArr == NULL || num <= 0){
        DEBUG_E("Wrong arguments!\n");
        return -1;
    }
    pObjArr->arr_nums = num;
    pObjArr->arr_pbase = malloc(sizeof(struct StackObjUnit) * (num + 1));
    memset(pObjArr->arr_pbase, 0, sizeof(struct StackObjUnit) * (num + 1));
    pObjArr->arr_ptop = NULL;
//    pObjArr->arr_ptop = pObjArr->arr_pbase;
    (pObjArr->arr_pbase + num)->unit_ptr = NULL;
    (pObjArr->arr_pbase + num)->unit_size = -1; // Full flag
//    for(i = 0; i < num; i++){

//    }

    return 0;
}
int stkSetName(struct StackObjArr *pObjArr, char *name)
{
    int name_len;
    if(pObjArr == NULL)
        return -1;
    name_len = strlen(name) > STACK_NAME_LEN ? STACK_NAME_LEN : strlen(name);
    strncpy(pObjArr->arr_name, name, name_len);
    pObjArr->arr_name[name_len] = '\0';
    return 0;
}


int stkPush(struct StackObjArr *pObjArr, void *ptr, int size)
{
    /*if stack if full*/
    if(pObjArr->arr_ptop == NULL){
        DEBUG_E("Stack is empty, First push !\n");
        pObjArr->arr_ptop = pObjArr->arr_pbase;
    }

    if(pObjArr->arr_ptop->unit_size == -1){
        DEBUG_E("Stack is full !\n");
        return -1;
    }
    pObjArr->arr_ptop->unit_size = size;
    pObjArr->arr_ptop->unit_ptr = malloc(size);
    if(pObjArr->arr_ptop->unit_ptr != NULL){
        memcpy(pObjArr->arr_ptop->unit_ptr, ptr, size);
        pObjArr->arr_ptop++;
    }else{
        DEBUG_E("Out of memory!\n");
        return -1;
    }

    return 0;
}

int stkPop(struct StackObjArr *pObjArr, void *ptr)
{
    struct StackObjUnit *pUnit = NULL;

    if(pObjArr->arr_pbase == NULL)
    {
        DEBUG_E("Stack uninitlized !\n");
        return -1;
    }
    if(pObjArr->arr_ptop == NULL){
        DEBUG_E("Stack is empty, Cannot pop unit!\n");
        return -1;
    }

    pUnit = --pObjArr->arr_ptop;

    memcpy(ptr, pUnit->unit_ptr, pUnit->unit_size);

    free(pUnit->unit_ptr);
    pObjArr->arr_ptop->unit_size = 0;
    pObjArr->arr_ptop->unit_ptr = NULL;

    if(pObjArr->arr_ptop == pObjArr->arr_pbase){
        pObjArr->arr_ptop = NULL;
    }

    return 0;
}

int stkPrint(struct StackObjArr *pObjArr, CB *cbx_fun)
{
    int stkIndex;
    if(pObjArr->arr_pbase == NULL)
    {
        DEBUG_E("Stack uninitlized !\n");
        return -1;
    }
    if(pObjArr->arr_ptop == NULL){
        DEBUG_E("Stack is empty, Cannot pop unit!\n");
        return -1;
    }
    if(cbx_fun == NULL){
        DEBUG_E("CBX arguments cannot be NULL!\n");
        return -1;
    }
    printf("[ %s ] : ", pObjArr->arr_name);
    for(stkIndex = 0; pObjArr->arr_pbase + stkIndex < pObjArr->arr_ptop; stkIndex++){
        cbx_fun((void *)pObjArr->arr_pbase[stkIndex].unit_ptr);
    }
    putchar('\n');

    return 0;
}
