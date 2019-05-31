//
//  main.c
//  Exe8.6
//
//  Created by Francesco Parrucci on 31/05/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 * Scrivete un programma che prenda in input una riga di testo con lunzione gets e la immagazzini nel vettore
 * di caratteri s[100]. Inviate in output la riga prima in lettere maiuscole e poi in minuscole
 */

#include <stdio.h>
#include <ctype.h>
#define SIZE 100

int main(){
 
	char s[SIZE] , *ptr = NULL ;

	while(1){
		
		printf("\nImmetti una stringa: ");
		gets(s);
	
		for(ptr = s; *ptr != '\0'; ptr++)
			putchar(tolower(*ptr));
		printf("\n");
		
		for(ptr = s; *ptr != '\0'; ptr++)
			putchar(toupper(*ptr));
		
		printf("\n");
	}

	return 0;
}
