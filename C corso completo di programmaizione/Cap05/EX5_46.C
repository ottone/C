int mystery(int, int);
   
main()
{
   int x, y;
   
   printf("Enter two integers: ");
   scanf("%d%d", &x, &y);
   printf("The result is %d\n", mystery(x, y));
   return 0;
}

/* Parameter b must be a positive  
   integer to prevent infinite recursion */
int mystery(int a, int b)
{
   if (b == 1)
      return a;
   else
      return a + mystery(a, b - 1);
}

