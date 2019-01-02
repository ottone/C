//
//  main.c
//  Exe3.20
//
//  Created by Francesco Parrucci on 29/12/18.
//  Copyright © 2018 Francesco Parrucci. All rights reserved.
//
/* 
  L'INTERESSE SEMPLICE SU UN MUTUO E' CALCOLATO DALLA FORMULA INTEREST = PRINCIPAL  * RATE * DAYS / 365 LA FORMULA PRECEDENTE
  PRESUME CHE RATE SIA IL TASSO DI INTERESSE ANNUALE E QUINDI INCLUDE LA DIVISIONE PER 365 GIORNI. SVILUPPATE UN PROGRAMMA C
  CHE PRENDA IN INPUT PRINCIPAL (CAPITALE) , RATE (TASSO) E DAYS (GIORNI) PER DIVERSI MUTUI  E VISUALIZZI L'INTERESSE  SEMPLICE
  PER OGNI MUTUO, UTILIZZANDO LA FORMULA PRECEDENTE.
*/

//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : CALCOLO DELL'INTERESSE ANNUO CON LA SEGUENTE FORMULA INTERESSE = CAPITALE * TASSO * GIORNI / 365
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE E INIZIALIZZAZIONE DELLE VARIABILI
// ACQUISIZIONE DATI E CALCOLO
// VISUALIZZA PROSPETTO
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE E INIZIALIZZAZIONE DELLE VARIABILI DEL CAPITALE , TASSO , GIORNI E INTERESSE
//###########################################################################################################################
//###########################################################################################################################
// CALCOLO INTERESSE CON LA SEGUENTE FORMULA INTERESSE = CAPITALE * TASSO * GIORNI / 365
//###########################################################################################################################
//###########################################################################################################################
// STAMPA IL PROSPETTO
//###########################################################################################################################
//###########################################################################################################################


#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    const int GIORNI = 365;
    int tempo;
    float interesse , capitale , tasso;
    printf("\t\t***\tCALCOLO DELL'INTERESSE ANNUO\t***\n");
    printf("\tInserire il capitale per il quale calcolare l'interesse: ");
    scanf("%f", &capitale);
    printf("\tInserire il tasso d'interesse: ");
    scanf("%f", &tasso);
    printf("\tInserire il numero di giorni per il quale si intende effettuare il calcolo: ");
    scanf("%d", &tempo);
    
    printf("\t*** Ammontare dell'interesse relativo al capitale e al periodo indicato : %.2f\n", interesse = capitale * tasso * tempo / GIORNI);
    
    
    return 0;
}
