//
//  main.c
//  Exe8.18
//
//  Created by Francesco Parrucci on 02/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
 * Scrivete un programma che prenda in input diverse righe di testo e un carattere da ricercare e utilizzi strchr,
 * per determinare il totale delle occorrenze del carattere nelle righe di testo. 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define size 100
void getStr(char *s);
void totChar(char *s);

int main(){

	char string[1000] = {'\0'};


	getStr(string);
	totChar(string);
	
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


void totChar(char *s){

char c, *searchPtr;
int n, l = 0;
	

	printf("\nCarattere da conteggiare: ");
	c = getchar();
	searchPtr = s;
	while((searchPtr = strchr(searchPtr,c))!= NULL){
			l++;
			searchPtr += 1;
		}

		printf("\nTotale occorrenze trovate del carattere %c : %d\n",c, l);
}
