//
//  main.c
//  Exe8.13
//
//  Created by Francesco Parrucci on 31/05/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 * Scrivete un programma che codifichi delle frasi della lingua inglese in pig Latin (Latino del maiale). Il pig Latin è una forma
 * di linguaggio codificato usato spesso per divertimento. Esistono molte versioni dei metodi utilizzati per formare delle frasi
 * in pig Latin. Per semplicità, utilizzate il seguente algoritmo:
 *
 * Per formare una frase in pig Latin formulatene una il lingua inglese e suddividetela in parole con la funzione strtok. Per tradurre 
 * ogni parola inglese nella corrispondente in pig Latin, spostate la prima lettera della parola inglese in coda alla stessa e addiungete 
 * le lettere "ay". In questo modo, la parola "jump" diventerà "umpjay", "the" si trasformerà in "hetay" e "computer" diventerà "omputercay"
 * Gli spazi tra le parole riamrranno tali. Supponete quanto segue: la frase in inglese consisterà di parole separate da spazi, non ci 
 * saranno segni di punteggiatura e tutte le parole saranno formate da due o piu lettere. La funzione printLatinWordovrà visualizzare ogni
 * parola. Suggerimento: ogni volta che una chiamata di strtok avrà trovato un token, passate il puntatore ottenuto alla funzione printLatinWord
 * e visualizzate la parola in pig Latin.
 */

#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define size 100
#define word 16

void printLatinWord(char *p);

int main(){

	srand(time(NULL));
	char *article[] = {"the","a","one","some","any"},
	     *noun[] = {"boy", "girl","dog","town ","car"},
	     *verb[] = {"drove","jumped","ran","walked","skipped"},
	     *preposition[] = {"to","from","over","under","on"};
	char ph[size];
	char *pt ;


	


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
		//strcat(ph , ".");
		ph[0] = toupper(ph[0]);
		printf("\nStringhe ph : %s.",ph);
			
		getchar();

	pt = strtok(ph," ");
	while(pt != NULL){
		printLatinWord(pt);
		pt = strtok(NULL," ");
	}
	
	
	return 0;
}


void printLatinWord(char *p){
	

	char wd[word];
	char c = tolower(p[0]);
	if(c != '.'){
		strcpy(wd,p);
		memmove(wd,&wd[1],strlen(wd));
		wd[strlen(wd)] = c;
		strcat(wd,"ay");
		printf("%s\n",wd);
	}

}
