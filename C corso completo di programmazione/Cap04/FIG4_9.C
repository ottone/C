/* Using the do/while repetition structure */
#include <stdio.h>

main()
{
   int counter = 1;
   
   do {
      printf("%d  ", counter);
   } while (++counter <= 10);

   return 0;
}

