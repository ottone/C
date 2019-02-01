//
//  main.c
//  Exe5.31
//
//  Created by Francesco Parrucci on 31/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
SCRIVETE UN PROGRAMMA CHE SIMULI IL LANCIO DI UNA MONETINA. PER OGNI LANCIO DELLA MONETINA IL PROGRAMMA DOVRA' VISUALIZZARE 
Heads o Tails. LASCIATE CHE IL PROGRAMMA LANCI LA MONETINA PER 100 VOLTE E CONTATE  IL NUMERO DI OCCORRENZE PER LA COMPARSA DI 
OGNI FACCIA DELLA MONETINA. VISUALIZZATE I RISULTATI. IL PROGRAMMA DOVRA' CHIAMARE UNA FUNZIONE DISTINTA flip, CHE NON
RICEVERA' ARGOMENTI E CHE RESTITUIRA' 0 PER CROCE E 1 PER TESTA. NOTA: QUALORA IL PROGRAMMA SIMULI REALISTICAMENE IL LANCIO DI
UNA MONETINBA, ALLORA OGNI FACCIA DELLA STESSA DOVRA' APPARIRE APPROSSIMATIVAMENE LA META' DELLE VOLTE, PER UN TOTALE
APPROSSIMATIVO DI 50 TESTE E 50 CROCI.
*/
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : LANCIO DI UNA MONETINA
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARARE LE VARIABILI E FUNZIONI flip:
// RICHIAMA LA FUNZIONE flip 100 VOLTE E POI CONTA IL NUMERO DELLE TESTE E CROCI.
// STAMPA DEL RISUTATI
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE DELLE VARIABILI E FUNZIONE flio:
// -- PROTOTIPO DI FUNZIONE int flip(void)
// -- VARIABILE INT count
//###########################################################################################################################
//###########################################################################################################################
// RICHIAMA LA FUNZIONE flip 100 VOLTE E POI CONTA IL NUMERO DELLE TESTE E CROCI.
// -- PER count da 1  a 100
//      -- SE flip = 0 incrementa Tails Altrimenti Heads
// STAMPA DEI RISULTATI
//###########################################################################################################################
//###########################################################################################################################
// DEFINIZIONE DELLA FUNZIONE int flip (void)
//###########################################################################################################################
//###########################################################################################################################
// INSEMINA rand() con srand(time(NULL));
// FATTORE DI SCALA 2
// RETURN rand() % 2;
//###########################################################################################################################
//###########################################################################################################################


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int flip(void);

int main(int argc, const char * argv[]) {
    // insert code here...
    srand((int)time(NULL));
    int Heads = 0, Tails = 0, count;
    for(count = 0; count < 100; count++)
        flip() ? Tails++ : Heads++;
    
    printf("\n%d Lanci , %d Teste e %d Croci.",count, Heads,Tails);
    printf("\nHello, World!\n");
    return 0;
}

int flip(void){
    return rand() % 2;
}