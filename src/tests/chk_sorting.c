#include<stdio.h>
#include <check.h>
#include "../core/c_algorithms.h"
#include "test_suites.h"

START_TEST (BUBBLE_WORST_CASE_SCENARIO)
{
    int arr[5] = {5,4,3,2,1};
    int sorted_arr[5] = {1,2,3,4,5};
    ck_assert_int_eq(-1,compareParallelArrs(arr,sorted_arr,5));
    bubbleSort(arr,5);
    ck_assert_int_eq(1,compareParallelArrs(arr,sorted_arr,5));

}
END_TEST
START_TEST (BUBBLE_SMALL_INPUTS)
{
    int arr[2] = {5,4};
    int sorted_arr[2] = {4,5};
    ck_assert_int_eq(-1,compareParallelArrs(arr,sorted_arr,2));
    bubbleSort(arr,2);
    ck_assert_int_eq(1,compareParallelArrs(arr,sorted_arr,2));

}
END_TEST
START_TEST (SELECTION_WORST_CASE_SCENARIO)
{
    int arr[5] = {5,4,3,2,1};
    int sorted_arr[5] = {1,2,3,4,5};
    ck_assert_int_eq(-1,compareParallelArrs(arr,sorted_arr,5));
    selectionSort(arr,5);
    ck_assert_int_eq(1,compareParallelArrs(arr,sorted_arr,5));

}
END_TEST
START_TEST (SELECTION_LAST_IS_HIGH)
{
    int arr[5] = {5,4,3,2,6};
    int sorted_arr[5] = {2,3,4,5,6};
    ck_assert_int_eq(-1,compareParallelArrs(arr,sorted_arr,5));
    selectionSort(arr,5);
    ck_assert_int_eq(1,compareParallelArrs(arr,sorted_arr,5));

}
END_TEST
START_TEST (INSERTION_WORST_CASE_SCENARIO)
{
    int arr[5] = {5,4,3,2,1};
    int sorted_arr[5] = {1,2,3,4,5};
    ck_assert_int_eq(-1,compareParallelArrs(arr,sorted_arr,5));
    insertionSort(arr,5);
    ck_assert_int_eq(1,compareParallelArrs(arr,sorted_arr,5));

}
END_TEST
START_TEST (INSERTION_LAST_IS_HIGH)
{
    int arr[5] = {5,4,3,2,6};
    int sorted_arr[5] = {2,3,4,5,6};
    ck_assert_int_eq(-1,compareParallelArrs(arr,sorted_arr,5));
    insertionSort(arr,5);
    ck_assert_int_eq(1,compareParallelArrs(arr,sorted_arr,5));

}
END_TEST
Suite * sorting_suite(void){
    Suite *s;
    s = suite_create("Check Sorting");

    TCase *tc_sorting;
    tc_sorting = tcase_create("Test Sorts");
    tcase_add_test(tc_sorting, BUBBLE_WORST_CASE_SCENARIO);
    tcase_add_test(tc_sorting, BUBBLE_SMALL_INPUTS);
    tcase_add_test(tc_sorting,SELECTION_WORST_CASE_SCENARIO);
    tcase_add_test(tc_sorting,SELECTION_LAST_IS_HIGH);
    tcase_add_test(tc_sorting,INSERTION_WORST_CASE_SCENARIO);
    tcase_add_test(tc_sorting,INSERTION_LAST_IS_HIGH);

    suite_add_tcase(s, tc_sorting);
    return s;
}