//
//  main.c
//  Exe6.19
//
//  Created by Francesco Parrucci on 10/02/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
SCRIVETE UN PROGRAMMA IN C CHE SIMULI IL LANCIO DI DUE DADI. IL PROGRAMMA DOVRA' UTILIZZARE RAND PER LANCIARE IL PRIMO DADO E 
INVOCARLA NUOVAMENTE PER LANCIARE IL SECONDO DADO. DOVRA' QUINDI ESSERE CALCOLATA LA SOMMA DEI DUE VALORI. NOTA : POICHE' OGNI 
DADO PUO' MOSTRARE UN VALORE INTERO COMPRESO TRA 1 E 6, LA SOMMA DEI DUE VALORI POTRA' VARIARE TRA 2 E 12, CON 7 COME SOMMA 
PIU' FREQUENTE E 2 E 12 COME SOMME MENO FREQUENTI. LA FIGURA 6.23 MOSTRA LE 36 POSSIBILI COMBINAZIONI DEI DUE DADI. IL VOSTRO 
PROGRAMMA DOVRA' LANCIARE I DUE DADI 36.000 VOLTE. UTILIZZATE UN VETTORE UNIDIMENSIONALE PER SOMMARE IL NUMERO DI OCCORRENZE DI 
OGNI SOMMA POSSIBILIE. VUSUALIZZATE I RISULTATI IN UN FORMATO TABULARE. DETERMINATE ANCHE SE I TOTALI SONO SENSATI: CI SONO SEI 
MODI PER OTTENERE UN 7, PERCIO' CIRCA UN SESTO DEI LANCI DOVREBBE OTTENERLO.
 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 36
int lancio(void);
void ordinamento(int [], int);
void stampa(int [], int);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    srand((int)time(NULL));
    
    int lanci[SIZE] = {0}, x = 0;
    
    while(x <= SIZE - 1)
        lanci[x++] = lancio() + lancio();
    
    printf("\n\n Stampa non ordinata \n\n");
    
    for(x = 1 ; x <= SIZE; x++){
        printf("%3d",lanci[x - 1]);
        if(x % 6 == 0)
            printf("\n");
    }
    
    ordinamento(lanci, SIZE);
    
    stampa(lanci, SIZE);
    
    printf("\nHello, World!\n");
    return 0;
}

void stampa(int array[], int index){
    
    int x, temp , y;
    
    printf("\n\n Stampa Ordinata \n\n");
    
    for(x = 0, temp = 6 ; x <= 5; x++,temp--){
        for(y = x; y <=  index - temp ; y += 6)
            printf("%3d",array[y]);
        printf("\n");
    }

}

void ordinamento(int array[], int index){
    
    int x, y, temp;
    
    printf("\n\n Ordinamento \n\n");
    
    for(x = 1; x <= index - 1; x++)
        for(y = 0; y <= index - (x +1); y++)
            if(array[y] > array[y + 1]) {
                temp = array[y];
                array[y] = array[y + 1];
                array[y + 1] = temp;
            }

}

int lancio (void){
    return rand() % 6 + 1;
}