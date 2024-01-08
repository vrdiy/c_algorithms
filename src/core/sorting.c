#include"c_algorithms.h"
#include<stdbool.h>
/*
    This algorithm takes an array of integers and sorts them in place, in quadratic time, or O(n^2)
*/
int bubbleSort(int * arr, unsigned int size){
    if (size<2){
        return 1;
    }
    bool is_sorted = true;
    unsigned int sorted_starts_here = size-1;
    int temp;
    do{
        is_sorted = true;
        for (int i = 0; i < sorted_starts_here; i++){
            if(arr[i]>arr[i+1]){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                is_sorted = false;
            }
        }
        sorted_starts_here-=1;
    }while(is_sorted != true);
    return 1;
}