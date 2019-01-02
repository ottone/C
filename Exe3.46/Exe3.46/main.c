//
//  main.c
//  Exe3.46
//
//  Created by Francesco Parrucci on 01/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 UNA AZIENDA VUOLE TRASMETTERE DEI DATI SULLA LINEA TELEFONICA, MA I SUOI RESPONSABILI SONO PREOCCUPATI DAL FATTO CHE I PROPRI
 TELEFONI POTREBBERO ESSERE SPIATI. TUTTI I LORO DATI SONO TRASMESSI COME INTRI DI QUATTRO CIFRE. VI HANNO QUINDI CHIESTO DI
 SCRIVERE UN PRAGRAMMA CHE CRITTOGRAFI I LORO DATI IN MODO CHE POSSANO ESSERE TRASMESSI CON MAGGIOR SICUREZZA. IL VOSTRO
 PROGRAMMA DOVRA LEGGERE UN INTERO DI QUATTRO CIFRE E CRITTOGRAFARLO NEL MODO SEGUENTE: SOSTITUITE OGNI CIFRA CON (LA SOMMA DI
 QUELLA CIFRA PIU' 7) MODULO 10. IN SEGUITO SAMBIATE LA PRIMA CIFRA CON LA TERZA E SCAMBIATE LA SECONDA CIFRA CON LA QUARTA.
 VISUALIZZATE QUIDNDI L'INTERO CRITTOGRAFATO. SCRIVETE UN PROGRAMMA A PARTE CHE PRENDA IN INPUT UN INTERO DI QUATTRO CIFRE E LO
 DECIFRI, IN MODO DA FORMARE IL NUMERO ORIGINALE.
 */
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : CIFRARE E DEFIFRARE UN INTERO DI QUATTRO CIFRE
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// INIZIALIZZARE LE VARIABILI
//###########################################################################################################################
//###########################################################################################################################
// PRENDERE IN INPUT UN INTERO DI QUATTRO CIFRE
// SEPARARE LE CIFRE
// CIFRARE OGNI CIFRA
// RIASSEMBLARE NELL'ORDINE CIFRATO
// STAMPARE L'OUTPUT CIFRATO
// SEPARARE L'INTERO CIFRATO
// DECIFRARE OGNI
// RIASSEMBLARE OGNI CIFRA NELL'ORDINE ORIGINARIO
// STAMPARE L'OUTPUT DEFIFRATO
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE E INIZIALIZZAZIONE DELLE VARIABILI:
// CHIARO , CIFRATO, PRIMA , SECONDA, TERZA , QUARTA
//###########################################################################################################################
//###########################################################################################################################
// PRENDERE IN INPUT UN INTERO COMPRESO TRA 1000 E 10000 MEMORIZZARLO IN CHIARO
//
// PRIMA = ((CHIARO % 10) + 7) % 10 E CHIARO = CHIARO / 10
// SECONDA = ((CHIARO % 10) + 7) % 10 E CHIARO = CHIARO / 10
// TERZA = ((CHIARO % 10) + 7) % 10 E CHIARO = CHIARO / 10
// QUARTA = ((CHIARO % 10) + 7) % 10 E CHIARO = CHIARO / 10
//
// CIFRATO = TERZA + 10 * QUARTA + 100 * PRIMA + 1000 * SECONDA
//
// STAMPA IL NUMERO CIFRATO
//
// PROCESSO INVERSO
//
// PRIMA = ((CIFRATO % 10 + 10) - 7) % 10 E CHIARO = CHIARO / 10
// SECONDA = ((CIFRATO % 10 + 10) - 7) % 10 E CHIARO = CHIARO / 10
// TERZA = ((CIFRATO % 10 + 10) - 7) % 10 E CHIARO = CHIARO / 10
// QUARTA = ((CIFRATO % 10 + 10) -7) % 10 E CHIARO = CHIARO / 10
//
// CHIARO = TERZA + 10 * QUARTA + 100 * PRIMA + 1000 * SECONDA
//
// STAMPA IL NUMERO CIFRATO
//###########################################################################################################################
//###########################################################################################################################


#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int chiaro, cifrato = 0, prima, seconda, terza, quarta;
    
    do{
       printf("\nInserisci un intero di quattro cifre:");
       scanf("%d", &chiaro);
    }while(chiaro <= 1000 || chiaro >= 10000);
    
    prima = (chiaro % 10 + 7) % 10;
    chiaro /= 10;
    seconda = (chiaro % 10 + 7) % 10;
    chiaro /= 10;
    terza = (chiaro % 10 + 7) % 10;
    chiaro /= 10;
    quarta = (chiaro % 10 + 7) % 10;
    chiaro /= 10;
        
    printf("\nNumero cifrato : %d\n", cifrato = terza + quarta * 10 + prima * 100 + seconda * 1000);
    
        
    prima = ((cifrato % 10 + 10) - 7) % 10;
    cifrato /= 10;
    seconda = ((cifrato % 10 + 10) - 7) % 10;
    cifrato /= 10;
    terza = ((cifrato % 10 + 10) - 7) % 10;
    cifrato /= 10;
    quarta = ((cifrato % 10 + 10) - 7) % 10;
    cifrato /= 10;
        
    printf("\nNumero in chiaro: %d\n", chiaro = terza + quarta * 10 + prima * 100 + seconda * 1000);
        
        
    return 0;
}
