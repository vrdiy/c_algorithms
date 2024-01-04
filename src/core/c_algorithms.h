
int addTwoNumbers(int a, int b);
typedef struct SortedInts SortedInts;
SortedInts * SortedIntsCreate(unsigned int size);
int * SortedIntsArr(SortedInts * s);
unsigned int SortedIntsSize(SortedInts * s);
void SortedIntsPrintValues(SortedInts * s);
void SortedIntsFree(SortedInts ** s);