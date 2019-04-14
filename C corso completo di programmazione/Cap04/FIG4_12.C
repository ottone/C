/* Using the continue statement in a for structure */
#include <stdio.h>

main()
{
   int x;
   
   for (x = 1; x <= 10; x++) {

      if (x == 5)   
         continue;  /* skip remaining code in loop only
                       if x == 5 */
   
      printf("%d ", x); 
   }
   
   printf("\nUsed continue to skip printing the value 5\n");
   return 0;
}

