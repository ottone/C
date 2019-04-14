/* Recursive fibonacci function */
#include <stdio.h>

long fibonacci(long);

main()
{
   long result, number;

   printf("Enter an integer: ");
   scanf("%ld", &number);
   result = fibonacci(number);
   printf("Fibonacci(%ld) = %ld\n", number, result);
   return 0;
}

/* Recursive definition of function fibonacci */
long fibonacci(long n)
{
   if (n == 0 || n == 1)
      return n;
   else
      return fibonacci(n - 1) + fibonacci(n - 2);
}

