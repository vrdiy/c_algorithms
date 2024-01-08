#include "c_algorithms.h"
#include <stdlib.h>
#include <stdio.h>
struct Set
{
    int *p_list;
    unsigned int size;
    unsigned int allocated_size; // Always a power of 2

};
/*
    Creates a Set with an array of (size), can be passed an array to initialize with or NULL for default values 0 to size-1
    The array passed in will be sorted and made into a set.
*/
Set * SetCreate(unsigned int size, int*arr){
    int amountOfBytesReserved = (sizeof(Set));

    /*
        You must use the address of the pointer you assigned the result of malloc to free later.
        When you call free() you need to give it the address of the pointer you assigned to the memory
        So calling free() should be done on the address of s
    */
    Set *s = malloc(amountOfBytesReserved);
    s->allocated_size = size == 0 ? 1 : nextPowerOfTwo(size);
    s->p_list = malloc(s->allocated_size*sizeof(int));
    if (s == NULL){
        return NULL;
    }
    if (arr == NULL || size == 0){
        for(int i = 0; i < size; i++){
            s->p_list[i] = i;
        }
        s->size = size;
    }else{ // Use insertion function for each element, making the list sorted set.
        s->size = 1;
        s->p_list[0] = arr[0];
        for(int i = 1; i < size; i++){
            SetInsert(s,arr[i]);
        }
    }
    return s;
}
// Prints out the values and addresses of the members
void SetPrintValues(Set * s){
    printf("Address of s: %p\n",s);
    printf("Size is set to: %d\n",s->size);
    printf("Allocated memory for p_list: %d\n",s->allocated_size);
    for (int i = 0; i < s->size; i++){
        printf("Value at i: %d\n",s->p_list[i]);
        printf("Address at i: %p\n",&s->p_list[i]);
    }
}
// Returns the array of Set, can get the size with SetSize()
int * SetArr(Set * s){
    return s->p_list;
}
unsigned int SetArrMemSize(Set * s){
    return s->allocated_size;
}
// Returns size of the array returned by SetArr()
unsigned int SetSize(Set * s){
    return s->size;
}
/*
    Allocates only the require amount of memory for the insert
    A better approach would likely be to allocate large segments at interval powers of 2
*/
int Insert(Set * s,int a, int index){ // Private
    // Check if there is already enough allocated size
    if (s->allocated_size > s->size+1){
        // No need to allocate
    }else{
        int*temp = realloc(s->p_list,s->allocated_size*2*sizeof(int)); // Double the allocated memory
        if (temp == NULL){
            return -1;
        }
        s->p_list = temp; // If good allocation, assign return value to the new valid pointer
        s->allocated_size = s->allocated_size*2; 
    }
    
    for (int i = s->size; i > index; i--){ // Shift elements to make room for insertion
        s->p_list[i] = s->p_list[i-1];
    }
    
    s->p_list[index] = a;
    s->size = s->size+1;
    return 1;
    
}
// Insert int a into Set array. Returns 1 on success, -1 on failure
int SetInsert(Set * s,int a){
    // This is an implementation of a binary search with a worst case time complexity of O(log N)
    // Very similar to SetFind(), but here looking for a gap.
    // Returns 1 on successful insert, -1 on failure
    // Fails from value already in array or failure to resize array
    int startIndex = 0;                     
    int endIndex = SetSize(s)-1;
    int middlePoint = endIndex/2;
    if (s->p_list[endIndex] < a){               // insert at the end     
        return Insert(s,a,endIndex+1);
    }
    if (s->p_list[startIndex] > a){             // insert at the start 
        return Insert(s,a,startIndex);
    }
    if (s->p_list[endIndex] == a){
        return -1;
    }
    if (s->p_list[startIndex] == a){
        return -1;
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
        if(startIndex==endIndex){
            printf("Start index is equal to end index... \n");
            return -1;
        }
        middlePoint = (startIndex+endIndex)/2;  // moving the midpoint of search area to the average of the two indexes.

    }
    return -1;
}
int Delete(Set * s, int index){ // Private
    int end_element = s->p_list[s->size-1]; // Need to copy last element before shrink
    unsigned int new_size = nextPowerOfTwo(s->size-1);
    if (new_size < s->allocated_size){ // List is now less than half its allocated size, free that memory
        int*temp = realloc(s->p_list,new_size*sizeof(int));
        if (temp == NULL){
            return -1;
        }
        s->allocated_size = new_size;
        s->p_list = temp;

    }
    for (int i = index; i < s->size-1; i++){ // Shift elements to make room for insertion, except final element
        s->p_list[i] = s->p_list[i+1];
    }
    s->p_list[s->size-1] = end_element;
    s->size = s->size-1;
    return 1;

}
// Remove int a from Set array, Returns 1 on success, 0 if not in list already, -1 on failure
int SetRemove(Set * s, int a){
    int index = SetFind(s,a);
    if (index == -1){ // Element isn't in array
        return 0;
    }
    int status = Delete(s,index);
    if (status == -1){
        return -1;
    }else{
        return 1;
    }
}
// Returns index of element, -1 if not found
int SetFind(Set * s, int a){
    // This is an implementation of a binary search with a worst case time complexity of O(log N)
    int startIndex = 0;                     
    int endIndex = SetSize(s)-1;
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
void SetFree(Set ** p_s){
    free((*p_s)->p_list);
    (*p_s)->p_list = NULL;
    free(*p_s);
    *p_s = NULL;
}
