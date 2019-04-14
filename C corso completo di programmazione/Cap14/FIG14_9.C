/* Using goto */
#include <stdio.h>

main()
{
   int count = 1;

   start:                    /* label */
      if (count > 10)
         goto end;

      printf("%d  ", count);
      ++count;
      goto start;

   end:                      /* label */
      putchar('\n');

   return 0;
}

