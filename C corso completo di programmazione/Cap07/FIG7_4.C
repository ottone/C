/* Using the & and * operators */
#include <stdio.h>

main()
{
   int a;        /* a is an integer */
   int *aPtr;    /* aPtr is a pointer to an integer */
   
   a = 7;
   aPtr = &a;    /* aPtr set to address of a */
   
   printf("The address of a is %p\n"
          "The value of aPtr is %p\n\n", &a, aPtr);

   printf("The value of a is %d\n"
          "The value of *aPtr is %d\n\n", a, *aPtr);

   printf("Proving that * and & are complements of "
          "each other.\n&*aPtr = %p\n*&aPtr = %p\n",
          &*aPtr, *&aPtr);
   return 0;
}

