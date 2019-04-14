/* Reading characters and strings */
#include <stdio.h>

main()
{
   char x, y[9];
   
   printf("Enter a string: ");
   scanf("%c%s", &x, y);

   printf("The input was:\n");
   printf("the character \"%c\" ", x);
   printf("and the string \"%s\"\n", y);
   return 0;
}

