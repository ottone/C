/* Using memchr */
#include <stdio.h>
#include <string.h>

main()
{
   char *s = "This is a string";

   printf("%s\'%c\'%s\"%s\"\n", 
          "The remainder of s after character ", 'r', 
          " is found is ", memchr(s, 'r', 16));
   return 0;
}

