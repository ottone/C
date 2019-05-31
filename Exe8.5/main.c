//
//  main.c
//  Exe8.5
//
//  Created by Francesco Parrucci on 31/05/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 * Scrivete un programma che prenda in input dalla tastiera un carattere e lo controlli con
 * ognuna dele funzioni incluse nella libreria per la gestione dei caratteri. Programma dovrà 
 * visualizzare il valore restituito da ogni funzione.
 *
 */

#include <stdio.h>
#include <ctype.h>

int main(){

	char c;
		
	while(c != EOF){
		
		printf("\nImmetti un carattere: ");
		c = getchar();
		getchar();

		printf("\nisdigit(%c)  : %5d",c,isdigit(c));
		printf("\nisalpha(%c)  : %5d",c,isalpha(c));
		printf("\nisalnum(%c)  : %5d",c,isalnum(c));
		printf("\nisxdigit(%c) : %5d",c,isxdigit(c));
		printf("\nislower(%c)  : %5d",c,islower(c));
		printf("\nisupper(%c)  : %5d",c,isupper(c));
		printf("\ntolower(%c)  : %5c",c,tolower(c));
		printf("\ntoupper(%c)  : %5c",c,toupper(c));
		printf("\nisspace(%c)  : %5d",c,isspace(c));
		printf("\niscntrl(%c)  : %5d",c,iscntrl(c));
		printf("\nispunct(%c)  : %5d",c,ispunct(c));
		printf("\nisprint(%c)  : %5d",c,isprint(c));
		printf("\nisgraph(%c)  : %5d",c,isgraph(c));
	}

	return 0;
}
