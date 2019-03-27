//
//  main.c
//  Exe6.28
//
//  Created by Francesco Parrucci on 09/03/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
(ELIMINAZIONE DEI DUPLICATI) NEL CAPITOLO 12 ESLPOREREMO LE STRUTTURE DI DATI CON RICERCA BINARIA AD ALTA VELOCITA'.
UNA CARATTEREISTICA DEGLI ALVERI DI RICERCA BINARIA E'Ì CHE I VALORI DUPLICATI SARANNO SCARTATI, NELLO STESSO MOMENTO
IN CUI GLI ELEMENTI SARANNO INSERITI NELL'ALBERO. QUESTA CARATTERISTICA E' DETTA APPUNTO ELIMINAZIONE DEI DUPLICATI.
SCRIVETE UN PROGRAMMA CHE PRODUCA 20 NUMERI CASUALI COMPRESI TRA 1 E 20 . IL PROGRAMMA DOVRA IMMAGAZZINARE IN UN VETTORE 
TUTTI I VALORI NON DUPLICATI. UTILIZZATE IL VETTORE PIU PICCOLO POSSIBILE PERPORTARE A TERMINE QUESTO COMPITO.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 20

int main(){

	srand(time(NULL));

	int m, n, t = 0, i, v[size] = {0};
        v[0] = rand() % 20 + 1;

	for(m = 1; m <= size - 1;){
		i = (rand() % 20) + 1;
		for(t = 0, n = 0; n < m; n++ )
			if(v[n] == i)
				break;


			if(n == m){
			   v[n] = i;
			   m++;
			}

	}

	for(m = 0; m <= size - 1; m++)
		printf("Numero %2d : %2d\n", m + 1, v[m]);

}
