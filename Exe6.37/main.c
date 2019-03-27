//
//  main.c
//  Exe6.37
//
//  Created by Francesco Parrucci on 09/03/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
(VISUALIZZARE UN VETTORE) SCRIVETE UNA FUNZIONE RICORSIVA printArray CHE RICEVA COME ARGOMENTI
UN VETTORE E LA SUA DIMENSIONE E NON RESTITUISCA ALCUN DATO. LA FUNZIONE DOVRÀ TERMINARE LA PROPRIA
ELABORAIZONE E RESTITUIRE IL CONTROLLO A QUELLA CHIAMANTE, QUANDO AVRA' RICEVUTO UN VETTORE DI 
DIMENSIONE 0.
*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 15

int init(int v[SIZE]){
	int m = 0;

	
	printf("INVIO per continuare e EOF per terminare: ");
	
	while(getchar() != EOF && ++m <= SIZE - 1){
		v[m] = rand() % 99 + 1;
		printf("INVIO per continuare e EOF per terminare: ");
	}

	printf("\nvalore di m: %d\n",m);

	return m;
}

void printArray(int v[SIZE], int sz){

	
	if(sz == 0)
		;
	if(sz > 0){
		printArray(v, sz - 1);
		printf("%3d",v[sz]);
	}
		

}

int main(){
	
	srand(time(NULL));

	int v[SIZE] = {0}, n;

	n = init(v);

	printArray(v,n);
	

return 0;

}
