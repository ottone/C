//
//  main.c
//  Exe8.25
//
//  Created by Francesco Parrucci on 07/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
 * Scrivete un programma che prenda in input un codice ASCII e visualizzi il carattere corrispondente. Modificate questo programma,
 * in modo che generi tutti i possibili codici di tre cifre compresi nell'intervallo da 000 a 255 e tenti di visualizzare il carattere
 * corrispondente. Che cosa succederà quando questo programma sarà eseguito? 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define size 1000
#define word 15

void getStr(char *s);
void recharge(char [][word]);
void BubbleSort(char [][word], int , int );
void ShellSort(char [][word], int, int );

int main(){

	char s[size], *p, *c;
	int count;
 
	
	printf("\n\n");

	printf("\nInserire un numero da 0 a 255: ");
	scanf("%d",&count);
	
	while(count >= 0 && count <= 255){
		putchar(count);
		printf("\nInserire un numero da 0 a 255: ");
		scanf("%d",&count);
	}
	
	return 0;
}


void getStr(char *s){

int n = 0, temp[word];	
int c;

	printf("\nInserisci un testo CTRL-D per terminare: \n");
	
	while((c = getchar()) != EOF){
		s[n++] = (char)c;
	}	
	s[n] = '\0';

	clearerr(stdin);
	
}


void recharge(char s[size][word]){

	int count;

	for(count = 0; count < 5 ; count++){
		printf("\nNome di città: ");
		gets(&s[count]);
	}

	//return 0;

}


void ShellSort(char  a[size][word], int l, int r){

	int i, j, h;
	char temp[15];


	for( h = 1 ; h <= (r-l)/9; h = 3*h+1) ;
	for( ; h > 0 ; h / 3)
		for(i = 1 + h; i <= r; i++){ 
		   j = i;	
		   strcpy(temp,a[i]);
	   	   while( j >=  1+h && strcmp(temp,a[j-h]))
			{ strcpy(a[j],a[j-h]) ; j -= h;}
		   strcpy(a[j],temp);
		}	   

}
