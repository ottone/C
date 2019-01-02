//
//  main.c
//  Exe3.17
//
//  Created by Francesco Parrucci on 29/12/18.
//  Copyright © 2018 Francesco Parrucci. All rights reserved.
//
/* A CAUSA DELL'ALTO PREZZO DELLA BENZINA, GLI AUTOMOBILISTI SONO INTERESSATI AL NUMERO DI CHILOMETRI PERCORSI DALLE PROPRE AUTOMOBILI. UN AUTOMOBILISTA HA MENTENUTO TRACCIA DI DIVERSI PIENI DI BENZINA, REGISTRANDO I CHILOMETRI PERCORSI E I LITRI UTILIZZATI PER OGNI PIENO. SVILUPPATE UN PROGRAMMA C CHE PRENDA IN INPUT I CHILOMETRI PERCORSI EI LITRI UTILIZZATI PER OGNI PIENO. IL PROGRAMMA DOVRA'CALCOLARE E VISUALIZZARE ANCHE I CHILOMETRI PER LITRO OTTENUTI COMPLESSIVAMENTE DA TUTTI I PIENI
*/

//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : CALCOLARE I CHILOMETRI PER LITRO DI OGNI PIENO
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// INIZIALIZZARE LE VARIABILI LITRI, CHILOMETRI, LITRI_TOT E CHILOMETRI_TOT
// ACQUISIZIONE DATI LITRI E CHILOMETRI PERCORSI
// VISUALIZZA MEDIA DEI CHILOMETRI PER LITRO
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE E INIZIALIZZAZIONE DELLE VARIABILI LITRI , CHILOMETRI , LITRI TOT E CHILOMETRI E MEDIA_CONSUMI
//###########################################################################################################################
//###########################################################################################################################
// INSERISCI IL NUMERO DI CHILOMETRI PERCORSI
// INSERISCI IL NUMERO DI LITRI UTILIZZATI
// FINCHE' NUMERO DI LITRI E' DIVERSO DA -1 CONTINUA
// SOMMA LITRI A LITRI_TOT
// SOMMA CHILOMETRI A CHILOMETRI_TOT
// INSERISCI IL NUMERO DI CHILOMETRI PERCORSI
// INSERISCI IL NUMERO DI LITRI UTILIZZATI
//###########################################################################################################################
//###########################################################################################################################
// DIVIDI IL TOTALE DEI CHILOMETRI PER IL TOTALE LITRI ED ASSEGNA IL VALORE A MEDIA_CONSUMI
// VISUALIZZA IL RISULTATO.
//###########################################################################################################################
//###########################################################################################################################


#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int litri, chilometri, tot_litri, tot_chilometri;
    float media_consumi;
    
    printf("Inserisci il numero di chilometri percorsi:");
    scanf("%d",&chilometri);
    printf("Inserisci il numero di litri utilizzati -1 per terminare: ");
    scanf("%d", &litri);
    while( litri != -1){
        tot_litri += litri;
        tot_chilometri += chilometri;
        printf("Inserisci il numero di chilometri percorsi:");
        scanf("%d",&chilometri);
        printf("Inserisci il numero di litri utilizzati -1 per terminare: ");
        scanf("%d", &litri);
    }
    
    media_consumi = (float) tot_chilometri / tot_litri;
    
    printf("media dei consumi sui dati pieni / chilometri: %.2f Chilometri per litro\n", media_consumi);
    return 0;
}
