/* Attempting to modify data through a   */
/* non-constant pointer to constant data */
#include <stdio.h>

void f(const int *);

main()
{
   int y;

   f(&y);     /* f attempts illegal modification */
   return 0;
}

void f(const int *x)
{
   *x = 100;  /* cannot modify a const object */
}

