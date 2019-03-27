#include <stdio.h>
#define SIZE 10

int whatIsThis(int [], int);

main()
{
   int total, a[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

   total = whatIsThis(a, SIZE);
   printf("Total of array element values is %d\n", total);
   return 0;
}

int whatIsThis(int b[], int size)
{
   if (size == 1)
      return b[0];
   else
      return b[size - 1] + whatIsThis(b, size - 1);
}

