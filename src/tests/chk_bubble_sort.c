#include<stdio.h>
#include <check.h>
#include "../core/c_algorithms.h"
#include "test_suites.h"

START_TEST (WORST_CASE_SCENARIO)
{
    int arr[5] = {5,4,3,2,1};
    int sorted_arr[5] = {1,2,3,4,5};
    ck_assert_int_eq(-1,compareParallelArrs(arr,sorted_arr,5));
    bubbleSort(arr,5);
    ck_assert_int_eq(1,compareParallelArrs(arr,sorted_arr,5));

}
END_TEST
START_TEST (SMALL_INPUTS)
{
    int arr[2] = {5,4};
    int sorted_arr[2] = {4,5};
    ck_assert_int_eq(-1,compareParallelArrs(arr,sorted_arr,2));
    bubbleSort(arr,2);
    ck_assert_int_eq(1,compareParallelArrs(arr,sorted_arr,2));

}
END_TEST
Suite * bubblesort_suite(void){
    Suite *s;
    TCase *tc_core;
    s = suite_create("Check Bubble Sort");
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, WORST_CASE_SCENARIO);
    tcase_add_test(tc_core, SMALL_INPUTS);
    suite_add_tcase(s, tc_core);
    return s;
}