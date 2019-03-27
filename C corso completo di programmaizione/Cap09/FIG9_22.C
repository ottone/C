/* Using an inverted scan set */
#include <stdio.h>

main()
{
   char z[9];
   
   printf("Enter a string: ");
   scanf("%[^aeiou]", z);
   printf("The input was \"%s\"\n", z);
   return 0;
}

