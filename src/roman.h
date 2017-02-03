#ifndef ROMAN_H
#define ROMAN_H

   typedef struct Roman Roman;

   Roman *roman_create(char *romans);
   int roman2int(Roman *r);
   char* roman_read(Roman *r);
   void roman_free(Roman *r); 

#endif
