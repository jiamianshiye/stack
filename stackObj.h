#ifndef STACKOBJ_H
#define STACKOBJ_H
#ifdef __cplusplus
extern "C"{
#endif

#define     STACK_NAME_LEN  (64)

struct StackObjUnit{
    int unit_size;  //unit size, 0-empty, >0-have data, -1 stack full flag
    void *unit_ptr;
};

struct StackObjArr{
    char arr_name[STACK_NAME_LEN];
    int arr_nums;   //numbers of StackObjUnit
    struct StackObjUnit *arr_pbase;  //pointer to the address of stack base address

/*
pointer to the address stack top, stack is emtpy while point to NULL
*/
    struct StackObjUnit *arr_ptop;
};

int stkInit(struct StackObjArr *pObjArr, int num);
int stkSetName(struct StackObjArr *pObjArr, char *name);

int stkPush(struct StackObjArr *pObjArr, void *ptr, int ut_size);

int stkPop(struct StackObjArr *pObjArr, void *ptr);

typedef void (CB)(int *);
int stkPrint(struct StackObjArr *pObjArr, CB *cbx_fun);
#ifdef __cplusplus
}
#endif
#endif // STACKOBJ_H
