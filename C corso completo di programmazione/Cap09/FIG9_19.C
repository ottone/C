/* Reading floating-point numbers */
#include <stdio.h>

main()
{
   float a, b, c;
   
   printf("Enter three floating-point numbers: \n");
   scanf("%e%f%g", &a, &b, &c);
   printf("Here are the numbers entered in plain\n");
   printf("floating-point notation:\n");
   printf("%f %f %f\n", a, b, c);
   return 0;
}

