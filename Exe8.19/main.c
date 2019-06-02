//
//  main.c
//  Exe8.19
//
//  Created by Francesco Parrucci on 02/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
 * Scrivete un programma basato su quello dell'Esercizio 8.18 che prenda in input diverse righe di testo e utilizza la funzione strchr
 * per determinare il totale delle occorrenze nelle righe di ogni carattre incluso nell'alfabeto. Le lettere maiuscole e quelle minuscole 
 * dovranno essere contate insieme. Immagazzinate i totali di ogni lettera in un vettore e una volta che saranno stati determinati visualizzate 
 * i suddetti valori in un formato tabulare.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define size 100
void getStr(char *s);
int totChar(char *s, char);

int main(){

	char string[1000] = {'\0'};
	
	int count, matrix[26] = { 0 };

	getStr(string);
	
	for(count = 0; count < 26; count++)
		matrix[count] += totChar(string,count + 65);
	
	for(count = 0; count < 26; count++){
		matrix[count] += totChar(string,count + 97);
		if(matrix[count] != 0)
		printf("Carattere %c/%c : %d\n", count + 65, count + 97, matrix[count]);
	}

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


int totChar(char *s, char c){

char  *searchPtr;
int l = 0;
	
	searchPtr = s;
	while((searchPtr = strchr(searchPtr,c))!= NULL){
			l++;
			searchPtr += 1;
		}
	
	return l;
}
