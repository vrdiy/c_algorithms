#include <stdio.h>
#include <check.h>
#include "test_suites.h"

int main(void){
    printf("Running tests in run_tests.c\n");
    Suite *p_suite;
    SRunner *p_suiteRunner;
    int num_failed;
    p_suite = numbers_suite();
    p_suiteRunner = srunner_create(p_suite);
    srunner_add_suite(p_suiteRunner,sortedints_suite());
    srunner_add_suite(p_suiteRunner,bubblesort_suite());
    srunner_run_all(p_suiteRunner, CK_NORMAL);
    num_failed = srunner_ntests_failed(p_suiteRunner);
    srunner_free(p_suiteRunner);

    return num_failed == 0 ? CK_PASS : CK_FAILURE;
}