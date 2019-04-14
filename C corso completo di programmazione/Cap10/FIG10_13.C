/* Using the bitwise shift operators */
#include <stdio.h>

void displayBits(unsigned);

main()
{
   unsigned number1 = 960;

   printf("\nThe result of left shifting\n");
   displayBits(number1);
   printf("8 bit positions using the ");
   printf("left shift operator << is\n");
   displayBits(number1 << 8);

   printf("\nThe result of right shifting\n");
   displayBits(number1);
   printf("8 bit positions using the ");
   printf("right shift operator >> is\n");
   displayBits(number1 >> 8);
   return 0;
}

void displayBits(unsigned value)
{
   unsigned c, displayMask = 1 << 15;

   printf("%7u = ", value);

   for (c = 1; c <= 16; c++) {
      putchar(value & displayMask ? '1' : '0');
      value <<= 1;

      if (c % 8 == 0)
         putchar(' ');
   }

   putchar('\n');
}

