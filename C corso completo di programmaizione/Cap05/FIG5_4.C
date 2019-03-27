/* Finding the maximum of three integers */
#include <stdio.h>

int maximum(int, int, int);   /* function prototype */

main()
{
   int a, b, c;

   printf("Enter three integers: ");
   scanf("%d%d%d", &a, &b, &c);
   printf("Maximum is: %d\n", maximum(a, b, c));

   return 0;
}

/* Function maximum definition */
int maximum(int x, int y, int z)
{
   int max = x;

   if (y > max)
      max = y;

   if (z > max)
      max = z;

   return max;
}


