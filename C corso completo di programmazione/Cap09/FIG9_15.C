/* Printing with the 0(zero) flag fills in leading zeros */
#include <stdio.h>

main()
{
   printf("%+09d", 452);
   printf("%09d", 452);
   return 0;
}

