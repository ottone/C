#include <stdio.h>

int mystery(unsigned);

main()
{
   unsigned x;

   printf("Enter an integer: ");
   scanf("%u", &x);
   printf("The result is %d\n", mystery(x));
   return 0;
}

int mystery(unsigned bits)
{
   unsigned i, mask = 1 << 15, total = 0;

   for (i = 1; i <= 16; i++, bits <<= 1)
      if ((bits & mask) == mask) 
         ++total;

    return total % 2 == 0 ? 1 : 0;;
}

