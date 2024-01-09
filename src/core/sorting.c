#include<stdbool.h>
#include"c_algorithms.h"
/*
    This algorithm takes an array of integers and sorts them in place, in quadratic time, or O(n^2)
*/
int bubbleSort(int * arr, size_t size){
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

int selectionSort(int * arr, size_t size){
    if (size<2){
        return 1;
    }
    unsigned int current_pos = 0;
    int temp;
    while(current_pos!=size-1){
        unsigned int current_lowest = current_pos;
        for (int i = current_pos; i < size; i++){
            if(arr[i] < arr[current_lowest]){
                current_lowest = i;
            }
        }
        temp = arr[current_pos];
        arr[current_pos] = arr[current_lowest];
        arr[current_lowest] = temp;
        current_pos += 1;
    }
    return 1;
}

int insertionSort(int * arr, size_t size){
    if (size < 2){
        return 1;
    }
    for (int i = 1; i < size; i++){
        unsigned int current_pos = i;
        int temp = arr[i];
        if(arr[current_pos-1] < temp){
            // Value is already in order
        }else{
            while(arr[current_pos - 1] > temp){
                arr[current_pos] = arr[current_pos - 1];
                current_pos -= 1;
                if(current_pos == 0){
                    break;
                }
            }
            arr[current_pos] = temp;
        }
    }
};