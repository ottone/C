/* Craps */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(void);

main()
{
   int gameStatus, sum, myPoint;

   srand(time(NULL));
   sum = rollDice();            /* first roll of the dice */

   switch(sum) {
      case 7: case 11:          /* win on first roll */
         gamestatus = 1;
         break;
      case 2: case 3: case 12:  /* lose on first roll */
         gameStatus = 2;
         break;
      default:                  /* remember point */
         gameStatus = 0;
         myPoint = sum;
         printf("Point is %d\n", myPoint);
         break;
   }

   while (gameStatus == 0) {    /* keep rolling */
      sum = rollDice();

      if (sum == myPoint)       /* win by making point */
         gameStatus = 1;
      else
         if (sum == 7)          /* lose by rolling 7 */
            gameStatus = 2;
   }

   if (gameStatus == 1)
      printf("Player wins\n");
   else
      printf("Player loses\n");

   return 0;
}

int rollDice(void)
{
   int die1, die2, workSum;

   die1 = 1 + (rand() % 6);
   die2 = 1 + (rand() % 6);
   workSum = die1 + die2;
   printf("Player rolled %d + %d = %d\n", die1, die2, workSum);
   return workSum;
}

