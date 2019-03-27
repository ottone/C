//
//  main.c
//  Exe6.32
//
//  Created by Francesco Parrucci on 09/03/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
(ORDINAMENTO PER SELEZIONE) UN ORDINAMENTO PER SELEZIONE RICERCHERA' IN UN VETTORE L'ELEMENTO PIU'
PICCOLO E, QUANDO L'AVRA' INDIVIDUATO, LO SCAMBIERA' DI POSTO CON IL PRIMO ELEMENTO DEL VETTORE. 
IL PROCESSO SI RIPETERA' PER IL SOTTOVETTORE CHE COMINCIA CON IL SECONDO ELEMENTO DEL VETTORE. OGNI
PASSAGGIO SUL VETTORE FARÀ IN MODO CHE UN ELEMENTO SIA SIASTEMATO NELLA POSIZIONE APPROPRIATA. 
QUESTO ORDINAMENTO RICHIEDE CAPACITÀ DI ELABORAZIONE SIMILI DELL'ORDINAMENTO A BOLLE PER UN VETTORE
DI N ELEMENTI, DOVRANNO ESSERE ESEGUITI N - 1 PASSAGGI E PER OGNI SOTTOVETTORE DOVRANNO ESSERE COMPIUTI
N - 1 CONFRONTI PER INDIVIDUAREE IL VALORE PIU' PICCOLO. IL VETTORE RISULTERÀ ORDINATO NEL MOMENTO IN 
CUI IL SOTTOVETTORE DA ELABORARE CONTERRÀ UN SOLO ELEMENTO. SCRIVETE UNA FUNZIONE RICORSIVA selectionSort 
CHE IMPLEMENTI QUESTO ALGORITMO.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10

void init(int v[size]){
	
	int m;

	for(m = 0; m <= size - 1; m++)
		v[m] = rand() % 99 + 1; 
	

	return;
}

void stampa(int v[size]){
	int m;

	for(m = 0; m <= size - 1; m++ )
		printf("\n%2d",v[m]);


	printf("\n");


	return;
}

void selectionSort(int v[size]){
	
	int m, n, swap;

	for(m = 0; m <= size - 1; m++)
		for(n = 0; n <= size - 1 ; n++)
		if(v[n] >= v[m]){
			swap = v[m];
			v[m] = v[n];
			v[n] = swap;
		}

	return;
}

int main(){

srand(time(NULL));

 int v[size] , m ;

init(v);

stampa(v);

selectionSort(v);

stampa(v);

return 0;
}

