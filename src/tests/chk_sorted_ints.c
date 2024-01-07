#include<stdio.h>
#include<time.h>

#include<check.h>

#include"test_suites.h"
#include"../core/c_algorithms.h"

START_TEST (DEFAULTS)
{
    SortedInts *s;
    s = SortedIntsCreate(4,NULL);
    ck_assert_int_eq(4,SortedIntsSize(s));
    ck_assert_int_eq(0,SortedIntsArr(s)[0]);
    SortedIntsFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
START_TEST (ILLEGAL_EMPTY)
{
    SortedInts *s;
    int test[0] = {};
    s = SortedIntsCreate(0,test);
    ck_assert_int_eq(0,SortedIntsSize(s));
    SortedIntsFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
START_TEST (ODD_NON_DEFAULT)
{
    SortedInts *s;
    int testArr[5] = {1,4,9,12,25};
    s = SortedIntsCreate(5,testArr);
    ck_assert_int_eq(5,SortedIntsSize(s));
    ck_assert_int_eq(9,SortedIntsArr(s)[2]);
    ck_assert_int_eq(3,SortedIntsFind(s,12));
    ck_assert_int_eq(4,SortedIntsFind(s,25));
    ck_assert_int_eq(0,SortedIntsFind(s,1));
    ck_assert_int_eq(-1,SortedIntsFind(s,7));
    SortedIntsFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
START_TEST (EVEN_NON_DEFAULT)
{
    SortedInts *s;
    int testArr[6] = {1,4,9,12,25,80};
    s = SortedIntsCreate(6,testArr);
    ck_assert_int_eq(6,SortedIntsSize(s));
    ck_assert_int_eq(25,SortedIntsArr(s)[4]);
    ck_assert_int_eq(3,SortedIntsFind(s,12));
    ck_assert_int_eq(5,SortedIntsFind(s,80));
    ck_assert_int_eq(0,SortedIntsFind(s,1));
    ck_assert_int_eq(-1,SortedIntsFind(s,7));
    SortedIntsFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
START_TEST (OOO_NON_DEFAULT) // out of order
{
    SortedInts *s;
    int testArr[6] = {80,4,25,12,9,1};
    int testArrSorted[6] = {1,4,9,12,25,80};
    s = SortedIntsCreate(6,testArr);
    for (int i = 0; i < SortedIntsSize(s)-1;i++){
        ck_assert_int_eq(testArrSorted[i],SortedIntsArr(s)[i]);
    }
    SortedIntsFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
START_TEST (OOO_DUPES) // out of order with dupes
{
    SortedInts *s;
    int testArr[6] = {80,4,80,12,9,80};
    int testArrSorted[4] = {4,9,12,80};
    s = SortedIntsCreate(6,testArr);
    ck_assert_int_eq(4,SortedIntsSize(s));
    for (int i = 0; i < SortedIntsSize(s)-1;i++){
        ck_assert_int_eq(testArrSorted[i],SortedIntsArr(s)[i]);
    }
    SortedIntsFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
START_TEST (INSERT)
{
    SortedInts *s;
    int testArr[6] = {1,4,9,12,25,80};
    s = SortedIntsCreate(6,testArr);
    ck_assert_int_eq(6,SortedIntsSize(s));
    SortedIntsInsert(s,13);
    ck_assert_int_eq(13,SortedIntsArr(s)[4]);
    SortedIntsFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
START_TEST (BAD_INSERT)
{
    SortedInts *s;
    int testArr[6] = {1,4,9,12,25,80};
    s = SortedIntsCreate(6,testArr);
    ck_assert_int_eq(6,SortedIntsSize(s));
    ck_assert_int_eq(-1,SortedIntsInsert(s,9));
    ck_assert_int_eq(6,SortedIntsSize(s));
    SortedIntsFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
START_TEST (INSERT_AT_ENDS)
{
    SortedInts *s;
    int testArr[6] = {1,4,9,12,25,80};
    s = SortedIntsCreate(6,testArr);
    ck_assert_int_eq(6,SortedIntsSize(s));
    SortedIntsInsert(s,0);
    SortedIntsInsert(s,100);
    ck_assert_int_eq(8,SortedIntsSize(s));
    ck_assert_int_eq(0,SortedIntsArr(s)[0]);
    ck_assert_int_eq(100,SortedIntsArr(s)[7]);

    SortedIntsFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
START_TEST (INSERT_EQUAL_ENDS)
{
    SortedInts *s;
    int arr[5] = {1,6,7,13,67};
    s = SortedIntsCreate(5,arr);
    ck_assert_int_eq(5,SortedIntsSize(s));
    ck_assert_int_eq(-1,SortedIntsInsert(s,1));
    ck_assert_int_eq(-1,SortedIntsInsert(s,67));
    ck_assert_int_eq(8,SortedIntsArrMemSize(s));
    SortedIntsFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
START_TEST (DELETIONS)
{
    SortedInts *s;
    int testArr[6] = {1,4,9,12,25,80};
    s = SortedIntsCreate(6,testArr);
    ck_assert_int_eq(1,SortedIntsRemove(s,9));
    ck_assert_int_eq(8,SortedIntsArrMemSize(s));
    ck_assert_int_eq(5,SortedIntsSize(s));

    ck_assert_int_eq(12,SortedIntsArr(s)[2]);

    ck_assert_int_eq(1,SortedIntsRemove(s,1));
    ck_assert_int_eq(4,SortedIntsArr(s)[0]);
    ck_assert_int_eq(1,SortedIntsRemove(s,80));
    ck_assert_int_eq(25,SortedIntsArr(s)[SortedIntsSize(s)-1]);
    SortedIntsFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
START_TEST (ONE_MILLION_INSERTIONS)
{
    SortedInts *s;
    s = SortedIntsCreate(0,NULL);
    ck_assert_int_eq(0,SortedIntsSize(s));
    for (int i = 1; i < 1000000; i++){
        SortedIntsInsert(s,i);
    }
    ck_assert_int_eq(1048576,SortedIntsArrMemSize(s));
    SortedIntsFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
START_TEST (TEN_MILLION_INSERTIONS)
{
    SortedInts *s;
    s = SortedIntsCreate(0,NULL);
    ck_assert_int_eq(0,SortedIntsSize(s));
    for (int i = 1; i < 10000000; i++){
        SortedIntsInsert(s,i);
    }
    ck_assert_int_eq(16777216,SortedIntsArrMemSize(s));
    ck_assert_int_eq(1,SortedIntsArr(s)[0]);
    ck_assert_int_eq(9999999,SortedIntsArr(s)[9999998]);

    SortedIntsFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
Suite * sortedints_suite(void){
    Suite *s;
    TCase *tc_core;
    s = suite_create("Check SortedInt");
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, DEFAULTS);
    tcase_add_test(tc_core, ILLEGAL_EMPTY);
    tcase_add_test(tc_core, ODD_NON_DEFAULT);
    tcase_add_test(tc_core, EVEN_NON_DEFAULT);
    tcase_add_test(tc_core, OOO_NON_DEFAULT);
    tcase_add_test(tc_core, OOO_DUPES);
    tcase_add_test(tc_core, INSERT);
    tcase_add_test(tc_core, BAD_INSERT);
    tcase_add_test(tc_core, INSERT_AT_ENDS);
    tcase_add_test(tc_core, INSERT_EQUAL_ENDS);
    tcase_add_test(tc_core, DELETIONS);
    tcase_add_test(tc_core, ONE_MILLION_INSERTIONS);
    tcase_add_test(tc_core, TEN_MILLION_INSERTIONS);
    tcase_set_timeout(tc_core, 4);
    suite_add_tcase(s, tc_core);
    return s;
}