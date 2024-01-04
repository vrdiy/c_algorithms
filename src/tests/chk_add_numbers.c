#include <check.h>
#include "../core/c_algorithms.h"
#include "test_suites.h"

START_TEST (ADD_NEGATIVE_NUMBERS)
{
    ck_assert_int_eq(-5,addTwoNumbers(1,-6));
}
END_TEST

START_TEST (ADD_ZERO)
{
    ck_assert_int_eq(5,addTwoNumbers(5,0));
}
END_TEST

Suite * numbers_suite(void){
    Suite *s;
    TCase *tc_core;
    s = suite_create("Check Numbers");
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, ADD_NEGATIVE_NUMBERS);
    tcase_add_test(tc_core, ADD_ZERO);

    suite_add_tcase(s, tc_core);
    return s;
}