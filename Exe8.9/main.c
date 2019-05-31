//
//  main.c
//  Exe8.9
//
//  Created by Francesco Parrucci on 31/05/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 * Scrivete un programma che utilizzi la funzione strcmp per confrontare due stringhe immesse dall'utente
 * Il programma dovrà stabilire se la prima stringa è minore uguale o maggiore della seconda
 */

#include <stdio.h>
#include <string.h>
#define SIZE 100

int main(){

	char s[SIZE], t[SIZE];
		
	printf("\nImmetti una stringa: ");
	gets(s);
	
	printf("\nImmetti una stringa: ");
	gets(t);

	if(strcmp(s,t) == 1)
	       printf("\n\"%s\" è maggiore di \"%s\"\n",t,s);
	else if(strcmp(s,t) == 0)
	       printf("\n\"%s\" è uguale a \"%s\"\n",t,s);
	else
	       printf("\n\"%s\" è minore di \"%s\"\n",t,s);
	
	return 0;
}
