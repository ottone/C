//
//  main.c
//  Exe9.9
//
//  Created by Francesco Parrucci on 30/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  Scrivete un programma che visualizzi i valori di un puntatore utilizzando tutti gli indicatori di conversione per gli interi e la
//  specifica %p. Quale visualizzerà dei valori strani? Quale provochera' degli errori? Sul vostro sistema, in quale formato visualizzerà
//  l'indirizzo la specifica di conversione %p?
//

#include <stdio.h>


int main(){

	int *iPtr, y;

	printf("\nOutput del contenuto del puntatore iPtr con le varie specifiche di conversione per interi:\n");
	printf("%%d , %%i , %%u, %%p ,%%hd, %%hi, %%hu, %%hp, %%ld, %%li, %%lu, %%lp\n");

	iPtr = &y;
	
	printf("\nAssegno a *iPtr l'indirizzo della variabile intera y\n");
	printf("\nVisualizzazione del valore di *iPtr con specifica di conversione %%d : %d",iPtr);
	printf("\nVisualizzazione del valore di *iPtr con specifica di conversione %%i : %i",iPtr);
	printf("\nVisualizzazione del valore di *iPtr con specifica di conversione %%u : %u",iPtr);
	printf("\nVisualizzazione del valore di *iPtr con specifica di conversione %%o : %o",iPtr);
	printf("\nVisualizzazione del valore di *iPtr con specifica di conversione %%x : %x",iPtr);
	printf("\nVisualizzazione del valore di *iPtr con specifica di conversione %%X : %X",iPtr);
	printf("\nVisualizzazione del valore di *iPtr con specifica di conversione %%ld : %ld",iPtr);
	printf("\nVisualizzazione del valore di *iPtr con specifica di conversione %%li : %li",iPtr);
	printf("\nVisualizzazione del valore di *iPtr con specifica di conversione %%lu : %lu",iPtr);
	printf("\nVisualizzazione del valore di *iPtr con specifica di conversione %%lo : %lo",iPtr);
	printf("\nVisualizzazione del valore di *iPtr con specifica di conversione %%lx : %lx",iPtr);
	printf("\nVisualizzazione del valore di *iPtr con specifica di conversione %%lX : %lX",iPtr);
	printf("\nVisualizzazione del valore di *iPtr con specifica di conversione %%p : %p\n\n",iPtr);

	return 0;

}

