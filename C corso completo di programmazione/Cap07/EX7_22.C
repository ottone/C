#include <stdio.h>

int mystery2(const char *);

main()
{
   char string[80];

   printf("Enter a string: ");
   scanf("%s", string);
   printf("%d\n", mystery2(string));
   return 0;
}

int mystery2(const char *s)
{
   int x = 0;

   for ( ; *s != '\0'; s++)
      ++x;

   return x;
}

