//
//  main.c
//  Exe8.10
//
//  Created by Francesco Parrucci on 31/05/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 * Scrivete un programma che utlizzi la funzione strncmp per confrontare due stringhe immesse dall'utente.
 * Il programma dovrà rivevere in input il numero di caratteri da confrontare e dovrà stabilire se la prima
 * stringa è minore, uguale o maggiore della seconda.
 */

#include <stdio.h>
#include <string.h>
#define SIZE 100

int main(){

	char s[SIZE], t[SIZE], pt1[SIZE] , pt2[SIZE];
	int n = 0;

	printf("\nImmetti una stringa: ");
	gets(s);
	
	printf("\nImmetti una stringa: ");
	gets(t);

	do{
	printf("\nImmetti il numero di caratteri da confrontare: ");
	scanf("%d",&n);
	}while(n < 1 || n > 100);


	memcpy(pt1,s,n);
	memcpy(pt2,t,n);

	if(strncmp(s,t,n) > 0)
	       printf("\n\"%s\" è maggiore di \"%s\" valore restituito dalla funzione %d\n",pt1,pt2,strncmp(s,t,n));
	else if(strncmp(s,t,n) == 0)
	       printf("\n\"%s\" è uguale a \"%s\" valore restituito dalla funzione %d\n",pt1,pt2,strncmp(s,t,n));
	else
	       printf("\n\"%s\" è minore di \"%s\" valore restituito dalla funzione %d\n",pt1,pt2,strncmp(s,t,n));
	
	return 0;
}
