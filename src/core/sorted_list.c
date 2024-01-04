#include "c_algorithms.h"
#include <stdlib.h>
#include <stdio.h>
struct SortedInts
{
    int *p_list;
    unsigned int size;

};

SortedInts * SortedIntsCreate(unsigned int size){
    int amountOfBytesReserved = (sizeof(SortedInts)+sizeof(int)*(size));
    printf("int* size: %zu\n",sizeof(int*));
    printf("unsigned int size: %ld\n",sizeof(unsigned int));
    printf("size of SortedInts: %ld\n",sizeof(SortedInts));
    printf("int size: %ld\n",sizeof(int));
    printf("reserved: %d\n",amountOfBytesReserved);
    SortedInts *s = malloc(amountOfBytesReserved);
    if (s == NULL){
        return NULL;
    }

    for(int i = 0; i < size; i++){
        s->p_list[i] = i;
    }
    s->size = size;
    return s;
}
void SortedIntsPrintValues(SortedInts * s){
    for (int i = 0; i < s->size; i++){
        printf("Value at i: %d\n",s->p_list[i]);
    }
}
int * SortedIntsArr(SortedInts * s){
    return s->p_list;
}

unsigned int SortedIntsSize(SortedInts * s){
    return s->size;
}

void SortedIntsFree(SortedInts ** s){
    free(*s);
    *s = NULL;
}
