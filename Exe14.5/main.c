//
//  main.c
//  Exe14.5
//
//  Created by Francesco Parrucci on 29/08/19.
//  Copyright © 219 Francesco Parrucci. All rights reserved.
//  
//  Scrivete un programma che inserisca uno spazio tra ogni carattere di un file. Il programma dovrà prima scrivere il contenuto del file da modificare in un archivio temporaneo, inserendo gli spazi tra i caratteri, e quindi 
//  dovrà ricopiare il file temporaneo su quello originale. Questa operazione dovrà sostituire i contenuti del file originale.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 100
int main(int argc, char *argv[]){

FILE *filePtr, *tempfilePtr;
srand(time(NULL));
int a, c;
char name[20]; 

printf("\nEnter a file name: ");
scanf("%s",name);

if((filePtr = fopen(name,"w")) != NULL){
	for(a = 0; a < SIZE; a++){
		if((a % 10) == 0){ 
			putc('\n',filePtr);
			//putchar('\n');
		}else{
			c = 60 + (rand() % 25);
			putc(c,filePtr);
			//putchar(c);
		}
	}
	fclose(filePtr);
}else{
	printf("\nCould not be possible open the file %s.\n",name);
}
	
if ( ( filePtr = fopen(name, "r+") ) != NULL){

      if ( ( tempfilePtr = tmpfile() ) != NULL) {
         printf("\nThe file before modification is:\n");

         while ( ( c = getc(filePtr) ) != EOF) {
            putchar(c);
	    putc(c,tempfilePtr);
            putc(' ', tempfilePtr);
         }

         rewind(tempfilePtr);
         rewind(filePtr);
         printf("\n\nThe file after modification is:\n");

         while ( ( c = getc(tempfilePtr) ) != EOF) {
            putchar(c);
            putc(c, filePtr);
         }

	 fclose(tempfilePtr);
	 fclose(filePtr);
      }
      else
         printf("Unable to open temporary file\n");
}else
      printf("Unable to open %s\n", name);



 return 0;
}
