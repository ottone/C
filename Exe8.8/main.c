//
//  main.c
//  Exe8.8
//
//  Created by Francesco Parrucci on 31/05/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 * Scrivete un programma che prenda in input 4 stringhe che rappresentino dei 
 * valori in virgola mobile, le converta in double, sommi i valori ottenuti
 * e visualizzi il loro totale.
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main(){

	int count;
	double total;
	char s[SIZE];
		
	for(count = 0, total = 0; count < 4; count++){
		
		printf("\nImmetti una stringa: ");
		gets(s);
		printf("\nValore intero della stringa: %.2f\n",atof(s));
		total += atoi(s); 
	}

	printf("\nThe total: %.2f\n",total);

	return 0;
}
