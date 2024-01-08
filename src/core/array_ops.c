#include"c_algorithms.h"

// Returns 1 when every element has the same value at each index in both arrays, the arrays must be the same length
int compareParallelArrs(int * arr_a, int * arr_b, unsigned int size){
    for(int i = 0; i < size; i++){
        if (arr_a[i] != arr_b[i]){
            return -1;
        }
    }
    return 1;
}