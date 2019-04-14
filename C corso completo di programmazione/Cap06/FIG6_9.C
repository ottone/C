/* Roll a six-sided die 6000 times */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 7

main()
{
   int face, roll, frequency[SIZE] = {0}; 

   srand(time(NULL));

   for (roll = 1; roll <= 6000; roll++) {
      face = rand() % 6 + 1;
      ++frequency[face];      /* replaces 20-line switch */
   }                          /* of Fig. 5.10 */

   printf("%s%17s\n", "Face", "Frequency");

   for (face = 1; face <= SIZE - 1; face++)
      printf("%4d%17d\n", face, frequency[face]);

   return 0;
}

