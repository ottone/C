//
//  main.c
//  Exe14.8
//
//  Created by Francesco Parrucci on 29/08/19.
//  Copyright © 219 Francesco Parrucci. All rights reserved.
//
//  Scrivete un programma che riceva come argomenti due nomi di file dalla riga di comando, legga uno per volta i caratteri dal primo e li scriva in ordine inverso nel secondo.
//

/* Using signal handling */

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
   int i, x ;
   char c ,a ;
   FILE *file1, *file2; 
   
  /* 

   if(argc != 3){
	   printf("\ncopyReverse file1 file2\n");
   }else{
*/	   
	   if(((file1 = fopen(argv[1],"r")) == NULL))// && ((file2 = fopen(argv[1],"w")) == NULL))
		   printf("\nImpossibile aprire i files...\n");
	   else{
		   i = 1;
		   //c = calloc(i,sizeof(char));
		   fread(&a,sizeof(char),1,file1);
		   putchar(a);
		   while(!feof(file1)){
			   fread(&a,sizeof(char),1,file1);
				putchar(a);
			}   //i = i + sizeof(char);
			   //c = realloc(c,i);
		   //}

		   //for(;i > 0; i--)
		//	   putchar(c[i]);
		   
		   fclose(file1);
/*
		   for(; i > 0; i--) putc(c[i],file2);

		   free(c);

		   rewind(file2);

		   while(a = getc(file2) != EOF) putchar(a);

		   fclose(file2);
*/		   
	   }


   }


