//
//  main.c
//  Exe8.39
//
//  Created by Francesco Parrucci on 23/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
//  (Il codice Morse) Il più famoso schema di codifica è probabilmente il codice Morse, sviluppato da Samuel Morse nel 1832 per il sistema telegrafico.
//  Il codice Morse assegna una serie di punti e di linee a ogni lettera dell'alfabeto, a ogni numero e a pochi caratteri speciali (come il punto, la
//  virgola, i due punti e il punto e virgola). Nei sistemi acustici, il punto è rappresentato da un suono breve e la linea è rappresentata da uno lungo.
//  Con i sistemi basati su segnali luminosi o sull'utilizzo di bandierine, sono utilizzate altre rappresentazioni di punti e linee.
//  La separazione tra le parole è indicata da uno spazio o, più semplicemente, dall'assenza di un punto o di una linea. Nei sistemi acustici, uno spazio
//  o, più semplicemente è indicato da un breve periodo durante il quale non è trasmesso alcun suono. La versione internaizonale del codice Morse è mostrata
//  nella Figura 8.39. 
//  Scrivete un programma che legga una frase in lingua italiana e la codifichi in codice Morse. Scrivete anche un programma che legga una frase in codice 
//  Morse e la converta nell'equivalente in lingua italiana. Utilizzate uno spazio tra le lettere del codice Morse e tre e tre fra le parole.
//
//  CARATTERE	CODICE	CARATTERE CODICE
//  A		.-	T	  -
//  B		-...	U	  ..-
//  C		-.-.	V	  ...-
//  D		-..	W	  .--
//  E		.	X	  -..-
//  F		..-.	Y	  -.--
//  G		--.	Z	  --..
//  H		....	
//  I		..	NUMERI
//  J		.---	1	  .----
//  K		-.-	2	  ..---
//  L		.-..	3	  ...--
//  M		--	4	  ....-
//  N		-.	5	  .....
//  O		---	6	  -....
//  P		.--.	7	  --...
//  Q		--.-	8	  --..
//  R		.-.	9	  ----.
//  S		...	0	  -----
//
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 20

char * toMors(char *s,char *b);
void fmMors(char *s);

int main(){
	
	char buf[100];
	char v[size];
	char *c;

	puts("Inserisci una stringa :");
	gets(v);
		
	c = toMors(v,buf);
	puts(c);

	fmMors(c);

	return 0;

}

char * toMors(char *s, char *b){
	
	
	char *p = b;
       	p[0] = '\0';

	char *al[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",
		      ".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",
		      ".--",".--","-..-","-.--","--.."};

	char *di[] = {"-----",".----","..---","...--","....-",
		      ".....","-....","--...","---..","----."};

	while(*s != '\0'){
			
			if(*s >= 65 && *s <= 90 ){
			       strcat(p,al[*s - 65]);
			       strcat(p," ");  
			       //printf("%s ",al[*s - 65]);
			}else if(*s >= 97 && *s <= 122){
			       strcat(p,al[*s - 97]); 
		      	       strcat(p," "); 
			       //printf("%s ",al[*s - 97]);
			}else if(*s >= 48 && *s <= 57){
			       strcat(p,di[*s - 48]);
		     	       strcat(p," ");
			       //]printf("%s ",di[*s - 48]);
			}else			
				puts("Valore non presente nel codice MORS");	
		s++;
	}

	return b;
}

void fmMors(char *b){

	int count;
	char *l;
	char *al[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",
		      ".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",
		      ".--",".--","-..-","-.--","--.."};

	char *di[] = 	  {"-----",".----","..---","...--","....-",
		           ".....","-....","--...","---..","----."};

	l = strtok(b," ");
	for(count = 0; count < 26; count++)
		if(strcmp(l,al[count]) == 0) printf("%c   ",count + 65);
	for(count = 0; count < 10; count++)
		if(strcmp(l,di[count]) == 0) printf("%c   ",count + 48);
	
	while((l = strtok(NULL," ")) != NULL){
		for(count = 0; count < 26; count++)
			if(strcmp(l,al[count]) == 0) printf("%c   ",count + 65);
		for(count = 0; count < 10; count++)
			if(strcmp(l,di[count]) == 0) printf("%c   ",count + 48);
		
	}

}
