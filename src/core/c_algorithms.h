
int addTwoNumbers(int a, int b);
unsigned int nextPowerOfTwo(unsigned int a);
typedef struct SortedInts SortedInts;
SortedInts * SortedIntsCreate(unsigned int size, int * arr);
int * SortedIntsArr(SortedInts * s);
unsigned int SortedIntsSize(SortedInts * s);
unsigned int SortedIntsArrMemSize(SortedInts * s);
void SortedIntsPrintValues(SortedInts * s);
int SortedIntsInsert(SortedInts * s,int a);
int SortedIntsRemove(SortedInts * s, int a);
int SortedIntsFind(SortedInts * s, int a);
void SortedIntsFree(SortedInts ** s);