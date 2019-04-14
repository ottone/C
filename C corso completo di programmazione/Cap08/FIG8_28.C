/* Using strstr */
#include <stdio.h>
#include <string.h>

main()
{
   char *string1 = "abcdefabcdef";
   char *string2 = "def";
   
   printf("%s%s\n%s%s\n\n%s\n%s%s\n",
          "string1 = ", string1, "string2 = ", string2,
          "The remainder of string1 beginning with the",
          "first occurrence of string2 is: ", 
          strstr(string1, string2));

   return 0;
}

