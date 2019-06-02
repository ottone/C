//
//  main.c
//  Exe8.15
//
//  Created by Francesco Parrucci on 31/05/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 *Scrivete un programma che prenda in input una riga di testo, la suddivida in token con la funzione strtok e li invii in output ordine inverso
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define size 20

void tokst(char *);
void rev(char *,int);

int main(){

	char s[size] = {'\0'}, *t = s;

	printf("\nInserisci una stringa: \n");
	gets(s);
	//tokst(s);
	rev(s,1);

	return 0;
}


void tokst(char *s){
	
void reverseTok(char *);

	char *p;
	p = strtok(s, " ");
	reverseTok(s);
	puts(p);

	return 0;
}

void reverseTok(char *s){

	char *n;

	n = strtok(NULL, " ");

	if(n == NULL)
		return;
	else
	       reverseTok(s);
       	
 	puts(n);
	
	
}




void rev(char *p, int i){
	
	char *t;	

	if(i != 0){

		t = strtok(p , " ");
		rev(p,0);
		puts(t);

	}else if(i == 0){
	
		t = strtok(NULL, " ");
		if(t == NULL)
			return;
		else{
			rev(p,0);
			puts(t);	
		}
		
	}
}
