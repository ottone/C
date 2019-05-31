//
//  main.c
//  Exe8.7
//
//  Created by Francesco Parrucci on 31/05/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 * Scrivete un programma che prenda in input 4 stringhe che rappresentino degli interi,
 * le converta in interi, sommi i valori ottenuti e visualizzi il loro totale.
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main(){

	int count, total;
	char s[SIZE];
		
	for(count = 0, total = 0; count < 4; count++){
		
		printf("\nImmetti una stringa: ");
		gets(s);
		printf("\nValore intero della stringa: %d\n",atoi(s));
		total += atoi(s); 
	}

	printf("\nThe total: %d\n",total);

	return 0;
}
