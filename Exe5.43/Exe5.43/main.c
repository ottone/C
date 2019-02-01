//
//  main.c
//  Exe5.43
//
//  Created by Francesco Parrucci on 01/02/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
PUO' IL MAIN ESSERE CHIAMATO IN MODO RICORSIVO? SRIVETE UN PROGRAMMA CHE CONTENGA UN FUNZIONE MAIN. INDICATE LA VARIABILE 
LOCALE STATIC COUNT INIZIALIZZATA A 1. OGNI VOLTA CHE LA FUNZIONE MAIN E' INVOCATA, APPLICATE L'OPERATORE DI POSTINCREMENTO E
VISUALIZZATE IL VALORE DI COUNT.
*/

#include <stdio.h>

void top(void);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    while(1)
        top();
    
    printf("\nHello, World!\n");
    return 0;
}

void top(void){
    static int count = 1;
    printf("\nvalore di count: %d",count++);
}