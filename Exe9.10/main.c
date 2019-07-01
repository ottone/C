//
//  main.c
//  Exe9.10
//
//  Created by Francesco Parrucci on 30/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  Scrivete un programma che verifichi i risultati ottenuti visualizzando il valore intero 12345 e quello in virgola mobile 1.2345
//  , in campi con varie dimenzioni. Che cosa succederà quando i valori saranno visualizzati in campi con una dimensione inferiore a 
//  a quelle dei valori?
//
//

#include <stdio.h>


int main(){

int c;


printf("\nRisultati ottenuti visualizzando il valore intero 12345 e quello in virgola mobile 1.2345 in campi con varie demenzioni\n");

for(c = 0 ; c <=  5; c++)
	printf("specifica %%d lunghezza di campo %d precisione %d valore %d : %*.*d\n",c,c,12345,c,c,12345);

getchar();

for(c = 0 ; c <=  5; c++)
	printf("specifica %%f campo %d precisione %d valore %f : %*.*f\n",c,c,1.2345,c,c,1.2345);

getchar();

for(c = 0 ; c <=  5; c++)
	printf("specifica %%e campo %d precisione %d valore %f : %*.*e\n",c,c,1.2345,c,c,1.2345);

getchar();

for(c = 0 ; c <=  5; c++)
	printf("specifica %%g campo %d precisione %d valore %g : %*.*g\n",c,c,1.2345,c,c,1.2345);

getchar();


return 0;

}

