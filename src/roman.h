/*
This is the interface for the Roman numeral calculator. 
Shuai Wei 
*/

#ifndef ROMAN_H
#define ROMAN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Defining a boolean type for C.
*/
typedef enum { false, true } bool;

/*
Defining a structure for roman numeral. 
*/
   typedef struct Roman{
      char *r;
      int num;
   } Roman;

/*
Creating a roman numeral project by inputing a string.
*/
   Roman *roman_create(char *romans);

/*
Mem free for the dynamically alocated Roman struct. 
*/
   void roman_free(Roman *r1); 

/*
Checking if the roman number is valid by looking for over-replicated strings.
*/   
   bool roman_check(Roman *r1);

/*
Translating roman numeral to integer and save it in the same Roman struct.
Also checking if the roman numeral has invalid char.
*/
   Roman *roman_to_int(char *r1);

/*
Translating int to a roman string and save to a Roman struct..
*/ 
   Roman *int_to_roman(int num);

/*
The add function that return the struct by adding up the two input Roman number strings.
*/
   Roman *roman_add(char* r_a, char* r_b);

/*
The subtract function that return the struct by subtracting the second Roman number string from the first Roman number string.
*/
   Roman *roman_subtract(char* r_a, char* r_b);

#endif
