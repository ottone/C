//
//  main.c
//  Exe9.16
//
//  Created by Francesco Parrucci on 30/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  Scrivete un programma che prenda in input il valore 437 utilizzando con scanf ognuno degli indicatori di conversione per gli 
//  interi. Visualizzate ogni valore ricevuto in input utitlizzando tutti gli indicatori di conversione per gli interi.
//
//


#include <stdio.h>

int main(){

int i;

printf("\nDigita il numero 437: ");
scanf("%d",&i);
printf("Stampa del numero 437 acquisito con l'indicatore di conversione %%d : %d",i);
getchar();

printf("\nDigita il numero 437: ");
scanf("%u",&i);
printf("Stampa del numero 437 acquisito con l'indicatore di conversione %%u : %d",i);
getchar();

printf("\nDigita il numero 437: ");
scanf("%o",&i);
printf("Stampa del numero 437 acquisito con l'indicatore di conversione %%o : %d",i);
getchar();

printf("\nDigita il numero 437: ");
scanf("%x",&i);
printf("Stampa del numero 437 acquisito con l'indicatore di conversione %%x : %d",i);
getchar();

printf("\nDigita il numero 437: ");
scanf("%i",&i);
printf("Stampa del numero 437 acquisito con l'indicatore di conversione %%i : %d\n\n",i);
getchar();

return 0;

}

