/* Using strpbrk */
#include <stdio.h>
#include <string.h>

int main()
{
   char *string1 = "This is a test";
   char *string2 = "beware";
   
   printf("%s\"%s\"\n'%c'%s\n\"%s\"\n", 
          "Of the characters in ", string2,
          *strpbrk(string1, string2),
          " is the first character to appear in ", string1);

   puts(strpbrk(string1, string2));
   return 0;
}

