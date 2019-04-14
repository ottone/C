/* Using the # flag with conversion specifiers 
   o, x, X, and any floating-point specifier */
#include <stdio.h>

main()
{
   int c = 1427;
   float p = 1427.0;
   
   printf("%#o\n", c);
   printf("%#x\n", c);
   printf("%#X\n", c);
   printf("\n%g\n", p);
   printf("%#g\n", p);
   return 0;
}

