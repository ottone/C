/* Using command-line arguments */
#include <stdio.h>

main(int argc, char *argv[])
{
   FILE *inFilePtr, *outFilePtr;
   int c;

   if (argc != 3)
      printf("Usage: copy infile outfile\n");
   else
      if ((inFilePtr = fopen(argv[1], "r")) != NULL)

         if ((outFilePtr = fopen(argv[2], "w")) != NULL)

            while ((c = fgetc(inFilePtr)) != EOF)
               fputc(c, outFilePtr);

         else
            printf("File \"%s\" could not be opened\n", argv[2]); 

      else
         printf("File \"%s\" could not be opened\n", argv[1]);

   return 0;
}

