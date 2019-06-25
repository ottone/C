//
//  main.c
//  Exe8.20
//
//  Created by Francesco Parrucci on 02/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
 * Scrivete un programma che prenda in input diverse righe di testo e utilizzi la funzione strtok per contare il numero di totale
 * delle parole. Supponete che queste siano separate da spazi o da caratteri newline
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define size 100
void getStr(char *s);
int totChar(char *s, char *);

int main(){

	char string[1000] = {'\0'};
	
	int count, matrix[26] = { 0 };

	getStr(string);
	printf("\nNumero di parole : %d\n",totChar(string," "));
	
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


int totChar(char *s, char *c){

char  *searchPtr;
int l = 0;
	
	searchPtr = strtok(s, c);
	l++;
	while(searchPtr != NULL){
		searchPtr = strtok(NULL,c);
		l++;
	}
	return l;
}
