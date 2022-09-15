//Neil O'Sullivan R00206266 SDH2B 

#ifndef __SNAKESANDLADDERS_C_
#define __SNAKESANDLADDERS_C_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MIN_SIZE   32
#define MAX_SIZE   64


typedef struct{
    int x;
    int ladderBottom;
    int ladderTop;
    int snakeHead;
    int snakeTail;
    struct square *next; 
    }square;
    

    
#endif