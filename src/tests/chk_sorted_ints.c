#include<stdio.h>
#include<check.h>
#include"test_suites.h"
#include"../core/c_algorithms.h"

START_TEST (CHECK_DEFAULTS)
{
    SortedInts *s;
    s = SortedIntsCreate(4,NULL);
    ck_assert_int_eq(4,SortedIntsSize(s));
    ck_assert_int_eq(0,SortedIntsArr(s)[0]);
    SortedIntsFree(&s);
    ck_assert_ptr_eq(NULL,s);
}
END_TEST
START_TEST (CHECK_ODD_NON_DEFAULT)
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
START_TEST (CHECK_EVEN_NON_DEFAULT)
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
START_TEST (CHECK_INSERT)
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
START_TEST (CHECK_BAD_INSERT)
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
START_TEST (CHECK_INSERT_AT_ENDS)
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
Suite * sortedints_suite(void){
    Suite *s;
    TCase *tc_core;
    s = suite_create("Check SortedInt");
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, CHECK_DEFAULTS);
    tcase_add_test(tc_core, CHECK_ODD_NON_DEFAULT);
    tcase_add_test(tc_core, CHECK_EVEN_NON_DEFAULT);
    tcase_add_test(tc_core, CHECK_INSERT);
    tcase_add_test(tc_core, CHECK_BAD_INSERT);
    tcase_add_test(tc_core, CHECK_INSERT_AT_ENDS);


    suite_add_tcase(s, tc_core);
    return s;
}