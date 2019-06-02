//
//  main.c
//  Exe8.16
//
//  Created by Francesco Parrucci on 31/05/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 * Scrivete un programma che prenda in input dalla stastiera una riga di testo e una stringa di ricerca. Utilizzando la funzione
 * strstr, individuate la prima occorrenza della stringa di ricerca nella riga di testo e assegnate la locazione ottenuta alla 
 * variabile searchPtr di tipo char *. Nel caso che la stringa di ricerca sisa stata ritrovata, cominciando da questa, visualizzate
 * la riga di testo. Utilizzate quindi nuovamente strstr per individuare nella riga di testo la successiva occorrenza della stringa
 * di ricerca. Nel caso che sia stata trovata una seconda occorrenza della stringa di ricerca, visualizzate la riga di testo cominciando
 * dalla seconda occorrenza. Suggerimento : la seconda invocazione di strstr dovrà contenere searchPtr + 1 come suo primo argomento.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define size 100


int main(){

	char string[size] = {'\0'} , search[size/10] = {'\0'} , *searchPtr;

	printf("\nInserisci una stringa: ");
	gets(string);
	printf("\nstringa di ricerca: ");
	gets(search);

	searchPtr = strstr(string,search);
	if(searchPtr != NULL)
		while(searchPtr != NULL){
			puts(searchPtr);
			searchPtr = strstr(searchPtr + 1,search);	
		}
	
	return 0;
}
