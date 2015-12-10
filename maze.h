#ifndef MAZE_H
#define MAZE_H

#include "stackObj.h"

struct MazePoint{
    int row;
    int col;
};

struct Vector{
    int vec_row;
    int vec_col;
};


int maze_work(struct StackObjArr *pObjArr);
#endif // MAZE_H

