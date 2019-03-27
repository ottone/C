//
//  main.c
//  Exe6.38
//
//  Created by Francesco Parrucci on 09/03/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
(VISUALIZZARE UNA STRINGA AL CONTRARIO) SCRIVETE UNA FUNZIONE stringReverse
CHE RICEVA COME ARGOMENTO UN VETTORE DI CARATTERI E NON RESTITUISCA NESSUN 
DATO. LA FUNZIONE DOVRÀ TERMINARE LA PROPRIA ELABORAZIONE E RESTITUIRE IL 
CONTROLLO A QUELLA CHIAMANTE, QUANDO AVRA' INCONTRATO IL NULL DI TERMINAZIONE 
DELLA STRINGA.
*/

#include <stdio.h>
#define SIZE 15

void stringReverse(char v[]){
	char c = v[0];


	if(c != '\0'){ 
		v++;
		stringReverse(v);
	}
	printf("%c",c);
}

int main(){

	char v[SIZE];

	printf("\nInserire una parola: ");
	scanf("%s",v);
	printf("\nParola immessa : %s\n",v);
	
	stringReverse(v);

return 0; 
}
