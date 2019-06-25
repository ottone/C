//
//  main.c
//  Exe8.23
//
//  Created by Francesco Parrucci on 07/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
 * Scrivete un programma che legga una serie di stringhe e visualizzi solo quelle che iniziano con la lettera "b". 
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
 
	getStr(s);		
	
	printf("\n\n");
	
	p = strtok(s,"\n");
	if(strchr(p,'b') != NULL)
		puts(p);
	while((p=strtok(NULL,"\n")) != NULL){
	if(strchr(p,'b') != NULL)
		puts(p);}
	
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
