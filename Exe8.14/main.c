//
//  main.c
//  Exe8.14
//
//  Created by Francesco Parrucci on 31/05/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 * Scrivete un programma che prenda in input un numero telefonico in una stringa del formato (555) 555-5555. Il programma dovrà
 * utilizzare la funzione strtok per estrarre il token del prefisso, quello delle prime tre e delle ultime cifre del numero telefonico.
 * Le sette cifre del numero telefonico dovranno essere concatenate in una stringa. Il programma dovrà convertire il prefisso in un 
 * int e la stringa del numero telefonico in un long. Dovranno essere visualizzate entrambe le informazioni: prefisso e numero telefonico.
 */

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define size 20

int main(){
	     
	char ph[size], *p, prefix[size/2], number[size/2] = {'\0'};
	int prefisso, numero;
	
	printf("\nDigita il numero: ");
	gets(ph);
	
	memmove(ph,strchr(ph,'(') + 1,strlen(ph));
	memmove(strchr(ph,')'),strchr(ph,')') + 1,strlen(ph));
	p = memchr(ph,'-',strlen(ph));
	*p = ' ';
	ph[strlen(ph) + 1] = '\0'; 
	
	puts(ph);
	
	p = strtok(ph," ");
	strcpy(prefix,p);	
	puts(prefix);
	prefisso = atoi(prefix);
	//number[0] = '\0';

	while(p != NULL){
		p = strtok(NULL, " ");
		if(p != NULL)
		    strcat(number,p);

	}
	
	
	puts(number);
	getchar();
	numero = atol(number);

	printf("Prefisso : %d e Numero : %d\n",prefisso,numero);
	return 0;
}

