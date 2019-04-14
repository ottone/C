/* Using strspn */
#include <stdio.h>
#include <string.h>

main()
{
   char *string1 = "The value is 3.14159";
   char *string2 = "aehilsTuv ";
   
   printf("%s%s\n%s%s\n\n%s\n%s%u\n",
          "string1 = ", string1, "string2 = ", string2,
          "The length of the initial segment of string1",
          "containing only characters from string2 = ",
          strspn(string1, string2));
   return 0;
}

