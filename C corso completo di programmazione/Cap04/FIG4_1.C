/* Counter-controlled repetition */
#include <stdio.h>

main()
{
   int counter = 1;             /* initialization */
   
   while (counter <= 10) {      /* repetition condition */
      printf ("%d\n", counter);
      ++counter;                /* increment */
   }

   return 0;
}

