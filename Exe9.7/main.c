//
//  main.c
//  Exe9.7
//
//  Created by Francesco Parrucci on 29/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  Srivete un programma che inizializzi i 10 elementi del vettore number con degli interi casuali compresi tra 1 e 1000. Visualizzate
//  ogni valore e il totale progressivo del numero di caratteri visualizzati. Utilizzate la specifica di conversione %n per determinare
//  il numero di caratteri inviati in output per ogni valore. Visualizzate il totale dei caratteri inviati in output per tutti i valori
//  , includendo anche quello corrente, ogni volta che sarà visualizzato. L'output dovrà avere il seguente formato:
//
//  Value		Total characers
//  342			3
//  1000		7
//  963			10
//  6			11
//  etc. 
//
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 10

int main(){

	srand(time(NULL));

	int number[10] = {0}, count , total , t; 	
	printf("\nValue\tTotal characers\n");
	for(count = 0, total = 0, t = 0; count < size; count++){
		number[count] = rand() % 1000 + 1;
		printf("%d%n",number[count], &t);
		printf("%*c",5-t,' ');
		total += t;
		printf("\t%d\n",total);

	}
	return 0;

}

