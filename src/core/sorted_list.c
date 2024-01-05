#include "c_algorithms.h"
#include <stdlib.h>
#include <stdio.h>
struct SortedInts
{
    int *p_list;
    unsigned int size;

};

SortedInts * SortedIntsCreate(unsigned int size, int*arr){ // does not check for orderliness of given arr
    int amountOfBytesReserved = (sizeof(SortedInts));
    //printf("int* size: %zu\n",sizeof(int*));
    //printf("unsigned int size: %ld\n",sizeof(unsigned int));
    //printf("size of SortedInts: %ld\n",sizeof(SortedInts));
    //printf("int size: %ld\n",sizeof(int));
    //printf("reserved: %d\n",amountOfBytesReserved);
    SortedInts *s = malloc(amountOfBytesReserved);
    s->p_list = malloc(size*sizeof(int));
    s->size = size;
    if (s == NULL){
        return NULL;
    }
    if (arr == NULL){
        for(int i = 0; i < size; i++){
            s->p_list[i] = i;
        }
    }else{ // populate with given values, does not check if given list is sorted
        for(int i = 0; i < size; i++){
            s->p_list[i] = arr[i];
        }
    }
    return s;
}
void SortedIntsPrintValues(SortedInts * s){
    printf("Address of s: %p\n",s);
    for (int i = 0; i < s->size; i++){
        printf("Value at i: %d\n",s->p_list[i]);
        printf("Address at i: %p\n",&s->p_list[i]);
    }
}
int * SortedIntsArr(SortedInts * s){
    return s->p_list;
}

unsigned int SortedIntsSize(SortedInts * s){
    return s->size;
}
void SortedIntsInsert(SortedInts * s,int a){

}
int SortedIntsFind(SortedInts * s, int a){      // Returns index of element, -1 if not found
    int startIndex = 0;                     
    int endIndex = SortedIntsSize(s)-1;
    int middlePoint = endIndex/2;
    if (s->p_list[endIndex] == a){              // handle case of array size of 2
        return endIndex;
    }
    if (s->p_list[startIndex] == a){
        return startIndex;
    }
    while (startIndex+1!=endIndex){             // if search area is now just two numbers, they'd both have been checked, therefore value is not in array
        if (s->p_list[middlePoint] == a) {      // if found value
            return middlePoint;
        }else{
            if(s->p_list[middlePoint]>a){       // value of interest can't be in the upper half of search area
                endIndex = middlePoint;
            }else{                              // value of interest can't be in lower half
                startIndex = middlePoint;
            }
        }
        if(startIndex+1==endIndex){              
            return -1;
        }
        middlePoint = (startIndex+endIndex)/2;  // moving the midpoint of search area to the average of the two indexes.

    }
    return -1;
}
void SortedIntsFree(SortedInts ** p_s){
    free((*p_s)->p_list);
    (*p_s)->p_list = NULL;
    free(*p_s);
    *p_s = NULL;
}
