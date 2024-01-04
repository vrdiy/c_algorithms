#include<stdio.h>
#include<check.h>
#include"test_suites.h"
#include"../core/c_algorithms.h"

START_TEST (CHECK_DEFAULTS)
{
    SortedInts *s;
    s = SortedIntsCreate(4);
    SortedIntsPrintValues(s);
    ck_assert_int_eq(4,SortedIntsSize(s));
    ck_assert_int_eq(0,SortedIntsArr(s)[0]);
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

    suite_add_tcase(s, tc_core);
    return s;
}