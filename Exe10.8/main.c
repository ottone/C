//
//  main.c
//  Exe10.8
//
//  Created by Francesco Parrucci on 05/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  Create l'unione integer con i membri char c, short s, int i, e long l. Scrivete un programma che accetti in input valori di tipo
//  char, short , int e long e li immagazzini nelle variabili di un'unione di tipo union integer. Ogni variabile dell'unione dovrà
//  essere visualizzata come un char uno short, un int e long. I valori saranno sempre stampati correttamente?
//
//

/* Example using a bit field  Figura 10.16*/

#include <stdio.h>
#include <stdlib.h>

union integer {
	char c;
	short s;
	int i;
	long l;
};

int main(){
 	
	union integer inte;

	printf("\nInserisci un carattere: ");
	scanf("%c",&inte.c);
	printf("\nValori dell'unione inte c : %c s : %hd i : %d l: %ld\n",inte.c,inte.s,inte.i,inte.l);

	printf("\nInserisci un intero short (%d Byte): ",sizeof(short));
	scanf("%hd",&inte.s);
	printf("\nValori dell'unione inte c : %c s : %hd i : %d l: %ld\n",inte.c,inte.s,inte.i,inte.l);

	printf("\nInserisci un intero (%d Byte): ",sizeof(int));
	scanf("%d",&inte.i);
	printf("\nValori dell'unione inte c : %c s : %hd i : %d l: %ld\n",inte.c,inte.s,inte.i,inte.l);
	
	printf("\nInserisci un intero long(%d Byte): ",sizeof(long));
	scanf("%ld",&inte.l);
	printf("\nValori dell'unione inte c : %c s : %hd i : %d l: %ld\n",inte.c,inte.s,inte.i,inte.l);

	return 0;	
}

