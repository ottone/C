//
//  main.c
//  Exe9.17
//
//  Created by Francesco Parrucci on 01/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  Scrivete un programma che utilizzi gli indicatori di conversione e, f e g per prendere in input il valore 1.2345. Visualizzate i 
//  valori di ogni variabile per dimostrare che i suddetti indicatori di conversione potranno essere utilizzati per prendere in input
//  lo stesso valore.
//


#include <stdio.h>

int main(){

float i;

printf("\nDigita il numero 1.2345: ");
scanf("%e",&i);
printf("Stampa del numero 1.2345 acquisito con l'indicatore di conversione %%e : %e",i);
getchar();

printf("\nDigita il numero 1.2345: ");
scanf("%f",&i);
printf("Stampa del numero 1.2345 acquisito con l'indicatore di conversione %%f : %f",i);
getchar();

printf("\nDigita il numero 1.2345: ");
scanf("%g",&i);
printf("Stampa del numero 1.2345 acquisito con l'indicatore di conversione %%g : %g",i);
getchar();

printf("\nDigita il numero 437: ");
scanf("%x",&i);
printf("Stampa del numero 437 acquisito con l'indicatore di conversione %%x : %d",i);
getchar();


return 0;

}

