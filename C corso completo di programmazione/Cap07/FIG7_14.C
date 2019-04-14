/* Attempting to modify a constant pointer to */
/* constant data                              */
#include <stdio.h>

main()
{
   int x = 5, y;
   const int *const ptr = &x;

   *ptr = 7;
   ptr = &y;
   return 0;
}

