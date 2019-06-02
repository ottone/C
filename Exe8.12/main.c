//
//  main.c
//  Exe8.12
//
//  Created by Francesco Parrucci on 31/05/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 * (Limerik) Una limerik è una poesia umoristica di cinque versi in cui il primo e il secondo verso fanno rima con il quinto
 * mentre il terzo fa rima con il quarto. Usando tecniche simili a quelle sviluppate nell'esercizio 8.10 scrivete un programma
 * C che produca una serie di limericka caso. Raffinate questo programma in modo che generi delle buone limerick sarà un compito
 * impegnativo, ma il risultato varrà bene la fatica.
 */
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define PHRASE 100
#define STORY 1000

int main(){

	srand(time(NULL));
	char *article[] = {"the","a","one","some","any"},
	     *noun[] = {"boy", "girl","dog","town ","car"},
	     *verb[] = {"drove","jumped","ran","walked","skipped"},
	     *preposition[] = {"to","from","over","under","on"};
	char *first, *forth;
	char ph[PHRASE];
	char st[STORY];

	st[0] = '\0';
	int n = 0;
	
	do{

		ph[0] = '\0';
		strcat(ph , article[rand() % 5]);
		strcat(ph , " ");
		strcat(ph , noun[rand() % 5]);
		strcat(ph , " ");
		strcat(ph , verb[rand() % 5]);
		strcat(ph , " ");
		strcat(ph , preposition[rand() % 5]);
		strcat(ph , " ");
		strcat(ph , article[rand() % 5]);
		strcat(ph , " ");
		if(n == 0){
			first = noun[rand() % 5];
			strcat(ph , first);
		}else if(n == 3){
			forth = noun[rand() % 5];
			strcat(ph , forth);
		}else if(n == 1 || n == 2)
			strcat(ph , first);
		else 
			strcat(ph , forth);

		strcat(ph , ".");

		ph[0] = toupper(ph[0]);
		strcat(st, ph);
		strcat(st, "\n");
		printf("\nStringhe ph : %s ",ph);// e st : %s",ph,st);
			
		getchar();

	}while(++n < 5);


	printf("\nThe story: \n\n");
	printf("%s",st);

	
	return 0;
}
