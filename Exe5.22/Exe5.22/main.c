//
//  main.c
//  Exe5.22
//
//  Created by Francesco Parrucci on 27/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 SCRIVETE DEI SEGMENTI DI PROGRAMMA CHE ESEGUONO OGNUNO DEI SEGUENTI COMPITI: 

 A) CALCOLARTE LA PARTE INTERA DEL QUOZIENTE OTTENUTO DALLA DIVISIONE DEGLI INTERI A E B
 
 B) CALCOLATE IL RESTO INTERO OTTENUTO DALLA DIVISIONE DEGLI INTERI A E B
 
 C) UTILIZZATE I PEZZI DI PROGRAMMA SVILUPPATI IN A) E B) PER SCRIVERE UNA FUNZIONE CHE PRENDA IN INPUT UN INTERO, COMPRESO TRA
 1 E 32727, E LO VISUALIZZI COME UNA SEQUENZA DI CIFRE, SEPARANDO OGNI COPPIA DI ESSE CON DUE SPAZI, PER ESEMPIO , L'INTERO
 4562 DOVRA' ESSERE STAMPATO COME 4  5  6  2
 */
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : STAMPA CIFRE DI UN NUMERO DISTAZIATE DA DUE SPAZI
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARARE LE VARIABILI E FUNZIONI:
// ACQUISISCI UN NUMERO TRA 1 E 32767
// CHIAMA LA FUNZIONE
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE DELLE VARIABILI E FUNZIONI:
// -- PROTOTIPO DI FUNZIONE void display (int)
// -- VARIABILE INT x
//###########################################################################################################################
//###########################################################################################################################
// ACQUISISCI UN INTERO TRA 1 E 32767
// CHIAMA LA FUNZIONE display
//###########################################################################################################################
//###########################################################################################################################
// DEFINIZIONE DELLA FUNZIONE void display(int x)
//###########################################################################################################################
//###########################################################################################################################
// DICHIARA UNA VARIABILE COUNT = 1
// FINCHE COUNT < X COUNT = COUNT * 10
// -- DIVIDI COUNT PER 10
// FINCHE IL RESTO DELLA DIVISIONE DI X PER COUNT E' MAGGIORE DI ZERO
// -- STAMPA IL QUOZIENTE E DUE SPAZI
// -- X %= COUNT
// -- COUNT /= 10
//###########################################################################################################################
//###########################################################################################################################



#include <stdio.h>

void display (int);

int main(int argc, const char * argv[]) {
    // insert code here...
    int x;
    do{
        printf("\nInserisci un intero tra 1 e 32767: ");
        scanf("%d",&x);
    }while(!(x>= 1 && x <= 32767));
           
           display(x);
    
    printf("\nHello, World!\n");
    return 0;
}

void display(int x){
    int count = 1;
    
    while(count <= x)
        count *= 10;
    count /= 10;
    
    while(x != 0){
        printf("%d  ",x / count);
        x %= count;
        count /= 10;
    }
    }