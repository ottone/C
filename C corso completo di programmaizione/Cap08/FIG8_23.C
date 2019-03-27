/* Using strchr */
#include <stdio.h>
#include <string.h>

main()
{
   char *string = "This is a test"; 
   char character1 = 'a', character2 = 'z';
   
   if (strchr(string, character1) != NULL)
      printf("\'%c\' was found in \"%s\".\n", 
             character1, string);
   else
      printf("\'%c\' was not found in \"%s\".\n", 
             character1, string);

   if (strchr(string, character2) != NULL)
      printf("\'%c\' was found in \"%s\".\n", 
             character2, string);
   else
      printf("\'%c\' was not found in \"%s\".\n", 
             character2, string);
   return 0;
}

