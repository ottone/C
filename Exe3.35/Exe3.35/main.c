//
//  main.c
//  Exe3.35
//
//  Created by Francesco Parrucci on 30/12/18.
//  Copyright © 2018 Francesco Parrucci. All rights reserved.
//
/* UN PALINDROMO E' UN NUMERO O UNA FRASE DI TESTO CHE DA SINISTRAA DESTRA O DA DESTRA A SINISTRA SI LEGGE NELLO STESSO MODO. PER ESEMPIO OGNUNO DEI SEGUENTI INTERI DI CINQUE CIFRE E' UN PALINDROMO: 12321, 55555, 45554 E 11611. SCRIVETE UN PROGRAMMA CHE LEGGA IN INPUT UN INTERO DI CINQUE CIFRE E DETERMINI SE SI TRATTA O NO DI UN PALINDROMO. (SUGGERIMENTO: PER SCINDERE IL NUMERO NELLE SUE SINGOLE CIFRE UTILIZZATE GLI OPERATORI DI DIVISIONE E DI MODULO)
*/
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : DETERMINARE SE UN NUMERO E' PALINDROMO
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// INIZIALIZZARE LE VARIABILI
//###########################################################################################################################
//###########################################################################################################################
// PRENDERE IN INPUT UN INTERO
// DETERMINARE SE E' UN PALINDROMO
//###########################################################################################################################
//###########################################################################################################################
// STAMPA IL RISULTATO
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE E INIZIALIZZAZIONE DELLE VARIABILI INTERO, LUNGHEZZA, SENTINELLA, COUNT1 E COUNT2;
//###########################################################################################################################
//###########################################################################################################################
// INSERIRE UN NUMERO E MEMORIZZARLO IN INTERO
// DETERMINARE LA LUNGHEZZA DELL'INTERO
// INIZIA CICLO WHILE INFINITO
// SE L'INTERO O IL QUOZIENTE DELL'INTERO DIVISO 10 E' UGUALE A ZERO O BREAK
// SE IL QUOZIENTE DELL'INTERO X IL MASSIMO MULTIPLO DI DIECI E IL QUOZIENTE DELL'INTERO PER 10 SONO UGUALI
// CORRISPONDENZA TROVATA, DIVIDI IL MASSIMO MULTIPLO X 10 PONI L'INTERO UGUALE AL QUOZIENTE DELLO STESSO PER 10
// PONI L'INTERO OTTENUTO UGUALE AL RESTO DEL QUOZIENTE DELL'INTERO DIVISO IL MULTIPLO DI 10 E RI-DIVIDI IL MASSIMO
// MULTIPLO PER 10 CONTINUA FINCHE' TROVI UGUAGLIANZE
// SE INVECE NON CI SONO CORRISPONDENZE STAMPLA IL MESSAGGIO CHE NON E' UN NUMERO PALINDROMO E ESCI DAL CICLO WHILE
//###########################################################################################################################
//###########################################################################################################################


#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int lunghezza = 1 , sentinella = 1, intero, count1 = 1 , count2 = 10;
    printf("Inserisci un numero: ");
    scanf("%d", &intero);
    
    while(count1 < intero)
        count1 *= 10;
    count1 /= 10;
    
    while (1){
        if(intero == 0 || intero / 10 == 0)
           break;
        else if(intero / count1 == intero % count2){
           printf("corrispondenza trovata!\n");
           count1 /= 10;
           intero = intero / 10;
           intero = intero % count1;
           count1 /= 10;
        }else{
           printf("non è un palindromo!");
           break;
        }
        
    }
    
    
    
    return 0;
}
