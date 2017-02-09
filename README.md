# RomanNumeralCalculatorTDD

## synopsis
#This is a test-driven solution for the addition and subtraction calculation of Roman numbers. Also, you can simply translate a Roman numeral string to an integer and vice versa. Both the Roman numeral and the integer value are recorded as two attributes of a simple data structure. 
#The source codes can be found in the 
#./src
#which contains two files
#roman.h
#roman.c

#The testing code is in the 
#./test
#with one file
#test_main.c

#Some macro files are saved in the
#./m4
#e.g. check.m4

## compilation
#The configure and  makefiles are generated by the autotools. And we used check.h for test-driven development.

#With autotools and check installed, 

#cd ./RomanNumeralCalculatorTDD, then type command

#autoreconf

#cd ./build

#../configure

#make check


## data structure
#This project use a Roman struct as a base data structure with only two attributes: a char string ("r") to record the Roman numeral and an int ("num") to record its value in integer. 

## sample code
#As you can also find in the test/test_main.c, this is a simple testing code to perform the addition and subtraction for two char strings.

#void sample_code()
#{
#   char *r_a = "LX";
#   char *r_b = "XIV";
#   Roman * r_add = roman_add(r_a, r_b); 
#   Roman * r_sub = roman_subtract(r_a, r_b); 
#   printf("%s + %s = %s.\n", r_a, r_b, r_add->r);
#   printf("%s - %s = %s.\n", r_a, r_b, r_sub->r);
#   free(r_add->r);
#   free(r_sub->r);
#   roman_free(r_add); 
#   roman_free(r_sub); 
#}


