//
//  main.c
//  Exe10.18
//
//  Created by Francesco Parrucci on 06/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  Modificate la funzione displayBits della Figura 10.7  in modo che sia portabile tra sistemi che usano interi di due o quattro
//  byte. Suggerimento: usate l'operatore sizeof per determinare la dimensione di un intero su una macchina particolare
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
   unsigned c, t = sizeof(unsigned), displayMask = 1 << t * 8 - 1;
   

   printf("%7u = ", value);

   for (c = 1; c <= t * 8; c++) {
      putchar(value & displayMask ? '1' : '0');
      value <<= 1;

      if (c % 8 == 0)
         putchar(' ');
   }

   putchar('\n');
}

