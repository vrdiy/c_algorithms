#include "c_algorithms.h"
#include <stdlib.h>
#include <stdio.h>
struct SortedInts
{
    int *p_list;
    unsigned int size;

};
// Creates a SortedInts with an array of (size), can be passed an array to initialize with or NULL for default values 0 to size-1
SortedInts * SortedIntsCreate(unsigned int size, int*arr){ // does not check for orderliness of given arr
    int amountOfBytesReserved = (sizeof(SortedInts));
    /*
        You must use the address of the pointer you assigned the result of malloc to free later.
        When you call free() you need to give it the address of the pointer you assigned to the memory
        So calling free() should be done on the address of s
    */
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
// Prints out the values and addresses of the members
void SortedIntsPrintValues(SortedInts * s){
    printf("Address of s: %p\n",s);
    printf("Size is set to: %d\n",s->size);
    for (int i = 0; i < s->size; i++){
        printf("Value at i: %d\n",s->p_list[i]);
        printf("Address at i: %p\n",&s->p_list[i]);
    }
}
// Returns the array of SortedInts, can get the size with SortedIntsSize()
int * SortedIntsArr(SortedInts * s){
    return s->p_list;
}
// Returns size of the array returned by SortedIntsArr()
unsigned int SortedIntsSize(SortedInts * s){
    return s->size;
}
int Insert(SortedInts * s,int a, int index){ // Private
    int*temp = realloc(s->p_list,(1+s->size)*sizeof(int));
    if (temp == NULL){
        return -1;
    }else{
        s->p_list = temp;
        for (int i = s->size; i > index; i--){ // Shift elements to make room for insertion
            s->p_list[i] = s->p_list[i-1];
        }
        if (index == s->size-1){ // handle if element is inserted at end
            s->p_list[index+1] = a;
        }else{
            s->p_list[index] = a;
        }
        s->size = s->size+1;
        return 1;
    }
}
// Insert int into SortedInts array. Returns 1 on success, -1 on failure
int SortedIntsInsert(SortedInts * s,int a){
    // This is an implementation of a binary search with a worst case time complexity of O(log N)
    // Very similar to SortedIntsFind(), but here looking for a gap.
    // Returns 1 on successful insert, -1 on failure
    // Fails from value already in array or failure to resize array
    int startIndex = 0;                     
    int endIndex = SortedIntsSize(s)-1;
    int middlePoint = endIndex/2;
    if (s->p_list[endIndex] < a){               // insert at the end     
        return Insert(s,a,endIndex);
    }
    if (s->p_list[startIndex] > a){             // insert at the start 
        return Insert(s,a,startIndex);
    }

    while (1){                                  // Will either return on found duplicate, or found the two values that surround our value 'a'       
        if (s->p_list[middlePoint] == a) {      // if found value return 0, no dupicates allowed
            return -1;
        }else{
            if(s->p_list[middlePoint]>a){       // value of interest can't be in the upper half of search area
                endIndex = middlePoint;
            }else{                              // value of interest can't be in lower half
                startIndex = middlePoint;
            }
        }
        if(startIndex+1==endIndex){             // search area is only two values
            return Insert(s,a,endIndex);        // we are now at the two values which surround our value
        }
        middlePoint = (startIndex+endIndex)/2;  // moving the midpoint of search area to the average of the two indexes.

    }
    return -1;
}
// Returns index of element, -1 if not found
int SortedIntsFind(SortedInts * s, int a){
    // This is an implementation of a binary search with a worst case time complexity of O(log N)
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
