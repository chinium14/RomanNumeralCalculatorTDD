#include "roman.h"

/*
Creating a roman numeral project by inputing a string.
*/
Roman *roman_create(char *romans)
{
   Roman *r1 = malloc(sizeof(Roman));
   r1->r = romans; 
   r1->num = 0;
   return r1;
}

/*
Mem free for the dynamically alocated Roman struct. 
*/
void roman_free(Roman *r1)
{
   free(r1);   
} 

/*
Checking if the roman number is valid by looking for over-replicated strings.
*/   
bool roman_check(Roman *r1)
{
   char * test_substr;
 /* 
 NOTE: check letter over-replication.
 */
   char invalid_str[6][5]={"IIII", "XXXX", "CCCC", "VV", "LL", "DD"};  
   for (int i = 0; i<6; i++)
   {
      test_substr = strstr(r1->r, invalid_str[i]);
      if (test_substr)
      {
         printf("Error: The string %s is not valid for a roman numeral.\n", invalid_str[i]);
         return false;
      } // if
   } // for i loop
   return true;
}

/*
Translating roman numeral to integer and save it in the same Roman struct.
Also checking if the roman numeral has invalid char.
*/
Roman* roman_to_int(char *r_str)
{
   Roman * r1 = roman_create(r_str);
   if (!roman_check(r1))
   {
      exit(-1); 
   } // if
  /* 
  NOTE: if the string passed the previous check,
        then calculat the numeral in int. 
        also, check if there is any invalid character.
        first, save each int for each roman char. 
  */
   int len = strlen(r1->r);
   int digits[len];

   for (int i = 0; i< len; i++)
   {
      switch (r1->r[i])
      {
         case 'I':
            digits[i] = 1;
            break; 
         case 'V':
            digits[i] = 5;
            break; 
         case 'X':
            digits[i] = 10;
            break; 
         case 'L':
            digits[i] = 50;
            break; 
         case 'C':
            digits[i] = 100;
            break; 
         case 'D':
            digits[i] = 500;
            break; 
         case 'M':
            digits[i] = 1000;
            break; 
         default:
            printf("%c is not a valid roman numeral letter.\n", r1->r[i]);
            exit(-1);
      } // switch case
   } //for i loop
   /*
   NOTE: second, sum/substract them up.
   */
   r1->num = digits[len-1];
   int temp = 0;
   for (int i=len-1; i>0; i--) 
   {
      if(digits[i] <= digits[i-1])
      {
        r1->num  += digits[i-1];
      }else
      {
         r1->num -= digits[i-1];
      }
   } // for i loop
   return r1;
}

/*
Translating int to a roman string and save to a Roman struct.
*/ 
Roman *int_to_roman(int num)
{
    char* roman_str;
    int num_list_10s[4] = {1, 10, 100, 1000};
    int num_list_5s[3] = {5, 50, 500};
    char roman_list_10s[4] = "IXCM";
    char roman_list_5s[3] = "VLD";
    /*
    Keep tracking the count of each digit(char).
    */
    char roman_substr[4][5];
    int sum_count = 0;
    int num_cpy = num; 
    /*
    Calculate the 1000's first, since there is no letter for 5000's. 
    */
    int count_temp_10s = num_cpy / num_list_10s[3];
    /*
    Put an alarm here for numbers that are too large. 
    */
    if (count_temp_10s >=4)
    {
       puts("The number is too large for this particular tool.");
       exit(-1);
    } // if

    for (int k = 0; k < count_temp_10s; k++){
       roman_substr[0][k] = roman_list_10s[3];
    } // for k loop
    roman_substr[0][count_temp_10s] = '\0';
    sum_count += count_temp_10s;
    num_cpy %= num_list_10s[3];
 
    /*
    Then work on the 100's 10's and 1's. 
    */
    for (int i=2; i>=0; i--)
    {
        count_temp_10s = num_cpy / num_list_10s[i];
        if (count_temp_10s==9)
        {
           roman_substr[3-i][0] = roman_list_10s[i];
           roman_substr[3-i][1] = roman_list_10s[i+1];
           roman_substr[3-i][2] = '\0';
           sum_count += 2;
        }else if (count_temp_10s==4)
        {
           roman_substr[3-i][0] = roman_list_10s[i];
           roman_substr[3-i][1] = roman_list_5s[i];
           roman_substr[3-i][2] = '\0';
           sum_count += 2;
        }else
        {
           int k = 0;
           if (count_temp_10s >= 5)
           {
              roman_substr[3-i][0] = roman_list_5s[i]; 
              k = k + 1;
              count_temp_10s -=5;
           } // if 
           int m;
           for (m = 0; m < count_temp_10s; m++)
           {
              roman_substr[3-i][m+k] = roman_list_10s[i];
           } //for m loop
           roman_substr[3-i][m+k] = '\0';
           sum_count += m+k;
        } // if
        num_cpy %= num_list_10s[i];
    } // for i loop

    /*
    Concatenate the sub strings into a single one.
    */
    roman_str = malloc((sum_count+1)*sizeof(char)); 
    memset(roman_str, '\0', (sum_count+1)*sizeof(char));
    for (int i = 0; i<4; i++)
    { 
       strcat(roman_str, roman_substr[i]);   
    } // for i loop
    Roman *r1 = roman_create(roman_str);
    r1->num = num; 
    return r1;
}

/*
The add function that return the struct by adding up the two input Roman number strings.
*/
Roman * roman_add(char* r_a, char* r_b)
{
   // Create structs initiated with the char strings with int calculated.
   Roman * roman_a = roman_to_int(r_a); 
   Roman * roman_b = roman_to_int(r_b);
   // Add by int numbers and translate to roman strings. save both to a new struct. 
   int sum_num = roman_a->num + roman_b->num;
   Roman * roman_add = malloc(sizeof(Roman));
   roman_add = int_to_roman(sum_num);
   // Free the two initial structs.
   free(roman_a);
   free(roman_b);
   return roman_add;
}

/*
The subtract function that return the struct by subtracting the second Roman number string from the first Roman number string.
*/
Roman * roman_subtract(char* r_a, char* r_b)
{
   // Create structs initiated with the char strings with int calculated.
   Roman * roman_a = roman_to_int(r_a); 
   Roman * roman_b = roman_to_int(r_b);
   //Subtract by int numbers and translate to roman strings. save both to a new struct. 
   int sub_num = roman_a->num - roman_b->num;
   Roman * roman_sub = malloc(sizeof(Roman));
   roman_sub = int_to_roman(sub_num);
   // Free the two initial structs.
   free(roman_a);
   free(roman_b);
   return roman_sub;
}
