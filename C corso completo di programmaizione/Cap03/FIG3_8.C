/* Class average program with 
   sentinel-controlled repetition */
#include <stdio.h>

main()
{
   float average;              /* new data type */
   int counter, grade, total;
   
   /* initialization phase */
   total = 0;
   counter = 0;
   
   /* processing phase */
   printf("Enter grade, -1 to end: ");
   scanf("%d", &grade);
   
   while (grade != -1) {
      total = total + grade;
      counter = counter + 1; 
      printf("Enter grade, -1 to end: ");
      scanf("%d", &grade);
   }

   /* termination phase */
   if (counter != 0) {
      average = (float) total / counter;
      printf("Class average is %.2f", average);
   }
   else
      printf("No grades were entered\n");

   return 0;   /* indicate program ended successfully */
}

