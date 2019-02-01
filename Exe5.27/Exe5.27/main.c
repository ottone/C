//
//  main.c
//  Exe5.27
//
//  Created by Francesco Parrucci on 30/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
UN INTERO E' DETTO PRIMO QUALORA SIA DIVISIBILE SOLTANTO PER 1 E PER SE STESSO. PER ESEMPIO 2, 3, 5, E 7 SONO PRIMI, MENTRE 3,5,7,9 NON LO SONO.
 A) SCRIVETE UNA FUNZIONE CHE DETERMINI SE UN NUMERO SIA PRIMO;
 B) UTILIZZATE QUESTA FUNZIONE IN UN PROGRAMMA CHE DETERMINI E VISUALIZZI TUTTI I NUMERI PRIMI TRA 1 E 10000 QUANTI DI QUESTI 
    10000 NUMERI DOVRETE REALMENTE VERIFICARE PRIMA DI ESSERE SICURI DI AVER TROVATO TUTTI I NUMERII PRIMI ?
 C) INIZIALMENTE POTRESTE PENSARE CHE N/2 SIA IL LIMITE SUPERIORE CHE DOVRETE VERIFICARE PER VEDERE SE UN NUMERO SIA PRIMOM MA 
    IN REALTA' VI VASTERA' ARRIVARE ALLA RADICE QUADRATA DI N. PERCHE'? RISCRIVETE IL PROGRAMMA E FATELO ESEGUIRE IN ENTRAMBI I 
    MODI. STIMATE IL MIGLIORAMENTO DELLE PRESTAZIONI
 */
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : VERIFICA DEL NUMERO PRIMO//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARARE LE VARIABILI E FUNZIONI first:
// ACQUISISCI IL NUMER DELLE ORE PARCHEGGIATE PER OGNI VETTURA
// STAMPA DEL RISUTATI
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE DELLE VARIABILI E FUNZIONI:
// -- PROTOTIPO DI FUNZIONE int first(int)
// -- VARIABILE INT COUNT
//###########################################################################################################################
//###########################################################################################################################
// ACQUISISCI IL NUMERO EOF PER TERMINARE
// -- PER COUNT DA 1 A 10000 VERIFICA SE PRIMO CON LA FUNZIONE first
//###########################################################################################################################
//###########################################################################################################################
// DEFINIZIONE DELLA FUNZIONE int first(int number, int divide = 2)
//###########################################################################################################################
//###########################################################################################################################
// SE COUNT == NUMBER - 1
//  -- RETURN 1
// ALTRIMENTI SE number % count == 0
//  -- RETURN first(number, count + 1)
// ALTRIMENTI
//  -- RERURN 0;
//###########################################################################################################################
//###########################################################################################################################


#include <stdio.h>
#include <math.h>

int first(int number, int count);

int main(int argc, const char * argv[]) {
    // insert code here...
    int number, count;
    /*do{
        printf("\nInserisci un numero EOF per terminare: ");
        scanf("%d",&number);
        printf("\nIl numero %d %s primo.",number,first(number,2) ? "è" : "non è");
    }while(getchar() != EOF);
    */
    printf("\nNumeri primi da 2 a 10000:\n");
    for(count = 1 ; count <= 1000000; count++)
        printf("\nIl numero %d %s primo.",count,first(count,1) ? "è" : "non è");
    
    printf("\nHello, World!\n");
    return 0;
}
int first(int number, int count){
    if(count >=  sqrt(number))
        return 1;
    else if(number % count != 0 || count == 1)
        return first(number, count + 1);
    else
        return 0;
}