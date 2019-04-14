/* Using the break statement in a for structure */
#include <stdio.h>

main()
{
   int x;
   
   for (x = 1; x <= 10; x++) {

      if (x == 5)
         break;    /* break loop only if x == 5 */

      printf("%d ", x); 
   }
   
   printf("\nBroke out of loop at x == %d\n", x);
   return 0;
}

