/* sizeof operator when used on an array name */
/* returns the number of bytes in the array   */
#include <stdio.h>

main()
{
   float array[20];

   printf("The number of bytes in the array is %d\n",
          sizeof(array));

   return 0;
}

