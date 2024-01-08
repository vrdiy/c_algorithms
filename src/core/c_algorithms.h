
//--------Generic Algorithms----------------
unsigned int nextPowerOfTwo(unsigned int a);

//--------Sorting Algorithms----------------
int bubbleSort(int * arr, unsigned int size);
int selectionSort(int * arr, unsigned int size);

//--------Generic Array Operations----------
int compareParallelArrs(int * arr_a, int * arr_b, unsigned int size);

//--------Set Structure---------------------
typedef struct Set Set;
Set * SetCreate(unsigned int size, int * arr);
int * SetArr(Set * s);
unsigned int SetSize(Set * s);
unsigned int SetArrMemSize(Set * s);
void SetPrintValues(Set * s);
int SetInsert(Set * s,int a);
int SetRemove(Set * s, int a);
int SetFind(Set * s, int a);
void SetFree(Set ** s);
