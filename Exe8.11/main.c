//
//  main.c
//  Exe8.11
//
//  Created by Francesco Parrucci on 31/05/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 * Scrivete un programma che utlizzi la generazione di numeri casuali per creare delle frasi. Il programma dovrà utilizzare quattro
 * vettori di puntatori a char chiamati article, noun, verb e preposition e dovrà creare una frase selezionando una parola a caso
 * da ognuno dei vettori nel suente ordine: articolo, noun, verb, preposition, article e noun. Man mano che selezionate le singole 
 * parole queste dovranno essere concatenate a quelle precedenti, in un vettore che sia sufficientemente grande per contenere la frase
 * intera. Le parole dovranno essere separate da spazi. Quando la frase finale sarà inviata in output, questa dovrà incominciare con una 
 * lettera maiuscola e terminare con un punto. Il programma dovrà generare 20 frasi. 
 * I vettori dovranno essere riempiti come segue: article dovrà contenere gli articoli "the" , "a", "one", "some" e "any"; noun dovrà 
 * contenere i nomi "boy", "girl" , "dog", "town" e "car"; verb dovrà contenere i verbi "drove" ,"jumped", "ran","walked" e "skipped" 
 * ; preposition dovrà contenere le preposizioni "to" , "from", "over" ,"under" e "on".
 * Una volta che il suddetto programma sarà stato scritto e sarà funzionante, modificatelo in modo che scriva una breve storia formata 
 * da queste frase. (Vi piace l'idea di uno scrittore casuale?)
 */
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define PHRASE 100
#define STORY 1000

int main(){

	srand(time(NULL));
	char *article[] = {"the","a","one","some","any"},
	     *noun[] = {"boy", "girl","dog","town ","car"},
	     *verb[] = {"drove","jumped","ran","walked","skipped"},
	     *preposition[] = {"to","from","over","under","on"};
	char *ptr;
	char ph[PHRASE];
	char st[STORY];

	st[0] = '\0';
	int n = 0;
	
	do{

		ph[0] = '\0';
		strcat(ph , article[rand() % 5]);
		strcat(ph , " ");
		strcat(ph , noun[rand() % 5]);
		strcat(ph , " ");
		strcat(ph , verb[rand() % 5]);
		strcat(ph , " ");
		strcat(ph , preposition[rand() % 5]);
		strcat(ph , " ");
		strcat(ph , article[rand() % 5]);
		strcat(ph , " ");
		strcat(ph , noun[rand() % 5]);
		strcat(ph , ".");

		ph[0] = toupper(ph[0]);
		strcat(st, ph);
		strcat(st, "\n");
		printf("\nStringhe ph : %s ",ph);// e st : %s",ph,st);
			
		getchar();

	}while(++n < 20);


	printf("\nThe story: \n\n");
	printf("%s",st);

	
	return 0;
}
