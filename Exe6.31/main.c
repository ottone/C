//
//  main.c
//  Exe6.31
//
//  Created by Francesco Parrucci on 09/03/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
(BUCKET SORT) UN BUCKET SORT INCOMINCIA DICHIARANDO UN VETTORE UNIDIMENSIONALE DI INTERI POSITIVI,
QUELLO CHE DOVRA' ESSERE ORDINATO, E UNA MATRICE DI INTERI CON LE RIGHE INDICIZZATE DA 0 A 9 E LE 
COLONNE DA 0 A N-1, DOVE N E IL NUMERO DEI VALORI PRESENTI NEL VETTORE CHE DOVRA' ESSERE ORDINATO. 
OGNI RIGA DELLA MATRICE E' DETTA BUCKET (SECCHIO). SCRIVETE UNA FUNZIONE bucketSort CHE RICERVA COME 
ARGOMENTI UN VETTORE DI INTERI E LA SUA DIMENSIONE. L'ALGORITMO E' IL SEGUENTE :

1) SCORRETE IL VETTORE UNIDIMENSIONALE E SISTEMATE OGNUNO DEI SUOI VALORI IN UNA RIGA DELLA MATRICE,
BASSANDOVI SULLA CIFRA DELLE UNITA'. PER ESEMPIO, IL 97 SARA' SISTEMATO NELLA RIGA 7 , IL 3 SARA' 
INSERITO NELLA RIGA 3 E IL 100 SARA' POSTO NELLA RIGA 0.

2) SCORRETE LA MATRICE E RIPORTATE I VALORI NEL VETTORE ORIGINARIO. NEL VETTORE UNIDIMENSIONALE IL 
NUOVO ORDINE DEI SUDDETTI VALORI SARA' 100, 3 E 97.

3) RIPETETE QUESTO PROCESSO PER OGNI SUCCESSIVA POSIZIONE DELLE CIFRE (DECINE , CENTINAIA,  MIGLIAIA 
ECC.) E FERMATEVI QUANDO SARA' STATA ELABORATA LA CIFRA PIU' SIGNIFICATIVA DEL NUMERO PIU' GRANDE.

AL TERMINE DEL SECONDO PASSAGGIO SUL VETTORE, IL 100 SARA' SISTEMATO NELLA RIGA 0, IL 3 SARA' INSERITO 
NELLA RIGA 0 O (POICHE HA SOLO UNA CIFRA) E IL 97 SARA' POSTO NELLA RIGA 9. L'ORDINE DEI VALORI NEL VETTORE
UNIDIMENSIONALE SARA' A QUESTO PUNTO :100 , 3, E 97.AL TERMINE DEL TERZO PASSAGGIO,  IL 100 SARA' SISTEMATO 
NELLA RIGA 1, IL 3 E IL 97 SARANNO INSERITI NELLA RIGA 0 (IL 97 DOPO IL 3).IL BUCKET SORT GARANTISCE CHE 
TUTTI I VALORI SARANNO ORDINATI APPROPRIATAMENTE, DOPO CHE SARA' STATA ELABORATA LA CIFRA PIU' SIGNIFICATIVA
DEL NUMERO PIU' GRANDE. IL BUCKET SORT SAPRA' DI AVERE TERMINATO IL PROPRIO COMPITO, QUANDO TUTTI I VALORI
SARANNO STATI RICOPIATI NELLA RIGA 0 DELLA MATRICE. OSSERVATE CHE LA MATRICE AVRA' UNA DIMENSIONE PARI A 10
VOLTE QUELLA DEL VETTORE DI INTERI DA ORDINARE. QUESTA TECNICA E' PIU' EFFICIENTE DI QUELLA DELL' ORDINAMENTO
A BOLLE, MA RICHIEDE UNA CAPACITÀ DI MEMORIA NOTEVOLMENTE SUPERIORE . L'ORDINAMENTO A BOLLE RICHIEDE SOLO UNA
POSIZIONE DI MEMORIA IN PIU' PER IL TIPO DI DATO DA ORDINARE. IL BUCKET SORT È UN ESEMPIO DI COMPROMESSO TRA 
CONSUMO DI MEMORIA ED EFFICIENZA: E' VERO CHE UTILIZZA PIU' MEMORIA, MA È ANCHE VERO CHE È PIU' EFFICIENTE.
QUESTA VERSIONE DEL BUCKET SORT RICHIEDE CHE PER OGNI PASSAGGIO I DATI SIANO RIPORTATI NEL VETTORE ORIGINALE.
SI POTREBBE ANCHE CREARE UNA SECONDA MATRICE E SPOSTARE RIPETUTAMENTE I DATI TRA LE DUE MATRICI, FINCHE' 
NON SIANO STATI RICOPIATI TUTTI NELLA RIGA 0 DI UNA DELLE DUE. A QUEL PUNTO LA RIGA 0 CONTERREBBE IL VETTORE ORDINATO.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 10




void clear(int m[size][size]){
	int i, j;

	for(i = 0 ; i <= size -1 ; i++)
                for(j = 0; j <= size -1; j++)
			m[i][j] = 0;

	return;
}

int paw(int e){

        if(e == 0)
                return 1;
        else
                return 10 * paw(e - 1);

}


void fill(int v[size]){
	
	int m;
	for(m = 0; m <= size - 1; m++)
		v[m] = rand() % 99 + 1;

return;
}

void stampa(int v[size]){
	int m;
	printf("\n");

	for(m = 0; m <= size - 1; m++)
		printf("v[%d] = %2d\n",m,v[m]);

return;
}

int unit(int x, int y){
        int j;
	if(y == 1)
		j = x % 10;
	else if(y > 1)
		j = x / paw(y - 1); 

  return j;
}


void bucketSort(int v[size]){
        
        int i = 0 , j = 0, n = 100, vet[size], m[size][size] = {{0}};
        int index;

	for(n = 1 ; n <= 2; n++){
       
	stampa(v);
        
	for(i = 0, j = 0; i <= size - 1; i++, j = 0){
		index = unit(v[i],n);
		while((m[index][j]) != 0) j++;
			m[index][j] = v[i];
                	      
	}
	
	printf("\n\nStampa della matrice \n\n");
	for(i = 0 ; i <= size -1 ; i++){
                for(j = 0; j <= size -1; j++){
			printf("%2d",m[i][j]);
		}
		printf("\n");
	}
	

	index = 0;

        for(i = 0 ; i <= size -1 ; i++)
                for(j = 0; j <= size -1; j++)
			if(m[i][j] != 0)
				v[index++] = m[i][j];

	clear(m);
	
	printf("\n\n\n");
	}
	stampa(v);
}


int main(){
	
	srand(time(NULL));

	int v[size], m, i; 
	

	fill(v);
	//stampa(v);
	bucketSort(v);
	//stampa(v);
	/*while(getchar() != EOF){
		printf("\nInserisci un numero: ");
		scanf("%d",&m);
		printf("\nInserisci un numero: ");
		scanf("%d",&i);
		printf("\nunit(%d,%d) = %d\n",m,i,unit(m,i));
	}*/
	return 0;
}	
