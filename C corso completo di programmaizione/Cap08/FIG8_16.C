/* Using sscanf */
#include <stdio.h>

main()
{
   char s[] = "31298 87.375";
   int x;
   float y;

   sscanf(s, "%d%f", &x, &y);  
   printf("%s\n%s%6d\n%s%8.3f\n",
          "The values stored in character array s are:",
          "Integer:", x, "Float:", y);
   return 0;
}

