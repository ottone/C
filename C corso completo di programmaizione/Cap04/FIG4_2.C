/* Counter-controlled repetition with the for structure */
#include <stdio.h>

main()
{
   int counter;
   
   /* initialization, repetition condition, and increment */
   /* are all included in the for structure header        */
   for (counter = 1; counter <= 10; counter++)
      printf("%d\n", counter);

   return 0;
}

