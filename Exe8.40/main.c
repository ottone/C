//
//  main.c
//  Exe8.39
//
//  Created by Francesco Parrucci on 25/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
//
//  (Programma per la conversione metrica) Scrivete un programma che assista l'utente con le conversioni metriche. Il vostro programma dovrà consentire all'utente di specificare con delle stringhe
//  i nomi delle unità di misura (ovverosia, centimetri , litri, grammi, ecc per il sistema metrico decimale e pollici , quarti di gallone , libre ecc per il sistema anglosassone) e dovrà rispondere
//  a semplici domande come:
//
//  "A quanti pollici corrispondono 2 metri?"
//  "A quanti litri corrispondono 10 quarti di gallone?"
//
//  Il vostro programma dovrà riconoscere le conversioni non valide. Per esempio, la domanda 
//
//  "A quanti piedi corrispondono 5 chilogrammi?"
//
//  non ha un senso perchè i piedi sono un'unità di misura della lunghezza mentre il "chilogrammo" è una unità di misura del peso.
//
//
//
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 20




int main(){
	
	char *sis[] = {"metri","pollici"};	
	char buf[1000];
	char v[size];
	char *t, *f = NULL, *s = NULL;
	int count = 0;
	float val;

	puts("Inserisci una stringa tipo \"A quanti pollici corrispondono 2 metri\"");
	gets(buf);


	t = strtok(buf," ");
	while ((t = strtok(NULL," ")) != NULL){
		for(count = 0; count < 2; count++){
			if(atof(t) != 0) val = atof(t);
	       		if(strcmp(t,sis[count]) == 0 && f == NULL) f = t;
			else s = t;
		}	
	}
	printf("\n%s %.2f %s\n",f,val,s);
	
	

	return 0;

}

