//
//  main.c
//  Exe8.21
//
//  Created by Francesco Parrucci on 02/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
 * Utilizzate le funzioni di confronto delle stringhe discusse nella Sezione 8.6 e le tecniche di ordinamento dei vettori sviluppate nel
 * Capitolo 6, per scrivere un programma che disponga in ordine in ordine alfabetico un elenco di stringhe. Utilizzate i nomi di 10 o 15
 * città della vostra zona come dati per il programma. 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define size 100
#define word 15
void getStr(char *s);
void recharge(char [][word]);

void BubbleSort(char [][word], int , int );
void ShellSort(char [][word], int, int );

int main(){

	char s[size][15], *p;
	int count;
 
	for(count = 0; count < 5 ; count++){
		printf("\nNome di città: ");
		gets(s[count]);
	}
	
	//BubbleSort(s, 0 ,4);
	ShellSort(s, 0, 4);

	for(count = 0; count < 5 ; count++)
		puts(s[count]);
	
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


void BubbleSort(char a[size][word], int l, int r){

	char temp[15];
	int i, j;

	for(i = l; i < r; i++)
		for(j = r; j > i ; j--){
			//printf("%s vs %s -> %d\n",a[j-1],a[j],strcmp(a[j-1],a[j]));
			if(strcmp(a[j],a[j-1]) < 0){
				strcpy(temp,a[j]);
				strcpy(a[j],a[j-1]);
				strcpy(a[j-1],temp);
			}
		}
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
