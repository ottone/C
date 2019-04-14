/* Using strcspn */
#include <stdio.h>
#include <string.h>

main()
{
   char *string1 = "The value is 3.14159";
   char *string2 = "1234567890";
   
   printf("%s%s\n%s%s\n\n%s\n%s%u",
          "string1 = ", string1, "string2 = ", string2,
          "The length of the initial segment of string1",
          "containing no characters from string2 = ",
          strcspn(string1, string2));
   return 0;
}

