//
//  main.c
//  Exe9.18
//
//  Created by Francesco Parrucci on 01/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  In alcuni linguaggi di programmazione, le stringhe devono essere immesse delimitandole con apici singoli o virgolette. Scrivete un 
//  programma che legga le tre stringhe suzy, "suzy" e 'suzy'. Il C ignora gli apici singoli e levirgolette o li considera parti
//  integranti della stringa?
//  


#include <stdio.h>

int main(){

char string[20];

printf("\nDigita la stringa suzy: ");
scanf("%s",string);
printf("Stampa della stringa suzy:  %s\n",string);
getchar();

printf("\nDigita la stringa \"suzy\": ");
scanf("%s",string);
printf("Stampa della stringa \"suzy\": %s",string);
getchar();

printf("\nDigita la stringa \'suzy\': ");
scanf("%s",string);
printf("Stampa della stringa \'suzy\' : %s\n\n",string);
getchar();

return 0;

}

