//
//  main.c
//  Exe11.15
//
//  Created by Francesco Parrucci on 14/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//   
//  Modificate l'esempio della Figura 8.14, in modo che utilizzi le funzioni fgetc e fputc, invece di getchar e puts. Il programma dovrà offrire all'utente la 
//  possibilità di scegliere se leggere dallo standard input e scrivere sullo standard output, o se leggere e scrivere in file specificati. Nel caso in cui
//  l'utente scelga la seconda possibilità, consentitegli di immettere i nomi dei file di input e di output.
//
/* Using getchar and puts */
#include <stdio.h>

int main()
{
   FILE *ptrIn, *ptrOut;
   char c, sentence[80], in[20], out[20];
   int i = 0;
   
   do{
   printf("\n1 per leggere da stdin e scrivere su stdout\n"
	    "2 per leggere da file e scrivere su file: ");
   scanf("%d",&i);
   }while(i < 1 || i > 2);

   if(i == 1) {
	i = 0;
   	puts("Enter a line of text:");
   	while(( c = fgetc(stdin)) != '\n') 
   	sentence[i++] = c;

   	sentence[i] = '\0';  /* insert NULL at end of string */
  	fputs("\nThe line entered was:",stdout);
  	fputs(sentence,stdout);
  	fputs("\n\0",stdout);
    }else{
	printf("\nImmettere il nome del file dal quale leggere:");
	scanf("%s",in);
	printf("\nImmettere il nome del file sul quale scrivere:");
	scanf("%s",out);
	
	if((ptrIn = fopen(in,"r")) == NULL){
			printf("\nImpossibile aprire il file %s\n",in);
	}else{
		i = 0;
   		while((c = fgetc(ptrIn)) != EOF) 
			sentence[i++] = c;
		sentence[i] = '\0';
		fclose(ptrIn);
	}

	if((ptrOut = fopen(out,"w")) == NULL){
			printf("\nImpossibile aprire il file %s\n",out);
	}else{
		fputs(sentence,ptrOut);
		fclose(ptrOut);
	}

    }

return 0;
}
