//
//  main.c
//  Exe10.10
//
//  Created by Francesco Parrucci on 05/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  Scrivete un programma che faccia scorrere a destra di 4 bit una viariabile intera. Il programma dovrà visualizzare l'intero
//  in bit, prima e dopo l'operazione di scorrimento. Il vostro sistema metterà degli 0 o degli 1 nei bit?
//
//


#include <stdio.h>
#include <stdlib.h>

void visualizeBit(int);

int main(){
 	
	int i;

	printf("\nInserire un intero:");
	scanf("%d",&i);
	visualizeBit(i);
	printf("\nFaccio scorrere di 4 bit a destra l'intero %d",i);
	printf(" e ottengo %d\n",i>>=4);
	visualizeBit(i);

	return 0;	
}

void visualizeBit(int a){
	
	int mask = 1, j;
	mask <<= 15;

	for(j = 1 ; j <= 16 ; j++, a <<= 1){
		mask & a ? putchar('1') : putchar('0');
	}
	putchar('\n');
}
