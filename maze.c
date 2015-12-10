#include <stdio.h>
#include "maze.h"
#include "stackObj.h"
#include "common.h"

#define MAX_ROW 5
#define MAX_COL 5

int maze[MAX_ROW][MAX_COL] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0}
};

               //row col,  down  right   up     left
struct Vector vt[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
static char *PrtVecStr(int index)
{
    switch (index) {
    case 0:
        return "down";
        break;
    case 1:
        return "right";
    case 2:
        return "up";
    case 3:
        return "left";
    default:
        return "unknown path";
        break;
    }
    return NULL;
}
static void print_maze(void)
{
    int i, j;
    for (i = 0; i < MAX_ROW; i++) {
        for (j = 0; j < MAX_COL; j++)
            printf("%d ", maze[i][j]);
        putchar('\n');
    }
    printf("*********\n");
}
int maze_work(struct StackObjArr *pObjArr)
{
    struct MazePoint mp = {0, 0};
    int i = 0;

    maze[mp.row][mp.col] = 2;
    stkPush(pObjArr, &mp, sizeof(struct MazePoint));
    while (pObjArr->arr_ptop != NULL) {
        stkPop(pObjArr, &mp);
        if(mp.col == MAX_COL - 1 && mp.row == MAX_ROW - 1)
            break;
        for(i = 0; i < 4; i++){
            if((unsigned)(mp.row + vt[i].vec_row) > MAX_ROW - 1
                    || (unsigned)(mp.col + vt[i].vec_col) > MAX_COL - 1){    //out line
                continue;
            }
            //not path
            if(maze[mp.row + vt[i].vec_row][mp.col + vt[i].vec_col] == 0){
                DEBUG_O("point rc(%d, %d), direction(%s)\n", mp.row, mp.col, PrtVecStr(i));
                mp.row += vt[i].vec_row;
                mp.col += vt[i].vec_col;
                maze[mp.row][mp.col] = 2;
                stkPush(pObjArr, &mp, sizeof(struct MazePoint));
            }
        }
    }
    print_maze();

    return 0;
}
