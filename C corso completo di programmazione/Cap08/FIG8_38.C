/* Using strlen */
#include <stdio.h>
#include <string.h>

main()
{
   char *string1 = "abcdefghijklmnopqrstuvwxyz";
   char *string2 = "four";
   char *string3 = "Boston";
   
   printf("%s\"%s\"%s%lu\n%s\"%s\"%s%lu\n%s\"%s\"%s%lu\n",
          "The length of ", string1, " is ", strlen(string1),
          "The length of ", string2, " is ", strlen(string2),
          "The length of ", string3, " is ", strlen(string3));
   return 0;
}

