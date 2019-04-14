/* Counting letter grades */
#include <stdio.h>

main()
{
   int grade;
   int aCount = 0, bCount = 0, cCount = 0, 
       dCount = 0, fCount = 0;

   printf("Enter the letter grades.\n");
   printf("Enter the EOF character to end input.\n");

   while ( ( grade = getchar() ) != EOF) {

      switch (grade) {    /* switch nested in while */

         case 'A': case 'a':  /* grade was uppercase A */
            ++acount;         /* or lowercase a */
            break;

         case 'B': case 'b':  /* grade was uppercase B */
            ++bcount;         /* or lowercase b */
            break;

         case 'C': case 'c':  /* grade was uppercase C */
            ++ccount;         /* or lowercase c */
            break;

         case 'D': case 'd':  /* grade was uppercase D */
            ++dcount;         /* or lowercase d */
            break;

         case 'F': case 'f':  /* grade was uppercase F */
            ++fcount;         /* or lowercase f */
            break;

         case '\n': case' ':  /* ignore these in input */
            break;

         default:        /* catch all other characters */
            printf("Incorrect letter grade entered."); 
            printf(" Enter a new grade.\n"); 
            break;
      }
   }

   printf("\nTotals for each letter grade are:\n");
   printf("A: %d\n", aCount);
   printf("B: %d\n", bCount);
   printf("C: %d\n", cCount);
   printf("D: %d\n", dCount);
   printf("F: %d\n", fCount);

   return 0;
}

