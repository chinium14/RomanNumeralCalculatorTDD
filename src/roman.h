#ifndef ROMAN_H
#define ROMAN_H
#include <stdio.h>
#include <stdlib.h>

   typedef struct Roman{
      char *r;
   } Roman;

   Roman *roman_create(char *romans);
   int roman2int(Roman *r);
   char* roman_read(Roman *r);
   void roman_free(Roman *r); 

#endif
