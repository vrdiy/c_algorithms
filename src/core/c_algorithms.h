#include<stddef.h>
//--------Generic Algorithms----------------
unsigned int nextPowerOfTwo(unsigned int a);

//--------Sorting Algorithms----------------
int bubbleSort(int * arr, size_t size);
int selectionSort(int * arr, size_t size);
int insertionSort(int * arr, size_t size);

//--------Generic Array Operations----------
int compareParallelArrs(int * arr_a, int * arr_b, size_t size);

//--------Set Structure---------------------
typedef struct Set Set;
Set * SetCreate(size_t size, int * arr);
int * SetArr(Set * s);
unsigned int SetSize(Set * s);
unsigned int SetArrMemSize(Set * s);
void SetPrintValues(Set * s);
int SetInsert(Set * s,int a);
int SetRemove(Set * s, int a);
int SetFind(Set * s, int a);
void SetFree(Set ** s);
