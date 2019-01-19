//
//  main.c
//  Exe4.14
//
//  Created by Francesco Parrucci on 12/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
  LA FUNZIONE FATTORIALE è UTILIZZATA FREQUENTEMENTE NEI PROBLEMI DI PROBABILITA'. IL FATTORIALE DI UN INTERO POSITIVO N , SCRITTO N! E PRONUNCIATO "FATTORIALE DI N", E' UGUALE AL PRODOTTO DEGLI INTERI POSITIVI
  DA 1 A N. SCRIVETE UN PROGRAMMA CHE VALUTI I FATTORIALI DEGLI INTERI DA 1 A 5. VISUALIZZATE I RISULTATI IN FORMATO TABULARE. QUALE DIFFICOLTA' PROTRA' IMPEDIRVI DI CALCOLARE IL FATTOIRLAE DI 20?
*/
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : VISUALIZZARE IL FATTORIALE DEGLI INTERI DA 1 A 5  IN FORMATO TABULARE
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARARE LE VARIABILI
// PER I VALORI DA 1 A 5 CALCOLA IL FATTORIALE E STAMPA OGNI VALORE IN LINEA
// VAI A CAPO E INCREMENTA COUNT
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE DELLE VARIABILI INTERO COUNT E FACT = 1
//###########################################################################################################################
//###########################################################################################################################
// PER COUNT UGUALE A 1 COUNT MINORE E UGUALE A 5
// PONI INTERO UGUALE A COUNT
// SE COUNT E' UGUALE A 1  IL FATTORIALE DI 1  E' 1 QUINDI STAMPA 1
// FINCHE INTERO > 1  STAMPA FACT * INTERO ED ESEGUI FACT = FACT * INTERO DECREMENTA INTERO
// STAMPA IL VALORE FACT E VAI A CAPO
//###########################################################################################################################
//###########################################################################################################################



#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int fact = 1, count , intero;
    printf("Fattoriale dei valori da 1 a 5\n");
    for(count = 1; count <= 8; count++, fact = 1){
        printf("%d! : ",count);
        intero = count;
        if(count == 1)
            ;
        else
            while(intero > 1){
                printf("| %d * %d ",fact , intero);
                fact *= intero;
                intero--;
            }
        
        printf(": %d \n",fact);
    }
    printf("\nFine!\n");
    return 0;
}
