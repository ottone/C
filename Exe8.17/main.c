//
//  main.c
//  Exe8.17
//
//  Created by Francesco Parrucci on 02/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
 * Scrivete un programma, basato sull'esercizio 8.16 che prenda in input diverse righe di testo e una stringa di ricerca e utilizzi la funzione 
 * strstr per determinare il totale delle occorrenze della stringa nelle righe di testo. Visualizzate il risultato.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define size 100
void getStr(char *s);
void serch(char *s);

int main(){

	char string[1000] = {'\0'};


	getStr(string);
	serch(string);
	
	return 0;
}


void getStr(char *s){

int n = 0, temp[size];	
int c;

	printf("\nInserisci un testo CTRL-D per terminare: \n");
	
	while((c = getchar()) != EOF){
		s[n++] = (char)c;
	}	
	s[n] = '\0';

	clearerr(stdin);
	
}


void serch(char *s){
char search[10] = {'\0'} , *searchPtr, c[size] = {'\0'}, pt2;
int n, l = 1;
	

	printf("\nstringa di ricerca: ");
	scanf("%s",search);

	n = 0;
	searchPtr = strstr(s,search);
		while(searchPtr != NULL){
		printf("\nline %d: ",l);	
			while(searchPtr[n] != '\n' && searchPtr[n] != EOF)
				putchar(searchPtr[n++]);
		searchPtr = strstr(searchPtr + 1,search);
		n = 0, l++;	
		}

		printf("\n\n");
}
