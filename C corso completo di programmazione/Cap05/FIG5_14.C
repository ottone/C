/* A scoping example */
#include <stdio.h>

void a(void);   /* function prototype */
void b(void);   /* function prototype */
void c(void);   /* function prototype */

int x = 1;      /* global variable */

main()
{
   int x = 5;   /* local variable to main */

   printf("local x in outer scope of main is %d\n", x);

   {            /* start new scope */
      int x = 7;

      printf("local x in inner scope of main is %d\n", x);
   }            /* end new scope */

   printf("local x in outer scope of main is %d\n", x);

   a();         /* a has automatic local x */
   b();         /* b has static local x */
   c();         /* c uses global x */
   a();         /* a reinitializes automatic local x */
   b();         /* static local x retains its previous value */
   c();         /* global x also retains its value */

   printf("local x in main is %d\n", x);
   return 0;
}

void a(void)
{
   int x = 25;  /* initialized each time a is called */

   printf("\nlocal x in a is %d after entering a\n", x);
   ++x;
   printf("local x in a is %d before exiting a\n", x);
}

void b(void)
{
    static int x = 50;  /* static initialization only */
                        /* first time b is called */
    printf("\nlocal static x is %d on entering b\n", x);
    ++x;
    printf("local static x is %d on exiting b\n", x);
}

void c(void)
{
   printf("\nglobal x is %d on entering c\n", x);
   x *= 10;
   printf("global x is %d on exiting c\n", x);
}

