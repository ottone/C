/* Attempting to modify a constant pointer to */
/* non-constant data                          */
#include <stdio.h>

main()
{
   int x, y;
   int * const ptr = &x;

   ptr = &y;
   return 0;
}

