//
//  main.c
//  Exe9.15
//
//  Created by Francesco Parrucci on 30/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  Scrivete un programma che determini se il ? possa essere visualizzato come carattere letterale nella stringa di controllo del 
//  formato di printf, invece che con la sequenza di escape \?.
//


#include <stdio.h>

int main(){

printf("Stampa del carattere di \? con sequenza di escape  \? \n");
printf("Stampa del carattere di \? senza sequenza di escape ? \n");
printf("Stampa del carattere di \? con indicatore di conversione %%c %c \n",'?');

return 0;

}

