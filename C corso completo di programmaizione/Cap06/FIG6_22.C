/* Double-subscripted array example */
#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

int minimum(int [][EXAMS], int, int);
int maximum(int [][EXAMS], int, int);
float average(int [], int);
void printArray(int [][EXAMS], int, int);

main()
{
   int student,
       studentGrades[STUDENTS][EXAMS] = {{77, 68, 86, 73},
                                         {96, 87, 89, 78},
                                         {70, 90, 86, 81}};

   printf("The array is:\n");
   printArray(studentGrades, STUDENTS, EXAMS);
   printf("\n\nLowest grade: %d\nHighest grade: %d\n",
          minimum(studentGrades, STUDENTS, EXAMS),
          maximum(studentGrades, STUDENTS, EXAMS));

   for (student = 0; student <= STUDENTS - 1; student++)
      printf("The average grade for student %d is %.2f\n", 
             student, average(studentGrades[student], EXAMS));

   return 0;
}

/* Find the minimum grade */
int minimum(int grades[][EXAMS], int pupils, int tests)
{
   int i, j, lowGrade = 100;

   for (i = 0; i <= pupils - 1; i++)
      for (j = 0; j <= tests - 1; j++)
         if (grades[i][j] < lowGrade)
            lowGrade = grades[i][j];

   return lowGrade;
}

/* Find the maximum grade */
int maximum(int grades[][EXAMS], int pupils, int tests)
{
   int i, j, highGrade = 0;

   for (i = 0; i <= pupils - 1; i++)
      for (j = 0; j <= tests - 1; j++)
         if (grades[i][j] > highGrade)
            highGrade = grades[i][j];

   return highGrade;
}

/* Determine the average grade for a particular exam */
float average(int setOfGrades[], int tests)
{
   int i, total = 0;

   for (i = 0; i <= tests - 1; i++)
      total += setOfGrades[i];

   return (float) total / tests;
}

/* Print the array */
void printArray(int grades[][EXAMS], int pupils, int tests)
{
   int i, j;

   printf("                 [0]  [1]  [2]  [3]");

   for (i = 0; i <= pupils - 1; i++) {
      printf("\nstudentGrades[%d] ", i);

      for (j = 0; j <= tests - 1; j++)
         printf("%-5d", grades[i][j]);
   }
}

