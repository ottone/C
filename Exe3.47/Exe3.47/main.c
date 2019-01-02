//
//  main.c
//  Exe3.47
//
//  Created by Francesco Parrucci on 01/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 SCRIVETE UN PROGRAMMA CHE LEGGA IN INPUT UN INTERO NON NEGATIVO E QUINDI CALCOLI E VISUALIZZI IL SUO FATTORIALE
 SCRIVETE UN PROGRAMMA CHE APPROSSIMI IL VALORE DELLA COSTANTE MATEMATICA e = 1 + 1/1! + 1/2! + ...
 SCRIVETE UN PROGRAMMA CHE APPROSSIMI IL VALORE DI UTILIZZANDO LA FORMULA E^x = 1 + X/ 1! + X^2/2! + ...
 */
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : CALCOLO DEL FATTORIALE
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// INIZIALIZZARE LE VARIABILI
//###########################################################################################################################
//###########################################################################################################################
// PRENDERE IN INPUT UN INTERO POSITIVO
// CALCOLARE IL FATTORIALE
// STAMPARE IL FATTORIALE
//###########################################################################################################################
//###########################################################################################################################

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    unsigned long fact(unsigned long); // PROTOTIPO FUNZIONE FATTORIALE
    unsigned long potenza(unsigned long, unsigned long); // PROTOTIPO FUNZIONE POTENZA
    
    // insert code here...
    unsigned long fat, count;
    double e = 1;
    
    do{
        printf("\nInserire un intero positivo: ");
        scanf("%u",&fat);
    }while(fat <= 0);
    
    printf("\nFattoriale di %u : %u \n",fat , fact(fat));

    for(count = 1; count <= 10; count++ )
        e += (double) 1 / (double) fact(count);
    
    printf("Costante e per un valore di x fino a 10 : %lf.\n",e);
    
    // SCRIVETE UN PROGRAMMA CHE APPROSSIMI IL VALORE DI UTILIZZANDO LA FORMULA e^x = 1 + X/ 1! + X^2/2! + X^3/3! + X^4/4!
    
    e = 1;
    
    for(count = 1; count < 5; count++ )
        e += (double) potenza(4,count) / (double) fact(count);
    
    printf("Costante e elevato alla 4 : %lf.\n",e);
    
    //printf("\npotenza di 4 alla 4:%u\n",potenza(4,1));
    
    
    return 0;
}

unsigned long fact(unsigned long fat){
    
    unsigned long count;
    count = fat;
    
    while(count != 1){
        fat *= (count - 1);
        count--;
    }
    return fat;
}

unsigned long potenza(unsigned long base, unsigned long esponente){
    unsigned long y = base;
    
    if(esponente == 0)
        base = 1;
    else
    while(esponente-- >= 2)
            base *= y;
    return base;
}