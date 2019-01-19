//
//  main.c
//  Exe4.16
//
//  Created by Francesco Parrucci on 12/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
 SCRIVERE UN PROGRAMMA CHE VISUALIZZI SEPARATAMENTE DEI DISEGNI UTILIZZANDO I CICLI FOR PER GENERARE I DISEGN. TUTTI GLI ASTERISCHI (*) DOVRANNO ESSERE STAMPATI DA UNA SINGOLA ISTRUZIONE PRINTF DELLA FORMA PRINTF("*"); (CIO' CAUSERA' LA VUSUALIZZAZIONE FIANCO A FIANCO DEGLI ASTERISCHI). SUGGERIMENTO: GLI ULTIMI DUE DISEGNI RICHIEDERANNO CHE OGNI RIGA INCOMINCI CON UN NUMERO APPROPIRATO DI SPAZI
*/
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : DISEGNI CON ASTERISCHI (*)
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARARE LE VARIABILI
// VISUALIZZA QUATTRO DISEGNI DI ASTERISCI
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE DELLE VARIABILI COUNT1 COUNT2 COUNT3
//###########################################################################################################################
//###########################################################################################################################
// PER COUNT1 DA 1 A 4 ESEGUI LE SEGUENTI OPERAZIONI
//  PRIMO DISEGNO
//      PER COUNT2 DA 1 A 10 ESEGUI LE SEGUENTI ISTRUZIONI E VAI A CAPO
//      PER COUNT3 DA 1 A COUNT2 STAMPA ASTERICHI
//
//  SECONDO DISEGNO
//      PER COUNT2 DA 10 A 1 ESEGUI LE SEGUENTI ISTRUZIONI E VAI A CAPO
//      PER COUNT3 DA 1 A COUNT2 STAMPA GLI ASTERISCHI
//
//  TERZO DISEGNO
//      PER COUNT2 DA 1 A 10 ESEGUI LE SEGUENTI ISTRUZIONI A VAI A CAPO
//      PER COUNT3 DA 1 A 10 SE MINORE O UGUALE A COUNT2 STAMPA UNO SPAZIO ALTRIMENTI UNO ASTERISCO
//
//  QUARTO DISEGNO
//      PER COUNT2 DA 10 A 1 ESEGUI LE SEGUENTI ISTRUZIONI A VAI A CAPO
//      PER COUNT3 DA 1 A 10 SE MINORE O UGUALE A COUNT2 STAMPA UNO SPAZIO ALTRIMENTI UNO ASTERISCO
//
//###########################################################################################################################
//###########################################################################################################################

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int count1, count2;
    
    printf("\nPrimo disegno:\n");
    
    for(count1 = 1 ; count1 <= 10; count1++){
        for(count2 = 1; count2 <= count1; count2++)
            printf("*");
        printf("\n");
    }
    
    printf("\Secondo disegno:\n");
    
    for(count1 = 10 ; count1 >= 1; count1--){
        for(count2 = 1; count2 <= count1; count2++)
            printf("*");
        printf("\n");
    }
    
    printf("\nTerzo disegno:\n");
    
    for(count1 = 1 ; count1 <= 10; count1++){
        for(count2 = 1; count2 <= 10; count2++)
            if(count2 <= count1)
                printf(" ");
            else
                printf("*");
        printf("\n");
    }
    
    printf("\nQuarto disegno:\n");
    
    for(count1 = 10 ; count1 >= 1; count1--){
        for(count2 = 1; count2 <= 10; count2++)
            if(count2 <= count1)
                printf(" ");
            else
                printf("*");
        printf("\n");
    }
    return 0;
}
