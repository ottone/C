//
//  main.c
//  Exe2.23
//
//  Created by Francesco Parrucci on 28/12/18.
//  Copyright © 2018 Francesco Parrucci. All rights reserved.
//

/* SCRIVETE UN PROGRAMMA CHE LEGGA UN INTERO E DETERMINI E VISUALIZZI SE SIA PARI O DISPARI. (SUGGERIMENTO: USATE L'OPERATORE MODULO, UN NUMERO PARI E' UN MULTIPLO DI DUE. OGNI MULTIPLO DI DUE DA' UN RESTO UGUALE A ZERO, QUANDO E' DIVISO PER 2.)
*/


#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int number;
    
    printf("Inserisci un numero intero: ");
    scanf("%d", &number);
    
    printf("...è un numero %s... \n", (number % 2) ? "dispari" : "pari" );
    
    return 0;
}
