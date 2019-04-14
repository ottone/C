/* Randomizing die-rolling program */
#include <stdlib.h>
#include <stdio.h>

main()
{
   int i;
   unsigned seed;
   
   printf("Enter seed: ");
   scanf("%u", &seed);
   srand(seed);
   
   for (i = 1; i <= 10; i++) {
      printf("%10d", 1 + (rand() % 6));
      
      if (i % 5 == 0)
         printf("\n");
   }

   return 0;
}

