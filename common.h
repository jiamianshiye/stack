#ifndef COMMON_H
#define COMMON_H

#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>


#define         __DEBUG__
#ifdef          __DEBUG__
#define DEBUG_O(x...)\
{\
  printf(" <DEBUG> %s-%d : " ,__func__,__LINE__);\
  printf(x);\
}
#define DEBUG_E(x...)\
{\
  printf(" <ERROR> %s-%d : ",__func__,__LINE__ );\
  printf(x);\
}
#else
#define DEBUG_O(x...) //printf(...);
#define DEBUG_E(x...) //printf(...);
#endif

#endif // COMMON_H
