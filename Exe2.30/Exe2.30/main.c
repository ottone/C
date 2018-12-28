//
//  main.c
//  Exe2.30
//
//  Created by Francesco Parrucci on 28/12/18.
//  Copyright © 2018 Francesco Parrucci. All rights reserved.
//

/* SCRIVETE UN PROGRAMMA CHE PRENDA IN INPUT UN NUMERO DI CINQUE CIFRE, LO SPEZZETTI NELLE SUE SINGOLE CIFRE E LE VISUALIZZI OGNUNA SEPARATA DALL'ALTRA DA TRE SPAZI. PER ESEMPIO, SE L'UTENTE DIGITASSE 42339, IL PROGRAMMA DOVREBBE VISUALIZZARE
*/

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int number, count;
    
    printf("Inserire un numero: ");
    scanf("%d",&number);
    
    printf("%d   ", number / 10000);
    number = number % 10000;
    
    printf("%d   ", number / 1000);
    number = number % 1000;
    
    printf("%d   ", number / 100);
    number = number % 100;
    
    printf("%d   ", number / 10);
    number = number % 10;
    
    printf("%d   \n", number);
    
    return 0;
}
