/* Using memset */
#include <stdio.h>
#include <string.h>

main()
{
   char string1[15] = "BBBBBBBBBBBBBB";
   
   printf("string1 = %s\n", string1);
   printf("string1 after memset = %s\n", 
          memset(string1, 'b', 7));
   return 0;
}

