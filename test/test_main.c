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

 // Test#0 checking the check lib.
   ck_assert_msg(5==5, "Error: #0! The 'check' lib may not work!");  
   char *r_input = "MCMXCVI";
   Roman *r1 = roman_create(r_input);
 // Test#1 checking if the "check" lib works.
   ck_assert_msg(strcmp(r1->r,r_input) == 0, "Error: #1! Did not get the right Roman string!");
 // Test#2 checking the input roman numeral is valid. 
   ck_assert_msg(roman_check(r1), "Error: #2! Invalid Roman string! (Check if there is any over-replication of a char! e.g. 'IIII'.)");
 // Test#3 checking the input roman numeral is valid and calculate the integer from the Roman string.
   roman_free(r1);
   ck_assert_msg(r1 = roman_to_int(r_input), "Error: #3.1! Invalid Roman string! Check if the Roman string has an invalid char!");
   ck_assert_msg(r1->num == 1996, "Error: #3.2! Did not get the right answer for 'Roman to Int'!");
 // Test#4 translate a int to a Roman string
   char *roman_str_cal = (int_to_roman(r1->num))->r;
   ck_assert_msg(strcmp(roman_str_cal,r1->r) == 0, "Error: #4! Did not get the right answer for 'Int to Roman'!");
 // Test#5 adding up two Roman numbers
   char *r_a = "LX";
   char *r_b = "XIV";
   Roman * r_add = roman_add(r_a, r_b);  
   ck_assert_msg(r_add->num == 74, "Error: #5! Function add does not work well yet!!");
 // Test#6 subtract two Roman numbers 
   Roman * r_sub = roman_subtract(r_a, r_b);  
   ck_assert_msg(r_sub->num == 46, "Error: #6! Function subtract does not work well yet!!");
   roman_free(r_sub);
   roman_free(r_add);
   roman_free(r1);
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

void sample_code()
{
   char *r_a = "LX";
   char *r_b = "XIV";
   Roman * r_add = roman_add(r_a, r_b); 
   Roman * r_sub = roman_subtract(r_a, r_b); 
   printf("%s + %s = %s.\n", r_a, r_b, r_add->r);
   printf("%s - %s = %s.\n", r_a, r_b, r_sub->r);
   free(r_add->r);
   free(r_sub->r);
   roman_free(r_add); 
   roman_free(r_sub); 
}

int main(int argc, char* argv[])
{
   int number_failed;
   Suite *s;
   SRunner *sr;
   
   s = Roman_suite();
   sr = srunner_create(s);

   puts("Testing starts here!\n");
   srunner_run_all(sr, CK_NORMAL);
   number_failed = srunner_ntests_failed(sr);
   srunner_free(sr);
   /*
   Run the sample code here.
   */
   sample_code();
   return(number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
