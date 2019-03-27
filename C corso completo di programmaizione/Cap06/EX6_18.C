#include <stdio.h>
#define SIZE 10

void someFunction(int [], int);

main()
{
   int a[SIZE] = {32, 27, 64, 18, 95, 14, 90, 70, 60, 37};

   printf("The values in the array are:\n");
   someFunction(a, SIZE);
   printf("\n");
   return 0;
}

void someFunction(int b[], int size)
{
   if (size > 0) {
      someFunction(&b[1], size - 1);
      printf("%d  ", b[0]);
   }
}

