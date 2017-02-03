/*****************************************************/
/*Shuai Wei 2/1/2017 using the C language with check */
/*This file contains the tests for the library in src*/    
/*****************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <check.h>
#include "../src/roman.h"

START_TEST(firstTest)
{
   ck_assert_msg(5==5, "Not quite right!");   
}
END_TEST

Suite * Roman_suite(void)
{
   Suite *s;
   TCase *tc_core;
   
   s = suite_create("Roman");
   tc_core = tcase_create("Core");

   tcase_add_test(tc_core, firstTest);
   suite_add_tcase(s, tc_core);

   return s;
}

int main(int argc, char* argv[])
{
//   return 0;
   int number_failed;
   Suite *s;
   SRunner *sr;
   
   s = Roman_suite();
   sr = srunner_create(s);

   puts("Testing starts here!\n");
   srunner_run_all(sr, CK_NORMAL);
   number_failed = srunner_ntests_failed(sr);
   srunner_free(sr);
   return(number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
