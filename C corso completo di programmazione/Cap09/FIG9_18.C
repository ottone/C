/* Reading integers */
#include <stdio.h>

main()
{
   int a, b, c, d, e, f, g;

   printf("Enter seven integers: ");
   scanf("%d%i%i%i%o%u%x", &a, &b, &c, &d, &e, &f, &g);
   printf("The input displayed as decimal integers is:\n");
   printf("%d %d %d %d %d %d %d\n", a, b, c, d, e, f, g);
   return 0;
}

