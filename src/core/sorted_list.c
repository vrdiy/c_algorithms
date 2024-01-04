#include "c_algorithms.h"
#include <stdlib.h>
struct SortedInts
{
    int *p_list;
    unsigned int size;

};

SortedInts * SortedIntsCreate(unsigned int size){
    SortedInts *s = malloc(sizeof(SortedInts));
    if (s == NULL){
        return NULL;
    }
    s->p_list = NULL;
    s->size = size;
    return s;
}

int * SortedIntsArr(SortedInts * s){
    return s->p_list;
}

unsigned int SortedIntsSize(SortedInts * s){
    return s->size;
}
