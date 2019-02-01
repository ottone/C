//
//  main.c
//  Exe5.37
//
//  Created by Francesco Parrucci on 31/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
SCRIVETE UNA FUNZIONE RICORSIVA power (base, exponent) CHE QUANDO INVOCATA RESTITUISCA LA POTENZA. SUPPONENDO CHE exponent SIA
MAGGIORE O UGUALE A 1. SUGGERIMENTO IL PASSO DI RICORSIONE DOVRA' UTILIZZARE LA RELAZIONE BASE ^ EXPONENT  = BASE * BASE ^
EXPONENT - 1. LA CONDIZIONE DI TERMINAZIONE SARA' VERIFICATA QUANDO EXPONENT SARA UGUALE A 1 PERCHE' BASE ^ = BASE
 */



#include <stdio.h>

int power(int, int);

int main(int argc, const char * argv[]) {
    // insert code here...
    int base, exponent;
    
    printf("\nInserire la Base e l'esponente per l'elevamento a potenza: ");
    scanf("%d%d",&base,&exponent);
    
    printf("\nRisultato: %d",power(base,exponent));
    
    printf("\nHello, World!\n");
    return 0;
}

int power(int base, int exponent){
    if(exponent == 0)
        return 1;
    else if(exponent == 1)
        return base;
    else
        return base * power(base , exponent - 1);
}