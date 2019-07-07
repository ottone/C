//
//  main.c
//  Exe10.11
//
//  Created by Francesco Parrucci on 05/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  Modificate il programma della Figura 10.7, in modo che possa funzionare con interi di 4 byte, qualora il vostro computer usi 
//  interi di 4 byte
//

/* Printing an unsigned integer in bits */
#include <stdio.h>

int main()
{
   unsigned x;
   void displayBits(unsigned);

   printf("Enter an unsigned integer: ");
   scanf("%u", &x);
   displayBits(x);
   return 0;
}

void displayBits(unsigned value)
{
      
   unsigned typein = sizeof(int), c, displayMask = 1 << (8 * typein - 1);

  
   printf("%7u = ", value);

   for (c = 1; c <= typein * 8 ; c++) {
      putchar(value & displayMask ? '1' : '0');
      value <<= 1;

      if (c % 8 == 0)
         putchar(' ');
   }

   putchar('\n');
}

