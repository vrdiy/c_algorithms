#include<stdio.h>
#include<time.h>

#include<check.h>

#include"test_suites.h"
#include"../core/c_algorithms.h"

START_TEST (DEFAULTS)
{
    Set *s;
    s = SetCreate(4,NULL);
    ck_assert_int_eq(4,SetSize(s));
    ck_assert_int_eq(0,SetArr(s)[0]);
    SetFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
START_TEST (ILLEGAL_EMPTY)
{
    Set *s;
    int test[0] = {};
    s = SetCreate(0,test);
    ck_assert_int_eq(0,SetSize(s));
    SetFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
START_TEST (ODD_NON_DEFAULT)
{
    Set *s;
    int testArr[5] = {1,4,9,12,25};
    s = SetCreate(5,testArr);
    ck_assert_int_eq(5,SetSize(s));
    ck_assert_int_eq(9,SetArr(s)[2]);
    ck_assert_int_eq(3,SetFind(s,12));
    ck_assert_int_eq(4,SetFind(s,25));
    ck_assert_int_eq(0,SetFind(s,1));
    ck_assert_int_eq(-1,SetFind(s,7));
    SetFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
START_TEST (EVEN_NON_DEFAULT)
{
    Set *s;
    int testArr[6] = {1,4,9,12,25,80};
    s = SetCreate(6,testArr);
    ck_assert_int_eq(6,SetSize(s));
    ck_assert_int_eq(25,SetArr(s)[4]);
    ck_assert_int_eq(3,SetFind(s,12));
    ck_assert_int_eq(5,SetFind(s,80));
    ck_assert_int_eq(0,SetFind(s,1));
    ck_assert_int_eq(-1,SetFind(s,7));
    SetFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
START_TEST (OOO_NON_DEFAULT) // out of order
{
    Set *s;
    int testArr[6] = {80,4,25,12,9,1};
    int testArrSorted[6] = {1,4,9,12,25,80};
    s = SetCreate(6,testArr);
    for (int i = 0; i < SetSize(s)-1;i++){
        ck_assert_int_eq(testArrSorted[i],SetArr(s)[i]);
    }
    SetFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
START_TEST (OOO_DUPES) // out of order with dupes
{
    Set *s;
    int testArr[6] = {80,4,80,12,9,80};
    int testArrSorted[4] = {4,9,12,80};
    s = SetCreate(6,testArr);
    ck_assert_int_eq(4,SetSize(s));
    for (int i = 0; i < SetSize(s)-1;i++){
        ck_assert_int_eq(testArrSorted[i],SetArr(s)[i]);
    }
    SetFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
START_TEST (INSERT)
{
    Set *s;
    int testArr[6] = {1,4,9,12,25,80};
    s = SetCreate(6,testArr);
    ck_assert_int_eq(6,SetSize(s));
    SetInsert(s,13);
    ck_assert_int_eq(13,SetArr(s)[4]);
    SetFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
START_TEST (BAD_INSERT)
{
    Set *s;
    int testArr[6] = {1,4,9,12,25,80};
    s = SetCreate(6,testArr);
    ck_assert_int_eq(6,SetSize(s));
    ck_assert_int_eq(-1,SetInsert(s,9));
    ck_assert_int_eq(6,SetSize(s));
    SetFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
START_TEST (INSERT_AT_ENDS)
{
    Set *s;
    int testArr[6] = {1,4,9,12,25,80};
    s = SetCreate(6,testArr);
    ck_assert_int_eq(6,SetSize(s));
    SetInsert(s,0);
    SetInsert(s,100);
    ck_assert_int_eq(8,SetSize(s));
    ck_assert_int_eq(0,SetArr(s)[0]);
    ck_assert_int_eq(100,SetArr(s)[7]);

    SetFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
START_TEST (INSERT_EQUAL_ENDS)
{
    Set *s;
    int arr[5] = {1,6,7,13,67};
    s = SetCreate(5,arr);
    ck_assert_int_eq(5,SetSize(s));
    ck_assert_int_eq(-1,SetInsert(s,1));
    ck_assert_int_eq(-1,SetInsert(s,67));
    ck_assert_int_eq(8,SetArrMemSize(s));
    SetFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
START_TEST (DELETIONS)
{
    Set *s;
    int testArr[6] = {1,4,9,12,25,80};
    s = SetCreate(6,testArr);
    ck_assert_int_eq(1,SetRemove(s,9));
    ck_assert_int_eq(8,SetArrMemSize(s));
    ck_assert_int_eq(5,SetSize(s));

    ck_assert_int_eq(12,SetArr(s)[2]);

    ck_assert_int_eq(1,SetRemove(s,1));
    ck_assert_int_eq(4,SetArr(s)[0]);
    ck_assert_int_eq(1,SetRemove(s,80));
    ck_assert_int_eq(25,SetArr(s)[SetSize(s)-1]);
    SetFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
START_TEST (ONE_MILLION_INSERTIONS)
{
    Set *s;
    s = SetCreate(0,NULL);
    ck_assert_int_eq(0,SetSize(s));
    for (int i = 1; i < 1000000; i++){
        SetInsert(s,i);
    }
    ck_assert_int_eq(1048576,SetArrMemSize(s));
    SetFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
START_TEST (TEN_MILLION_INSERTIONS)
{
    Set *s;
    s = SetCreate(0,NULL);
    ck_assert_int_eq(0,SetSize(s));
    for (int i = 1; i < 10000000; i++){
        SetInsert(s,i);
    }
    ck_assert_int_eq(16777216,SetArrMemSize(s));
    ck_assert_int_eq(1,SetArr(s)[0]);
    ck_assert_int_eq(9999999,SetArr(s)[9999998]);

    SetFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
Suite * set_suite(void){
    Suite *s;
    TCase *tc_core;
    s = suite_create("Check Set");
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