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
   int i = 1;
   char *c ,a ;
   FILE *file1, *file2; 
   
  

   if(argc != 3){
	   printf("\n14.8 file1 file2\n");
   }else{
	   
	   if ((file1 = fopen(argv[1],"r")) == NULL)  
		   printf("\nImpossibile aprire i files...\n");
	   else{
		   if((file2 = fopen(argv[2],"w")) == NULL)
			   printf("\nImpossibile aprire %s\n",argv[2]);
		   else{
		  	 while((a = getc(file1)) != EOF)  i++;
		   
		  	 rewind(file1);

		 	  c = calloc(i,sizeof(char));
		
		 	  i = 0;
		 	  while((a = getc(file1)) != EOF) c[i++] = a;
		   
		 	  fclose(file1);
		   
		 	  for(; i >= 0; i--){ 
				   putchar(c[i]);
				   putc(c[i],file2);
		   		}
			
		   	//free(c);
		   	fclose(file2);
		
		   }
	

   }
}
}

