//
//  main.c
//  Exe4.18
//
//  Created by Francesco Parrucci on 13/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 UNA INTERESSANTE APPLICAZIONE DEI COMPUTER E' IL DISEGNO DI DIAGRAMMI E DI GRAFICI A BARRE (DETTI A VOLTE "ISTOGRAMMI").
 SCRIVETE UN PROGRAMMA CHE LEGGA CINQUE NUMERI (OGNUNO COMPRESO TRA 1 E 30). PER OGNI NUMERO LETTO, IL VOSTRO PROGRAMMA DOVRA'
 VISUALIZZARE UNA RIGA CONTENTENTE QUEL NUMERO DI ASTERISCI ADIACENTI, PER ESEMPIO SI IL VOSTRO PROGRAMMA LEGGESSE IL NUMERO
 SETTE DOVRA' VISUALIZZARE *******.
*/
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : DISEGNARE UNA RIGA DI ASTERISCHI PER PER OGNI NUMERO INSERITO
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARARE LE VARIABILI:
// RIPETERE LE SEGUENTI ISTRUZIONI PER TRE VOLTE
// ACQUISIZIONE DI UN NUMERO
// STAMPA UN NUMERO DI ASTERISCHI PARI AL NUMERO INSERITO
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE DELLE VARIABILI:
// -- VARIABILE INTERA COUNT1;
// -- VARIABILE INTERA NUMERO;
//###########################################################################################################################
//###########################################################################################################################
// PER COUNT1 DA 1 A 3 ACQUISIZIONE DATI:
// -- RACCOGLIERE IN INPUT UN NUMERO
// -- RACCOGLIERE IN INPUT IL LIMETE DI CREDITO DEL CLIENTE PRIMA DELLA RECESSIONE
// STAMPA
// -- PER NUMERO MAGGIORE O UGUALE A 1 STAMPA UN ASTERSISCO E DECREMENTA DI UNA UNITA' NUMERO;
// -- VAI A CAPO
//###########################################################################################################################
//###########################################################################################################################

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int count1 , numero;
    
    for(count1 = 1 ; count1 <= 3 ; count1++) {
        printf("Inserisci un numero intero : ");
        scanf("%d",&numero);
        while(numero-- >= 1)
               printf("*");
               printf("\n");
    }
    return 0;
}
